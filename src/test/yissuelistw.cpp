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
    QListWidget *ilw = new QListWidget();
    new QListWidgetItem("item #1", ilw);
    new QListWidgetItem("item #2", ilw);
    vl->addWidget(ilw);
    setLayout(vl);
}

YIssueListW::~YIssueListW()
{

}
