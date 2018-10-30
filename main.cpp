#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  qRegisterMetaType<XboxThread::position>("testthread::position");

  MainWindow w;
  w.show();

  return a.exec();
}
