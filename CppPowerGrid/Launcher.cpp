#include <iostream>
#include <sstream>
#include <cstdlib>
#include "Launcher.h"
#include "jni.h"
#include "reflect/JavaEnv.h"
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>

using namespace std;

//using curlpp::Easy;
//using curlpp::options::Url;
//using curlpp::options::WriteStream;
using powergrid::reflect::JavaEnv;


    
    int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
					LPTSTR lpCmdLine, int nCmdShow) {
		JavaEnv env = JavaEnv(hInstance);
        try {
            //const char* link = powergrid::getRSGamepackLink();
            env.Setup(".", "");
			MessageBox(NULL, "Environment created", "Hoera", MB_OK);
			//jclass objectClass = env->FindClass("java.lang.Object");
			//jobject o = env->Env()->AllocObject(objectClass);
			//cout << "Created Object: " << env->AsString(o) << endl;
			
            //delete &env; 
        } catch (int e) {
            MessageBox(NULL, "Exception number " + e, "Exception", MB_OK);
			return EXIT_FAILURE;
        } catch (exception e) {
			string msg = "Exception: ";
			msg += e.what();
            MessageBox(NULL, msg.c_str(), "Exception", MB_OK);
			return EXIT_FAILURE;
        } catch (...) {
            MessageBox(NULL, "Unknown Exception", "Exception", MB_OK);
			return EXIT_FAILURE;
        }
        return EXIT_SUCCESS;
    }

//namespace powergrid {
//    char* getRSGamepackLink() {
//        //Easy* easyHandle = new Easy();
//        char* link = NULL;
//        stringstream stream;
//        try {
//            //easyHandle->setOpt(Url("http://www.runescape.com/k=3/l=en/jav_config.ws"));
//            //easyHandle->setOpt(WriteStream(&stream));
//            //easyHandle->perform();
//        } catch (exception e) {
//            cout << "Failed to set URL, exception occurred: " << e.what() << endl;
//        }
//        cout << "Stream contents:" << endl << stream;
//        
//        //delete easyHandle;
//        return link;
//    }
//
//}