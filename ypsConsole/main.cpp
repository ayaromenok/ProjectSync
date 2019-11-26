//Copyrigth (C) 2019 Andrey Yaromenok
#include <QtCore>

#include "../src/main/ygitlab.h"
//#include "../src/main/yrequest.h"

void fnHelper()
{
    QFile file(":/test/issues.txt");
    if (file.exists()){
            qDebug() << "file: " << file.size() << "bytes";
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
