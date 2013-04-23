#include <iostream>
#include <sstream>
#include <cstdlib>
#include "Launcher.h"
#include "jni.h"
#include "reflect/JavaEnv.h"
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Exception.hpp>

using namespace std;

using curlpp::Easy;
using curlpp::options::Url;
using curlpp::options::WriteStream;
using powergrid::reflect::JavaEnv;

namespace powergrid {

    JavaEnv* env;
    
    int main(int argc, char** argv) {
        try {
            const char* link = getRSGamepackLink();
            env->Setup(".", "Rs2Applet");
        
            while (false /* running */) {
                //TODO run the bot
                
            }
            
            delete env;
        } catch (int e) {
            cout << "An error occurred: error code " << e << endl;
        } catch (exception e) {
            cout << "An exception occurred: " << e.what() << endl;
        } catch (...) {
            cout << "An undefined error has occurred" << endl;
        }
        return EXIT_SUCCESS;
    }

    char* getRSGamepackLink() {
        Easy* easyHandle = new Easy();
        char* link = NULL;
        stringstream stream;
        try {
            easyHandle->setOpt(Url("http://www.runescape.com/k=3/l=en/jav_config.ws"));
            easyHandle->setOpt(WriteStream(&stream));
            easyHandle->perform();
        } catch (exception e) {
            cout << "Failed to set URL, exception occurred: " << e.what() << endl;
        }
        cout << "Stream contents:" << endl << stream;
        
        delete easyHandle;
        return link;
    }

}