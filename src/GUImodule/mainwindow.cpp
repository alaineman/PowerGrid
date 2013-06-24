#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
            QMainWindow(parent),
            ui(new Ui::MainWindow) {

  ui->setupUi(this);

  ui->JNIsafetyCheck->setDescription("Enabled JNI safety checks. Prevents weird error messages "
                                     "and sudden crashes, but also slows down interaction between PowerGrid and Runescape a lot.\n\n"
                                     "If you are unsure, leave this option unchecked.");
  connect(ui->JNIsafetyCheck, SIGNAL(descriptionSet(QString)), ui->SettingDescription, SLOT(setText(QString)));
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
