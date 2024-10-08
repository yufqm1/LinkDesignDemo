#include "PhaseShifterLinkItem.h"

PhaseShifterLinkItem::PhaseShifterLinkItem(int id)
{
    QPixmap daptPixmap = QPixmap(":/res/loading.png").scaled(40,40,Qt::KeepAspectRatio);

    m_pixmap = new QGraphicsPixmapItem(daptPixmap,this);
    m_info = new QGraphicsTextItem("移相器" + QString::number(id),this);

    m_pixmap->setPos(10,10);
    m_info->setPos(10,60);

    // 设置id
    setId(id);
}

PhaseShifterLinkItem::~PhaseShifterLinkItem()
{

}

void PhaseShifterLinkItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    // TODO 双击事件
    BaseLinkItem::mousePressEvent(event);
}

void PhaseShifterLinkItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    BaseLinkItem::mouseMoveEvent(event);
}

void PhaseShifterLinkItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    BaseLinkItem::mouseReleaseEvent(event);
}
