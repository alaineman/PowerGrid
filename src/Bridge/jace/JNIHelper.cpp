#include "jace/JNIHelper.h"

#include "jace/os_dep.h"
#include "jace/JFactory.h"
using jace::JFactory;

#include "jace/proxy/JObject.h"
using jace::proxy::JObject;

#include "jace/VmLoader.h"
using ::jace::VmLoader;

#include <cstdarg>
#include <stdlib.h>
#include <memory>
#include <iostream>
using std::cout;
using std::endl;

#if !defined(SUPPORTS_PTHREADS) && !defined(_WIN32)
#error Platform does not support pthreads or win32 thread-local storage
#endif

// Maybe something to think about: Qt has platform-independent Threads (QThreads)
// Can't we simplify this class to use QThreads?

#include <algorithm>
using std::copy;
using std::replace;

#include <vector>
using std::vector;

#include <map>
using std::map;

#include <string>
using std::string;

#ifdef SUPPORTS_PTHREADS
#include <pthread.h>
#include <errno.h>
#elif _WIN32

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers
#endif

#include <windows.h>

#endif

namespace jace {
namespace helper {

namespace {
    // A workaround for Ctrl-C causing problems.
    // If Ctrl-C isn't handled by the program, and it causes
    // a SIGTERM, the VM automatically shuts down. Meanwhile
    // we still attempt to free references. Since the VM isn't
    // there anymore, we core dump.
    //
    // Since there is no means for querying a VM to see if it is still
    // alive, we have to come up with something.
    // By making a global variable with destructor, we hope to discover
    // that the program is shutting down, and disable interaction
    // with the VM. This seems to work ok on Windows, but not with
    // gcc. *shrugs* For now, those people will have to handle Ctrl-C.
    volatile bool globalHasShutdown = false;

    // A reference to the java virtual machine.
    // We're under the assumption that there will always only be one of these.
    //
    JavaVM* javaVM = 0;

    std::auto_ptr<VmLoader> globalLoader( 0 );

    // The map of all of the java class factories.
    //
    typedef std::map<string,JFactory*> FactoryMap;

    FactoryMap* getFactoryMap() {
        static FactoryMap factoryMap;
        return &factoryMap;
    }

#ifdef SUPPORTS_PTHREADS
    pthread_key_t CLASSLOADER_KEY = 0;
#elif _WIN32
    DWORD CLASSLOADER_KEY = 0;
#endif

} // namespace

std::string asString( JNIEnv* env, jstring str ) {
    const char* utfString = env->GetStringUTFChars( str, 0 );
    if ( ! utfString ) {
        std::string msg = "Unable to retrieve the character string for an exception message.";
        throw JNIException( msg );
    }
    std::string stdString = utfString;
    env->ReleaseStringUTFChars( str, utfString );
    return stdString;
}


::jace::VmLoader* getVmLoader() {
    return globalLoader.get();
}


void setVmLoader( const ::jace::VmLoader& loader ) {
    globalLoader = std::auto_ptr<VmLoader>( loader.clone() );
}

/**
 * Invoked by jace.util.ShutdownHook on VM shutdown.
 */
extern "C" JNIEXPORT void JNICALL Java_jace_util_ShutdownHook_signalVMShutdown(JNIEnv*, jobject)
{
    globalHasShutdown = true;
}

void createVm( const VmLoader& loader,
               const OptionList& options,
               bool ignoreUnrecognized ) {

    globalLoader = std::auto_ptr<VmLoader>( loader.clone() );
    globalLoader->loadVm();

    JavaVM* vm;
    JNIEnv* env;

    JavaVMInitArgs vm_args;
    JavaVMOption* jniOptions = options.createJniOptions();

    vm_args.version = globalLoader->version();
    vm_args.options = jniOptions;
    vm_args.nOptions = jint( options.size() );

    vm_args.ignoreUnrecognized = ignoreUnrecognized;

    jint rc = globalLoader->createJavaVM( &vm, reinterpret_cast<void**>( &env ), &vm_args );

    options.destroyJniOptions( jniOptions );

    if ( rc != 0 ) {
        string msg = "Unable to create the virtual machine. The error was " + std::to_string( rc );
        throw JNIException( msg );
    }

    jclass runtimeClass = env->FindClass( "java/lang/Runtime" );
    if ( ! runtimeClass ) {
        string msg = "Assert failed: Unable to find the class, java.lang.Runtime.";
        throw JNIException( msg );
    }

    jmethodID runtimeGetRuntime = env->GetStaticMethodID( runtimeClass, "getRuntime", "()Ljava/lang/Runtime;" );
    if ( ! runtimeGetRuntime ) {
        deleteLocalRef( env, runtimeClass );
        string msg = "Assert failed: Unable to find the method, Runtime.getRuntime().";
        throw JNIException( msg );
    }

    jobject runtimeObject = env->CallStaticObjectMethod( runtimeClass, runtimeGetRuntime );
    if ( ! runtimeObject )	{
        deleteLocalRef( env, runtimeClass );
        string msg = "Unable to invoke Runtime.getRuntime()";
        try
        {
            helper::catchAndThrow();
        }
        catch (JNIException& e)
        {
            msg.append("\ncaused by:\n");
            msg.append(e.what());
        }
        throw JNIException( msg );
    }

    jmethodID runtimeAddShutdownHook = env->GetMethodID( runtimeClass, "addShutdownHook", "(Ljava/lang/Thread;)V" );
    if ( ! runtimeAddShutdownHook ) {
        deleteLocalRef( env, runtimeObject );
        deleteLocalRef( env, runtimeClass );
        string msg = "Assert failed: Unable to find the method, Runtime.addShutdownHook().";
        throw JNIException( msg );
    }

    jclass shutdownHookClass = env->FindClass( "jace/util/ShutdownHook" );
    if ( ! shutdownHookClass ) {
        deleteLocalRef( env, runtimeObject );
        deleteLocalRef( env, runtimeClass );
        string msg = "Assert failed: Unable to find the class, jace.util.ShutdownHook. Did you forget to include "
                "jace-runtime.jar in your classpath at runtime?";
        throw JNIException( msg );
    }

    // Register the native method jace.util.ShutdownHook.signalVMShutdown
    JNINativeMethod signalVMShutdown;
    signalVMShutdown.fnPtr     = reinterpret_cast<void*>(Java_jace_util_ShutdownHook_signalVMShutdown);
    signalVMShutdown.name      = const_cast<char*>("signalVMShutdown");
    signalVMShutdown.signature = const_cast<char*>("()V");

    jint result = env->RegisterNatives(shutdownHookClass, &signalVMShutdown, 1);
    if (result != JNI_OK) {
        deleteLocalRef( env, runtimeObject );
        deleteLocalRef( env, runtimeClass );
        deleteLocalRef( env, shutdownHookClass );
        string msg = "Assert failed: Unable to register native method, jace.util.ShutdownHook.signalVMShutdown()";
        throw JNIException( msg );
    }

    jmethodID shutdownHookGetInstance = env->GetStaticMethodID( shutdownHookClass, "getInstance", "()Ljace/util/ShutdownHook;" );
    if ( ! shutdownHookGetInstance ) {
        deleteLocalRef( env, runtimeObject );
        deleteLocalRef( env, runtimeClass );
        deleteLocalRef( env, shutdownHookClass );
        string msg = "Assert failed: Unable to find the method, jace.util.ShutdownHook.getInstance()";
        throw JNIException( msg );
    }

    jobject shutdownHookObject = env->CallStaticObjectMethod( shutdownHookClass, shutdownHookGetInstance );
    if ( ! shutdownHookObject ) {
        deleteLocalRef( env, runtimeObject );
        deleteLocalRef( env, runtimeClass );
        deleteLocalRef( env, shutdownHookClass );
        string msg = "Unable to invoke jace.util.ShutdownHook.getInstance()";
        try
        {
            helper::catchAndThrow();
        }
        catch (JNIException& e)
        {
            msg.append("\ncaused by:\n");
            msg.append(e.what());
        }
        throw JNIException( msg );
    }

    env->CallVoidMethod( runtimeObject, runtimeAddShutdownHook, shutdownHookObject );
    try
    {
        helper::catchAndThrow();
    }
    catch (JNIException& e)
    {
        string msg = "Exception thrown invoking Runtime.addShutdownHook(shutdownHook)";
        msg.append("\ncaused by:\n");
        msg.append(e.what());
        throw JNIException( msg );
    }
    deleteLocalRef( env, runtimeObject );
    deleteLocalRef( env, runtimeClass );
    deleteLocalRef( env, shutdownHookClass );
}

JavaVM* getJavaVM() throw ( JNIException ) {

    if ( ! javaVM ) {

        jsize numVMs;
        if (globalLoader.get() == 0) {
            string msg = string( "JNIHelper::getJavaVM\n" ) +
                    "Unable to find the JVM loader";
            throw JNIException( msg );
        }
        jint result = globalLoader->getCreatedJavaVMs( &javaVM, 1, &numVMs );

        if ( result != 0 ) {
            string msg = string( "JNIHelper::getJavaVM\n" ) +
                    "Unable to find the JVM. The specific JNI error code is " +
                    std::to_string( result );
            throw JNIException( msg );
        }

        if ( numVMs != 1 ) {
            string msg = string( "JNIHelper::getJavaVM\n" ) +
                    "Looking for exactly 1 JVM, but " +
                    std::to_string( numVMs ) +
                    " were found.";
            throw JNIException( msg );
        }
    }

    return javaVM;
}


void shutdown() {
    globalHasShutdown = true;

    // Currently (JDK 1.5) JVM unloading is not supported and DestroyJavaVM() always returns failure.
    // We do our best to ensure that the JVM is not used past this point.
    globalLoader->unloadVm();
}

JNIEnv* attach() throw ( JNIException ) {

    if ( globalHasShutdown ) {
        throw JNIException( "The VM has already been shutdown." );
    }

    JNIEnv* env;

    jint result = getJavaVM()->AttachCurrentThread( reinterpret_cast<void**>( &env ), 0 );

    if ( result != 0 ) {
        string msg = "JNIHelper::attach\n" \
                "Unable to attach the current thread. The specific JNI error code is " +
                std::to_string( result );
        throw JNIException( msg );
    }

    return env;
}

void detach() throw () {

    getJavaVM()->DetachCurrentThread();
}

void enlist( JFactory* factory ) {
    string name = factory->getClass()->getName();
    replace( name.begin(), name.end(), '/', '.' );
    getFactoryMap()->insert( FactoryMap::value_type( name, factory ) );
    //  cout << "helper::enlist - Enlisted " << name << endl;
}


jobject newLocalRef( JNIEnv* env, jobject ref ) {

    jobject localRef = env->NewLocalRef( ref );

    if ( ! localRef ) {
        string msg = string( "JNIHelper::newLocalRef\n" ) +
                "Unable to create a new local reference.\n" +
                "It is likely that you have exceeded the maximum local reference count.\n" +
                "You can increase the maximum count with a call to EnsureLocalCapacity().";
        throw JNIException( msg );
    }

    return localRef;
}

void deleteLocalRef( JNIEnv* env, jobject localRef ) {

    if ( hasShutdown() ) {
        return;
    }

    env->DeleteLocalRef( localRef );
}

jobject newGlobalRef( JNIEnv* env, jobject ref ) {

    jobject globalRef = env->NewGlobalRef( ref );

    if ( ! globalRef ) {
        string msg = string( "JNIHelper::newGlobalRef\n" ) +
                "Unable to create a new global reference.\n" +
                "It is likely that you have exceeded the max heap size of your virtual machine.";
        throw JNIException( msg );
    }

    return globalRef;
}

void deleteGlobalRef( JNIEnv* env, jobject globalRef ) {

    if ( hasShutdown() ) {
        return;
    }

    env->DeleteGlobalRef( globalRef );
}

void catchAndThrow() {

    JNIEnv* env = attach();

    if ( ! env->ExceptionCheck() ) {
        return;
    }

    jthrowable jexception = env->ExceptionOccurred();

    // cout << "helper::catchAndThrow() - Discovered an exception: " << endl;
    // print( jexception );

    env->ExceptionClear();

    /* Find the fully qualified name for the exception type, so
   * we can find a matching C++ proxy exception.
   *
   * In java, this looks like:
   *   String typeName = exception.getClass().getName();
   */
    //  cout << "helper::catchAndThrow() - Retrieving the exception class type..." << endl;
    jclass throwableClass = env->FindClass( "java/lang/Throwable" );

    if ( ! throwableClass ) {
        string msg = "Assert failed: Unable to find the class, java.lang.Throwable.";
        throw JNIException( msg );
    }

    jclass classClass = env->FindClass( "java/lang/Class" );

    if ( ! classClass ) {
        string msg = "Assert failed: Unable to find the class, java.lang.Class.";
        throw JNIException( msg );
    }

    jmethodID throwableGetClass = env->GetMethodID( throwableClass, "getClass", "()Ljava/lang/Class;" );

    if ( ! throwableGetClass ) {
        string msg = "Assert failed: Unable to find the method, Throwable.getClass().";
        throw JNIException( msg );
    }

    deleteLocalRef( env, throwableClass );

    jmethodID classGetName = env->GetMethodID( classClass, "getName", "()Ljava/lang/String;" );

    if ( ! classGetName ) {
        string msg = "Assert failed: Unable to find the method, Class.getName().";
        throw JNIException( msg );
    }

    jmethodID classGetSuperclass = env->GetMethodID( classClass, "getSuperclass", "()Ljava/lang/Class;" );

    if ( ! classGetSuperclass ) {
        string msg = "Assert failed: Unable to find the method, Class.getSuperclass().";
        throw JNIException( msg );
    }

    deleteLocalRef( env, classClass );

    jobject exceptionClass = env->CallObjectMethod( jexception, throwableGetClass );

    if ( env->ExceptionOccurred() ) {
        env->ExceptionDescribe();
        string msg = "helper::catchAndThrow()\n" \
                "An error occurred while trying to call getClass() on the thrown exception.";
        throw JNIException( msg );
    }

    jstring exceptionType = static_cast<jstring>( env->CallObjectMethod( exceptionClass, classGetName ) );

    if ( env->ExceptionOccurred() ) {
        env->ExceptionDescribe();
        string msg = "helper::catchAndThrow()\n" \
                "An error occurred while trying to call getName() on the class of the thrown exception.";
        throw JNIException( msg );
    }

    string exceptionTypeString = asString( env, exceptionType );

    /* Now, find the matching factory for this exception type.
   */
    while ( true ) {

        FactoryMap::iterator it = getFactoryMap()->find( exceptionTypeString );

        /* If we couldn't find a match, try to find the parent exception type.
     */
        if ( it == getFactoryMap()->end() ) {

            // cout << "Finding super class for " << endl;
            // print( exceptionClass );

            jobject superClass = env->CallObjectMethod( exceptionClass, classGetSuperclass );

            if ( env->ExceptionOccurred() ) {
                env->ExceptionDescribe();
                string msg = "helper::catchAndThrow()\n" \
                        "An error occurred while trying to call getSuperclass() on the thrown exception.";
                throw JNIException( msg );
            }

            /* We get NULL if we've already reached java.lang.Object, in which case,
       * we couldn't find any match at all.
       */
            if ( ! superClass ) {
                break;
            }

            deleteLocalRef( env, exceptionClass );
            deleteLocalRef( env, exceptionType );
            exceptionClass = superClass;

            exceptionType = static_cast<jstring>( env->CallObjectMethod( exceptionClass, classGetName ) );

            if ( env->ExceptionOccurred() ) {
                env->ExceptionDescribe();
                string msg = "helper::catchAndThrow()\n" \
                        "An error occurred while trying to call getName() on the superclass " \
                        "of the thrown exception.";
                throw JNIException( msg );
            }

            exceptionTypeString = asString( env, exceptionType );
            if ( exceptionTypeString == "java.lang.Object" ) {
                /*
                 * Couldn't find a matching exception. Abort!
                 */
                break;
            }
            continue;
        }

        /* Ask the factory to throw the exception.
     */
        // cout << "helper::catchAndThrow() - Throwing the exception " << endl;
        // print( jexception );

        jvalue value;
        value.l = jexception;
        it->second->throwInstance( value );
    }

    exceptionClass = env->CallObjectMethod( jexception, throwableGetClass );

    if ( env->ExceptionOccurred() ) {
        env->ExceptionDescribe();
        string msg = "helper::catchAndThrow()\n" \
                "An error occurred while trying to call getClass() on the thrown exception.";
        throw JNIException( msg );
    }

    exceptionType = static_cast<jstring>( env->CallObjectMethod( exceptionClass, classGetName ) );

    if ( env->ExceptionOccurred() ) {
        env->ExceptionDescribe();
        string msg = "helper::catchAndThrow()\n" \
                "An error occurred while trying to call getName() on the class of the thrown exception.";
        throw JNIException( msg );
    }

    exceptionTypeString = asString( env, exceptionType );
    //    cout << "Unable to find an enlisted class factory matching the type <" + exceptionTypeString + ">" << endl;
    //    cout << "Throwing Exception instead." << endl;
    string msg = string( "Can't find any linked in parent exception for " ) + exceptionTypeString + "\n";
    throw JNIException( msg );
}

namespace {

void classLoaderDestructor( void* value ) {

#ifdef SUPPORTS_PTHREADS
    // GILI: To my understanding, pthreads will call the destructor even if the slot contains NULL.
    //       The win32 code will not.
    if ( value == 0 )
        return;
#endif
    JNIEnv* env = helper::attach();
    jobject reference = static_cast<jobject> ( value );
    helper::deleteGlobalRef( env, reference );
}
}

jobject getClassLoader() {

#ifdef SUPPORTS_PTHREADS
    return static_cast<jobject> ( pthread_getspecific( CLASSLOADER_KEY ) );
#elif _WIN32
    return static_cast<jobject> ( TlsGetValue( CLASSLOADER_KEY ) );
#endif
}

void onProcessCreation() throw ( ::jace::JNIException ) {

#ifdef SUPPORTS_PTHREADS
    int rc = pthread_key_create( &CLASSLOADER_KEY, classLoaderDestructor );
    switch ( rc )
    {
    case 0:
        break;
    case ENOMEM:
    case EAGAIN: {
        std::string msg = "Out of memory";
        throw JNIException( msg );
    }
    default: {
        std::string msg = "JNIHelper::setClassLoader()\n"
                "phread_key_create() returned " + std::to_string( rc ) + ".";
        throw JNIException( msg );
    }
    }
#elif _WIN32
    CLASSLOADER_KEY = TlsAlloc();
    if ( CLASSLOADER_KEY == TLS_OUT_OF_INDEXES ) {
        std::string msg = "JNIHelper::setClassLoader()\n"
                "TlsAlloc() returned " + std::to_string( GetLastError() ) + ".";
        throw JNIException( msg );
    }
#endif
}

void onThreadCreation() throw ( ::jace::JNIException ) {
}

void onThreadDestruction() throw ( ::jace::JNIException ) {

#ifdef _WIN32
    if ( hasShutdown() )
        return;
    JavaVM* jvm = getJavaVM();
    ::jace::VmLoader* loader = getVmLoader();
    jobject value = getClassLoader();
    JNIEnv* env;

    // We must ensure that the thread is detached when we leave this function.
    bool mustDetachJVM = value != 0 || jvm->GetEnv( (void**) &env, loader->version() ) != JNI_EDETACHED;
    if ( mustDetachJVM ) {
        if ( value != 0 ) {
            setClassLoader( 0 );
        }
        jace::helper::detach();
    }
#endif
}

void onProcessDestruction() throw ( ::jace::JNIException ) {

#ifdef SUPPORTS_PTHREADS
    int rc = pthread_key_delete( CLASSLOADER_KEY );
    if ( rc != 0 ) {
        std::string msg = "JNIHelper::setClassLoader()\n"
                "thread_key_delete() returned " + std::to_string( rc ) + ".";
        throw JNIException( msg );
    }
#elif _WIN32
    BOOL rc = TlsFree( CLASSLOADER_KEY );
    if ( !rc ) {
        std::string msg = "JNIHelper::setClassLoader()\n"
                "TlsFree() returned " + std::to_string( GetLastError() ) + ".";
        throw JNIException( msg );
    }
#endif
}


void setClassLoader(jobject classLoader) {

    JNIEnv* env = attach();
    jobject oldRef = getClassLoader();

#ifdef SUPPORTS_PTHREADS
    int rc;
#elif _WIN32
    BOOL rc;
#endif

    // Set the new value
    if ( classLoader != 0 ) {
        classLoader = static_cast<jobject> ( newGlobalRef( env, classLoader ) );
    }
#ifdef SUPPORTS_PTHREADS
    rc = pthread_setspecific( CLASSLOADER_KEY, classLoader );
    if ( rc != 0 ) {
        std::string msg = "JNIHelper::setClassLoader()\n"
                "pthread_setspecific() returned " + std::to_string( rc ) + ".";
        throw JNIException( msg );
    }
#elif _WIN32
    rc = TlsSetValue( CLASSLOADER_KEY, classLoader );
    if ( !rc ) {
        std::string msg = "JNIHelper::setClassLoader()\n"
                "TlsSetValue() returned " + std::to_string( GetLastError() ) + ".";
        throw JNIException( msg );
    }
#endif

    // Delete the old value if necessary
    if ( oldRef != 0 ) {
        classLoaderDestructor( oldRef );
    }
}

std::string toString( jobject obj ) {

    JNIEnv* env = attach();

    jclass objectClass = env->FindClass( "java/lang/Object" );

    if ( ! objectClass ) {
        string msg = "Assert failed: Unable to find the class, java.lang.Object.";
        try
        {
            helper::catchAndThrow();
        }
        catch (JNIException& e)
        {
            msg.append("\ncaused by:\n");
            msg.append(e.what());
        }
        throw JNIException( msg );
    }

    jmethodID toString = env->GetMethodID( objectClass, "toString", "()Ljava/lang/String;" );

    if ( ! toString ) {
        string msg = "Assert failed: Unable to find the method, Object.toString().";
        try
        {
            helper::catchAndThrow();
        }
        catch (JNIException& e)
        {
            msg.append("\ncaused by:\n");
            msg.append(e.what());
        }
        throw JNIException( msg );
    }

    jstring javaStr = static_cast<jstring>( env->CallObjectMethod( obj, toString ) );

    const char* strBuf = env->GetStringUTFChars( javaStr, 0 );
    string value = string( strBuf );

    env->ReleaseStringUTFChars( javaStr, strBuf );

    deleteLocalRef( env, javaStr );
    deleteLocalRef( env, objectClass );

    return value;
}

void print( jobject obj ) {
    cout << toString( obj ) << endl;
}

void printClass( jobject obj ) {
    JNIEnv* env = attach();
    jclass objClass = env->GetObjectClass( obj );
    print( objClass );
    deleteLocalRef( env, objClass );
}

QString getJavaProperty(QString name) {
    JNIEnv* env = attach();
    jclass systemClass = env->FindClass("java/lang/System");
    if (systemClass) {
        jmethodID getProperty = env->GetStaticMethodID(systemClass, "getProperty", "(Ljava/lang/String;)Ljava/lang/String;");
        if (getProperty) {
            const char* propUtf = name.toStdString().c_str();
            jstring property = env->NewStringUTF(propUtf);
            jstring result = (jstring) env->CallStaticObjectMethod(systemClass, getProperty, property);
            const char* resUtf = env->GetStringUTFChars(result, NULL);
            QString returnValue (resUtf);

            env->DeleteLocalRef(result);
            env->DeleteLocalRef(property);
            env->DeleteLocalRef(systemClass);

            return returnValue;
        } else {
            throw JNIException("cannot find System.getProperty method");
        }
    } else {
        throw JNIException("cannot find System class");
    }
}

bool hasShutdown() {
    return globalHasShutdown;
}

} // end namespace helper
} // end namespace jace

