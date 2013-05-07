#include <iostream>
#include <sstream>
#include <cstdlib>
#include <process.h>
#include "PowerGrid.h"
#include "jni.h"
#include "JNIAccessor/JavaEnv.h"
#include <windows.h>
#include "pgexcept.h"

#ifndef UNICODE
#define UNICODE
#endif 

using namespace std;

using powergrid::JNIAccessor::JavaEnv;

namespace powergrid {
JavaEnv env = NULL;

//INT APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
//					LPTSTR lpCmdLine, INT nCmdShow) {
//	// Register the application class.
//	LPCSTR CLASS_NAME = TEXT("PowerGrid");
//
//	WNDCLASS wc = { };
//	wc.lpfnWndProc   = WindowProc;
//	wc.hInstance     = hInstance;
//	wc.lpszClassName = CLASS_NAME;
//
//	RegisterClass(&wc);
//
//	// Set up a Java Environment
//	env = JavaEnv(hInstance);
//	//_beginthread(JVMThread, 0, NULL);
//	JVMThread((void*)(&hInstance));
//
//	// Create a window
//	HWND hwnd = CreateWindowEx(
//        0,                              // Optional window styles.
//        CLASS_NAME,                     // Window class
//        TEXT("PowerGrid Config panel"), // Window text
//        WS_OVERLAPPEDWINDOW,            // Window style
//
//        // Size and position
//        CW_USEDEFAULT, CW_USEDEFAULT, 320, 480,
//
//        NULL,       // Parent window    
//        NULL,       // Menu
//        hInstance,  // Instance handle
//        NULL        // Additional application data
//		);
//
//	if (hwnd == NULL) {
//		MessageBox(NULL, "Creating a window failed", "Critical error", MB_OK);
//		return EXIT_FAILURE;
//	}
//
//	ShowWindow(hwnd, nCmdShow);
//	
//	// Start the message loop
//	MSG msg = { };
//    while (GetMessage(&msg, NULL, 0, 0))
//    {
//        TranslateMessage(&msg);
//        DispatchMessage(&msg);
//    }
//
//    return EXIT_SUCCESS;
//}

IMPLEMENT_APP(PowerGrid);

bool PowerGrid::OnInit() {

}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg) {
    case WM_DESTROY:
		PostQuitMessage(WM_QUIT);
		env.Terminate();
		break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));

            EndPaint(hwnd, &ps);
        }
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}

void JVMThread(void* pParams) {
	try {
		env = JavaEnv(*(HINSTANCE*)(pParams));
		env.Setup();
	} catch (exception e) {
		string msg = "Failed to start Runescape:\n";
		msg += e.what();
		msg += "\nEnsure that the official Jagex launcher is installed on your system.";
		MessageBox(NULL, msg.c_str(), "Critical Failure", MB_OK);
	} CATCH_UNKNOWN
}

}