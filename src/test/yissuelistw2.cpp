//Copyrigth (C) 2019 Andrey Yaromenok
#include <QtWidgets>

#include "yissuelistw2.h"
// based on Qt example widgets/dragndrop/draggabletext
// need to update with respect to fridgeagnets (custom label)
// or dragwidget with icons
static QString hotSpotMimeDataKey() { return QStringLiteral("application/x-hotspot"); }
static QLabel *createDragLabel(const QString &text, QWidget *parent)
{
    QLabel *label = new QLabel(text, parent);
    label->setAutoFillBackground(true);
    label->setFrameShape(QFrame::Panel);
    label->setFrameShadow(QFrame::Raised);
    return label;
}

YIssueListW2::YIssueListW2(QWidget *parent) : QWidget(parent)
{
    setObjectName("Issue List/Widgets #2");
    QLabel *lb1 = createDragLabel("label 1", this);
    lb1->move(10,10);
    QLabel *lb2 = createDragLabel("label 2", this);
    lb2->move(40,40);
    QLabel *lb3 = createDragLabel("label 3", this);
    lb3->move(70,70);
    lb1->show();
    lb2->show();
    lb3->show();

    setAcceptDrops(true);
}

void
YIssueListW2::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasText()) {
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

void
YIssueListW2::dropEvent(QDropEvent *event)
{
    if (event->mimeData()->hasText()) {
        const QMimeData *mime = event->mimeData();
        QString piece = mime->text();
        QPoint position = event->pos();
        QPoint hotSpot;

        QByteArrayList hotSpotPos = mime->data(hotSpotMimeDataKey()).split(' ');
        if (hotSpotPos.size() == 2) {
            hotSpot.setX(hotSpotPos.first().toInt());
            hotSpot.setY(hotSpotPos.last().toInt());
        }
        qDebug() << "pieces" << piece.length() << piece;

        QLabel *newLabel = createDragLabel(piece, this);
        newLabel->move(position - hotSpot);
        newLabel->show();
        newLabel->setAttribute(Qt::WA_DeleteOnClose);

        position += QPoint(newLabel->width(), 0);

        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
    for (QWidget *widget : findChildren<QWidget *>()) {
        if (!widget->isVisible())
            widget->deleteLater();
    }
    qInfo() << "drop:" << event->pos();
}

void
YIssueListW2::mouseMoveEvent(QMouseEvent *event)
{
    QLabel *child = qobject_cast<QLabel*>(childAt(event->pos()));
    if (!child)
        return;

    QPoint hotSpot = event->pos() - child->pos();

    QMimeData *mimeData = new QMimeData;
    mimeData->setText(child->text());
    mimeData->setData(hotSpotMimeDataKey(),
                      QByteArray::number(hotSpot.x()) + ' ' + QByteArray::number(hotSpot.y()));

    qreal dpr = window()->windowHandle()->devicePixelRatio();
    QPixmap pixmap(child->size() * dpr);
    pixmap.setDevicePixelRatio(dpr);
    child->render(&pixmap);

    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setPixmap(pixmap);
    drag->setHotSpot(hotSpot);

    Qt::DropAction dropAction = drag->exec( Qt::MoveAction, Qt::CopyAction);

    if (dropAction == Qt::MoveAction)
        child->close();
}
