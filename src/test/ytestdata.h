//Copyrigth (C) 2019 Andrey Yaromenok
#ifndef YTESTDATA_H
#define YTESTDATA_H

#include <QObject>
class YProject;
class YUser;
class YMilestone;
class YIssue;
class YNotes;

class YTestData : public QObject
{
    Q_OBJECT
public:
    explicit YTestData(QObject *parent = nullptr);
    static bool loadProjects(QList<YProject*> *pl);
    static bool loadUsers(QList<YUser*> *ul);
    static bool loadMilestones(QList<YMilestone*> *ml);
    static bool loadIssues(QList<YIssue*> *il);
    static bool loadNotes(QList<YNotes*> *nl);

signals:

};

#endif // YTESTDATA_H
