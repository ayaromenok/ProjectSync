//Copyrigth (C) 2019 Andrey Yaromenok
#include <QtCore>

#include "yuser.h"

YUser::YUser(QObject *parent) : QObject(parent),
    _id(0),
    _name(""),
    _username(""),
    _state(0),
    _avatarUrl(""),
    _webUrl("")
{

}

YUser::~YUser()
{

}

void
YUser::parse(const QJsonObject &jo)
{
    _id = jo["id"].toInt();
    setObjectName(QString::number(jo["id"].toInt()));
    if (jo.contains("name")){_name = jo["name"].toString();}
    if (jo.contains("username")){_username = jo["username"].toString();}
    if (jo.contains("state")){_state = jo["state"].toString()=="active"?1:0;}
    if (jo.contains("avatar_url")){_avatarUrl = jo["avatar_url"].toString();}
    if (jo.contains("web_url")){_webUrl = jo["web_url"].toString();}
}

void
YUser::dumpToConsole()
{
    qDebug() << "user" << _id << _username << _state << _name
             <<"\n" <<_avatarUrl << "\n" <<_webUrl;
}
