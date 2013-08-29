/*
 * Copyright 2012-2013 Patrick Kramer, Vincent Wassenaar
 *
 * This file is part of PowerGrid.
 *
 * PowerGrid is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PowerGrid is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with PowerGrid.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "mainwindow.h"

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <sstream>

#ifdef Q_OS_WIN
# include <windows.h>
#endif

#include <QApplication>
#include <QLabel>
#include <QtConcurrent/QtConcurrent>

#include "javaenvironment.h"

#include "jace/proxy/java/lang/String.h"
#include "jace/proxy/java/lang/System.h"

using namespace jace::proxy::java::lang;

using namespace std;

ofstream logStream;

// Custom message handler for Qt messages. It prints the message to the
// standard error stream prepended with the appropriate level identifier.
void PGMessageHandler(QtMsgType type, const QMessageLogContext&, const QString& msg) {
  stringstream out;
  switch (type) {
    case QtDebugMsg:
      out << "Info     | ";
      break;
    case QtWarningMsg:
      out << "Warning  | ";
      break;
    case QtCriticalMsg:
      out << "Critical | ";
      break;
    case QtFatalMsg:
      out << "Fatal    | ";
      break;
    default:
      out << "         | ";
  }
  // We add information from the QMessageLogContext object allowing us to
  // localize the origin of the message, also making it easier to trace
  // bugs and errors. We don't do this for release builds
#ifdef DEBUG
  out << "At " << context.file << ":" << context.line
      << " (" << context.function << ")" << endl
      << "         |>  ";
#endif
  out << qPrintable(msg) << endl;
  string logrecord = out.str();
  logStream << logrecord;
  cerr << logrecord;
  if (type == QtFatalMsg) {
    abort();
  }
}

bool openWindows = false;

#ifdef Q_OS_WIN
// On windows we can use the EnumWindows function to check the open windows
BOOL CALLBACK EnumWindowsProc(HWND hWnd, long) {
  if (IsWindowVisible(hWnd)) {
      openWindows = true;
  }
  return TRUE;
}
void WaitForShutdown() {
  do {
    openWindows = false;
    EnumWindows(EnumWindowsProc, 0);
    QThread::currentThread()->sleep(5);
  } while (openWindows);
  qDebug() << "PowerGrid terminating";
}
#else
void WaitForShutdown() {}
#endif


int main(int, char*[]) {
  JavaEnvironment env;
  try {
    env.start();
  } catch (std::runtime_error& err) {
    qDebug() << "A runtime error occurred:" << err.what();
    return EXIT_FAILURE;
  }

  String key ("java.version");
  String version = System::getProperty( key );
  std::string versionStr = version.toStdString();
  qDebug() << "Java Version: " << versionStr.c_str();
  return EXIT_SUCCESS;
}
