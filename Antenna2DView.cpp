#include <QWheelEvent>
#include <QKeyEvent>
#include "Antenna2DView.h"
#include "LinkDesignManager.h"
#define VIEW_CENTER viewport()->rect().center()
#define VIEW_WIDTH  viewport()->rect().width()
#define VIEW_HEIGHT viewport()->rect().height()

Antenna2DView::Antenna2DView(QWidget *parent)
    : QGraphicsView(parent),
    m_translateButton(Qt::LeftButton),
    m_scale(1.0),
    m_zoomDelta(0.1),
    m_translateSpeed(1.0),
    m_bMouseTranslate(false)
{
    setAlignment(Qt::AlignLeft | Qt::AlignTop);

    setBackgroundBrush(Qt::gray);
    // 设置场景矩形区域范围
    setSceneRect(0, 0, 100, 100);
    centerOn(sceneRect().center());


    // 去掉滚动条
    // setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // setCursor(Qt::PointingHandCursor);
    // setRenderHint(QPainter::Antialiasing);

    //setSceneRect(INT_MIN/2, INT_MIN/2, INT_MAX, INT_MAX);
}

// 平移速度
void Antenna2DView::setTranslateSpeed(qreal speed)
{
    // 建议速度范围
    Q_ASSERT_X(speed >= 0.0 && speed <= 2.0,
               "InteractiveView::setTranslateSpeed",
               "Speed should be in range [0.0, 2.0].");
    m_translateSpeed = speed;
}

qreal Antenna2DView::translateSpeed() const
{
    return m_translateSpeed;
}

// 缩放的增量
void Antenna2DView::setZoomDelta(qreal delta)
{
    // 建议增量范围
    Q_ASSERT_X(delta >= 0.0 && delta <= 1.0,
               "InteractiveView::setZoomDelta", "Delta should be in range [0.0, 1.0].");
    m_zoomDelta = delta;
}

qreal Antenna2DView::zoomDelta() const
{
    return m_zoomDelta;
}

// 上/下/左/右键向各个方向移动、加/减键进行缩放、空格/回车键旋转
void Antenna2DView::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Up:
        translate(QPointF(0, -2));  // 上移
        break;
    case Qt::Key_Down:
        translate(QPointF(0, 2));  // 下移
        break;
    case Qt::Key_Left:
        translate(QPointF(-2, 0));  // 左移
        break;
    case Qt::Key_Right:
        translate(QPointF(2, 0));  // 右移
        break;
    case Qt::Key_Plus:  // 放大
        zoomIn();
        break;
    case Qt::Key_Minus:  // 缩小
        zoomOut();
        break;
    case Qt::Key_Space:  // 逆时针旋转
        rotate(-5);
        break;
    case Qt::Key_Enter:  // 顺时针旋转
    case Qt::Key_Return:
        rotate(5);
        break;
    default:
        QGraphicsView::keyPressEvent(event);
    }
}

// 平移
void Antenna2DView::mouseMoveEvent(QMouseEvent *event)
{
    if (m_bMouseTranslate){
        QPointF mouseDelta = mapToScene(event->pos()) - mapToScene(m_lastMousePos);
        translate(mouseDelta);
    }

    m_lastMousePos = event->pos();

    QGraphicsView::mouseMoveEvent(event);
}

void Antenna2DView::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == m_translateButton) {
        // 当光标底下没有 item 时才能移动
        QPointF point = mapToScene(event->pos());
        if (scene()->itemAt(point, transform()) == NULL)  {
            m_bMouseTranslate = true;
            m_lastMousePos = event->pos();
            // 全部不被选中
            LinkDesignManager::getInstance()->dePickUpAll();
        }
    }

    QGraphicsView::mousePressEvent(event);
}

void Antenna2DView::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == m_translateButton)
        m_bMouseTranslate = false;

    QGraphicsView::mouseReleaseEvent(event);
}

// 放大/缩小
void Antenna2DView::wheelEvent(QWheelEvent *event)
{
    // 滚轮的滚动量
    QPoint scrollAmount = event->angleDelta();
    // 正值表示滚轮远离使用者放大负值表示朝向使用者缩小
    scrollAmount.y() > 0 ? zoomIn() : zoomOut();
}

// 放大
void Antenna2DView::zoomIn()
{
    zoom(1 + m_zoomDelta);
}

// 缩小
void Antenna2DView::zoomOut()
{
    zoom(1 - m_zoomDelta);
}

// 缩放 - scaleFactor缩放的比例因子
void Antenna2DView::zoom(float scaleFactor)
{
    // 防止过小或过大
    qreal factor = transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
    // if (factor < 0.07 || factor > 100)
    // {
    //     return;
    // }
    scale(scaleFactor, scaleFactor);
    m_scale *= scaleFactor;
}

// 平移
void Antenna2DView::translate(QPointF delta)
{
    // 根据当前 zoom 缩放平移数
    delta *= m_scale;
    delta *= m_translateSpeed;

    // view 根据鼠标下的点作为锚点来定位 scene
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    QPoint newCenter(VIEW_WIDTH / 2 - delta.x(),  VIEW_HEIGHT / 2 - delta.y());
    centerOn(mapToScene(newCenter));

    // scene 在 view 的中心点作为锚点
    setTransformationAnchor(QGraphicsView::AnchorViewCenter);
}
