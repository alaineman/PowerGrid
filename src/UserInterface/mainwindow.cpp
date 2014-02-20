/*
 * Copyright 2014 Patrick Kramer, Vincent Wassenaar
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
#include "versionInfo.h"

#include "api/bridge/client.h"

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
        api::bridge::Client c = api::bridge::Client::getClient();
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
