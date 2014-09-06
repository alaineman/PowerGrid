#include "monitorwindow.h"
#include "ui_monitorwindow.h"

#include "jace/RSClassMapper.h"
#include "jace/RSClass.h"
#include "jace/JNIHelper.h"
#include "jace/JNIException.h"

#include "rs/client.h"
#include "rs/mouselistener.h"
#include "jace/javacast.h"
using namespace RS;
using jace::java_cast;
using namespace std;

#include <QDebug>

Q_DECLARE_LOGGING_CATEGORY(guiLogger)

using jace::RSClassMapper;
using jace::RSClass;

MonitorWindow::MonitorWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MonitorWindow), timer(new QTimer) {
    ui->setupUi(this);

    timer->setInterval(200); // 5 times per second
    connect(timer, SIGNAL(timeout()),
            this,  SLOT(updateMousePos()));
    timer->start();
}

MonitorWindow::~MonitorWindow() {
    delete ui;
}

void MonitorWindow::on_evaluateButton_clicked() {
    QString expression = ui->expression->text();

    // TODO: Convert the Expression here using the Mapper data
    QString realExpression = expression;
    QByteArray expressionBytes = realExpression.toLocal8Bit();

    // Copy the string to the JVM, get the classes/methods, and invoke it...
    JNIEnv* env = jace::helper::attach();
    jstring jExpression = env->NewStringUTF(expressionBytes.constData());
    if(!jExpression) {
        ui->result->setText("Could not create Java String");
        return;
    }
    jclass reflectionClass = env->FindClass("net/pgrid/loader/bridge/Reflection");
    if (!reflectionClass) {
        ui->result->setText("Cannot find Reflection class");
        return;
    }
    jmethodID mId = env->GetStaticMethodID(reflectionClass, "evaluateToString",
                                       "(Ljava/lang/String;)Ljava/lang/String;");
    if (!mId) {
        ui->result->setText("Could not find 'evaluateToString' method");
        return;
    }
    jstring result = (jstring) env->CallStaticObjectMethod(reflectionClass,
                                                           mId, jExpression);
    if (env->ExceptionCheck()) {
        qCDebug(guiLogger) << "Exception occurred in JVM";
        env->ExceptionDescribe();
        env->ExceptionClear();
        ui->result->setText("Exception occurred in JVM");
    } else if (!result) {
        ui->result->setText("Failed to get result");
    } else {
        const char* localResult = env->GetStringUTFChars(result, NULL);
        if (localResult) {
            ui->result->setText(localResult);
        } else {
            ui->result->setText("Could not convert Java result to local string");
        }
    }
}

void MonitorWindow::updateMousePos() {
    try {
        MouseListener listener = java_cast<MouseListener>(Client::getMouse());
        if (listener.isNull()) {
            throw jace::JNIException("MouseListener is null");
        }
        QString position = QString("(")
                .append(to_string(listener.getX().getInt()).c_str()).append(",")
                .append(to_string(listener.getY().getInt()).c_str()).append(")");
        ui->mousePos->setText(position);
    } catch(jace::JNIException& ex) {
        qCDebug(guiLogger) << "Exception in updateMousePos:" << ex.what();
        ui->mousePos->setText(QString("Cannot find data: ") % ex.what());
    }
}

void MonitorWindow::on_MonitorWindow_destroyed() {
    timer->deleteLater();
}
