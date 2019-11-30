//Copyrigth (C) 2019 Andrey Yaromenok
#include "../src/test/ymaintestwindow.h"

#include <QtCore>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setOrganizationName("Andrey Yaromenok");
    QCoreApplication::setOrganizationDomain("yaromenok.info");
    QCoreApplication::setApplicationName("YaProjectSync");

    qInfo() << QCoreApplication::applicationName();
    YMainTestWindow w;
    w.show();
    return a.exec();
}
