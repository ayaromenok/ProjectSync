//Copyrigth (C) 2019 Andrey Yaromenok
#include <QtCore>
#include "yproject.h"
#include "../src/main/yuser.h"
#include "../src/main/ymilestone.h"
#include "../src/main/yissue.h"
#include "../src/main/ynotes.h"

#include "../src/test/ytestdata.h"

YProject::YProject(QObject *parent) : QObject(parent),
    _isTest(true)
{
    if (_isTest){
        qInfo() << __PRETTY_FUNCTION__ << "used test values!!!";
        useTestValues();
    } else {
        qErrnoWarning("not Implemented yet, exiting");
        return;
    }
}
YProject::~YProject()
{

}

void
YProject::useTestValues()
{

    _ul = new QList<YUser*>;    
    _ml = new QList<YMilestone*>;
    _il = new QList<YIssue*>;
    _nl = new QList<YNotes*>;
    YTestData::loadUsers(_ul);
    YTestData::loadMilestones(_ml);
    YTestData::loadIssues(_il);
    YTestData::loadNotes(_nl);
    qDebug() << "Loaded: " << _ul->length() << "users, " << _ml->length() << "milestones,"
             << _il->length() << "issues, " << _nl->length() << "notes";
}
