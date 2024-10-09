#ifndef LINKDESIGNMANAGER_H
#define LINKDESIGNMANAGER_H
#include <functional>
#include "linkdesign_common.h"
#include "linkItem\BaseLinkItem.h"
class QGraphicsScene;
class LinkDesignManager
{
public:
    static LinkDesignManager* getInstance();

    void createLinkItem(ItemType type, QGraphicsScene* scene);
    void deleteLinkItem(const QSharedPointer<BaseLinkItem>& linkItem = nullptr);
    QVector<QSharedPointer<BaseLinkItem>> getLinkItems();
    bool rebuildLinks(int sId, int dId);
    QSharedPointer<BaseLinkItem> getLinkItem(int id);
    void dePickUpAll();
    void pickUpOne(int id);
private:
    LinkDesignManager();
    ~LinkDesignManager();
    LinkDesignManager(const LinkDesignManager&) = delete;
    LinkDesignManager& operator=(const LinkDesignManager&) = delete;
private:
    static LinkDesignManager* m_pInstance;
    static std::once_flag m_flag;

    QVector<QSharedPointer<BaseLinkItem>> m_LinkItems;
    int count = 0;
};

#endif // LINKDESIGNMANAGER_H
