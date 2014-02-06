#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "versionInfo.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui_controlPanel)
{
    ui->setupUi(this);
    ui->pgVersion->setText(PG_VERSION_STR);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setJVMVersion(QString version) {
    ui->jvmVersion->setText(version);
}
