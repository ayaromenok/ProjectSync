//Copyrigth (C) 2019 Andrey Yaromenok
#include <QtCore>

#include "ymilestone.h"

YMilestone::YMilestone(QObject *parent) : QObject(parent),
    _id(0),
    _iid(0),
    _projectId(0),
    _title(""),
    _descr(""),
    _state(0),
    _createdAt(0),
    _updatedAt(0),
    _dueDate(0),
    _startDate(0),
    _webUrl("")
{

}


YMilestone::~YMilestone()
{

}

void
YMilestone::dumpToConsole()
{
    qDebug() << "milestone" << _id << _iid;

}
