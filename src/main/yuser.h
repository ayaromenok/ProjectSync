//Copyrigth (C) 2019 Andrey Yaromenok
#ifndef YUSER_H
#define YUSER_H

#include <QObject>

class YUser : public QObject
{
    Q_OBJECT
public:
    explicit YUser(QObject *parent = nullptr);
    ~YUser();
    void dumpToConsole();
    int getId(){return _id;}
    void setId(int id){_id = id;}

signals:

private:
    int         _id;
    QString     _name;
    QString     _username;
    int         _state;
    QString     _avatarUrl;
    QString     _webUrl;

};

#endif // YUSER_H
