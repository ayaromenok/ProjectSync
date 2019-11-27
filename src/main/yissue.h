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

    void dumpToConsole();
    int getId(){return _id;}
    void setId(int id) {_id = id;}
    int getIid(){return _iid;}
    void setIid(int iid){_iid = iid;}
    int getProjectId(){return _projectId;}
    void setProjectId(int projectId){_projectId = projectId;}
    QString getTitle(){return _title;}
    void setTitle(QString title){_title = title;}
    QString getDescr(){return _descr;}
    void setDescr(QString descr){_descr = descr;}
    int getState(){return _state;}
    void setState(int state){_state = state;}
    quint64 getCreatedAt(){return _createdAt;}
    void setCreatedAt(quint64 createdAt){_createdAt = createdAt;}
    quint64 getUpdatedAt(){return _updatedAt;}
    void setUpdatedAt(quint64 updatedAt){_updatedAt = updatedAt;}
    quint64 getClosedAt(){return _closedAt;}
    void setClosedAt(quint64 closedAt){_closedAt = closedAt;}
    int getTimeEst(){return _timeEst;}
    void setTimeEst(int time){_timeEst = time;}
    int getTimeSpend(){return _timeSpend;}
    void setTimeSpend(int time){_timeSpend = time;}
    int getWeight(){return _weight;}
    void setWeight(int weight){_weight = weight;}
    int getAuthorId(){return _authorId;}
    void setAuthorId(int authorId){_authorId = authorId;}
signals:

private:
    int             _id;
    int             _iid;
    int             _projectId;
    QString         _title;
    QString         _descr;
    int              _state;
    quint64         _createdAt;
    quint64         _updatedAt;
    quint64         _closedAt;
    int             _userId;      //need own holder - YUser
    int             _milestoneId; //need own holder - YMilesone
    int             _timeEst;
    int             _timeSpend;
    int             _weight;
    //assignees - array of obj - YUser
    int             _authorId;// - obj - YUser
    //assignee - obj - YUser
    //up/down votes - int
    //web_url - str
    //links - obj
    //user_notes_count - int and link from above
    // notes required own holder - YIssueNotes
};

#endif // YISSUE_H
