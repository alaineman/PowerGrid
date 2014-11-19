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

#ifndef MAIN_H
#define MAIN_H

#include <QtCore>
#include <QApplication>

#include <stdexcept>
#include <string>
#include <cstdlib>
#include <iostream>

#include "versionInfo.h"
#include "javaloader.h"
#include "mainwindow.h"

Q_DECLARE_LOGGING_CATEGORY(logLauncher)

/**
 * @brief Entry point of the application.
 * @param argc - The amount of command-line arguments
 * @param argv - The command-line arguments
 * @return       The status code.
 */
int main(int argc, char** argv);

/**
 * @brief Custom Qt MessageHandler function for handling all log messages.
 *
 * This QtMessageHandler function logs messages including either the category of their
 * logger or the type of message if no category was specified.
 *
 * @param type    - The type of message to be logged
 * @param context - The context of the message to be logged
 * @param msg     - The message itself
 */
void PGMessageHandler(QtMsgType type, const QMessageLogContext& context, const QString& msg);

/**
 * @brief Initialzes the Logger system.
 *
 * This function sets the filter rules for the logging system and installs the
 * custom QtMessageHandler (see @c PGMessageHandler(...)).
 */
void initializeLoggers();

/**
 * @brief Starts the JVM and the Java loader.
 * @throws jace::JNIException - When an Exception occurs in the JVM.
 */
void startJavaClient() throw (jace::JNIException);

/**
 * @brief Loads the updater data and enables it throughout the client.
 */
void runUpdater();

#endif // MAIN_H
