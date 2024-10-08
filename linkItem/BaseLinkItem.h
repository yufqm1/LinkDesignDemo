#ifndef BASELINKITEM_H
#define BASELINKITEM_H
#include <QPen>
#include <QGraphicsItem>
class BaseLinkItem : public QGraphicsRectItem
{
public:
    explicit BaseLinkItem(QGraphicsRectItem* parent = nullptr);
    virtual ~BaseLinkItem();
    QPointF getCenterPos();
    void setPosition(const QPointF& pos);
    void setId(int id);
    int getId();
    bool isPickup();
    void setPickup(bool pickup);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    void paint(QPainter* painter,const QStyleOptionGraphicsItem* option,QWidget* widget) override;
    void setName(const QString& name);
    QString getName();


private:
    QString m_name;
    QPointF m_cursorPos;
    QPointF m_originPos;
    bool m_isPickup;   // Item是否被选中(按键按下未释放)
    bool m_isToReplace;
    int m_id;  // 索引
};




#endif // BASELINKITEM_H
