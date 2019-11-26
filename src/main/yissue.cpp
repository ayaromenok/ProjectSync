//Copyrigth (C) 2019 Andrey Yaromenok
#include "yissue.h"
#include <QtCore>

YIssue::YIssue(QObject *parent) : QObject(parent)
{
}

YIssue::~YIssue()
{

}
bool
YIssue::parseIssue(const QJsonObject &jo)
{
    bool result = true;

    if (jo.contains("id")){ _id = jo["id"].toInt(); }
    if (jo.contains("iid")){ _iid = jo["iid"].toInt(); }
    if (jo.contains("project_id")){ _projectId = jo["project_id"].toInt();}
    if (jo.contains("title")){ _title = jo["title"].toString(); }
    if (jo.contains("description")){ _descr = jo["description"].toString(); }
    if (jo.contains("state")){ _state = jo["state"].toString(); }
    if (jo.contains("created_at")){ _createdAt = jo["created_at"].toString(); }
    if (jo.contains("closed_by")){
        QJsonObject ju = jo["closed_by"].toObject();
        if (ju.contains("username")){
            _user = ju["username"].toString();
        }
    }
    return result;
}

void
YIssue::dumpToConsole()
{
    qInfo() << "Issue #" << _iid << _title << _state << ": " << _descr;
    qInfo() << "created at" << _createdAt << "closed" << _user;
}

