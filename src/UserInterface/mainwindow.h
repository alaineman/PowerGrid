#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class Ui_controlPanel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui_controlPanel *ui;

public slots:
    void setJVMVersion(QString version);
};

#endif // MAINWINDOW_H
