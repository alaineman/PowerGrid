#pragma once
/* 
 * File:   Launcher.h
 * Author: Chronio
 *
 * Entry point for the application. This header defines functions required solely for starting 
 * the application.
 */

#include <windows.h>

/* Processes the provided message. This function is called repetatively when there is a message.
 */
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

/* Starts the JVM.
 */
void JVMThread(void* pParams);