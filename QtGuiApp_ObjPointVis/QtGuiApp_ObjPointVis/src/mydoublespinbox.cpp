#include "mydoublespinbox.h"

MyDoubleSpinBox::MyDoubleSpinBox(QWidget *q) : QDoubleSpinBox(q) {
    this->setFocusPolicy(Qt::ClickFocus);
}

void MyDoubleSpinBox::slot_resetChangePosSpin(double x) {
    QDoubleSpinBox::setValue(x);
}

void MyDoubleSpinBox::slot_DisplayColorRed(double d) {
    QDoubleSpinBox::setValue(d);
    std::cout<<"setting value Red to "<<(d);
}

void MyDoubleSpinBox::slot_DisplayColorGreen(double d) {
    QDoubleSpinBox::setValue(d);
    std::cout<<"setting value Green to "<<(d);
}

void MyDoubleSpinBox::slot_DisplayColorBlue(double d) {
    QDoubleSpinBox::setValue(d);
    std::cout<<"setting value Blue to "<<(d);
}

void MyDoubleSpinBox::slot_needToSendMagnVal() {
    emit sig_sendMagnVal(this->value());
}
