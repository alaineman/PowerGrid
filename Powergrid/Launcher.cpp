#include <iostream>
#include <sstream>
#include <cstdlib>
#include "Launcher.h"
#include "jni.h"
#include "reflect/JavaEnv.h"
#include "wintools/Registry.h"
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
        env.Setup(NULL, NULL);

		jclass objectClass = env.FindClass("java.lang.Object");
		if (objectClass == NULL) {
			throw "Failed to get Object Class from Java Environment";
		}
		jmethodID cons = env.FindConstructor(objectClass, "()V");
		if (env.Env()->ExceptionOccurred()) {
			env.Env()->ExceptionDescribe();
			env.Env()->ExceptionClear();
			throw "Exception occurred in Java Environment for collecting Object constructor";
		} else {
			jobject o = env.Env()->NewObject(objectClass, cons);
			MessageBox(NULL, ("Created Object: " + env.AsString(o)).c_str(), "JavaEnv", MB_OK);
		}
    } catch (int e) {
        MessageBox(NULL, "Exception number " + e, "Exception", MB_OK);
		return EXIT_FAILURE;
    } catch (exception e) {
		string msg = "Exception: ";
		msg += e.what();
        MessageBox(NULL, msg.c_str(), "Exception", MB_OK);
		return EXIT_FAILURE;
	} catch (LPCSTR message) {
		MessageBox(NULL, message, "Error", MB_OK);
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
        CW_USEDEFAULT, CW_USEDEFAULT, 640, 480,

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