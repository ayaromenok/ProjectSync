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
    QString getName(){return _name;}
    void setName(QString name){_name = name;}
    QString getUserName(){return _username;}
    void setUserName(QString username){_username = username;}
    int getState(){return _state;}
    void setState(int state){_state = state;}
    QString getAvatarUrl(){return _avatarUrl;}
    void setAvatarUrl(QString urlStr){_avatarUrl = urlStr;}
    QString getWebUrl(){return _webUrl;}
    void setWebUrl(QString urlStr){_webUrl = urlStr;}

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
