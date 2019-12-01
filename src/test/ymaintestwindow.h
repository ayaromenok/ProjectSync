//Copyrigth (C) 2019 Andrey Yaromenok
#ifndef YMAINTESTWINDOW_H
#define YMAINTESTWINDOW_H

#include <QMainWindow>
class QTabWidget;
class QVBoxLayout;

class YMainTestWindow : public QMainWindow
{
    Q_OBJECT

public:
    YMainTestWindow(QWidget *parent = nullptr);
    ~YMainTestWindow();
    void addTab(QWidget *w);
    void addDualTab(QWidget *w1, QWidget *w2);

private:
    QTabWidget      *_cw;

};
#endif // MAINWINDOW_H
