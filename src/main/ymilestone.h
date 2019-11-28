//Copyrigth (C) 2019 Andrey Yaromenok
#ifndef YMILESTONE_H
#define YMILESTONE_H

#include <QObject>

class YMilestone : public QObject
{
    Q_OBJECT
public:
    explicit YMilestone(QObject *parent = nullptr);
    ~YMilestone();
    void dumpToConsole();
    int getId(){return _id;}
    void setId(int id){_id = id;}
    int getIid(){return _iid;}
    void setIid(int iid){_iid = iid;}
    int getProjectId(){return _projectId;}
    void setProjectId(int id){_projectId = id;}
    int getState(){return _state;}
    void setState(int state){_state = state;}
    QString getTitle(){return _title;}
    void setTitle(QString title){_title = title;}
    QString getDescr(){return _descr;}
    void setDescr(QString descr){_descr = descr;}
    QString getWebUrl(){return _webUrl;}
    void setWebUrl(QString webUrl){_webUrl = webUrl;}

signals:

private:
    int         _id;
    int         _iid;
    int         _projectId;
    QString     _title;
    QString     _descr;
    int         _state;
    quint64     _createdAt;
    quint64     _updatedAt;
    quint64     _dueDate;
    quint64     _startDate;
    QString     _webUrl;
};

#endif // YMILESTONE_H
