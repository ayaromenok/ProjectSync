//Copyrigth (C) 2019 Andrey Yaromenok
#include <QtWidgets>

#include "yissuewidget.h"

YIssueWidget::YIssueWidget(int id, QWidget *parent)
    : QLabel(parent)
{
    setObjectName("issue #"+QString::number(id));

    QFontMetrics metric(font());
    QString text("#"+QString::number(id));
    QString strTitle("title");
    QString strAuthor("author");
    QString strBody("body text\nsecond line");

    QSize size(100,40);

    QImage image(size.width() + 12, size.height() + 12, QImage::Format_ARGB32_Premultiplied);
    image.fill(qRgba(0, 0, 0, 0));

    QFont font;
    font.setStyleStrategy(QFont::ForceOutline);
//! [0]

//! [1]
    QLinearGradient gradient(0, 0, 0, image.height()-1);
    gradient.setColorAt(0.0, Qt::white);
    gradient.setColorAt(0.2, QColor(200, 200, 255));
    gradient.setColorAt(0.8, QColor(200, 200, 255));
    gradient.setColorAt(1.0, QColor(127, 127, 200));

    QPainter painter;
    painter.begin(&image);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(gradient);
    painter.drawRoundedRect(QRectF(0.5, 0.5, image.width()-1, image.height()-1),
                            25, 25, Qt::RelativeSize);

    painter.setFont(font);
    painter.setBrush(Qt::black);
    painter.drawText(QRect(QPoint(5, 0), size), Qt::AlignLeft, text);
    painter.drawText(QRect(QPoint(25, 0), size), Qt::AlignLeft, strTitle);
    painter.drawText(QRect(QPoint(60, 0), size), Qt::AlignLeft, strAuthor);
    painter.drawText(QRect(QPoint(5, 16), size), Qt::AlignLeft, strBody);

    painter.end();
//! [1]

//! [2]
    setPixmap(QPixmap::fromImage(image));
}
YIssueWidget::~YIssueWidget()
{

}

void
YIssueWidget::dumpToConsole()
{
    qInfo() << "issue widget:" << _id;
}
