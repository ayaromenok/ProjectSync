//Copyrigth (C) 2019 Andrey Yaromenok
#include "yissue.h"
#include <QDebug>

YIssue::YIssue(QObject *parent) : QObject(parent)
{
    qDebug() << __PRETTY_FUNCTION__;
}

YIssue::~YIssue()
{

}
