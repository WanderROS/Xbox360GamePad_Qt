#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  thread = new XboxThread(this);
  thread->start();
  connect(thread, SIGNAL(resultReady(XboxThread::position)), this,
          SLOT(readXbox(XboxThread::position)));
}

MainWindow::~MainWindow() {
  thread->setrun(false);
  thread->quit();
  thread->wait();
  delete thread;
  delete ui;
}

void MainWindow::readXbox(XboxThread::position p) {
  qDebug() << "\n\n\n";
  qDebug() << "A:" << p.buttonA;
  qDebug() << "B:" << p.buttonB;
  qDebug() << "X:" << p.buttonX;
  qDebug() << "Y:" << p.buttonY;
  qDebug() << "UP:" << p.buttonUp;
  qDebug() << "DOWN:" << p.buttonDown;
  qDebug() << "LEFT:" << p.buttonLeft;
  qDebug() << "RIGHT:" << p.buttonRight;
  qDebug() << "BACK:" << p.buttonBack;
  qDebug() << "START:" << p.buttonStart;
  qDebug() << "XBOX:" << p.buttonXBox;

  qDebug() << "LB:" << p.buttonLB;
  qDebug() << "RB:" << p.buttonRB;
  qDebug() << "buttonRS:" << p.buttonRS;
  qDebug() << "buttonLS:" << p.buttonLS;
  qDebug() << "SLIDERL:" << (int)(p.SLValue);
}
