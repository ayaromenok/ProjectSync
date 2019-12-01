//Copyrigth (C) 2019 Andrey Yaromenok
#include "../src/main/yproject.h"

#include "../src/test/ymaintestwindow.h"
#include "../src/test/yissuelistw.h"
#include "../src/test/yissuelistw2.h"

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
    YProject prj;

    YMainTestWindow w;
    YIssueListW *il = new YIssueListW();
    w.addTab(il);
    YIssueListW2 *il2 = new YIssueListW2();
    w.addTab(il2);
    w.show();
    return a.exec();
}
