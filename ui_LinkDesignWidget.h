/********************************************************************************
** Form generated from reading UI file 'LinkDesignWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINKDESIGNWIDGET_H
#define UI_LINKDESIGNWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <antenna2dview.h>

QT_BEGIN_NAMESPACE

class Ui_LinkDesignWidget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *addBtn;
    QPushButton *delBtn;
    QSpacerItem *horizontalSpacer;
    QSplitter *splitter;
    QListView *componentView;
    Antenna2DView *designWidget;

    void setupUi(QWidget *LinkDesignWidget)
    {
        if (LinkDesignWidget->objectName().isEmpty())
            LinkDesignWidget->setObjectName("LinkDesignWidget");
        LinkDesignWidget->resize(652, 457);
        verticalLayout = new QVBoxLayout(LinkDesignWidget);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        addBtn = new QPushButton(LinkDesignWidget);
        addBtn->setObjectName("addBtn");

        horizontalLayout_2->addWidget(addBtn);

        delBtn = new QPushButton(LinkDesignWidget);
        delBtn->setObjectName("delBtn");

        horizontalLayout_2->addWidget(delBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);

        splitter = new QSplitter(LinkDesignWidget);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Orientation::Horizontal);
        componentView = new QListView(splitter);
        componentView->setObjectName("componentView");
        splitter->addWidget(componentView);
        designWidget = new Antenna2DView(splitter);
        designWidget->setObjectName("designWidget");
        splitter->addWidget(designWidget);

        verticalLayout->addWidget(splitter);


        retranslateUi(LinkDesignWidget);

        QMetaObject::connectSlotsByName(LinkDesignWidget);
    } // setupUi

    void retranslateUi(QWidget *LinkDesignWidget)
    {
        LinkDesignWidget->setWindowTitle(QCoreApplication::translate("LinkDesignWidget", "Form", nullptr));
        addBtn->setText(QCoreApplication::translate("LinkDesignWidget", "Add", nullptr));
        delBtn->setText(QCoreApplication::translate("LinkDesignWidget", "Del", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LinkDesignWidget: public Ui_LinkDesignWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINKDESIGNWIDGET_H
