#include "monitorwindow.h"
#include "ui_monitorwindow.h"

#include "jace/RSClassMapper.h"
#include "jace/RSClass.h"
#include "jace/jnihelper.h"

#include <QDebug>

Q_DECLARE_LOGGING_CATEGORY(guiLogger)

using jace::RSClassMapper;
using jace::RSClass;

MonitorWindow::MonitorWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MonitorWindow) {
    ui->setupUi(this);
}

MonitorWindow::~MonitorWindow() {
    delete ui;
}

void MonitorWindow::on_evaluateButton_clicked() {
    QString expression = ui->expression->text();

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
