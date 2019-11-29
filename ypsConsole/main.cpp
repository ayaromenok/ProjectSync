//Copyrigth (C) 2019 Andrey Yaromenok
#include <QtCore>

#include "../src/main/ygitlab.h"
//#include "../src/main/yrequest.h"

#include "../src/main/yissueparse.h"
#include "../src/main/yissue.h"
#include "../src/main/yuser.h"
#include "../src/main/ymilestone.h"

void fnHelper()
{
    QFile file(":/test/issues.txt");
    YIssueParse ip;
    QList<YIssue*> *issueList = new QList<YIssue*>;
    QList<YUser*>  *userList = new QList<YUser*>;
    QList<YMilestone*>  *milestoneList = new QList<YMilestone*>;

    if (file.exists()){
        qDebug() << "file: " << file.size() << "bytes";
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
            QByteArray ba = file.readAll();
            QJsonDocument jDoc = QJsonDocument::fromJson(ba);
            if (!jDoc.isNull()){
                if (jDoc.isArray()) {
                    QJsonArray ja = jDoc.array();
                    ip.parseIssue(ja, *issueList, *userList, *milestoneList);
                }
            }
        }
    }

    for (int i = 0; i<issueList->size(); ++i){
        //qDebug() << issueList->at(i)->objectName();
        issueList->at(i)->dumpToConsole();
    }
    qDebug() << "# of users:" <<userList->size();
    for (int i = 0; i<userList->size(); ++i){
        qDebug() << userList->at(i)->objectName();
        userList->at(i)->dumpToConsole();
    }
    qDebug() << "# of milestones:" <<milestoneList->size();
    for (int i = 0; i<milestoneList->size(); ++i){
        qDebug() << milestoneList->at(i)->objectName();
        milestoneList->at(i)->dumpToConsole();
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QCoreApplication::setOrganizationName("Andrey Yaromenok");
    QCoreApplication::setOrganizationDomain("yaromenok.info");
    QCoreApplication::setApplicationName("YaProjectSync");

    qInfo() << QCoreApplication::applicationName();
    YGitLab gl;
    fnHelper();

    return a.exec();
}
