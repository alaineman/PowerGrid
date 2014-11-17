
#include "jace/JClassImpl.h"
#include "jace/JNIHelper.h"
#include "qglobal.h"

using std::string;

namespace jace {

JClassImpl::JClassImpl( const string name, const string nameAsType, jclass cls) :
  mName( name ), 
  mNameAsType( nameAsType ),
  mClass( cls ) {
}

JClassImpl::JClassImpl( const string name, jclass cls ) :
  mName( name ),
  mNameAsType( "L" + name + ";" ),
  mClass( cls ) {
}

JClassImpl::~JClassImpl() throw () {
  if ( mClass ) {
    try {
      if ( helper::hasShutdown() ) {
        return;
      }
      JNIEnv* env = helper::attach();
      helper::deleteGlobalRef( env, mClass );
    }
    catch ( std::exception& e ) {
      Q_UNUSED(e);
    }
  }
}



const string& JClassImpl::getName() const {
  return mName;
}

const string& JClassImpl::getNameAsType() const {
  return mNameAsType;
}

jclass JClassImpl::getClass() const throw ( JNIException ) {
    if ( mClass ) {
        return mClass;
    }

    JNIEnv* env = helper::attach();

	jobject classLoader = jace::helper::getClassLoader();
	jclass localClass;

    if ( classLoader != 0 ) {
        std::string binaryName( getName() );
		
		// Replace '/' by '.' in the name
        std::replace(binaryName.begin(), binaryName.end(), '/', '.');

		jclass classLoaderClass = env->GetObjectClass( classLoader );
		jmethodID loadClass = env->GetMethodID( classLoaderClass, "loadClass", "(Ljava/lang/String;)Ljava/lang/Class;" );
		if ( loadClass == 0 ) {
			string msg = "JClass::getClass - Unable to find the method JNIHelper::getClassLoader().loadClass()";
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
		jstring javaString = env->NewStringUTF( binaryName.c_str() );
		localClass = static_cast<jclass>( env->CallObjectMethod( classLoader, loadClass, javaString ) );
		env->DeleteLocalRef( javaString );
    } else {
        localClass = env->FindClass( getName().c_str() );
    }

    if ( ! localClass ) {
        string msg = "JClass::getClass - Unable to find the class <" + getName() + ">";
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

    mClass = static_cast<jclass>( helper::newGlobalRef( env, localClass ) );
    helper::deleteLocalRef( env, localClass );
    return mClass;
}

std::unique_ptr<JClass> JClassImpl::clone() const {
  return std::unique_ptr<JClass>( new JClassImpl( *this ) );
}

}
