#include "monitorwindow.h"
#include "ui_monitorwindow.h"

#include "jace/RSClassMapper.h"
#include "jace/RSClass.h"
#include "jace/jnihelper.h"

#include <QDebug>

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

    qDebug() << "Evaluating" << expression;

    //TODO convert parts using RSClassMapper
    QString realExpression = expression;
    QByteArray expressionBytes = realExpression.toLocal8Bit();

    // Copy the string to the JVM, get the classes/methods, and invoke it...
    JNIEnv* env = jace::helper::attach();
    jstring jExpression = env->NewStringUTF(expressionBytes.constData());
    if(!jExpression) {
        ui->result->setText("Could not create Java String");
    }
    jclass reflectionClass = env->FindClass("net.pgrid.loader.bridge.Reflection");
    if (!reflectionClass) {
        ui->result->setText("Cannot find Reflection class");
    }
    jmethodID mId = env->GetStaticMethodID(reflectionClass, "evaluateToString",
                                       "(Ljava/lang/String;)Ljava/lang/String;");
    if (!mId) {
        ui->result->setText("Could not find 'evaluateToString' method");
    }
    jstring result = (jstring) env->CallStaticObjectMethod(reflectionClass,
                                                           mId, jExpression);
    if (!result) {
        ui->result->setText("Failed to get result");
    } else {
        const char* localResult = env->GetStringUTFChars(result, NULL);
        ui->result->setText(localResult);
    }
}
