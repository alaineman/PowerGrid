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

void MainWindow::updateVersionInfo(jni::JavaEnv* env) {
  if (env == NULL) {
    ui->jvmversion->setText("<Failed to start JavaVM>");
  } else {
    QString result = env->GetEnvironmentVersion();
    if (result.isEmpty()) {
      ui->jvmversion->setText("<Java Virtual Machine is not running>");
    } else {
      ui->jvmversion->setText(result);
    }
  }
  ui->PGversion->setText(POWERGRID_VERSION);
}

void MainWindow::on_travelHere_clicked() {
  qDebug() << "TravelHere button clicked";
}
