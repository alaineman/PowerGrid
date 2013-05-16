#include "ongoinginvocation.h"

namespace jni {

  OngoingInvocation::OngoingInvocation(jobject o, JNIMethod *m) {
    VERIFY_NON_NULL(o);
    VERIFY_NON_NULL(m);
    object = o;
    method = m;
  }

  vector<JNIValue> OngoingInvocation::GetArguments() {
    vector<JNIValue> copy (arguments);
    return copy;
  }

  OngoingInvocation OngoingInvocation::operator<<(JNIValue v) {
    jvalue_type required = GetNextArgumentType();
    VERIFY_THAT(v.GetType() == required);
    arguments.push_back(v);
    return *this;
  }

  OngoingInvocation OngoingInvocation::operator<<(jobject o) {
    return (*this) << JNIValue(o);
  }

  jboolean OngoingInvocation::isValid() {
    return method->ValidateInput(arguments);
  }

  jvalue_type OngoingInvocation::GetNextArgumentType() {
    uint n = arguments.size();
    return method->GetArgumentType(n);
  }

}
