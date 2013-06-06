#include "mainwindow.h"
#include "javaenv.h"

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <sstream>

#include <QApplication>
#include <QLabel>
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
  // We add information from the QMessageLogContext object allowing us to
  // localize the origin of the message, also making it easier to trace
  // bugs and errors.
  out << "At " << context.file << ":" << context.line
      << " (" << context.function << ")" << endl
      << "         |>  " << qPrintable(msg) << endl;
  string logrecord = out.str();
  logStream << logrecord;
  cerr << logrecord;
  if (type == QtFatalMsg) {
    abort();
  }
}

JavaEnv* RunJavaVM() {
    JavaEnv* env = new JavaEnv();
    qDebug() << "Starting Java Virtual Machine";
    try {
        env->Start();
    } catch (runtime_error e) {
        qWarning() << e.what();
    }
    qDebug() << "Java Virtual Machine started";
    return env;
}

int main(int argc, char *argv[]) {
  // Open the log file for writing
  logStream.open("PowerGrid.log", std::ofstream::out | std::ofstream::trunc);
  logStream << "PowerGrid " << qPrintable(POWERGRID_VERSION) << " log file" << endl;
  // Install the message handler for Qt.
  qInstallMessageHandler(PGMessageHandler);

  QFuture<JavaEnv*> futureRunJVM = QtConcurrent::run(RunJavaVM);

  // << Add startup code here if it does not require the Java VM

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
  return a.exec();
}
