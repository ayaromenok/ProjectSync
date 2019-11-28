//Copyrigth (C) 2019 Andrey Yaromenok
#ifndef YUTILS_H
#define YUTILS_H

#include <QObject>

class YUtils : public QObject
{
    Q_OBJECT
public:
    explicit YUtils(QObject *parent = nullptr);
    static qint64 timeStrToInt64(QString str);
    static qint64 dateStrToInt64(QString str);
signals:

};

#endif // YUTILS_H
