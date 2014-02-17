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
    delete timer;
    delete ui;
}

void MainWindow::setJVMVersion(QString version) {
    ui->jvmVersion->setText(version);
}

void MainWindow::updateFPS() {
    try {
        api::native::Client c = api::native::Client::getClient();
        if (!c.isNull()) {
            JInt fpsValue = c.getFPS();
            ui->fps->setText(QString::number(fpsValue.getInt()));
        } else {
            ui->fps->setText(QStringLiteral("ERR: Client is null"));
        }
    } catch (jace::JNIException& e) {
        ui->fps->setText(QStringLiteral("ERR: Client class missing"));
    }
}
