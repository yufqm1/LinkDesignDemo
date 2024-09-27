#ifndef SUBARRAYLINKITEM_H
#define SUBARRAYLINKITEM_H

#include <QObject>
#include "BaseLinkItem.h"
#include "QTimer"
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
    QTimer timer;
    qint64 lastClickTime = 0;

private slots:
    void onSingleClickTimeout();

};

#endif // SUBARRAYLINKITEM_H
