/********************************************************************************
** Form generated from reading UI file 'QtGuiApp_ObjPointVis.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTGUIAPP_OBJPOINTVIS_H
#define UI_QTGUIAPP_OBJPOINTVIS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtGuiApp_ObjPointVisClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtGuiApp_ObjPointVisClass)
    {
        if (QtGuiApp_ObjPointVisClass->objectName().isEmpty())
            QtGuiApp_ObjPointVisClass->setObjectName(QStringLiteral("QtGuiApp_ObjPointVisClass"));
        QtGuiApp_ObjPointVisClass->resize(600, 400);
        menuBar = new QMenuBar(QtGuiApp_ObjPointVisClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        QtGuiApp_ObjPointVisClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtGuiApp_ObjPointVisClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtGuiApp_ObjPointVisClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(QtGuiApp_ObjPointVisClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QtGuiApp_ObjPointVisClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QtGuiApp_ObjPointVisClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtGuiApp_ObjPointVisClass->setStatusBar(statusBar);

        retranslateUi(QtGuiApp_ObjPointVisClass);

        QMetaObject::connectSlotsByName(QtGuiApp_ObjPointVisClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtGuiApp_ObjPointVisClass)
    {
        QtGuiApp_ObjPointVisClass->setWindowTitle(QApplication::translate("QtGuiApp_ObjPointVisClass", "QtGuiApp_ObjPointVis", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtGuiApp_ObjPointVisClass: public Ui_QtGuiApp_ObjPointVisClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGUIAPP_OBJPOINTVIS_H
