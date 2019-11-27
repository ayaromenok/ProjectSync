//Copyrigth (C) 2019 Andrey Yaromenok
#include "yissueparse.h"
#include "yissue.h"
#include <QtCore>

YIssueParse::YIssueParse(QObject *parent) : QObject(parent)
{

}

YIssueParse::~YIssueParse()
{

}

bool
YIssueParse::parseIssue(const QJsonArray &ja, QList<YIssue*> &il)
{
    for (int i=0; i< ja.size(); ++i){
        YIssue* issue = new YIssue();
        QJsonObject jo = ja[i].toObject();
        if (jo.contains("id"))         {
            issue->setId(jo["id"].toInt());
            issue->setObjectName(QString::number(jo["id"].toInt()));
        }
        if (jo.contains("iid"))        { issue->setIid(jo["iid"].toInt()); }
        if (jo.contains("project_id")) { issue->setProjectId(jo["project_id"].toInt()); }
        if (jo.contains("title"))      { issue->setTitle(jo["title"].toString()); }
        if (jo.contains("description")){ issue->setDescr(jo["description"].toString()); }
        if (jo.contains("state"))      { issue->setState(jo["state"].toString().contains("open")?1:0); }
//        if (jo.contains("created_at")) { issue->setCreatedAt(jo["created_at"].toString()); }
//        if (jo.contains("updated_at")) { issue->setUpdatedAt(jo["updated_at"].toString()); }
//        if (jo.contains("closed_at"))  { issue->setClosedAt(jo["closed_at"].toString()); }

        if (jo.contains("time_stats")){
            QJsonObject jtime = jo["time_stats"].toObject();
            if (jtime.contains("time_estimate")){
                issue->setTimeEst(jtime["time_estimate"].toInt());
            }
            if (jtime.contains("time_spend")){
                issue->setTimeSpend(jtime["time_spend"].toInt());
            }
        }
        if (jo.contains("weight"))       { issue->setWeight(jo["weight"].toInt()); }

        il.append(issue);
    }
    return true;
}
