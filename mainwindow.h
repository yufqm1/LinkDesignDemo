#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Antenna2DView.h"

#include <QStandardItem>
#include <QStandardItemModel>
#include "linkdesign_common.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

enum class DataType
{
    Name = Qt::UserRole,
    ComType,


};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_AddBtn_clicked();

    void on_DelBtn_clicked();

    void slotComponentClicked(const QModelIndex& index);
private:
    Ui::MainWindow *ui;

    Antenna2DView* m_Antena2DView;
    QGraphicsScene* m_scence;
    QStandardItemModel* m_model;
    ItemType m_itemType;
};
#endif // MAINWINDOW_H
