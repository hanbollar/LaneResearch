#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtGuiApp_ObjPointVis.h"

class QtGuiApp_ObjPointVis : public QMainWindow
{
	Q_OBJECT

public:
	QtGuiApp_ObjPointVis(QWidget *parent = Q_NULLPTR);

private:
	Ui::QtGuiApp_ObjPointVisClass ui;
};
