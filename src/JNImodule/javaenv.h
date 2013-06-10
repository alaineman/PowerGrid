#ifndef JAVAENV_H
#define JAVAENV_H

#include <jni.h>
#include "jnimethod.h"
#include <QMap>
#include <QHash>
#include "jniclass.h"

namespace jni {
  using namespace std;
  /**
   * The JavaEnv class is a C++ wrapper around the Java environment (JNIEnv struct).
   * The functions this class provides checks for illegal arguments, like NULL values.
   * The original JNI does not do this, and as such errors could occur when providing the
   * JNI with such arguments.
   */
  class JavaEnv : public QObject {
  private:
    JavaVM* jvm;
    jboolean running;
    QMap<QThread*, JNIEnv*> environments;
    QMap<QString, JNIClass*> classes;
  public:
    /// Constructs a new JavaEnv object.
    JavaEnv();

    /**
     * @brief Returns the JNI environment object for the calling thread
     *
     * Calling this before calling @c Start() does not give a valid JNIEnv object pointer.
     * When a thread is not linked to the JVM, the thread is automatically linked to it, and
     * the corresponding JNIEnv object is stored for future reference.
     * @return a pointer to the JNI environment
     */
    JNIEnv* GetEnv();

    /**
     * @brief Returns the JavaVM object
     * Calling this before calling @c Start() does not give a valid JavaVM object pointer.
     * @return a pointer to the JavaVM
     */
    JavaVM* GetJVM() { return jvm; }

    /**
     * @brief Returns whether the JNI environment is running.
     * @return true if the JNI environment is running, false otherwise.
     */
    jboolean IsRunning() { return running; }

    /**
     * @brief Starts the JNI environment
     *
     * Calling this function results in the JNI environment being set up. This function then calls the main method
     * of the jagexappletviewer jar file afterwards. This function returns when the main method in the JVM returns.
     * That is to say, when the intial loading screen of Runescape disappears.
     */
    void Start();

    /**
     * @brief Returns the class with the given name
     * @param name the name of the requested class
     * @return a pointer to the JNIClass object with the requested name, or NULL if no class exists with the given name.
     */
    JNIClass* GetClass(const char* name);

    /**
     * @brief Returns the method ID with the given requirements.
     * @param c the class in which the method is declared
     * @param name the name of the method
     * @param signature the signature of the method
     *
     * Use the GetStaticMethodID function for static methods, because they are handled in a different way in the JNI.
     *
     * @return the jmethodID object representing the method with the given requirements, or NULL is the method was not found.
     */
    jmethodID GetMethodID(JNIClass* c, const char* name, const char* signature);

    /**
     * @brief Returns the static method ID with the given requirements.
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
     * @brief Returns the Java Virtual machine version
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
     * @brief Calls the provided (non-static) method
     * @param ret_type the expected return type
     * @param c the object to perform the method call on
     * @param method the id of the method to invoke
     * @param args the arguments to the method call
     * @return a JNIValue with the result of the performed method call.
     */
    JNIValue Call(jvalue_type ret_type, jobject c, jmethodID method, va_list args);
    /**
     * @brief Calls the provided static method
     * @param ret_type the expected return type
     * @param c the class to perform the static method call on
     * @param method the id of the static method to invoke
     * @param args the arguments to the static method call
     * @return a JNIValue with the result of the performed static method call.
     */
    JNIValue CallStatic(jvalue_type ret_type, jclass c, jmethodID method, va_list args);

    /**
     * @brief Retrieves information on the method specified by the given parameters
     *
     * @param c the class the method is declared in
     * @param name the name of the method
     * @param signature the signature of the method
     *
     * This method is completely type-safe regarding input and output.
     *
     * @return a pointer to the JNIMethod object containing the method information of the
     *         requested method, or NULL if the method does not exist in the JVM.
     */
    JNIMethod* GetMethod(jclass c, const char* name, const char* signature);

    /**
     * @brief Creates a String in the Java environment's  String pool
     * @param str the string to create
     * @return a jstring object that references the created Java String.
     */
    jstring CreateString(const char* str);

    /**
     * @brief Collects the given jstring from the Java environment and returns it as a QString
     * @param str the jstring to collect
     * @return the QString with the contents of the provided jstring
     */
    QString GetString(jstring str);

    /**
     * @brief Collects the given JNIValue from the Java environment and returns it as a QString
     *
     * If the provided JNIValue is not of the JOBJECT type, this function throws a runtime_error.
     * @param str the JNIValue to collect
     * @return the QString with the contents of the provided jstring
     */
    QString GetString(JNIValue str);

    /**
     * @brief Parses the return value from a Java method signature
     * @param signature the signture to parse
     * @return the jvalue_type of the return value of the given method signature
     */
    jvalue_type ParseReturnValueFromSignature(const char* signature);

    /**
     * @brief Parses the argument types
     * @param signature
     * @return
     */
    vector<jvalue_type> ParseArgumentTypesFromSignature(const char* signature);

    /**
     * @brief Checks each registered thread - JNIEnv mapping for validity
     * For each thread that has already finished, the corresponding JNIEnv object is removed.
     *
     * It is advised to use the @c unlinkThread() slot instead, because it prevents illegal references from remaining in the thread to JNIEnv mapping.
     *
     */
    void syncJavaVMThreads();

    /**
     * @brief Checks if the given QThread is attached to the Java VM
     * @param thread the QThread to check
     * @return true if and only if the thread is still running and has a binding to a JNIEnv object, false otherwise.
     */
    bool isAttached(QThread* thread);

  signals:
    /// Signal that the JNI environment has started
    void started();
    /// Signal that the JNI environment has stopped.
    void stopped();

  public slots:
    /**
     * @brief Unlinks the current thread from the Java VM
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
