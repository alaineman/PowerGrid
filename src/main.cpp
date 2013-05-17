#include "stdafx.h"
#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include "JNIConnection"

using namespace std;
using namespace jni;

// Custom message handler for Qt messages. It prints the message to the
// standard error stream prepended with the appropriate level identifier.
void PGMessageHandler(QtMsgType type, const QMessageLogContext&, const QString& msg) {
     switch (type) {
     case QtDebugMsg:
         cerr << "Debug    | " << qPrintable(msg) << endl;
         break;
     case QtWarningMsg:
         cerr << "Warning  | " << qPrintable(msg) << endl;
         break;
     case QtCriticalMsg:
         cerr << "Critical | " << qPrintable(msg) << endl;
         break;
     case QtFatalMsg:
         cerr << "Fatal    | " << qPrintable(msg) << endl;
         abort();
     }
 }

int main(int argc, char *argv[]) {
  qInstallMessageHandler(PGMessageHandler);
  QApplication a(argc, argv);

  // Attempt to start the Java environment
  qDebug() << "Starting Java Environment";
  JavaEnv environment;
  try {
    environment.Start();
  } catch (runtime_error e) {
    // Report a fatal message stating what the problem was.
    // The message level is fatal because the application
    // cannot continue without a Java environment.
    qFatal(e.what());
  }

  // Show our main window
  MainWindow w;
  w.setGeometry(40, 60, w.width(), w.height());
  w.updateVersionInfo(&environment);

  w.show();

  qDebug() << "PowerGrid started";

  // enter the Qt message loop
  const int qtReturnValue = a.exec();

  if (environment.IsRunning()) {
    // Destroy the Java Virtual Machine.
    JNIEnv* env = environment.GetEnv();
    JavaVM* jvm;
    env->GetJavaVM(&jvm);
    jvm->DestroyJavaVM();
  }

  // Exit the application;
  return qtReturnValue;
}
