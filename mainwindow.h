#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Antenna2DView.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_AddBtn_clicked();

    void on_DelBtn_clicked();

private:
    Ui::MainWindow *ui;

    Antenna2DView* m_Antena2DView;
    QGraphicsScene* m_scence;
};
#endif // MAINWINDOW_H
