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

/*!
 * \class MainWindow
 * \brief PowerGrid Control panel
 *
 * This class provides the PowerGrid control panel. It contains a variety
 * of slots to update the different properties this control panel displays.
 *
 * For example, there is a \c{setJVMVersion(QString)} slot that sets the version
 * of the running Java VM, as well as a slot to update the number of frames/second
 * the RS client is running (\c{updateFPS()}).
 *
 */

/*!
 * \brief Creates a new MainWindow instance
 * \param parent the parent, if any
 *
 * This constructor creates a new \c MainWindow object that can be displayed
 * on screen.
 */
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

/*!
 * \brief sets the JVM version displayed by this \c MainWindow
 * \param version the version to display
 */
void MainWindow::setJVMVersion(QString version) {
    ui->jvmVersion->setText(version);
}
/*!
 * \brief updates the number of frames per second (FPS)
 *
 * This slot automatically collects the required information from the
 * RS client, the FPS can be kept up-to-date if this is called
 * periodically.
 */
void MainWindow::updateFPS() {
    static bool thrown = false;
    try {
        api::bridge::Client c = api::bridge::Client::getClient();
        if (!c.isNull()) {
            jace::helper::printClass(c.getJavaJniObject());
            JInt fpsValue = c.getFPS();
            ui->fps->setText(QString::number(fpsValue.getInt()));
        } else {
            ui->fps->setText(QStringLiteral("ERR: Client is null"));
        }
    } catch (jace::JNIException& e) {
        if (!thrown) {
            thrown = true;
            qDebug() << e.what();
        }
        ui->fps->setText(QStringLiteral("ERR: ") + e.what());
    }
}
