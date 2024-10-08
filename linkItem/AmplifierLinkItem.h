#ifndef AMPLIFIERLINKITEM_H
#define AMPLIFIERLINKITEM_H

#include <QObject>
#include "BaseLinkItem.h"
class AmplifierLinkItem : public QObject,public BaseLinkItem
{
    Q_OBJECT
public:
    AmplifierLinkItem(int id);
    virtual ~AmplifierLinkItem();
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

#endif // AMPLIFIERLINKITEM_H
