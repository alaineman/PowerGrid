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
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "javaenv.h"
#include <QMainWindow>
#include <QString>

#define POWERGRID_VERSION QStringLiteral("0.2")

namespace Ui {
  class MainWindow;
}

typedef enum {
  DISABLED, LOW, HIGH
} ActivityLevel;

class MainWindow : public QMainWindow {
  Q_OBJECT
  
public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

  void updateVersionInfo(QString env_version);
  
signals:
  void activitySet(ActivityLevel level);

private slots:
  void on_travelHere_clicked();

private:
  Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
