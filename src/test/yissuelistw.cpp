//Copyrigth (C) 2019 Andrey Yaromenok
#include <QtWidgets>

#include "yissuelistw.h"

YIssueListW::YIssueListW(QWidget *parent) : QWidget(parent)
{
    setObjectName("Issue List");
    QVBoxLayout *vl = new QVBoxLayout();
    QLabel *lb1 = new QLabel("issue #1");
    QLabel *lb2 = new QLabel("issue #2");
    QLabel *lb3 = new QLabel("issue #3");
    vl->addWidget(lb1);
    vl->addWidget(lb2);
    vl->addWidget(lb3);
    setLayout(vl);
}

YIssueListW::~YIssueListW()
{

}
