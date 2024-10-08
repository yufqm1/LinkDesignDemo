#ifndef MIXERLINKITEM_H
#define MIXERLINKITEM_H

#include <QObject>
#include "BaseLinkItem.h"
class MixerLinkItem : public QObject,public BaseLinkItem
{
    Q_OBJECT
public:
    MixerLinkItem(int id);
    virtual ~MixerLinkItem();
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

#endif // MIXERLINKITEM_H
