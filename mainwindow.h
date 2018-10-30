#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "xboxthread.h"
#include <QByteArray>
#include <QMainWindow>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

private slots:
  void readXbox(XboxThread::position p);

private:
  Ui::MainWindow *ui;
  XboxThread *thread;
};

#endif // MAINWINDOW_H
