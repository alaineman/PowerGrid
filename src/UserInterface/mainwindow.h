#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class Ui_controlPanel;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui_controlPanel *ui;
    QTimer* timer;

public slots:
    void setJVMVersion(QString version);
    void updateFPS();
};

#endif // MAINWINDOW_H
