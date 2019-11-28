//Copyrigth (C) 2019 Andrey Yaromenok
#include <QtCore>

#include "yissue.h"

YIssue::YIssue(QObject *parent) : QObject(parent),
    _id(0),
    _iid(0),
    _projectId(0),
    _title(""),
    _descr(""),
    _state(0),
    _createdAt(0),
    _updatedAt(0),
    _closedAt(0),
    _milestoneId(0),
    _timeEst(0),
    _timeSpend(0),
    _weight(0),
    _authorId(0)
{
}

YIssue::~YIssue()
{

}

void
YIssue::dumpToConsole()
{
    qInfo() << "Issue #" <<_id << _iid << _projectId << _title
    << _descr << _state << _timeEst << _timeSpend << _weight
    << _createdAt << _updatedAt << _closedAt  << _authorId << _milestoneId;
}

