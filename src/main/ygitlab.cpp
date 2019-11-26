//Copyrigth (C) 2019 Andrey Yaromenok
#include "ygitlab.h"
#include <QSettings>
#include <QDebug>

YGitLab::YGitLab(QObject *parent) : QObject(parent)
{
    _settings = new QSettings(this);
    _token.append(_settings->value("providers/gitlab/token","empty").toString());
    _userId = _settings->value("providers/gitlab/userid",0).toUInt();
    _prjCurId = _settings->value("providers/gitlab/projectCurrentId",0).toUInt();
    _prjCurName.append(_settings->value("providers/gitlab/projectCurrentName","empty").toString());

    qDebug() << __PRETTY_FUNCTION__ << "userId:" <<_userId << ", token:"<<_token
             << "prjId:"<<_prjCurId << ", prjName:"<< _prjCurName;
}

YGitLab::~YGitLab()
{
    _settings->sync();
    delete _settings;
}
