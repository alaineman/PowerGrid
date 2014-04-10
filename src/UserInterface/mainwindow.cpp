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
#include "api/bridge/keyboard.h"

#include "java/awt/event/keyevent.h"
using java::awt::event::KeyEvent;

#include "net/pgrid/loader/pgloader.h"

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
    ui(new Ui_mainWindow),
    timer(new QTimer) {
    ui->setupUi(this);
    ui->pgVersion->setText(PG_VERSION_STR);

    connect(ui->sendText, SIGNAL(clicked()), this, SLOT(sendText()));

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

void MainWindow::sendText() {
    try {
        api::bridge::Keyboard keyboard = api::bridge::Client::getKeyboard();
        java::awt::Component source = net::pgrid::loader::PGLoader::getApplet();
        QString text = ui->textToSend->text();
        for(int i=0;i<text.length();i++) {
            QDateTime time (QDateTime::currentDateTime());
            qint64 msec = time.toMSecsSinceEpoch();
            keyboard.dispatch(KeyEvent::createEvent(source,
                              KeyEvent::Typed, msec, 0, -1,
                              JChar(text.at(i).toLatin1())));
            qDebug() << "Char" << text.at(i) << "sent.";
        }
    } catch (jace::JNIException& e) {
        qDebug() << "Exception in sendText():" << e.what();
    }
}
