#ifndef MYDOUBLESPINBOX_H
#define MYDOUBLESPINBOX_H

#include <QSpinBox>
#include "la.h"
#include <iostream>

class MyDoubleSpinBox : public QDoubleSpinBox
{
    Q_OBJECT
public:
    MyDoubleSpinBox(QWidget *q);

public slots:
    void slot_resetChangePosSpin(double);
    //void slot_resetChangeColSpins(double); - dont use (DNW)
    void slot_DisplayColorRed(double);
    void slot_DisplayColorGreen(double);
    void slot_DisplayColorBlue(double);

    void slot_needToSendMagnVal();

signals:
    void sig_sendMagnVal(double);
};

#endif // MYDOUBLESPINBOX_H
