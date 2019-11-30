//Copyrigth (C) 2019 Andrey Yaromenok
#ifndef YPROJECT_H
#define YPROJECT_H

#include <QObject>
class YIssue;
class YNotes;
class YMilestone;
class YUser;


class YProject : public QObject
{
    Q_OBJECT
public:
    explicit YProject(QObject *parent = nullptr);
    ~YProject();
signals:

private:
    void useTestValues();
    QList<YUser*>       *_ul;
    QList<YMilestone*>  *_ml;
    QList<YIssue*>      *_il;
    QList<YNotes*>      *_nl;
    bool                _isTest;
};

#endif // YPROJECT_H
