//Copyrigth (C) 2019 Andrey Yaromenok
#include <QtCore>

#include "ynotes.h"
#include "../utils/yutils.h"

YNotes::YNotes(QObject *parent) : QObject(parent),
    _id(0),
    _noteableId(0),
    _noteableIid(0),
    _noteableType(0),
    _type(0),
    _body(""),
    _attach(0),
    _authorId(0),
    _createdAt(0),
    _updatedAt(0),
    _system(false),
    _resolvable(false)
{

}

YNotes::~YNotes()
{

}

void
YNotes::parse(const QJsonObject &jo)
{
    _id = jo["id"].toInt();
    setObjectName(QString::number(jo["id"].toInt()));
    if (jo.contains("noteable_id")){_noteableId = jo["noteable_id"].toInt();}
    if (jo.contains("noteable_iid")){_noteableIid = jo["noteable_iid"].toInt();}
    if (jo.contains("noteable_type")){_noteableType = (jo["noteable_type"].toString() == "Issue"?1:0);}
    if (jo.contains("type")){_type = jo["type"].toInt();}
    if (jo.contains("body")){_body = jo["body"].toString();}
    if (jo.contains("attach")){_type = jo["attach"].toInt();}
    if (jo.contains("system")){_type = jo["system"].toBool();}
    if (jo.contains("resolvable")){_type = jo["resolvable"].toBool();}
    if (jo.contains("author")){
        QJsonObject jauthor = jo["author"].toObject();
        if (jauthor.contains("id")){
            _authorId = jauthor["id"].toInt();
        }
    }
    if (jo.contains("created_at")) { _createdAt = YUtils::timeStrToInt64(jo["created_at"].toString()); }
    if (jo.contains("updated_at")) { _updatedAt = YUtils::timeStrToInt64(jo["updated_at"].toString()); }

}
void
YNotes::dumpToConsole()
{
    qDebug() << "notes" << _id << "from Issue #"<< _noteableIid << _noteableId
             << _noteableType << _system << _resolvable << _attach << "\n"
             << _body << _authorId <<_createdAt << _updatedAt;
}
