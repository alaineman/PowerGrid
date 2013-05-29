#ifndef JNI_ERROR_H
#define JNI_ERROR_H

#include "stdexcept"
#include "jniobject.h"

using namespace std;

namespace jni {

  /**
   * @brief Describes an error in the JNI
   */
  class jni_error : public runtime_error {
    public:
      /**
       * @brief Creates a new jni_error with the specified message
       * @param msg the message describing this jni_error
       */
      jni_error(const string& msg) : runtime_error(msg) {}
  };

  class java_exception : public jni_error {
    private:
      JNIObject* exception;
    public:
      java_exception(JNIObject* ex, QString desc = "Java Exception occurred");

      JNIObject* GetExceptionObject();
      virtual const char* what() const noexcept;
  };
}

#endif // JNI_ERROR_H
