#include "SubArrayLinkItem.h"

SubArrayLinkItem::SubArrayLinkItem(int id)
{
    QPixmap daptPixmap = QPixmap(":/res/loading.png").scaled(40,40,Qt::KeepAspectRatio);

    m_pixmap = new QGraphicsPixmapItem(daptPixmap,this);
    m_info = new QGraphicsTextItem("子阵" + QString::number(id),this);

    m_pixmap->setPos(10,10);
    m_info->setPos(10,60);

    // 设置id
    setId(id);
}

SubArrayLinkItem::~SubArrayLinkItem()
{

}

void SubArrayLinkItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    // TODO 双击事件
    BaseLinkItem::mousePressEvent(event);
}

void SubArrayLinkItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    BaseLinkItem::mouseMoveEvent(event);
}

void SubArrayLinkItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    BaseLinkItem::mouseReleaseEvent(event);
}

