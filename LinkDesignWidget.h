#ifndef LINKDESIGNWIDGET_H
#define LINKDESIGNWIDGET_H

#include <QWidget>

#include "Antenna2DView.h"

#include <QStandardItem>
#include <QStandardItemModel>
#include "linkdesign_common.h"

namespace Ui {
class LinkDesignWidget;
}

class LinkDesignWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LinkDesignWidget(QWidget *parent = nullptr);
    ~LinkDesignWidget();

private slots:
    void on_addBtn_clicked();

    void on_delBtn_clicked();

    void slotComponentClicked(const QModelIndex& index);

private:
    Ui::LinkDesignWidget *ui;

    Antenna2DView* m_Antena2DView;
    QGraphicsScene* m_scence;
    QStandardItemModel* m_model;
    ItemType m_itemType;
};

#endif // LINKDESIGNWIDGET_H
