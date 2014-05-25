#ifndef MONITORWINDOW_H
#define MONITORWINDOW_H

#include <QMainWindow>

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

private:
    Ui::MonitorWindow *ui;
};

#endif // MONITORWINDOW_H
