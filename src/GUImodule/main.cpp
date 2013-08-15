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
#include "javaenv.h"

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

using namespace std;
using namespace jni;

ofstream logStream;

// Custom message handler for Qt messages. It prints the message to the
// standard error stream prepended with the appropriate level identifier.
void PGMessageHandler(QtMsgType type, const QMessageLogContext& context, const QString& msg) {
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

JavaEnv* RunJavaVM() {
    JavaEnv* env = JavaEnv::createInstance();
    qDebug() << "Starting Java Virtual Machine";
    try {
        env->Start();
    } catch (runtime_error e) {
        qWarning() << e.what();
    }
    qDebug() << "Java Virtual Machine started";
    return env;
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

int main(int argc, char *argv[]) {
  // Open the log file for writing
  logStream.open("PowerGrid.log", std::ofstream::out | std::ofstream::trunc);
  logStream << "PowerGrid " << qPrintable(POWERGRID_VERSION) << " log file" << endl;
  // Install the message handler for Qt.
  qInstallMessageHandler(PGMessageHandler);

  QThread* current = QThread::currentThread();
  current->setObjectName("PG-main");

  QFuture<JavaEnv*> futureRunJVM = QtConcurrent::run(RunJavaVM);

  QApplication a(argc, argv);

  // Show our main window
  MainWindow w;
  w.setGeometry(40, 60, w.width(), w.height());

  // Now we wait until the Java VM is started and collect the resulting JavaEnv instance
  JavaEnv* environment = futureRunJVM.result();

  if (environment == NULL) {
    qWarning() << "Could not detect running Java VM";
    w.updateVersionInfo(QStringLiteral("No Java VM detected"));
  } else {
    // << Add startup code here if it does require the Java VM
    QString version = environment->GetEnvironmentVersion();
    qDebug() << "Java Version: " << version;
    w.updateVersionInfo(version);
  }

  w.show();

  // enter the Qt message loop
  int result = a.exec();

  qDebug() << "PowerGrid window closed";

  WaitForShutdown();

  return result;
}
