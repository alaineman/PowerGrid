#include "monitorwindow.h"
#include "ui_monitorwindow.h"

#include "jace/RSClassMapper.h"
#include "jace/RSClass.h"
#include "jace/jnihelper.h"

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
    QString cls = className.getText();
    QString fld = fieldName.getText();
    qDebug("Evaluating: " + qPrintable(cls) + "." + qPrintable(fld) + "...");

    RSClassMapper* classMap = RSClassMapper::DefaultInstance();
    RSClass* rsClass = classMap->getRSClass(cls);
    QString realFieldName = rsClass->getFieldName(fld);
    JNIEnv* env = jace::helper::attach();
}
