/********************************************************************************
** Form generated from reading UI file 'DoesNotLoad.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOESNOTLOAD_H
#define UI_DOESNOTLOAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(366, 48);
        label = new QLabel(Form);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 10, 321, 21));
        label_2 = new QLabel(Form);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(110, 10, 55, 16));

        retranslateUi(Form);
        QObject::connect(Form, SIGNAL(sig_vertexId(int)), label_2, SLOT(setNum(int)));

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("Form", "That Vertex [             ] was already loaded as a point", Q_NULLPTR));
        label_2->setText(QApplication::translate("Form", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOESNOTLOAD_H
