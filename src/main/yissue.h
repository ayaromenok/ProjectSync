//Copyrigth (C) 2019 Andrey Yaromenok
#ifndef YISSUE_H
#define YISSUE_H

#include <QObject>

class YIssue : public QObject
{
    Q_OBJECT
public:
    explicit YIssue(QObject *parent = nullptr);
    ~YIssue();
    bool parseIssue(const QJsonObject &jo);
    void dumpToConsole();
signals:

private:
    int             _id;
    int             _iid;
    int             _projectId;
    QString         _title;
    QString         _descr;
    QString         _state; //may be need to make enum/int
    QString         _createdAt; //need to convert to quint64
    QString         _updatedAt; //need to convert to quint64
    QString         _closedAt; //need to convert to quint64
    QString         _user;
};

#endif // YISSUE_H
