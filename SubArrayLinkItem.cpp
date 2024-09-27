#include "SubArrayLinkItem.h"
#include <QGraphicsSceneMouseEvent>
#include <QApplication>
#include <QDateTime>
SubArrayLinkItem::SubArrayLinkItem(int id)
{
    QPixmap daptPixmap = QPixmap(":/res/loading.png").scaled(40,40,Qt::KeepAspectRatio);

    m_pixmap = new QGraphicsPixmapItem(daptPixmap,this);
    m_info = new QGraphicsTextItem("子阵" + QString::number(id),this);

    m_pixmap->setPos(10,10);
    m_info->setPos(10,60);

    // 设置id
    setId(id);


    // 初始化等
    timer.setSingleShot(true);
    connect(&timer, &QTimer::timeout, this, &SubArrayLinkItem::onSingleClickTimeout);

    // 双击响应
    connect(this, &SubArrayLinkItem::doubleClicked, this, [](){
        qDebug() << "SubArrayLinkItem::doubleClicked";
    });
}

SubArrayLinkItem::~SubArrayLinkItem()
{

}

void SubArrayLinkItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        if (timer.isActive() && (QDateTime::currentMSecsSinceEpoch() - lastClickTime) < QApplication::doubleClickInterval()) {
            timer.stop();
            emit doubleClicked();
        }
    }

    BaseLinkItem::mousePressEvent(event);
}

void SubArrayLinkItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    BaseLinkItem::mouseMoveEvent(event);
}

void SubArrayLinkItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        lastClickTime = QDateTime::currentMSecsSinceEpoch();
        timer.start(QApplication::doubleClickInterval());
    }

    BaseLinkItem::mouseReleaseEvent(event);
}

void SubArrayLinkItem::onSingleClickTimeout()
{

}

