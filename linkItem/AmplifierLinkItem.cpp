#include "AmplifierLinkItem.h"

AmplifierLinkItem::AmplifierLinkItem(int id)
{
    QPixmap daptPixmap = QPixmap(":/res/loading.png").scaled(40,40,Qt::KeepAspectRatio);

    m_pixmap = new QGraphicsPixmapItem(daptPixmap,this);
    m_info = new QGraphicsTextItem("放大器" + QString::number(id),this);

    m_pixmap->setPos(10,10);
    m_info->setPos(10,60);

    // 设置id
    setId(id);
}

AmplifierLinkItem::~AmplifierLinkItem()
{

}

void AmplifierLinkItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    BaseLinkItem::mousePressEvent(event);
}

void AmplifierLinkItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    BaseLinkItem::mouseMoveEvent(event);
}

void AmplifierLinkItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    BaseLinkItem::mouseReleaseEvent(event);
}
