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
signals:

private:


};

#endif // YISSUE_H
