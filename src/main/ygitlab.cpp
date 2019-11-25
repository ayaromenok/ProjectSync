//Copyrigth (C) 2019 Andrey Yaromenok
#include "ygitlab.h"
#include <QSettings>
#include <QDebug>

YGitLab::YGitLab(QObject *parent) : QObject(parent)
{
    _settings = new QSettings(this);
    _token.append(_settings->value("providers/gitlab/token","empty").toString());
    _userId = _settings->value("providers/gitlab/userid",0).toUInt();
    qDebug() << __PRETTY_FUNCTION__ << _userId << _token;
}

YGitLab::~YGitLab()
{
    _settings->sync();
    delete _settings;
}
