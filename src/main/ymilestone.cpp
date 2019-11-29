//Copyrigth (C) 2019 Andrey Yaromenok
#include <QtCore>

#include "ymilestone.h"
#include "../utils/yutils.h"

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
YMilestone::parse(QJsonObject &jo)
{
    _id = jo["id"].toInt();
    setObjectName(QString::number(jo["id"].toInt()));
    if (jo.contains("iid")){_iid = jo["iid"].toInt();}
    if (jo.contains("project_id")){_projectId= jo["project_id"].toInt();}
    if (jo.contains("state")){_state = jo["state"].toString()=="active"?1:0;}
    if (jo.contains("title")){_title = jo["title"].toString();}
    if (jo.contains("description")){_descr = jo["description"].toString();}
    if (jo.contains("web_url")){_webUrl = jo["web_url"].toString();}
    if (jo.contains("created_at")){_createdAt = YUtils::timeStrToInt64(jo["created_at"].toString());}
    if (jo.contains("updated_at")){_updatedAt =  YUtils::timeStrToInt64(jo["updated_at"].toString());}
    if (jo.contains("due_date")){ _dueDate = YUtils::dateStrToInt64(jo["due_date"].toString());}
    if (jo.contains("start_date")){ _startDate = YUtils::dateStrToInt64(jo["start_date"].toString());}
}
void
YMilestone::dumpToConsole()
{
    qDebug() << "milestone" << _id << _title << _iid << _projectId << _state
             << _createdAt << _updatedAt << _startDate << _dueDate
              << "\n" << _descr << "\n" << _webUrl;
}

