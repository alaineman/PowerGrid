#include "stdafx.h"
#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include "jni/javaenv.h"
#include <fstream>
#include <QtConcurrent/QtConcurrent>

using namespace std;
using namespace jni;

std::ofstream logStream;

// Custom message handler for Qt messages. It prints the message to the
// standard error stream prepended with the appropriate level identifier.
void PGMessageHandler(QtMsgType type, const QMessageLogContext& context, const QString& msg) {
  stringstream out;
  switch (type) {
    case QtDebugMsg:
      out << "Debug    | ";
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
  if (type != QtDebugMsg) {
    // Since debug messages usually only occur as general debug info, we are not interested in its location.
    out << "At " << context.file << ":" << context.line
        << " (" << context.function << ")" << endl
        << "         |>  ";
  }
  out << qPrintable(msg) << endl;
  string logrecord = out.str();
  cerr << logrecord;
  logStream << logrecord;
  if (type == QtFatalMsg) {
    abort();
  }
}

void RunJavaVM(JavaEnv* env) {
    env = new JavaEnv();
    qDebug() << "Starting Java Virtual Machine";
    try {
        env->Start();
    } catch (runtime_error e) {
        qWarning() << e.what();
    }
    qDebug() << "Java Virtual Machine started";
}

void TerminateJavaVM(JavaEnv* env) {
    if (env != NULL) {
        if (env->IsRunning()) {
            JNIEnv* e = env->GetEnv();
            JavaVM* j = NULL;
            jint res = JNI_OK;
            if (e != NULL) {
                res = e->GetJavaVM(&j);
            }
            if (res < 0 || j == NULL) {
                qWarning() << "Could not get Java VM, error code" << res;
                delete env;
            } else {
                delete env;
                if (res < 0) {
                    qWarning() << "Could not attach thread to terminate JavaVM, error code" << res;
                } else {
                    j->DestroyJavaVM();
                }

            }
        }
    }
}

int main(int argc, char *argv[]) {
  // Open the log file for writing
  logStream.open("PowerGrid.log", std::ofstream::out | std::ofstream::trunc);
  logStream << "PowerGrid " << POWERGRID_VERSION << " log file" << endl;
  // Install the message handler for Qt.
  qInstallMessageHandler(PGMessageHandler);

  JavaEnv* environment = NULL;
  QFuture<void> futureRunJVM = QtConcurrent::run(RunJavaVM, environment);

  // << Add startup code here if it does not require the Java VM

  QApplication a(argc, argv);

  // Show our main window
  MainWindow w;
  w.setGeometry(40, 60, w.width(), w.height());

  // Now we wait until the Java VM is started
  futureRunJVM.waitForFinished();

  if (environment == NULL) {
    qWarning() << "Could not detect running Java VM";
  } else {
    // << Add startup code here if it does require the Java VM
  }
  // We set the version info and show the GUI after the Java VM was started.
  w.updateVersionInfo(environment);
  w.show();

  // enter the Qt message loop
  const int qtReturnValue = a.exec();

  // << Add shutdown code here that does require the Java VM

  // Once we leave the Qt message loop, we should assert the Java Virtual Machine is terminated.
//  QFuture<void> futureStopJVM = QtConcurrent::run(TerminateJavaVM, environment);

//  // << Add shutdown code here that does not require the Java VM

//  futureStopJVM.waitForFinished();
  // Exit the application;
  return qtReturnValue;
}
