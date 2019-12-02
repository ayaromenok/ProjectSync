//Copyrigth (C) 2019 Andrey Yaromenok
#ifndef YISSUEWIDGET_H
#define YISSUEWIDGET_H

#include <QLabel>


class YIssueWidget : public QLabel
{
    Q_OBJECT
public:
    YIssueWidget(int id = 0, QWidget *parent = nullptr);
    ~YIssueWidget();
    void dumpToConsole();

    int getId(){return _id;}
    void setId(int id){_id = id;}

signals:

private:
    int        _id;
};

#endif // YISSUEWIDGET_H
