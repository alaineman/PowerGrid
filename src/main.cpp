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
void PGMessageHandler(QtMsgType type, const QMessageLogContext&, const QString& msg) {
  cstring prefix = "         | ";
  switch (type) {
    case QtDebugMsg:
      prefix = "Debug    | ";
      break;
    case QtWarningMsg:
      prefix = "Warning  | ";
      break;
    case QtCriticalMsg:
      prefix = "Critical | ";
      break;
    case QtFatalMsg:
      prefix = "Fatal    | ";
      break;
  }
  cstring message = qPrintable(msg);
  cerr << prefix << message << endl;
  logStream << prefix << message << endl;
  if (type == QtFatalMsg) {
    abort();
  }
}

void RunJavaVM(JavaEnv* env) {
    env = new JavaEnv();
    qDebug << "Starting Java Virtual Machine";
    try {
        env->Start();
    } catch (runtime_error e) {
        qWarning << e.what();
    }
    qDebug << "Java Virtual Machine started";
}

int main(int argc, char *argv[]) {
  // Open the log file for writing
  logStream.open("PowerGrid.log", std::ofstream::out | std::ofstream::trunc);
  logStream << "PowerGrid " << POWERGRID_VERSION << " log file" << endl;
  // Install the message handler for Qt.
  qInstallMessageHandler(PGMessageHandler);

  JavaEnv* environment = NULL;
  QFuture<JavaEnv*> future = QtConcurrent::run(RunJavaVM, environment);

  QApplication a(argc, argv);

  // Show our main window
  MainWindow w;
  w.setGeometry(40, 60, w.width(), w.height());
  w.updateVersionInfo(&environment);

  w.show();

  // enter the Qt message loop
  const int qtReturnValue = a.exec();

  if (environment != NULL) {
      if (environment->IsRunning()) {
        // Destroy the Java Virtual Machine.
        JNIEnv* env = environment->GetEnv();
        JavaVM* jvm;
        env->GetJavaVM(&jvm);
        jvm->DestroyJavaVM();
      }
      delete environment;
  }

  // Exit the application;
  return qtReturnValue;
}
