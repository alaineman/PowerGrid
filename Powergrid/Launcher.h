/* 
 * File:   Launcher.h
 * Author: Chronio
 *
 * Entry point for the application. This header defines functions required solely for starting 
 * the application.
 */

#ifndef LAUNCHER_H
#define	LAUNCHER_H

#include <windows.h>

/* Processes the provided message. This function is called repetatively when there is a message.
 */
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

#endif	/* LAUNCHER_H */