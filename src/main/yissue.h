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
    void parse(const QJsonObject &jo);
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
    qint64 getCreatedAt(){return _createdAt;}
    void setCreatedAt(qint64 createdAt){_createdAt = createdAt;}
    qint64 getUpdatedAt(){return _updatedAt;}
    void setUpdatedAt(qint64 updatedAt){_updatedAt = updatedAt;}
    qint64 getClosedAt(){return _closedAt;}
    void setClosedAt(qint64 closedAt){_closedAt = closedAt;}
    int getTimeEst(){return _timeEst;}
    void setTimeEst(int time){_timeEst = time;}
    int getTimeSpend(){return _timeSpend;}
    void setTimeSpend(int time){_timeSpend = time;}
    int getWeight(){return _weight;}
    void setWeight(int weight){_weight = weight;}
    int getAuthorId(){return _authorId;}
    void setAuthorId(int authorId){_authorId = authorId;}
    int getMilestoneId(){return _milestoneId;}
    void setMilestoneId(int milestoneId){_milestoneId = milestoneId;}
    QStringList getLabels(){return _labels;}
    void setLabels(QStringList labels){_labels = labels;}

signals:

private:
    int             _id;
    int             _iid;
    int             _projectId;
    QString         _title;
    QString         _descr;
    int             _state;
    qint64         _createdAt;
    qint64         _updatedAt;
    qint64         _closedAt;
    int             _userId;      //need own holder - YUser
    int             _milestoneId; //need own holder - YMilesone
    int             _timeEst;
    int             _timeSpend;
    int             _weight;
    //assignees - array of obj - YUser
    int             _authorId;// - obj - YUser
    QStringList     _labels;
    //assignee - obj - YUser
    //up/down votes - int
    //web_url - str
    //links - obj
    //user_notes_count - int and link from above
    // notes required own holder - YIssueNotes
};

#endif // YISSUE_H
