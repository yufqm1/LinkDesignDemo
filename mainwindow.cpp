#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsScene>

#include "LinkDesignManager.h"
#include <QVBoxLayout>
#include "LinkDesignWidget.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    LinkDesignWidget* designWidget = new LinkDesignWidget(this);


    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(designWidget);// view 需要有个布局
    setLayout(layout);


    setCentralWidget(designWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}


