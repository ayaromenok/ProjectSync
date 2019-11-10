//Copyrigth (C) 2019 Andrey Yaromenok
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QtGui>
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initTestUi();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void
MainWindow::initTestUi()
{
    QStringList slBranches;
    QStringList slProjectHeaders;
    QList<QTreeWidgetItem *> prjItems;
    QStringList slFileList;

    //change layout proportion
    ui->hloMain->setStretch(0,1);
    ui->hloMain->setStretch(1,2);
    ui->hloMain->setStretch(2,2);
    ui->vloPrj->setStretch(0,1);
    ui->vloPrj->setStretch(1,2);
    //prj
    slProjectHeaders << "PrjName" << "LastModified" << "NoIdea";
    for (int i = 0; i < 5; ++i){
        QTreeWidgetItem *item = new QTreeWidgetItem((QTreeWidget*)0, QStringList(QString("prj_%1").arg(i)));
        item->addChild(new QTreeWidgetItem((QTreeWidget*)0, QStringList(QDate::currentDate().toString())));
        prjItems.append(item);
    }
    ui->twPrjTree->setHeaderLabels(slProjectHeaders);
    ui->twPrjTree->insertTopLevelItems(0,prjItems);

    slBranches << "00_branch" << "01_branch" << "02_branchXXX" << "03_branchYYY";
    ui->lwPrjBranches->insertItems(0,slBranches);

    //files
    slFileList << "file000.txt" << "fileAbcDef.txt" << "someStupidName.doc";
    ui->lwFileList->insertItems(0,slFileList);
    ui->teDiffLeft->append("some text at\n\t LEFT\nside");
    ui->teDiffRight->append("some text at\n\t RIGHT\nside");
    ui->lwGitLog->addItem("git log #0");
    ui->lwGitLog->addItem("git log #1");
    ui->lwGitLog->addItem("git log #2");

    //issues
    ui->lwIssueList->addItem("issue #1");
    ui->lwIssueList->addItem("issue #2");
    ui->lwIssueList->addItem("issue #3");

    ui->lwIssueBody->addItem("body of\nIssue #1");
    ui->lwIssueComments->addItem("git commit #1 related to \nissue #1");
    ui->lwIssueComments->addItem("some comment to issue #1");
}
