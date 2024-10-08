#ifndef WAVEFILTERLINKITEM_H
#define WAVEFILTERLINKITEM_H

#include <QObject>
#include "BaseLinkItem.h"
class WaveFilterLinkItem : public QObject,public BaseLinkItem
{
    Q_OBJECT
public:
    WaveFilterLinkItem(int id);
    virtual ~WaveFilterLinkItem();
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

#endif // WAVEFILTERLINKITEM_H
