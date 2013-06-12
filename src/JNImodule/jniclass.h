#ifndef JNICLASS_H
#define JNICLASS_H

#include <jni.h>
#include "jnivalue.h"
#include "jniobject.h"

namespace jni {

  /**
   * type definition of the access modifiers of a Java Class.
   * These values are taken straight from the Java Language Specification (Java SE 7 Edition), table 4.1
   */
  enum AccModifier {
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
  };

  // These are defines that give the proper semantic names for access flags of methods.
  // This is required because these flags overlap with the access flags of fields.
#define ACC_SYNCHRONIZED jni::ACC_SUPER
#define ACC_BRIDGE jni::ACC_VOLATILE
#define ACC_VARARGS jni::ACC_TRANSIENT

  /**
   * @brief Representation of a Class in the Java environment
   *
   */
  class JNIClass : public JNIObject {
    private:
      // reference values
      jclass clazz;

      // cached values
      JNIClass* superClass;       // This JNIClass' superclass
      QString name;              // The fully qualified name (with '/' as separator) for use in signatures of functions.
      QString semantic_name;     // The semantic name given to this JNIClass object for easy identification.
      jint modifiers;             // The modifiers of the class (a combination of public, protected, private, final, static, abstract and interface, encoded in an integer)
      map<JNIClass*, JNIValue*> anns;    // Map of annotations this JNIClass contains
      map<QString, JNIMethod*> methods; // Map of methods that this class provides.
      map<QString, jfieldID> fields;    // Map of field that this class provides.

      friend class JavaEnv;

      bool LoadMethod(JNIMethod* method);
      bool LoadField(QString name, jfieldID f_id);
    public:
      /**
       * @brief Creates a JNIClass based on the given jclass reference
       * @param c the jclass this JNIClass object represents
       * @param e the Java environment
       */
      JNIClass(jclass c) : JNIObject(c) {}

      ~JNIClass() {}

      virtual jclass GetJObject() { return clazz; }

      /**
       * @brief Returns the simple name (without package) of the class
       * @return the simple name of the class
       */
      QString GetSimpleName();
      /**
       * @brief Returns the name of the class.
       * The signature name contains the full package (separated by '/').
       * @return the signature name of this class
       */
      QString J_GetName();

      /**
       * @brief Returns whether the given JNIObject represents an instance of this JNIClass
       * @param o the JNIObject to check
       *
       * @return true if the provided JNIObject is an @c JOBJECT of this JNIClass, false otherwise
       */
      jboolean IsInstance(JNIObject o);
      /**
       * @brief Returns whether the given jobject is an instance of this JNIClass
       * @param o the jobject to check
       * @return true if the jobject is an instance of this JNIClass, false otherwise
       */
      jboolean IsInstance(jobject o);

      /**
       * @brief Returns the superclass of this JNIClass
       * @return the superclass of this JNIClass
       */
      JNIClass* GetSuperClass();
      /**
       * @brief Looks up the method with the specified name and signature
       * @param name the name of the method
       * @param signature the signature of the method
       * @return the JNIMethod reference to the requested method, or @c NULL if no such method exists
       */
      JNIMethod* GetMethod(const char* name, const char* signature);
      /**
       * @brief Looks up the constructor with the specified signature
       * @param signature the signature of the constructor
       * @return the JNIMethod reference to the requested constructor, or @c NULL if no such constructor exists
       */
      JNIMethod* GetConstructor(QString signature);

      /**
       * @brief Returns the signature of the field with the given name
       * @param fieldname the fieldname to look up
       * @return the signature of the requested fieldname if it exists, or an empty QString otherwise
       */
      QString GetFieldSignature(QString fieldname);
      /**
       * @brief Returns the type of the field as a jvalue_type id
       * @param fieldname the name of the field to look up
       * @return the jvalue_type representing the field's type
       */
      jvalue_type GetFieldType(QString fieldname);
      /**
       * @brief Returns the contents of the field with the given name
       * @param fieldName the name of the field
       * @return the JNIValue with this field's contents.
       */
      JNIValue GetFieldContents(QString fieldName);

      /**
       * @brief Retrieves the Access modifiers for this class
       * @return the access modifiers for this class
       */
      jint GetModifiers();
      /**
       * @brief Returns whether this JNIClass has the given access modifier
       * @param m the AccModifier to check for
       * @return @c (GetModifiers() & m != 0)
       */
      jboolean HasModifier(AccModifier m) { return (GetModifiers() & m) != 0; }

      /**
       * @brief Returns the annotation object belonging to the given class.
       * @param annotationClass the class of the annotation to retrieve
       * @return the JNIObject representing the requested annotation, or a JNIObject representing @c NULL if the annotation was not found
       */
      JNIObject GetAnnotation(JNIClass* annotationClass);
      /**
       * @brief Returns whether this class contains the given annotation
       * @param annotationClass the class of the annotation to check
       *
       * @return @c !GetAnnotation(annotationClass).IsNull()
       */
      jboolean HasAnnotation(JNIClass* annotationClass) { return !GetAnnotation(annotationClass).IsNull(); }

      JNIValue InvokeStaticMethod(QString name, QString signature, ...);
      JNIValue InvokeStaticMethod(JNIMethod* method, ...);

      void emptyCache();


  };
}

#endif // JNICLASS_H
