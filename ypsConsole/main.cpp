//Copyrigth (C) 2019 Andrey Yaromenok
#include <QCoreApplication>
#include <QDebug>
#include "../src/main/ygitlab.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QCoreApplication::setOrganizationName("Andrey Yaromenok");
    QCoreApplication::setOrganizationDomain("yaromenok.info");
    QCoreApplication::setApplicationName("YaProjectSync");

    qInfo() << QCoreApplication::applicationName();
    YGitLab gl;

    return a.exec();
}
