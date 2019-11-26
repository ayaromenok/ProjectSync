//Copyrigth (C) 2019 Andrey Yaromenok
#ifndef YREQUEST_H
#define YREQUEST_H

#include <QObject>

class YRequest : public QObject
{
    Q_OBJECT
public:
    explicit YRequest(QObject *parent = nullptr);
    ~YRequest();
signals:

};

#endif // YREQUEST_H
