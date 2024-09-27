#include "LinkDesignManager.h"
#include "SubArrayLinkItem.h"
#include <QGraphicsScene>

std::once_flag LinkDesignManager::m_flag;
LinkDesignManager* LinkDesignManager::m_pInstance = nullptr;
LinkDesignManager *LinkDesignManager::getInstance()
{
    std::call_once(m_flag, [] {
        m_pInstance = new LinkDesignManager;
    });
    return m_pInstance;
}

void LinkDesignManager::createLinkItem(ItemType type,QGraphicsScene* scene)
{
    switch(type){
    case ItemType::SubArray:
        auto subArray = new SubArrayLinkItem(count++);
        subArray->setPosition(QPointF(60 *count ,100));
        scene->addItem(subArray);
        m_LinkItems.push_back(QSharedPointer<BaseLinkItem>(subArray));

        break;
    defult:
        return;
    }
}

// 后面如果要删除多个，写个deleteLinkItems调用下面的接口
void LinkDesignManager::deleteLinkItem(const QSharedPointer<BaseLinkItem>& linkItem)
{
    Q_UNUSED(linkItem); // 后期考虑右击选中
    int delIdx = -1; // -1 无效
    int isize = m_LinkItems.size();
    for (int i = 0; i < isize; ++i) {
        if(m_LinkItems[i]->isPickup()) {
            count--;
            m_LinkItems.remove(i);
            delIdx = i;
            break;
        }
    }

    for (int i = 0; i < isize - 1; ++i) {
        if(delIdx < 0) {
            break;
        }
        if(i >= delIdx) {
            QPointF pos;
            pos.setX(m_LinkItems[i]->pos().x() - m_LinkItems[i]->rect().width());
            pos.setY(m_LinkItems[i]->pos().y());
            m_LinkItems[i]->setPosition(pos);
            m_LinkItems[i]->setId(m_LinkItems[i]->getId() - 1);
        }
    }
}

QVector<QSharedPointer<BaseLinkItem> > LinkDesignManager::getLinkItems()
{
    return m_LinkItems;
}

bool LinkDesignManager::rebuildLinks(int sId, int dId)
{
    if(sId == dId) {
        return false;
    }

    qDebug() << "sId = " << sId << "   " << "dId = " << dId;
    // 左移，引起其他节点右移
    auto desLinkItem = getLinkItem(dId);
    QPointF desPos(desLinkItem->pos());
    if(sId > dId) {
        for(auto item : m_LinkItems) {
            if(item->getId() >= dId && item->getId() < sId) {
                QPointF pos;
                pos.setX(item->pos().x() + item->rect().width());
                pos.setY(item->pos().y());
                item->setPosition(pos);
                item->setId(item->getId() + 1);
            }else if(item->getId() == sId) {
                item->setPosition(desPos);
                item->setId(dId);
            }else{
                // do nothing
            }
        }
    }
    else // 右移，引起其他节点左移
    {
        for(auto item : m_LinkItems) {
            qDebug() << "item->getId() = " << item->getId()
                     <<  "sId = " << sId << "dId = " << dId;
            if(item->getId() > sId && item->getId() <= dId) {
                QPointF pos;
                pos.setX(item->pos().x() - item->rect().width());
                pos.setY(item->pos().y());
                item->setPosition(pos);
                item->setId(item->getId() - 1);
            }else if(item->getId() == sId) {
                item->setPosition(desPos);
                item->setId(dId);
            } else{
                // do nothing
            }
        }
    }

    return true;
}

QSharedPointer<BaseLinkItem> LinkDesignManager::getLinkItem(int id)
{
    auto iter = std::find_if(m_LinkItems.begin(),m_LinkItems.end(),[=](QSharedPointer<BaseLinkItem> paraItem){
        return paraItem->getId() == id ? true : false;
    });

    if(iter != m_LinkItems.end()) {

        return *iter;
    }
    return nullptr;
}

void LinkDesignManager::dePickUpAll()
{
    for(auto item : m_LinkItems) {
        item->setPickup(false);
    }
}

void LinkDesignManager::pickUpOne(int id)
{
    for(auto item : m_LinkItems) {
        if (item->getId() == id) {
            if(!item->isPickup()) {
                item->setPen(QPen(Qt::green));
                item->setPickup(true);
            }else{
                item->setPen(QPen(Qt::black));
                item->setPickup(false);
            }
        }else {
            item->setPen(QPen(Qt::black));
            item->setPickup(false);
        }
    }
}

LinkDesignManager::LinkDesignManager()
{

}

LinkDesignManager::~LinkDesignManager()
{

}
