#include <iostream>
#include <cstdlib>
#include "Launcher.h"
#include "jni.h"
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Exception.hpp>

using namespace std;
using curlpp::options::Url;
using curlpp::options::WriteStream;

namespace powergrid {
    
    cURLpp::Easy easyHandle;

    int main(int argc, char** argv) {
        easyHandle = new cURLpp::Easy();
        
        // Set up the Java Virtual Machine
        JavaVM* jvm;
        JNIEnv* env;
        JavaVMInitArgs args;
        args.version = JNI_VERSION_1_6;
        args.nOptions = 2;
        args.options = new JavaVMOption[2];

        args.options[0].optionString = "-Djava.class.path=" + getRSLink();
        args.options[1].optionString = "-Xmx256m";

        jint result = JNI_CreateJavaVM(&jvm, reinterpret_cast<void **>(&env), &args);
        if (result != JNI_OK) {
            cout << "Failed to create JVM" << endl;
            return EXIT_FAILURE;
        }
        jclass mainClass = env->FindClass("Rs2Applet");
        if (mainClass == NULL) {
            cout << "Could not find the required class on the classPath" << endl;
            return EXIT_FAILURE;
        }
        
        env->CallStaticVoidMethod(mainClass, "main", NULL);
        
        while (true /* running */) {
            /* Read and update fields */
        }
        
        jvm->DestroyJavaVM();
        
        return EXIT_SUCCESS;
    }

    char* getRSLink() {
        char* link = NULL;
        stringstream stream;
        try {
            easyHandle.setOpt(Url("http://www.runescape.com/k=3/l=en/jav_config.ws"));
            easyHandle.setOpt(WriteStream(&stream))
            easyHandle.perform();
        } catch (std::exception e) {
            cout << "Failed to set URL, exception occurred: " << e.what() << endl;
        }
        //TODO dump and filter stream and store in link.
        return link;
    }

}