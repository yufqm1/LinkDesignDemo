#ifndef PHASESHIFTERLINKITEM_H
#define PHASESHIFTERLINKITEM_H
#include <QObject>
#include "BaseLinkItem.h"
class PhaseShifterLinkItem : public QObject,public BaseLinkItem
{
    Q_OBJECT
public:
    PhaseShifterLinkItem(int id);
    virtual ~PhaseShifterLinkItem();
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


#endif // PHASESHIFTERLINKITEM_H
