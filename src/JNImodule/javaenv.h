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
   * JNI with such arguments. NULL value checking is enabled only when the PG_NULL_CHECK macro is defined.
   */
  class JavaEnv : public QObject {
  private:
    JNIEnv* env;
    jboolean running;
    QMap<QString, JNIClass*> classes;

  public:
    /**
     * @brief Constructs a new JavaEnv object.
     */
    JavaEnv();

    /**
     * @brief Returns the JNI environment object
     *
     * Calling this before calling Setup does not give a valid JNIEnv object.
     * @return the JNI environment
     */
    JNIEnv* GetEnv() { return env; }

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
     *      System.getProperty("java.version");
     * and returns the result as a QString
     * @return the version of the JVM as a QString
     */
    QString GetEnvironmentVersion();

    // Safe versions of all (16) method invocation functions. They check NULL values and such
    // as long as the PG_NULL_CHECK macro is defined.
    jobject  CallObjectMethod  (jobject obj, jmethodID method, uint n_args, ...);
    jint     CallIntMethod     (jobject obj, jmethodID method, uint n_args, ...);
    jdouble  CallDoubleMethod  (jobject obj, jmethodID method, uint n_args, ...);
    jboolean CallBooleanMethod (jobject obj, jmethodID method, uint n_args, ...);
    jfloat   CallFloatMethod   (jobject obj, jmethodID method, uint n_args, ...);
    jbyte    CallByteMethod    (jobject obj, jmethodID method, uint n_args, ...);
    jchar    CallCharMethod    (jobject obj, jmethodID method, uint n_args, ...);
    jlong    CallLongMethod    (jobject obj, jmethodID method, uint n_args, ...);
    jshort   CallShortMethod   (jobject obj, jmethodID method, uint n_args, ...);

    jobject  CallStaticObjectMethod  (jclass c, jmethodID method, uint n_args, ...);
    jint     CallStaticIntMethod     (jclass c, jmethodID method, uint n_args, ...);
    jdouble  CallStaticDoubleMethod  (jclass c, jmethodID method, uint n_args, ...);
    jboolean CallStaticBooleanMethod (jclass c, jmethodID method, uint n_args, ...);
    jfloat   CallStaticFloatMethod   (jclass c, jmethodID method, uint n_args, ...);
    jbyte    CallStaticByteMethod    (jclass c, jmethodID method, uint n_args, ...);
    jchar    CallStaticCharMethod    (jclass c, jmethodID method, uint n_args, ...);
    jlong    CallStaticLongMethod    (jclass c, jmethodID method, uint n_args, ...);
    jshort   CallStaticShortMethod   (jclass c, jmethodID method, uint n_args, ...);

    // generalized versions of the method invocation functions. They delegate to the
    // specific version based on the provided jvalue_type.
    JNIValue Call(jvalue_type ret_type, jobject c, jmethodID method, va_list args);
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

    jvalue_type ParseReturnValueFromSignature(const char* signature);
    vector<jvalue_type> ParseArgumentTypesFromSignature(const char* signature);
  };
}

#endif // JAVAENV_H
