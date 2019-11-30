//Copyrigth (C) 2019 Andrey Yaromenok
#include <QtCore>

#include "ytestdata.h"

#include "../src/main/yproject.h"
#include "../src/main/yissue.h"
#include "../src/main/yuser.h"
#include "../src/main/ymilestone.h"
#include "../src/main/ynotes.h"

YTestData::YTestData(QObject *parent) : QObject(parent)
{

}

bool
YTestData::loadProjects(QList<YProject*> *pl)
{
    bool result = false;
    QFile file(":/test/projects.txt");
    if (file.exists()){
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
            QByteArray ba = file.readAll();
            if (ba.length() > 0){
                QJsonDocument jDoc = QJsonDocument::fromJson(ba);
                if (!jDoc.isNull()){
                    if (jDoc.isArray()) {
                        QJsonArray ja = jDoc.array();
                        for (int i=0; i< ja.size(); ++i){
                             QJsonObject jo = ja[i].toObject();
                             YProject* prj = new YProject();
                             //prj->parse(jo);
                             pl->append(prj);
                        }
                    }
                    if (pl->length() > 0){
                        result = true;
                    }
                }
            }
        }
    }
    return result;
}
bool
YTestData::loadUsers(QList<YUser*> *ul)
{
    bool result = false;
    QFile file(":/test/members.txt");
    if (file.exists()){
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
            QByteArray ba = file.readAll();
            if (ba.length() > 0){
                QJsonDocument jDoc = QJsonDocument::fromJson(ba);
                if (!jDoc.isNull()){
                    if (jDoc.isArray()) {
                        QJsonArray ja = jDoc.array();
                        for (int i=0; i< ja.size(); ++i){
                             QJsonObject jo = ja[i].toObject();
                             YUser* user = new YUser();
                             user->parse(jo);
                             ul->append(user);
                        }
                    }
                    if (ul->length() > 0){
                        result = true;
                    }
                }
            }
        }
    }
    return result;
}
bool
YTestData::loadMilestones(QList<YMilestone*> *ml)
{
    return true;
}
bool
YTestData::loadIssues(QList<YIssue*> *il)
{
    return true;
}
bool
YTestData::loadNotes(QList<YNotes*> *nl)
{
    return true;
}
