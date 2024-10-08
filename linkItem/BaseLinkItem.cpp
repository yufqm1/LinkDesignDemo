#include "BaseLinkItem.h"
#include "QDebug"
#include <QStyleOptionGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QEvent>
#include "LinkDesignManager.h"
BaseLinkItem::BaseLinkItem(QGraphicsRectItem *parent)
    : QGraphicsRectItem(parent),m_isPickup(false)
{
    setRect(QRect(0,0,60,100));
    // setPen(Qt::NoPen);
    setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
}

BaseLinkItem::~BaseLinkItem()
{

}

QPointF BaseLinkItem::getCenterPos()
{
    qDebug() << "---- centerPos: " << m_originPos.x() + rect().center().x() << " " << m_originPos.y() + rect().center().y();

    return QPointF(m_originPos.x() + rect().center().x(),
                   m_originPos.y() + rect().center().y());
}

void BaseLinkItem::setPosition(const QPointF &pos)
{
    setPos(pos);
    // 记录初始位置
    m_originPos =  QPointF(pos.x(),pos.y());

    qDebug() <<"id=" << getId() <<"  m_originPos():" << m_originPos.x() << "  " << m_originPos.y();
}

void BaseLinkItem::setId(int id)
{
    m_id = id;
}

int BaseLinkItem::getId()
{
    return m_id;
}

bool BaseLinkItem::isPickup()
{
    return m_isPickup;
}

void BaseLinkItem::setPickup(bool pickup)
{
    m_isPickup = pickup;
}

void BaseLinkItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    // 监听双击事件
    // if (event->button() == Qt::LeftButton && event->type() == QEvent::MouseButtonDblClick) {
    //     emit doubleClicked();
    // }


    LinkDesignManager::getInstance()->pickUpOne(getId());

    m_cursorPos = QCursor::pos();

    // if(!m_isPickup) {
    //     setPen(QPen(Qt::darkGreen));
    //     setPickup(true);
    // } else {
    //     setPen(QPen(Qt::black));
    //     setPickup(false);
    // }

    QGraphicsRectItem::mousePressEvent(event);
}

void BaseLinkItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

    QGraphicsRectItem::mouseMoveEvent(event);
}

void BaseLinkItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF currentPos;
    currentPos.setX(m_originPos.x() + QCursor::pos().x() - m_cursorPos.x());
    currentPos.setY(m_originPos.y() + QCursor::pos().y() - m_cursorPos.y());
        // 更新位置
        auto items = LinkDesignManager::getInstance()->getLinkItems();
        for(auto item : items) {
            QRectF thisRect(currentPos,QSizeF(rect().width(),rect().height()));
            if(thisRect.contains(item->getCenterPos())) { // 与另一个Item产生了有效碰撞
                // Item之前的所有节点均前移
                bool isRebuild = LinkDesignManager::getInstance()->rebuildLinks(getId(),item->getId());
                if(!isRebuild){
                    setPosition(QPointF(m_originPos.x(),m_originPos.y()));
                }

                QGraphicsRectItem::mouseReleaseEvent(event);
                return;
            }
        }

    setPosition(QPointF(m_originPos.x(),m_originPos.y()));
    QGraphicsRectItem::mouseReleaseEvent(event);
}

void BaseLinkItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // 编辑状态按原来的执行
    if (hasFocus())
    {
        QGraphicsRectItem::paint(painter, option, widget);
    }
    // 选中状态去掉虚线
    else
    {
        // 原来什么属性就要什么属性,只不过去掉多余的选中状态
        QStyleOptionGraphicsItem optionx(*option );
        optionx.state &= ~QStyle::State_Selected;
        QGraphicsRectItem::paint(painter, &optionx, widget);
    }
}

void BaseLinkItem::setName(const QString &name)
{
    m_name = name;
}

QString BaseLinkItem::getName()
{
    return m_name;
}


