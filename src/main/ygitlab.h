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
    quint32                 _prjCurId;
    QString                 _prjCurName;
};

#endif // YGITLAB_H
