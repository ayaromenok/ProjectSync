//Copyrigth (C) 2019 Andrey Yaromenok
#include <QtCore>

#include "yissue.h"
#include "../utils/yutils.h"

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
    _authorId(0),
    _labels("")
{
}

YIssue::~YIssue()
{

}

void
YIssue::parse(const QJsonObject &jo)
{
    _id = jo["id"].toInt();
    setObjectName(QString::number(jo["id"].toInt()));
    if (jo.contains("iid"))        { _iid = jo["iid"].toInt(); }
    if (jo.contains("project_id")) { _projectId = jo["project_id"].toInt(); }
    if (jo.contains("title"))      { _title = jo["title"].toString(); }
    if (jo.contains("description")){ _descr = jo["description"].toString(); }
    if (jo.contains("state"))      { _state = jo["state"].toString().contains("open")?1:0; }
    if (jo.contains("created_at")) { _createdAt = YUtils::timeStrToInt64(jo["created_at"].toString()); }
    if (jo.contains("updated_at")) { _updatedAt = YUtils::timeStrToInt64(jo["updated_at"].toString()); }
    if (jo.contains("closed_at"))  { _closedAt = YUtils::timeStrToInt64(jo["closed_at"].toString()); }
    if (jo.contains("weight"))     { _weight = jo["weight"].toInt(); }

    if (jo.contains("labels")){
        QJsonArray al = jo["labels"].toArray();
        if (!al.empty()){
            for (int i=0; i< al.size(); ++i){
                _labels.append(al.at(i).toString());
            }
        }
    }

    if (jo.contains("time_stats")){
        QJsonObject jtime = jo["time_stats"].toObject();
        if (jtime.contains("time_estimate")){
            _timeEst = jtime["time_estimate"].toInt();
        }
        if (jtime.contains("time_spend")){
            _timeSpend = jtime["time_spend"].toInt();
        }
    }

}
void
YIssue::dumpToConsole()
{
    qInfo() << "Issue #" <<_id << _iid << _projectId << _title
    << _descr << _state << _timeEst << _timeSpend << _weight
    << _createdAt << _updatedAt << _closedAt  << _authorId << _milestoneId
    << _labels;
}

