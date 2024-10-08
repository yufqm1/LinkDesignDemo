#include "LinkDesignWidget.h"
#include "ui_LinkDesignWidget.h"

#include <QGraphicsScene>

#include "LinkDesignManager.h"
#include <QVBoxLayout>

LinkDesignWidget::LinkDesignWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LinkDesignWidget)
{
    ui->setupUi(this);
    m_scence = new QGraphicsScene(this);
    ui->designWidget->setScene(m_scence);

    ui->splitter->setStretchFactor(0,1);
    ui->splitter->setStretchFactor(1,10);

    m_model = new QStandardItemModel;
    ui->componentView->setEditTriggers(QAbstractItemView::NoEditTriggers);// 设置节点不可编辑
    ui->componentView->setModel(m_model);

    QStandardItem* subArrayItem = new QStandardItem(QIcon(":/res/loading.png"),"子阵");
    subArrayItem->setData((int)ItemType::SubArray,(int)DataType::ComType);
    QStandardItem* phaseShifterItem = new QStandardItem(QIcon(":/res/loading.png"),"移相器");
    phaseShifterItem->setData((int)ItemType::PhaseShifter,(int)DataType::ComType);
    QStandardItem* attenuatorItem = new QStandardItem(QIcon(":/res/loading.png"),"衰减器");
    attenuatorItem->setData((int)ItemType::Attenuator,(int)DataType::ComType);
    QStandardItem* amplifierItem = new QStandardItem(QIcon(":/res/loading.png"),"放大器");
    amplifierItem->setData((int)ItemType::Amplifier,(int)DataType::ComType);
    QStandardItem* waveFilterItem = new QStandardItem(QIcon(":/res/loading.png"),"滤波器");
    waveFilterItem->setData((int)ItemType::WaveFilter,(int)DataType::ComType);
    QStandardItem* mixerItem = new QStandardItem(QIcon(":/res/loading.png"),"混频器");
    mixerItem->setData((int)ItemType::Mixer,(int)DataType::ComType);

    m_model->appendRow(subArrayItem);
    m_model->appendRow(phaseShifterItem);
    m_model->appendRow(attenuatorItem);
    m_model->appendRow(amplifierItem);
    m_model->appendRow(waveFilterItem);
    m_model->appendRow(mixerItem);

    connect(ui->componentView, &QListView::clicked, this, &LinkDesignWidget::slotComponentClicked);

}

LinkDesignWidget::~LinkDesignWidget()
{
    delete ui;
}

void LinkDesignWidget::on_addBtn_clicked()
{
    LinkDesignManager::getInstance()->createLinkItem(m_itemType,m_scence);
}


void LinkDesignWidget::on_delBtn_clicked()
{
     LinkDesignManager::getInstance()->deleteLinkItem();
}

void LinkDesignWidget::slotComponentClicked(const QModelIndex &index)
{
    // TODO
    m_itemType = (ItemType)index.data((int)DataType::ComType).toInt();
    qDebug() << " ++++++++++++   " << (int)m_itemType;
}

