#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "versionInfo.h"

#include "api/native/client.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui_controlPanel),
    timer(new QTimer) {
    ui->setupUi(this);
    ui->pgVersion->setText(PG_VERSION_STR);

    timer->setInterval(1000); // Update every second
    connect(timer, SIGNAL(timeout()), this, SLOT(updateFPS()));
    timer->start();
}

MainWindow::~MainWindow() {
    timer->stop();
    delete ui;
    delete timer;
}

void MainWindow::setJVMVersion(QString version) {
    ui->jvmVersion->setText(version);
}

void MainWindow::updateFPS() {
    try {
        api::native::Client c = api::native::Client::getClient();
        JInt fpsValue = c.getFPS();
        ui->fps->setText(QString::number(fpsValue.getInt()));
    } catch (jace::JNIException& e) {
        qDebug() << "updateFPS failed:" << e.what();
    }
}
