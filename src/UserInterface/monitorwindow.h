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
    void on_MonitorWindow_destroyed();

public slots:
    void updateMousePos();

private:
    Ui::MonitorWindow *ui;
    QTimer* timer;
};

#endif // MONITORWINDOW_H
