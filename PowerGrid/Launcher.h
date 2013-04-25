/* 
 * File:   Launcher.h
 * Author: Chronio
 *
 * Created on April 21, 2013, 6:37 PM
 */

#ifndef LAUNCHER_H
#define	LAUNCHER_H

#include <windows.h>

/* Processes the provided message. This function is called repetatively when there is a message.
 */
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

namespace powergrid {
    
    /* Collects the configuration for the Runescape client.
     * It returns the direct full link to the Loader jar file as a string
     */
    char* getRSGamepackLink();

}
#endif	/* LAUNCHER_H */

