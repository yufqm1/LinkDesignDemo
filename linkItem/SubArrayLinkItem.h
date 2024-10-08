#ifndef SUBARRAYLINKITEM_H
#define SUBARRAYLINKITEM_H

#include <QObject>
#include "BaseLinkItem.h"
class SubArrayLinkItem : public QObject,public BaseLinkItem
{
    Q_OBJECT
public:
    SubArrayLinkItem(int id);
    virtual ~SubArrayLinkItem();
signals:
    void doubleClicked();


protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
private:
    QGraphicsPixmapItem* m_pixmap;
    QGraphicsTextItem* m_info;
};

#endif // SUBARRAYLINKITEM_H
