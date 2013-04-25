#include <iostream>
#include <sstream>
#include <cstdlib>
#include "Launcher.h"
#include "jni.h"
#include "reflect/JavaEnv.h"
#include <windows.h>

#ifndef UNICODE
#define UNICODE
#endif 

using namespace std;

//using curlpp::Easy;
//using curlpp::options::Url;
//using curlpp::options::WriteStream;
using powergrid::reflect::JavaEnv;

JavaEnv env = NULL;

INT APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
					LPTSTR lpCmdLine, INT nCmdShow) {
	// Register the application class.
	LPCSTR CLASS_NAME = TEXT("PowerGrid");

	WNDCLASS wc = { };
	wc.lpfnWndProc   = WindowProc;
	wc.hInstance     = hInstance;
	wc.lpszClassName = CLASS_NAME;

	RegisterClass(&wc);

	// Set up a Java Environment
	env = JavaEnv(hInstance);
    try {
        //const char* link = powergrid::getRSGamepackLink();
        env.Setup(".", NULL);
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

	// Create a window
	HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        TEXT("PowerGrid"),              // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,       // Parent window    
        NULL,       // Menu
        hInstance,  // Instance handle
        NULL        // Additional application data
        );

	if (hwnd == NULL) {
		MessageBox(NULL, "Creating a window failed", "Ciritcal error", MB_OK);
		return 0;
	}

	ShowWindow(hwnd, nCmdShow);

	// Start the message loop
	MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return EXIT_SUCCESS;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));

            EndPaint(hwnd, &ps);
        }
        return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
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