//Copyrigth (C) 2019 Andrey Yaromenok
#include <QtWidgets>

#include "ymaintestwindow.h"

YMainTestWindow::YMainTestWindow(QWidget *parent)
    : QMainWindow(parent),
      _cw(new QTabWidget)
{
    this->setGeometry(100,100,1024,600);
    setCentralWidget(_cw);
}

YMainTestWindow::~YMainTestWindow()
{
}

void
YMainTestWindow::addTab(QWidget *w)
{
    _cw->addTab(w, w->objectName());
}
