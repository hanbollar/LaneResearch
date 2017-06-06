/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>
#include "mygl.h"
#include "mylistwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QAction *actionCamera_Controls;
    QAction *actionLoad_ImportantPoints;
    QAction *actionSave_ImportantPoints;
    QAction *actionLoad_Given_Object;
    QWidget *centralWidget;
    MyListWidget *list_currentObjectVertices;
    QPushButton *button_addByVertexNumber;
    QSpinBox *spinBox_addByVertexNumber;
    QLabel *title_vertices;
    QLabel *title_options;
    QPushButton *button_recenterMyGL;
    QPushButton *button_addPoint;
    MyGL *mygl;
    MyListWidget *list_currentlySelectedPoints;
    QLabel *title_selectedPoints;
    QPushButton *button_removePoint;
    QPushButton *button_removeByPointNumber;
    QSpinBox *spinBox_removeByPointNumber;
    QLabel *label_currentlySelectedVertex;
    QLabel *label_xPosition;
    QLabel *label_yPosition;
    QLabel *label_zPosition;
    QLabel *label_xPVal;
    QLabel *label_yPVal;
    QLabel *label_zPVal;
    QCheckBox *checkBox_viewPoints;
    QCheckBox *checkBox_viewObjVertices;
    QCheckBox *checkBox_viewMesh;
    QCheckBox *checkBox_createPoints;
    QLabel *label;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1284, 606);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionCamera_Controls = new QAction(MainWindow);
        actionCamera_Controls->setObjectName(QStringLiteral("actionCamera_Controls"));
        actionLoad_ImportantPoints = new QAction(MainWindow);
        actionLoad_ImportantPoints->setObjectName(QStringLiteral("actionLoad_ImportantPoints"));
        actionSave_ImportantPoints = new QAction(MainWindow);
        actionSave_ImportantPoints->setObjectName(QStringLiteral("actionSave_ImportantPoints"));
        actionLoad_Given_Object = new QAction(MainWindow);
        actionLoad_Given_Object->setObjectName(QStringLiteral("actionLoad_Given_Object"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        list_currentObjectVertices = new MyListWidget(centralWidget);
        list_currentObjectVertices->setObjectName(QStringLiteral("list_currentObjectVertices"));
        list_currentObjectVertices->setGeometry(QRect(1150, 50, 101, 501));
        button_addByVertexNumber = new QPushButton(centralWidget);
        button_addByVertexNumber->setObjectName(QStringLiteral("button_addByVertexNumber"));
        button_addByVertexNumber->setGeometry(QRect(590, 140, 121, 28));
        spinBox_addByVertexNumber = new QSpinBox(centralWidget);
        spinBox_addByVertexNumber->setObjectName(QStringLiteral("spinBox_addByVertexNumber"));
        spinBox_addByVertexNumber->setGeometry(QRect(720, 140, 71, 22));
        spinBox_addByVertexNumber->setMaximum(999999999);
        title_vertices = new QLabel(centralWidget);
        title_vertices->setObjectName(QStringLiteral("title_vertices"));
        title_vertices->setGeometry(QRect(1160, 30, 71, 20));
        title_vertices->setMaximumSize(QSize(259, 487));
        title_options = new QLabel(centralWidget);
        title_options->setObjectName(QStringLiteral("title_options"));
        title_options->setGeometry(QRect(630, 20, 61, 41));
        button_recenterMyGL = new QPushButton(centralWidget);
        button_recenterMyGL->setObjectName(QStringLiteral("button_recenterMyGL"));
        button_recenterMyGL->setGeometry(QRect(590, 320, 121, 28));
        button_addPoint = new QPushButton(centralWidget);
        button_addPoint->setObjectName(QStringLiteral("button_addPoint"));
        button_addPoint->setGeometry(QRect(590, 60, 121, 28));
        mygl = new MyGL(centralWidget);
        mygl->setObjectName(QStringLiteral("mygl"));
        mygl->setEnabled(true);
        mygl->setGeometry(QRect(20, 10, 550, 550));
        mygl->setMinimumSize(QSize(0, 489));
        mygl->setStyleSheet(QStringLiteral("width: 200px, height 10px"));
        list_currentlySelectedPoints = new MyListWidget(centralWidget);
        list_currentlySelectedPoints->setObjectName(QStringLiteral("list_currentlySelectedPoints"));
        list_currentlySelectedPoints->setGeometry(QRect(800, 50, 331, 501));
        title_selectedPoints = new QLabel(centralWidget);
        title_selectedPoints->setObjectName(QStringLiteral("title_selectedPoints"));
        title_selectedPoints->setGeometry(QRect(920, 30, 91, 20));
        title_selectedPoints->setMaximumSize(QSize(259, 487));
        button_removePoint = new QPushButton(centralWidget);
        button_removePoint->setObjectName(QStringLiteral("button_removePoint"));
        button_removePoint->setGeometry(QRect(590, 100, 121, 28));
        button_removeByPointNumber = new QPushButton(centralWidget);
        button_removeByPointNumber->setObjectName(QStringLiteral("button_removeByPointNumber"));
        button_removeByPointNumber->setGeometry(QRect(590, 180, 121, 28));
        spinBox_removeByPointNumber = new QSpinBox(centralWidget);
        spinBox_removeByPointNumber->setObjectName(QStringLiteral("spinBox_removeByPointNumber"));
        spinBox_removeByPointNumber->setGeometry(QRect(720, 180, 71, 22));
        spinBox_removeByPointNumber->setMaximum(999999999);
        label_currentlySelectedVertex = new QLabel(centralWidget);
        label_currentlySelectedVertex->setObjectName(QStringLiteral("label_currentlySelectedVertex"));
        label_currentlySelectedVertex->setGeometry(QRect(590, 420, 161, 16));
        label_xPosition = new QLabel(centralWidget);
        label_xPosition->setObjectName(QStringLiteral("label_xPosition"));
        label_xPosition->setGeometry(QRect(590, 440, 55, 16));
        label_yPosition = new QLabel(centralWidget);
        label_yPosition->setObjectName(QStringLiteral("label_yPosition"));
        label_yPosition->setGeometry(QRect(590, 460, 55, 16));
        label_zPosition = new QLabel(centralWidget);
        label_zPosition->setObjectName(QStringLiteral("label_zPosition"));
        label_zPosition->setGeometry(QRect(590, 480, 55, 16));
        label_xPVal = new QLabel(centralWidget);
        label_xPVal->setObjectName(QStringLiteral("label_xPVal"));
        label_xPVal->setGeometry(QRect(620, 440, 55, 16));
        label_xPVal->setStyleSheet(QStringLiteral("qproperty-alignment:AlignRight;"));
        label_yPVal = new QLabel(centralWidget);
        label_yPVal->setObjectName(QStringLiteral("label_yPVal"));
        label_yPVal->setGeometry(QRect(620, 460, 55, 16));
        label_yPVal->setStyleSheet(QStringLiteral("qproperty-alignment:AlignRight;"));
        label_zPVal = new QLabel(centralWidget);
        label_zPVal->setObjectName(QStringLiteral("label_zPVal"));
        label_zPVal->setGeometry(QRect(620, 480, 55, 16));
        label_zPVal->setStyleSheet(QStringLiteral("qproperty-alignment:AlignRight;"));
        checkBox_viewPoints = new QCheckBox(centralWidget);
        checkBox_viewPoints->setObjectName(QStringLiteral("checkBox_viewPoints"));
        checkBox_viewPoints->setEnabled(true);
        checkBox_viewPoints->setGeometry(QRect(590, 230, 111, 20));
        checkBox_viewPoints->setChecked(true);
        checkBox_viewObjVertices = new QCheckBox(centralWidget);
        checkBox_viewObjVertices->setObjectName(QStringLiteral("checkBox_viewObjVertices"));
        checkBox_viewObjVertices->setEnabled(true);
        checkBox_viewObjVertices->setGeometry(QRect(590, 260, 121, 20));
        checkBox_viewObjVertices->setChecked(true);
        checkBox_viewMesh = new QCheckBox(centralWidget);
        checkBox_viewMesh->setObjectName(QStringLiteral("checkBox_viewMesh"));
        checkBox_viewMesh->setEnabled(true);
        checkBox_viewMesh->setGeometry(QRect(590, 290, 121, 20));
        checkBox_viewMesh->setChecked(true);
        checkBox_createPoints = new QCheckBox(centralWidget);
        checkBox_createPoints->setObjectName(QStringLiteral("checkBox_createPoints"));
        checkBox_createPoints->setEnabled(true);
        checkBox_createPoints->setGeometry(QRect(590, 390, 211, 20));
        checkBox_createPoints->setChecked(true);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(590, 509, 201, 51));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1284, 26));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionLoad_Given_Object);
        menuFile->addAction(actionLoad_ImportantPoints);
        menuFile->addAction(actionSave_ImportantPoints);
        menuFile->addAction(actionQuit);
        menuHelp->addAction(actionCamera_Controls);

        retranslateUi(MainWindow);
        QObject::connect(MainWindow, SIGNAL(sig_filePathString(QString)), mygl, SLOT(slot_loadFileData(QString)));
        QObject::connect(mygl, SIGNAL(sig_clearVertexList()), list_currentObjectVertices, SLOT(clear()));
        QObject::connect(mygl, SIGNAL(sig_addVertex(QListWidgetItem*)), list_currentObjectVertices, SLOT(slot_addItem(QListWidgetItem*)));
        QObject::connect(list_currentObjectVertices, SIGNAL(itemClicked(QListWidgetItem*)), mygl, SLOT(slot_vertexItemClicked(QListWidgetItem*)));
        QObject::connect(mygl, SIGNAL(sig_vertexChanged(QListWidgetItem*)), list_currentObjectVertices, SLOT(slot_selectItem(QListWidgetItem*)));
        QObject::connect(button_recenterMyGL, SIGNAL(clicked()), mygl, SLOT(slot_recenter()));
        QObject::connect(mygl, SIGNAL(sig_addPoint(QListWidgetItem*)), list_currentlySelectedPoints, SLOT(slot_addItem(QListWidgetItem*)));
        QObject::connect(mygl, SIGNAL(sig_removeSelectedVertPoint(QListWidgetItem*)), list_currentlySelectedPoints, SLOT(slot_removeItem(QListWidgetItem*)));
        QObject::connect(list_currentlySelectedPoints, SIGNAL(itemClicked(QListWidgetItem*)), list_currentObjectVertices, SLOT(clearSelection()));
        QObject::connect(list_currentObjectVertices, SIGNAL(itemClicked(QListWidgetItem*)), list_currentlySelectedPoints, SLOT(clearSelection()));
        QObject::connect(list_currentlySelectedPoints, SIGNAL(itemClicked(QListWidgetItem*)), mygl, SLOT(slot_interestPointItemClicked(QListWidgetItem*)));
        QObject::connect(list_currentObjectVertices, SIGNAL(sig_highlightById(int)), mygl, SLOT(slot_highlightVertexById(int)));
        QObject::connect(MainWindow, SIGNAL(sig_pointsFilePathString(QString)), mygl, SLOT(slot_loadPointsFromTxt(QString)));
        QObject::connect(mygl, SIGNAL(sig_clearPointList()), list_currentlySelectedPoints, SLOT(clear()));
        QObject::connect(MainWindow, SIGNAL(sig_saveCurrentPointsFilePath(QString)), mygl, SLOT(slot_savePointsToTxt(QString)));
        QObject::connect(mygl, SIGNAL(sig_invalidTxtFileLine(int)), MainWindow, SLOT(slot_txtFileLoadingError(int)));
        QObject::connect(mygl, SIGNAL(sig_DisplayPosX(double)), label_xPVal, SLOT(setNum(double)));
        QObject::connect(mygl, SIGNAL(sig_DisplayPosY(double)), label_yPVal, SLOT(setNum(double)));
        QObject::connect(mygl, SIGNAL(sig_DisplayPosZ(double)), label_zPVal, SLOT(setNum(double)));
        QObject::connect(list_currentObjectVertices, SIGNAL(currentRowChanged(int)), list_currentObjectVertices, SLOT(slot_highlightItemByRowNum(int)));
        QObject::connect(list_currentlySelectedPoints, SIGNAL(currentRowChanged(int)), list_currentlySelectedPoints, SLOT(slot_highlightItemByRowNum(int)));
        QObject::connect(checkBox_viewPoints, SIGNAL(clicked(bool)), mygl, SLOT(slot_viewPointsSet(bool)));
        QObject::connect(list_currentlySelectedPoints, SIGNAL(sig_removePoint()), mygl, SLOT(slot_removedInterestPoint()));
        QObject::connect(checkBox_viewObjVertices, SIGNAL(clicked(bool)), mygl, SLOT(slot_viewObjVertices(bool)));
        QObject::connect(list_currentlySelectedPoints, SIGNAL(sig_highlightById(int)), mygl, SLOT(slot_highlightPointById(int)));
        QObject::connect(list_currentObjectVertices, SIGNAL(sig_addVertexAsPoint()), mygl, SLOT(slot_addPointFromVertex()));
        QObject::connect(button_addPoint, SIGNAL(clicked()), mygl, SLOT(slot_addPointFromVertex()));
        QObject::connect(button_removePoint, SIGNAL(clicked()), mygl, SLOT(slot_removedInterestPoint()));
        QObject::connect(spinBox_addByVertexNumber, SIGNAL(valueChanged(int)), mygl, SLOT(slot_highlightVertexById(int)));
        QObject::connect(button_addByVertexNumber, SIGNAL(clicked()), mygl, SLOT(slot_addPointFromVertex()));
        QObject::connect(spinBox_removeByPointNumber, SIGNAL(valueChanged(int)), mygl, SLOT(slot_highlightPointById(int)));
        QObject::connect(button_removeByPointNumber, SIGNAL(clicked()), mygl, SLOT(slot_removedInterestPoint()));
        QObject::connect(checkBox_viewMesh, SIGNAL(clicked(bool)), mygl, SLOT(slot_viewMesh(bool)));
        QObject::connect(mygl, SIGNAL(sig_preExistingVertex(int)), MainWindow, SLOT(slot_addedPreExistingPointError(int)));
        QObject::connect(checkBox_createPoints, SIGNAL(clicked(bool)), mygl, SLOT(slot_creatingPoints(bool)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "OpenGLDemo", Q_NULLPTR));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", Q_NULLPTR));
        actionQuit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", Q_NULLPTR));
        actionCamera_Controls->setText(QApplication::translate("MainWindow", "Camera Controls", Q_NULLPTR));
        actionCamera_Controls->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", Q_NULLPTR));
        actionLoad_ImportantPoints->setText(QApplication::translate("MainWindow", "Load Points", Q_NULLPTR));
        actionLoad_ImportantPoints->setShortcut(QApplication::translate("MainWindow", "P", Q_NULLPTR));
        actionSave_ImportantPoints->setText(QApplication::translate("MainWindow", "Save Points", Q_NULLPTR));
        actionSave_ImportantPoints->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", Q_NULLPTR));
        actionLoad_Given_Object->setText(QApplication::translate("MainWindow", "Load Object", Q_NULLPTR));
        actionLoad_Given_Object->setShortcut(QApplication::translate("MainWindow", "O", Q_NULLPTR));
        button_addByVertexNumber->setText(QApplication::translate("MainWindow", "Add By Num", Q_NULLPTR));
        title_vertices->setText(QApplication::translate("MainWindow", "All Vertices", Q_NULLPTR));
        title_options->setText(QApplication::translate("MainWindow", "Options", Q_NULLPTR));
        button_recenterMyGL->setText(QApplication::translate("MainWindow", "Recenter the View", Q_NULLPTR));
        button_addPoint->setText(QApplication::translate("MainWindow", "Add Point", Q_NULLPTR));
        title_selectedPoints->setText(QApplication::translate("MainWindow", "Selected Points", Q_NULLPTR));
        button_removePoint->setText(QApplication::translate("MainWindow", "Remove Point", Q_NULLPTR));
        button_removeByPointNumber->setText(QApplication::translate("MainWindow", "Remove By Num", Q_NULLPTR));
        label_currentlySelectedVertex->setText(QApplication::translate("MainWindow", "Currently Selected Item:", Q_NULLPTR));
        label_xPosition->setText(QApplication::translate("MainWindow", "X:", Q_NULLPTR));
        label_yPosition->setText(QApplication::translate("MainWindow", "Y:", Q_NULLPTR));
        label_zPosition->setText(QApplication::translate("MainWindow", "Z:", Q_NULLPTR));
        label_xPVal->setText(QString());
        label_yPVal->setText(QString());
        label_zPVal->setText(QString());
        checkBox_viewPoints->setText(QApplication::translate("MainWindow", "View Points", Q_NULLPTR));
        checkBox_viewObjVertices->setText(QApplication::translate("MainWindow", "View All Vertices", Q_NULLPTR));
        checkBox_viewMesh->setText(QApplication::translate("MainWindow", "View Mesh", Q_NULLPTR));
        checkBox_createPoints->setText(QApplication::translate("MainWindow", "On: Click to Create Points", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Use Clicking for Movement or\n"
"Press Keys for movement. See \n"
"Camera Controls for more Info.", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
