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
YUser::dumpToConsole()
{
    qDebug() << "user" << _id << _username << _state << _name
             <<"\n" <<_avatarUrl << "\n" <<_webUrl;
}
