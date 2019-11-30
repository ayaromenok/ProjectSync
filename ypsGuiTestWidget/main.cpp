//Copyrigth (C) 2019 Andrey Yaromenok
#include "../src/test/ymaintestwindow.h"

#include <QtCore>
#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setOrganizationName("Andrey Yaromenok");
    QCoreApplication::setOrganizationDomain("yaromenok.info");
    QCoreApplication::setApplicationName("YaProjectSync");

    qInfo() << QCoreApplication::applicationName();
    YMainTestWindow w;
    QLabel *l1 = new QLabel("label 1");
    l1->setObjectName("lb1");
    w.addTab(l1);
    w.show();
    return a.exec();
}
