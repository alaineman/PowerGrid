#include <iostream>
#include <cstdlib>
#include "Launcher.h"
#include "jni.h"
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Exception.hpp>

namespace powergrid {
    
    // I'm too lazy to type <namespace>::<identifier> everytime.
    using std::string;
    using std::cout;
    using std::endl;
    using curlpp::options::Url;
    
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

        return EXIT_SUCCESS;
    }

    char* getRSLink() {
        char* link = NULL;
        try {
            easyHandle.setOpt(new Url("http://www.runescape.com/k=3/l=en/jav_config.ws"));
        } catch (std::exception e) {
            cout << "Failed to set URL, exception occurred: " << e.what() << endl;
        }
        return link;
    }

}