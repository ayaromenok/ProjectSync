//Copyrigth (C) 2019 Andrey Yaromenok
#ifndef YISSUELISTW2_H
#define YISSUELISTW2_H

#include <QWidget>

class QDragEnterEvent;
class QDropEvent;

class YIssueListW2 : public QWidget
{
    Q_OBJECT
public:
    explicit YIssueListW2(QWidget *parent = nullptr);

signals:

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
};

#endif // YISSUELISTW2_H
