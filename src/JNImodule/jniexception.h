#ifndef JNI_ERROR_H
#define JNI_ERROR_H

#include "stdexcept"
#include "jnivalue.h"
#include <QtCore>

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
      JNIValue* exception;
    public:
      java_exception(JNIValue* ex, QString desc = "Java Exception occurred");

      JNIValue* GetExceptionObject();
      virtual const char* what() const throw();
  };
}

#endif // JNI_ERROR_H
