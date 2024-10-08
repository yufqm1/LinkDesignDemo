#include "WaveFilterLinkItem.h"

WaveFilterLinkItem::WaveFilterLinkItem(int id)
{
    QPixmap daptPixmap = QPixmap(":/res/loading.png").scaled(40,40,Qt::KeepAspectRatio);

    m_pixmap = new QGraphicsPixmapItem(daptPixmap,this);
    m_info = new QGraphicsTextItem("滤波器" + QString::number(id),this);

    m_pixmap->setPos(10,10);
    m_info->setPos(10,60);

    // 设置id
    setId(id);
}

WaveFilterLinkItem::~WaveFilterLinkItem()
{

}

void WaveFilterLinkItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    BaseLinkItem::mousePressEvent(event);
}

void WaveFilterLinkItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    BaseLinkItem::mouseMoveEvent(event);
}

void WaveFilterLinkItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    BaseLinkItem::mouseReleaseEvent(event);
}
