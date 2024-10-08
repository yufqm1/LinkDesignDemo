#ifndef ATTENUATORLINKITEM_H
#define ATTENUATORLINKITEM_H

#include <QObject>
#include "BaseLinkItem.h"
class AttenuatorLinkItem : public QObject,public BaseLinkItem
{
    Q_OBJECT
public:
    AttenuatorLinkItem(int id);
    virtual ~AttenuatorLinkItem();
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
#endif // ATTENUATORLINKITEM_H
