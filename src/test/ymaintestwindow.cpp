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

void
YMainTestWindow::addDualTab(QWidget *w1, QWidget *w2)
{
    QFrame *fr = new QFrame(this);
    fr->setObjectName("Dual Tab");
    QHBoxLayout *hl = new QHBoxLayout;
    hl->addWidget(w1);
    hl->addWidget(w2);
    fr->setLayout(hl);
    _cw->addTab(fr,fr->objectName());
}
