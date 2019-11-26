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

    if (jo.contains("id"))         { _id = jo["id"].toInt(); }
    if (jo.contains("iid"))        { _iid = jo["iid"].toInt(); }
    if (jo.contains("project_id")) { _projectId = jo["project_id"].toInt();}
    if (jo.contains("title"))      { _title = jo["title"].toString(); }
    if (jo.contains("description")){ _descr = jo["description"].toString(); }
    if (jo.contains("state"))      { _state = jo["state"].toString(); }
    if (jo.contains("created_at")) { _createdAt = jo["created_at"].toString(); }
    if (jo.contains("updated_at")) { _updatedAt = jo["updated_at"].toString(); }
    if (jo.contains("closed_at"))  { _closedAt = jo["closed_at"].toString(); }
    if (jo.contains("closed_by")){
        QJsonObject ju = jo["closed_by"].toObject();
        if (ju.contains("username")){
            _user = ju["username"].toString();
        }
    }
    if (jo.contains("labels")){
        QJsonArray jaLabels = jo["labels"].toArray();
        if (jaLabels.size() > 0){
            for (int i=0; i< jaLabels.size(); ++i){
                // just a list of strings, like "To Do", "Doing", custom labels
                qDebug() << jaLabels[i].toString();
            }
        }
    }
    if (jo.contains("milestone")){
        QJsonObject jmlstn = jo["milestone"].toObject();
        if (jmlstn.contains("title")){
            _milestone = jmlstn["title"].toString();
        }
    }

    if (jo.contains("time_stats")){
        QJsonObject jtime = jo["time_stats"].toObject();
        if (jtime.contains("time_estimate")){
            _timeEst = jtime["time_estimate"].toInt();
        }
        if (jtime.contains("time_spent")){
            _timeEst = jtime["time_spend"].toInt();
        }
    }

    if (jo.contains("weight"))         { _weight = jo["weight"].toInt(); }

    return result;
}

void
YIssue::dumpToConsole()
{
    qInfo() << "Issue #" << _iid << _title << _state << ": " << _descr;
    qInfo() << _createdAt << _updatedAt << _closedAt << "closed" << _user;
    qInfo() << _milestone << _timeEst << _timeSpent << _weight;
}

