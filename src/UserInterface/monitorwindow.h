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
#ifndef MONITORWINDOW_H
#define MONITORWINDOW_H

#include <QMainWindow>

#include "expressionparser.h"

namespace Ui {
class MonitorWindow;
}

class MonitorWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MonitorWindow(QWidget *parent = 0);
    ~MonitorWindow();

private slots:
    void on_evaluateButton_clicked();
    void on_MonitorWindow_destroyed();

public slots:
    void updateMousePos();

private:
    Ui::MonitorWindow *ui;
    QTimer* timer;
    API::ExpressionParser* parser;
};

#endif // MONITORWINDOW_H
