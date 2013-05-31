#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "javaenv.h"
#include <QMainWindow>

#define POWERGRID_VERSION "0.1"

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT
  
public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

  void updateVersionInfo(jni::JavaEnv* environment);
  
  private slots:
  void on_travelHere_clicked();

  private:
  Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
