//Copyrigth (C) 2019 Andrey Yaromenok
#ifndef YNOTES_H
#define YNOTES_H

#include <QObject>

class YNotes : public QObject
{
    Q_OBJECT
public:
    explicit YNotes(QObject *parent = nullptr);
    ~YNotes();
    void parse(const QJsonObject &jo);
    void dumpToConsole();
signals:

private:
    int         _id;
    int         _noteableId;
    int         _noteableIid;    //local issue number;
    int         _noteableType;   //issue, what more?
    int         _type;          //null
    QString     _body;
    int         _attach;        //null, need to evaluate
    int         _authorId;
    qint64      _createdAt;
    qint64      _updatedAt;
    bool        _system;        //wtf?
    bool        _resolvable;
};

#endif // YNOTES_H
