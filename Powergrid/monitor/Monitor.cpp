#include "Monitor.h"
#include <Windows.h>
#include "pgexcept.h"

using powergrid::monitor::RSMonitor;

RSMonitor::RSMonitor() {
	stopNow = true;
}

RSMonitor::~RSMonitor() {
	stop();
}

void RSMonitor::start() {
	stopNow = false;
}

void RSMonitor::stop() {
	stopNow = true;
}

void RSMonitor::execute() {
	try {
		//TODO poll data from the RS client and push it into the caches.
	} CATCH_ALL 
}