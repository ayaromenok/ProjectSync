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

        il.append(issue);
    }
    return true;
}
