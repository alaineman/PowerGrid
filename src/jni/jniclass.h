#ifndef JNICLASS_H
#define JNICLASS_H

#include "stdafx.h"
#include "javaenv.h"

namespace jni {

  // type definition of the access modifiers of a Java Class.
  // These values are taken straight from the Java Language Specification (Java SE 7 Edition), table 4.1
  typedef enum {
    ACC_PUBLIC     = 0x0001,
    ACC_PRIVATE    = 0x0002,
    ACC_PROTECTED  = 0x0004,
    ACC_STATIC     = 0x0008,
    ACC_FINAL      = 0x0010,
    ACC_SUPER      = 0x0020,
    ACC_VOLATILE   = 0x0040,
    ACC_TRANSIENT  = 0x0080,
    ACC_NATIVE     = 0x0100,
    ACC_INTERFACE  = 0x0200,
    ACC_ABSTRACT   = 0x0400,
    ACC_STRICT     = 0x0800,
    ACC_SYNTHETIC  = 0x1000,
    ACC_ANNOTATION = 0x2000,
    ACC_ENUM       = 0x4000
  } AccModifier;

  // These are defines that give the proper names for access flags of methods.
  // This is required because these flags overlap with the access flags of fields.
#define ACC_SYNCHRONIZED jni::ACC_SUPER
#define ACC_BRIDGE jni::ACC_VOLATILE
#define ACC_VARARGS jni::ACC_TRANSIENT

  class JNIClass {
    private:
      // reference values
      JavaEnv* env;         // Reference to the Java Environment for required JNI method invocations
      jclass clazz;         // Reference to the jclass value itself

      // cached values
      JNIClass* superClass;       // This JNIClass' superclass
      QString* name;              // The fully qualified name (with '/' as separator) for use in signatures of functions.
      jint modifiers;             // The modifiers of the class (a combination of public, protected, private, final, static, abstract and interface, encoded in an integer)
      map<JNIClass*, JNIValue> anns;    // Map of annotations this JNIClass contains
      map<QString, JNIMethod*> methods; // Map of methods that this class provides.
    public:
      JNIClass(jclass c, JavaEnv* e);

      QString GetSimpleName();
      QString GetSigName();

      jboolean IsInstance(JNIValue v);
      jboolean IsInstance(jobject o);

      JNIClass* GetSuperClass();
      JNIMethod* GetMethod(QString name, QString signature);
      JNIMethod* GetConstructor(QString signature);
      QString GetFieldSignature();
      jvalue_type GetFieldType();
      JNIValue GetFieldContents(QString fieldName);

      jint GetModifiers();
      jboolean HasModifier(AccModifier m);

      JNIValue GetAnnotation(JNIClass* annotationClass);
      jboolean HasAnnotation(JNIClass* annotationClass);

      void emptyCache();

  };
}

#endif // JNICLASS_H
