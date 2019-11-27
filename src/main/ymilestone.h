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
