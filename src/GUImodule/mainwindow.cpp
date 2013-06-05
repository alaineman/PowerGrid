#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
            QMainWindow(parent),
            ui(new Ui::MainWindow) {

  ui->setupUi(this);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::updateVersionInfo(QString env_version) {
  ui->jvmversion->setText(env_version);
  ui->PGversion->setText(POWERGRID_VERSION);
}

void MainWindow::on_travelHere_clicked() {
  qDebug() << "TravelHere button clicked";
}
