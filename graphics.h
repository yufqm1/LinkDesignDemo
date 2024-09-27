#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QString>
#include <QPainter>

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QVBoxLayout>
#include <QWidget>
#include <QPen>


class SeatItem : public QObject,public QGraphicsRectItem{
    Q_OBJECT
public:
    SeatItem(int seatNumber, QGraphicsItem *parent = nullptr)
        : QGraphicsRectItem(parent), seatNumber(seatNumber) {
        setRect(0, 0, 20, 20); // 设置阵元大小
        //setBrush(Qt::green);
        setPen(QPen(Qt::darkGreen));
    }

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override {
        if (pen().color() == Qt::darkGreen) {
            setPen(QPen(Qt::red));
            emit seatBooked(seatNumber);
        } else {
            setPen(QPen(Qt::darkGreen));
            emit seatCanceled(seatNumber);
        }
        QGraphicsRectItem::mousePressEvent(event);
    }
signals:
    void seatBooked(int seatNumber);
    void seatCanceled(int seatNumber);

private:
    int seatNumber;
};


class CinemaSeatMap : public QWidget {
public:
    CinemaSeatMap(QWidget *parent = nullptr) : QWidget(parent) {
        QVBoxLayout *layout = new QVBoxLayout(this);

        QGraphicsScene *scene = new QGraphicsScene(this);
        //scene->setBackgroundBrush(Qt::gray);
        QGraphicsView *view = new QGraphicsView(scene);
        //view->setBackgroundBrush(Qt::red);
        view->setRenderHint(QPainter::Antialiasing);
        //view->setFixedSize(700, 500);
        //view->setDragMode(QGraphicsView::ScrollHandDrag);
        const int rows = 50;   // 行数
        const int cols = 50;   // 列数
        const int spacing = 10; // 阵元间隔
        SeatItem seat(-1);
        int seatWidth = seat.rect().width();
        int seatHeight = seat.rect().height();
        // 绘制阵元
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                SeatItem *seatItem = new SeatItem(row * cols + col + 1);

                seatItem->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);

                seatItem->setPos(spacing + col * (seatItem->rect().width() + spacing),
                                 spacing + row * (seatItem->rect().height() + spacing));
                scene->addItem(seatItem);

                // 连接信号
                connect(seatItem, &SeatItem::seatBooked, this, [this](int seatNumber) {
                    // 可以在这里处理阵元
                    qDebug() << "Seat booked:" << seatNumber;
                });

                connect(seatItem, &SeatItem::seatCanceled, this, [this](int seatNumber) {
                    qDebug() << "Seat canceled:" << seatNumber;
                });
            }
        }

        for(int row = 1;row < rows;++row) {
            QLineF lineF((seatWidth + spacing) * row + spacing/2,spacing/2,
                         (seatWidth + spacing) * row + spacing/2,rows * (seatWidth + spacing) + spacing/2);
            QGraphicsLineItem* lineItem = new QGraphicsLineItem(lineF);
            lineItem->setPen(QPen(Qt::gray, 1));
            scene->addItem(lineItem);
        }

        for(int col = 1;col < cols;++col) {
            QLineF lineF(spacing/2,(seatHeight + spacing) * col+ spacing/2,
                         cols * (seatWidth + spacing) + spacing/2, (seatHeight + spacing) * col + spacing/2);
            QGraphicsLineItem* lineItem = new QGraphicsLineItem(lineF);
            lineItem->setPen(QPen(Qt::gray, 1));
            scene->addItem(lineItem);
        }

        // 绘制外轮廓
        QRectF outerRect(spacing/2, spacing/2, cols * (seatWidth + spacing), rows *  (seatHeight + spacing));
        QGraphicsRectItem *outerItem = new QGraphicsRectItem(outerRect);
        outerItem->setPen(QPen(Qt::gray, 1));
        scene->addItem(outerItem);

        layout->addWidget(view);
        setLayout(layout);
        setWindowTitle("天线阵列图");
        //resize(700, 500);
    }
};


#endif // GRAPHICS_H
