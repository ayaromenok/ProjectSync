//Copyrigth (C) 2019 Andrey Yaromenok
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QtGui>
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initTestUi();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void
MainWindow::initTestUi()
{

}
