//Copyrigth (C) 2019 Andrey Yaromenok
#include <QtCore>

#include "../src/main/ygitlab.h"
//#include "../src/main/yrequest.h"
#include "../src/main/yissue.h"

void fnHelper()
{
    QFile file(":/test/issues.txt");
    if (file.exists()){
        qDebug() << "file: " << file.size() << "bytes";
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
            QByteArray ba = file.readAll();
            QJsonDocument jDoc = QJsonDocument::fromJson(ba);
            if (jDoc.isArray()) {
                QJsonArray ja = jDoc.array();
                for (int i=0; i< ja.size(); ++i){
                    YIssue issue;
                    QJsonObject jo = ja[i].toObject();
                    issue.parseIssue(jo);
                    issue.dumpToConsole();
                }
            }
        }
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
