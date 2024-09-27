#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsScene>

#include "LinkDesignManager.h"
#include <QVBoxLayout>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_Antena2DView = new Antenna2DView(ui->widget);
    m_scence = new QGraphicsScene(this);
    m_Antena2DView->setScene(m_scence);

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(m_Antena2DView);// view 需要有个布局
    ui->widget->setLayout(layout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_AddBtn_clicked()
{
    LinkDesignManager::getInstance()->createLinkItem(ItemType::SubArray,m_scence);
}


void MainWindow::on_DelBtn_clicked()
{
    LinkDesignManager::getInstance()->deleteLinkItem();
}

