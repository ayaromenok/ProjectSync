//Copyrigth (C) 2019 Andrey Yaromenok
#include <QtCore>
#include "yutils.h"

YUtils::YUtils(QObject *parent) : QObject(parent)
{

}

qint64
YUtils::timeStrToInt64(QString str)
{
    quint64 result = 0;

    QStringRef strDate, strTime;
    strDate = str.midRef(0,10);
    strTime = str.midRef(11,12);
    if(str.length() >0 ){
        result = QDateTime::fromString(strDate.toString(),"yyyy-MM-dd").toMSecsSinceEpoch();
        result += QTime::fromString(strTime.toString(),"hh:mm:ss.zzz").msecsSinceStartOfDay();
//        qDebug() << "timeStrToUInt64: " << str << result
//                 << QDateTime::fromMSecsSinceEpoch(result).toString("yyyy-MM-ddThh:mm:ss.zzzZ");
    }
    return result;
}

qint64
YUtils::dateStrToInt64(QString str)
{
    quint64 result = 0;

    if(str.length() >0 ){
        result = QDateTime::fromString(str,"yyyy-MM-dd").toMSecsSinceEpoch();
//            qDebug() << "dateStrToUInt64: "<<str << result
//            << QDateTime::fromMSecsSinceEpoch(result).toString("yyyy-MM-dd");
    }
    return result;
}
