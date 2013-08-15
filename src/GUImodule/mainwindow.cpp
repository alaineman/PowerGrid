/*
 * Copyright 2012-2013 Patrick Kramer, Vincent Wassenaar
 *
 * This file is part of PowerGrid.
 *
 * PowerGrid is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PowerGrid is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with PowerGrid.  If not, see <http://www.gnu.org/licenses/>.
 */
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
