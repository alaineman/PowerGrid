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
    QMainWindow(parent), ui(new Ui::MonitorWindow), timer(new QTimer(this)),
    parser(new API::ExpressionParser(RSClassMapper::DefaultInstance())) {

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
    QString result;
    try {
        result = parser->evaluateToString(expression);
    } catch (jace::JNIException& ex) {
        result = QString("ERR: ").append(ex.what());
    }
    ui->result->setText(result);
}

void MonitorWindow::updateMousePos() {
    try {
        MouseListener listener = java_cast<MouseListener>(Client::getMouse());
        if (listener.isNull()) {
            throw jace::JNIException("MouseListener is null");
        }
        QString position = QString("(")
                .append(QString().setNum(listener.getX())).append(",")
                .append(QString().setNum(listener.getY())).append(")");
        ui->mousePos->setText(position);
    } catch(jace::MappingUnavailableException& ex) {
        qCDebug(guiLogger) << "updateMousePos: Cannot find required field: " << ex.what();
        ui->mousePos->setText("Cannot find mouse coordinates (missing hook)");
        timer->stop(); // Prevent this same Exception from occurring again.
    } catch(jace::JNIException& ex) {
        qCDebug(guiLogger) << "updateMousePos: Error in JNI layer: " << ex.what();
        ui->mousePos->setText("Error retrieving mouse coordinates");
        timer->stop();
    }
}

void MonitorWindow::on_MonitorWindow_destroyed() {
    timer->deleteLater();
}
