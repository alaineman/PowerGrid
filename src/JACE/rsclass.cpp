#include "rsclass.h"
#include "jace/JNIHelper.h"

/**
 * Creates a new RSClass with the given name and type name.
 *
 * @param name - The name of this class, suitable for use in
 *               a call to JNIEnv::FindClass.
 * @param simpleName the simple (semantic) name of the RSClass
 */
RSClass::RSClass(const std::string name, const std::string simpleName) :
  name (name),
  nameAsType ("L" + name + ";"),
  javaClass (NULL),
  simpleName (simpleName) {
}

RSClass::~RSClass() throw () {
  if (javaClass) {
    try {
      if (jace::helper::hasShutdown()) {
        return;
      }

      JNIEnv* env = jace::helper::attach();
      jace::helper::deleteGlobalRef(env, javaClass);
    } catch (std::exception& e) {
      (void) e; // See JClassImpl::~JClassImpl()
    }
  }
}

const std::string& RSClass::getName() const {
  return name;
}

const std::string& RSClass::getNameAsType() const {
  return nameAsType;
}

const std::string& RSClass::getSimpleName() const {
  return simpleName;
}

jclass RSClass::getClass() const throw( jace::JNIException ) {
  if (javaClass) {
    return javaClass;
  }

  JNIEnv* env = jace::helper::attach();

  jobject classLoader = jace::helper::getClassLoader();
  jclass localClass;

  if (classLoader != NULL) {
    std::string binaryName (getName());
    jclass clsClassLoader = env->GetObjectClass(classLoader);
    jmethodID loadClass = env->GetMethodID(clsClassLoader, "loadClass", "(Ljava/lang/String;)Ljava/lang/Class;");
    if (loadClass == NULL) {
      std::string msg = "JClass::getClass - Unable to find the method JNIHelper::getClassLoader().loadClass()";
      try {
        jace::helper::catchAndThrow();
      } catch (jace::JNIException& e) {
        msg.append("\ncaused by:\n");
        msg.append(e.what());
      }
      throw JNIException(msg);
    }
    jstring javaString = env->NewStringUTF(binaryName.c_str());
    localClass = static_cast<jclass>(env->CallObjectMethod(classLoader, loadClass, javaString));
    env->DeleteLocalRef(javaString);
  } else {
    localClass = env->FindClass(getName().c_str());
  }

  if (!localClass) {
    std::string msg = "JClass::getClass - Unable to find the class <" + getName() + ">";
    try {
      jace::helper::catchAndThrow();
    } catch (jace::JNIException& e) {
      msg.append("\ncaused by:\n");
      msg.append(e.what());
    }
    throw JNIException(msg);
  }

  javaClass = static_cast<jclass>(jace::helper::newGlobalRef(env, localClass));
  jace::helper::deleteLocalRef(env, localClass);

  return javaClass;
}

std::auto_ptr<RSClass> RSClass::clone() const {
  return std::auto_ptr<RSClass>(new RSClass( *this ));
}
