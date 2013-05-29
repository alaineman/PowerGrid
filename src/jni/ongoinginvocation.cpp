#include "ongoinginvocation.h"
#include "javaenv.h"

namespace jni {

  OngoingInvocation::OngoingInvocation(const OngoingInvocation &orig) {
    object = orig.object;
    method = orig.method;
    arguments = vector<JNIValue>(orig.arguments);
  }

  OngoingInvocation::OngoingInvocation(JavaEnv* e, jobject o, JNIMethod *m) {
    // the method must be static if and only if o == NULL
    if (ISNULL(e) || ISNULL(m) || (o == NULL) != m->IsStatic()) {
      throw invalid_argument("invalid argument conbination");
    }
    env = e;
    object = o;
    method = m;
  }

  vector<JNIValue> OngoingInvocation::GetArguments() {
    return vector<JNIValue> (arguments);
  }

  JNIMethod* OngoingInvocation::GetMethod() {
    return method;
  }

  jobject OngoingInvocation::GetObject() {
    return object;
  }

  jboolean OngoingInvocation::isValid() {
    return method->ValidateInput(arguments);
  }

  jvalue_type OngoingInvocation::GetNextArgumentType() {
    uint n = arguments.size();
    return method->GetArgumentType(n);
  }

  jvalue_type OngoingInvocation::GetReturnType() {
    return method->GetReturnType();
  }

  void OngoingInvocation::ClearArguments() {
    arguments.clear();
  }

  jvalue* OngoingInvocation::CreateArgumentArray() {
    uint n = arguments.size();
    jvalue* args = new jvalue[n];
    qDebug() << "Creating argument array with" << n << "element(s)";
    for (uint i = 0; i < n; i++) {
      JNIValue val = arguments.at(i);
      args[i] = val.Get();
    }
    return args;
  }

  OngoingInvocation OngoingInvocation::operator<<(JNIValue v) {
   // jvalue_type required = GetNextArgumentType();
   // VERIFY_THAT(v.GetType() == required); // This is not yet collected and verifyable
    arguments.push_back(v);
    return *this;
  }

  OngoingInvocation OngoingInvocation::operator<<(jobject o) {
    return (*this) << JNIValue(o);
  }

  JNIValue OngoingInvocation::operator <<(Invoke) {
    return Execute();
  }

  JNIValue OngoingInvocation::Execute() {
    //VERIFY_THAT(isValid()); // This is not yet verifyable

    throw runtime_error("OngoingInvocation is not yet supported as a JNI invocation procedure");

    jvalue* args = CreateArgumentArray();
    JNIEnv* jnienv = env->GetEnv();
    jvalue result;
    jvalue_type retType = method->GetReturnType();
    if (method->IsStatic()) {
      jclass c = method->GetClass();
      switch (retType) {
        // Switch over the different types and call the appropriate static method from the JNIEnv.
        case JOBJECT:  result.l = jnienv->CallStaticObjectMethodA  (c, method->GetMethodID(), args); break;
        case JBOOLEAN: result.z = jnienv->CallStaticBooleanMethodA (c, method->GetMethodID(), args); break;
        case JBYTE:    result.b = jnienv->CallStaticByteMethodA    (c, method->GetMethodID(), args); break;
        case JCHAR:    result.c = jnienv->CallStaticCharMethodA    (c, method->GetMethodID(), args); break;
        case JSHORT:   result.s = jnienv->CallStaticShortMethodA   (c, method->GetMethodID(), args); break;
        case JINT:     result.i = jnienv->CallStaticIntMethodA     (c, method->GetMethodID(), args); break;
        case JLONG:    result.j = jnienv->CallStaticLongMethodA    (c, method->GetMethodID(), args); break;
        case JDOUBLE:  result.d = jnienv->CallStaticDoubleMethodA  (c, method->GetMethodID(), args); break;
        case JFLOAT:   result.f = jnienv->CallStaticFloatMethodA   (c, method->GetMethodID(), args); break;
        case JVOID:               jnienv->CallStaticVoidMethodA    (c, method->GetMethodID(), args); break;
        default: throw logic_error("Invalid or unknown return type for static JNIMethod");
      }
    } else {
      switch (retType) {
        // Switch over the different types and call the appropriate non-static method from the JNIEnv.
        case JOBJECT:  result.l = jnienv->CallObjectMethodA  (object, method->GetMethodID(), args); break;
        case JBOOLEAN: result.z = jnienv->CallBooleanMethodA (object, method->GetMethodID(), args); break;
        case JBYTE:    result.b = jnienv->CallByteMethodA    (object, method->GetMethodID(), args); break;
        case JCHAR:    result.c = jnienv->CallCharMethodA    (object, method->GetMethodID(), args); break;
        case JSHORT:   result.s = jnienv->CallShortMethodA   (object, method->GetMethodID(), args); break;
        case JINT:     result.i = jnienv->CallIntMethodA     (object, method->GetMethodID(), args); break;
        case JLONG:    result.j = jnienv->CallLongMethodA    (object, method->GetMethodID(), args); break;
        case JDOUBLE:  result.d = jnienv->CallDoubleMethodA  (object, method->GetMethodID(), args); break;
        case JFLOAT:   result.f = jnienv->CallFloatMethodA   (object, method->GetMethodID(), args); break;
        case JVOID:               jnienv->CallVoidMethodA    (object, method->GetMethodID(), args); break;
        default: throw logic_error("Invalid or unknown non-static return type for JNIMethod");
      }
    }
    if (retType == JVOID) return JNIValue();
    else return JNIValue(retType, result);
  }

}
