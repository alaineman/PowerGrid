#ifndef JAVAENV_H
#define JAVAENV_H

#include <jni.h>
#include "jnimethod.h"
#include <QMap>
#include <QHash>
#include <QtCore>

namespace jni {
  using namespace std;

  class JNIClass;
  class JNIMethod;

#define JAVAENV jni::JavaEnv::instance()
#define JNIENV JAVAENV->GetEnv()
#define S_JAVAENV(env) JavaEnv* env = JAVAENV
#define S_JNIENV(env) JNIEnv* env = JNIENV

  /**
   * The JavaEnv class is a C++ wrapper around the Java environment (JNIEnv struct).
   * The functions this class provides checks for illegal arguments, like NULL values.
   * The original JNI does not do this, and as such errors could occur when providing the
   * JNI with such arguments.
   */
  class JavaEnv : public QObject {
    Q_OBJECT
  private:
    Q_DISABLE_COPY(JavaEnv)

    static JavaEnv* theEnvironment;

    /// Constructs a new JavaEnv object. Made private to ensure only one instance exists.
    JavaEnv(QObject* parent = NULL);

    JavaVM* jvm;
    jboolean running;
    QMap<QThread*, JNIEnv*> environments;
    QMap<QString, JNIClass*> classes;
  public:

    virtual ~JavaEnv() {}

    /// Returns the global JavaEnv instance.
    static JavaEnv* instance() { return theEnvironment; }
    /// Creates a new global JavaEnv instance if one did not yet exist
    static JavaEnv* createInstance() { return (theEnvironment == NULL ? theEnvironment = new JavaEnv() : theEnvironment); }

    /**
     * Returns the JNI environment object for the calling thread
     *
     * Calling this before calling Start() does not give a valid JNIEnv object pointer.
     * When a thread is not linked to the JVM, the thread is automatically linked to it, and
     * the corresponding JNIEnv object is stored for future reference.
     * @return a pointer to the JNI environment
     */
    JNIEnv* GetEnv();

    /**
     * Returns the JavaVM object.
     * Calling this before calling Start() does not give a valid JavaVM object pointer.
     * @return a pointer to the JavaVM
     */
    JavaVM* GetJVM() { return jvm; }

    /**
     * Returns whether the JNI environment is running.
     * @return true if the JNI environment is running, false otherwise.
     */
    jboolean IsRunning() { return running; }

    /**
     * Starts the JNI environment
     *
     * Calling this function results in the JNI environment being set up. This function then calls the main method
     * of the jagexappletviewer jar file afterwards. This function returns when the main method in the JVM returns.
     * That is to say, when the intial loading screen of Runescape disappears.
     */
    void Start();

    /**
     * Returns the class with the given name
     * @param name the name of the requested class
     * @return a pointer to the JNIClass object with the requested name, or NULL if no class exists with the given name.
     */
    JNIClass* GetClass(QString name);

    /**
     * Returns the JNIClass representing the given jclass object
     * @param c the jclass reference
     * @return the JNIClass object representing the provided jclass
     */
    JNIClass* GetClass(jclass c);
    /**
     * Returns the class of the given object
     * @param obj the object to return the class for
     * @return the JNIClass representing the class of the object
     */
    JNIClass* GetClassForObject(jobject obj);

    /**
     * Returns the method ID with the given requirements.
     * @param c the class in which the method is declared
     * @param name the name of the method
     * @param signature the signature of the method
     *
     * Use the GetStaticMethodID function for static methods, because they are handled in a different way in the JNI.
     *
     * @return the jmethodID object representing the method with the given requirements, or NULL is the method was not found.
     */
    jmethodID GetMethodID(JNIClass* c, QString name, QString signature);

    /**
     * Returns the static method ID with the given requirements.
     * @param c the class in which the static method is declared
     * @param name the name of the static method
     * @param signature the signature of the static method
     *
     * Use the GetMethodID function for non-static methods, because they are handled in a different way in the JNI.
     *
     * @return the jmethodID object representing the static method with the given requirements, or NULL is the method was not found.
     */
    jmethodID GetStaticMethodID(JNIClass* c, const char* name, const char* signature);

    /**
     * Returns the Java Virtual machine version
     *
     * This function call performs the following Java method invocation:
     * <pre>
     *     System.getProperty("java.version");
     * </pre>
     * and returns the result as a QString
     *
     * @return the version of the JVM as a QString
     */
    QString GetEnvironmentVersion();

    /// Safe version of the object method invocation function from JNI.
    jobject  CallObjectMethod  (jobject obj, jmethodID method, uint n_args, ...);
    /// Safe version of the int method invocation function from JNI.
    jint     CallIntMethod     (jobject obj, jmethodID method, uint n_args, ...);
    /// Safe version of the double method invocation function from JNI.
    jdouble  CallDoubleMethod  (jobject obj, jmethodID method, uint n_args, ...);
    /// Safe version of the boolean method invocation function from JNI.
    jboolean CallBooleanMethod (jobject obj, jmethodID method, uint n_args, ...);
    /// Safe version of the float method invocation function from JNI.
    jfloat   CallFloatMethod   (jobject obj, jmethodID method, uint n_args, ...);
    /// Safe version of the byte method invocation function from JNI.
    jbyte    CallByteMethod    (jobject obj, jmethodID method, uint n_args, ...);
    /// Safe version of the char method invocation function from JNI.
    jchar    CallCharMethod    (jobject obj, jmethodID method, uint n_args, ...);
    /// Safe version of the long method invocation function from JNI.
    jlong    CallLongMethod    (jobject obj, jmethodID method, uint n_args, ...);
    /// Safe version of the short method invocation function from JNI.
    jshort   CallShortMethod   (jobject obj, jmethodID method, uint n_args, ...);

    /// Safe version of the static object method invocation function from JNI.
    jobject  CallStaticObjectMethod  (jclass c, jmethodID method, uint n_args, ...);
    /// Safe version of the static int method invocation function from JNI.
    jint     CallStaticIntMethod     (jclass c, jmethodID method, uint n_args, ...);
    /// Safe version of the static double method invocation function from JNI.
    jdouble  CallStaticDoubleMethod  (jclass c, jmethodID method, uint n_args, ...);
    /// Safe version of the static boolean method invocation function from JNI.
    jboolean CallStaticBooleanMethod (jclass c, jmethodID method, uint n_args, ...);
    /// Safe version of the static float method invocation function from JNI.
    jfloat   CallStaticFloatMethod   (jclass c, jmethodID method, uint n_args, ...);
    /// Safe version of the static byte method invocation function from JNI.
    jbyte    CallStaticByteMethod    (jclass c, jmethodID method, uint n_args, ...);
    /// Safe version of the static char method invocation function from JNI.
    jchar    CallStaticCharMethod    (jclass c, jmethodID method, uint n_args, ...);
    /// Safe version of the static long method invocation function from JNI.
    jlong    CallStaticLongMethod    (jclass c, jmethodID method, uint n_args, ...);
    /// Safe version of the static short method invocation function from JNI.
    jshort   CallStaticShortMethod   (jclass c, jmethodID method, uint n_args, ...);

    /**
     * Calls the provided (non-static) method
     * @param ret_type the expected return type
     * @param c the object to perform the method call on
     * @param method the id of the method to invoke
     * @param args the arguments to the method call
     * @return a JNIValue with the result of the performed method call.
     */
    JNIValue Call(jvalue_type ret_type, jobject c, jmethodID method, va_list args);
    /**
     * Calls the provided static method
     * @param ret_type the expected return type
     * @param c the class to perform the static method call on
     * @param method the id of the static method to invoke
     * @param args the arguments to the static method call
     * @return a JNIValue with the result of the performed static method call.
     */
    JNIValue CallStatic(jvalue_type ret_type, jclass c, jmethodID method, va_list args);

    /**
     * Retrieves information on the method specified by the given parameters
     *
     * @param c the name of the class the method is declared in
     * @param name the name of the method
     * @param signature the signature of the method
     *
     * This method is completely type-safe regarding input and output.
     *
     * @return a pointer to the JNIMethod object containing the method information of the
     *         requested method, or NULL if the method does not exist in the JVM.
     */
    JNIMethod* GetMethod(QString className, QString name, QString signature, bool stat = false);

    JNIMethod* GetMethod(JNIClass* cls, QString name, QString signature, bool stat = false);

    /**
     * @brief Parses the return value from a Java method signature
     * @param signature the signture to parse
     * @return the jvalue_type of the return value of the given method signature
     */
    jvalue_type ParseReturnValueFromSignature(QString signature);

    /**
     * @brief Parses the argument types
     * @param signature
     * @return
     */
    vector<jvalue_type> ParseArgumentTypesFromSignature(QString signature);

    /**
     * Checks each registered thread - JNIEnv mapping for validity
     *
     * For each thread that has already finished, the corresponding JNIEnv object is removed.
     * It is advised to use the unlinkThread() slot instead, because it prevents illegal references from remaining in the thread to JNIEnv mapping.
     *
     */
    void syncJavaVMThreads();

    /**
     * Checks if the given QThread is attached to the Java VM
     * @param thread the QThread to check
     * @return true if and only if the thread is still running and has a binding to a JNIEnv object, false otherwise.
     */
    bool isAttached(QThread* thread);

    /// Checks for a thrown Java Exception and throws a java_exception object when there is one
    void exceptionCheck();

    /// deletes the local reference to the given java object.
    void deleteLocalReference(jobject obj);

  signals:
    /// Signal that the JNI environment has started, emitted just before the Start function returns.
    void started();

  public slots:
    /**
     * Unlinks the current thread from the Java VM
     *
     * After this method returns, the JNIEnv object associated with this thread has been removed.
     * Note that calling any other JavaEnv function that requires a JNIEnv object, the JNIEnv object
     * will be re-created.
     *
     * This function can be linked to QThread's finished() signal to cleanly detach the thread and the remove the JNIEnv.
     * Alternatively, the syncJavaVMThreads() function can be called to check each registered thread and JNIEnv for validity.
     */
    void unlinkThread();
  };
}

#endif // JAVAENV_H
