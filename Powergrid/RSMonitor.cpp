#include "RSMonitor.h"
#include <Windows.h>
#include "pgexcept.h"

using powergrid::RSMonitor;

RSMonitor::RSMonitor() {
	stopNow = true;
}


RSMonitor::~RSMonitor() {

}

void RSMonitor::start() {
	stopNow = false;
}

void RSMonitor::stop() {
	stopNow = false;
}

void RSMonitor::execute() {
	try {
		//TODO poll data from the RS client and push it into the caches.
	} CATCH_ALL 
}