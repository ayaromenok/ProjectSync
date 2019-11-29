//Copyrigth (C) 2019 Andrey Yaromenok
#include "yissueparse.h"
#include "yissue.h"
#include "../utils/yutils.h"
#include <QtCore>

YIssueParse::YIssueParse(QObject *parent) : QObject(parent)
{

}

YIssueParse::~YIssueParse()
{

}

bool
YIssueParse::parseIssue(const QJsonArray &ja, QList<YIssue*> &il,
                        QList<YUser*> &ul,QList<YMilestone*> &ml)
{
    for (int i=0; i< ja.size(); ++i){
        YIssue* issue = new YIssue();
        QJsonObject jo = ja[i].toObject();
        issue->parse(jo);

        if (jo.contains("author")){
            QJsonObject jauthor = jo["author"].toObject();
            if (jauthor.contains("id")){
                issue->setAuthorId(jauthor["id"].toInt());
                bool userNotExist = true;
                if (!ul.empty()){
                     for (int i = 0; i<ul.size(); ++i){
                         if (ul.at(i)->getId() == issue->getAuthorId()){
                             userNotExist = false;
                         }
                     }
                }
                if (userNotExist){
                    YUser* user = new YUser();
                    user->parse(jauthor);
                    ul.append(user);
                }
            }
        }

        if (jo.contains("milestone")){
            QJsonObject jml = jo["milestone"].toObject();
            if (jml.contains("id")){
                issue->setMilestoneId(jml["id"].toInt());
                bool mlNotExist = true;
                if (!ml.empty()){
                     for (int i = 0; i<ml.size(); ++i){
                         if (ml.at(i)->getId() == issue->getMilestoneId()){
                             mlNotExist = false;
                         }
                     }
                }
                if (mlNotExist){
                    YMilestone* milestone = new YMilestone();
                    milestone->parse(jml);
                    ml.append(milestone);
                }
            }
        }

        il.append(issue);
    }
    return true;
}
