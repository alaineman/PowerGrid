#pragma once
/* 
 * File:   Launcher.h
 * Author: Chronio
 *
 * Entry point for the application. This header defines functions required solely for starting 
 * the application.
 */

#include <windows.h>
#include <wx/wx.h>

namespace powergrid {
	class PowerGrid : public wxApp {
		virtual bool OnInit();
	};
}


/* Starts the JVM.
 */
void JVMThread(void* pParams);