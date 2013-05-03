#pragma once
/*
 * File:   pgexcept.h
 * Author: Chronio
 *
 * This header file contains definitions for the various exceptions and exception handling.
 */
#include <Windows.h>
#include <stdexcept>
#include <string>

using std::string;
using std::exception;
using std::runtime_error;

namespace powergrid {
	/* This class represents an exception thrown by a powergrid::reflect::JavaEnv object upon failure.
	 */
	class JavaEnvException : public runtime_error {
	public:
		JavaEnvException(LPCSTR message) : runtime_error(message) {};
	};

	/* Reports an error to the user in the form of a message box. */ 
	class Reporter {
	public:
		Reporter() throw() {}
		~Reporter() throw() {}
		void report_errorcode(int code) throw() {
			MessageBox(NULL, "An error occurred with error code " + code, "An error occurred", MB_OK);
		}
		void report_errorstring(LPCSTR message) throw() {
			MessageBox(NULL, string("An error occurred:\n").append(message).c_str(), "An error occurred", MB_OK);
		}
		void report_exception(exception e) throw() {
			LPCSTR msg = e.what();
			MessageBox(NULL, string("An exception occurred:\n").append(msg).c_str(), "An exception occurred", MB_OK);
		}
		void report_unknown() throw() {
			MessageBox(NULL, "An unknown error has occurred", "An error occurred", MB_OK);
		}
		// Reports that an unrecoverable error has occurred. Use when PowerGrid will crash or hang afterwards
		void report_critical(LPCSTR message) throw() {
			MessageBox(NULL, string(message).append("\nPowerGrid will now likely crash or hang.").c_str(), "A critical error occurred", MB_OK);
		}
	};
}

// Macros to quickly report an error to the user
#define REPORT_ERRORCODE(code) powergrid::Reporter().report_errorcode(code);
#define REPORT_ERRORSTRING(message) powergrid::Reporter().report_errorstring(message);
#define REPORT_EXCEPTION(ex) powergrid::Reporter().report_exception(e);
#define REPORT_UNKNOWN() powergrid::Reporter().report_unknown();
#define REPORT_CRITICAL(message) powergrid::Reporter().report_critical(message);

#define CATCH_INT catch(int i) { REPORT_ERRORCODE(i); }
#define CATCH_STRING catch(LPCSTR m) { REPORT_ERRORSTRING(m); }
#define CATCH_EXCEPTION catch(std::exception e) { REPORT_EXCEPTION(e); }
#define CATCH_UNKNOWN catch(...) { REPORT_UNKNOWN(); }

#define CATCH_ALL CATCH_INT CATCH_STRING CATCH_EXCEPTION CATCH_UNKNOWN
