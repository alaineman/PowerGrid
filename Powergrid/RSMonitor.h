#pragma once
/*
 * File:   RSMonitor.h
 * Author: Chronio
 *
 * Monitors the Runescape client and extracts wanted data. The monitor itself 
 * runs on a separate thread, continuously polling the client for updates.
 */

namespace powergrid {

	class RSMonitor {
	private:
		bool stopNow;

		/* Loops Executes a single step of the monitor. */
		void execute();
	public:
		RSMonitor();
		~RSMonitor();

		virtual void start();
		virtual void stop();

	};
}


