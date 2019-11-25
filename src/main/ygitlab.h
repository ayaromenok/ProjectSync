//Copyrigth (C) 2019 Andrey Yaromenok
#ifndef YGITLAB_H
#define YGITLAB_H

#include <QObject>

class QSettings;

class YGitLab : public QObject
{
    Q_OBJECT
public:
    explicit YGitLab(QObject *parent = nullptr);
    ~YGitLab();
signals:

private:
    QSettings               *_settings;
    QString                 _token;
    quint32                 _userId;
    QList<quint32>          _prjects;
    QList<QString>          _projectNames;
};

#endif // YGITLAB_H
