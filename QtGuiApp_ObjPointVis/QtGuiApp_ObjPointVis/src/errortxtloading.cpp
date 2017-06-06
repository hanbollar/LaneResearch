#include "errortxtloading.h"
#include "ui_errortxtload.h"

ErrorTxtLoading::ErrorTxtLoading(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::Form)
{
	ui->setupUi(this);
}

ErrorTxtLoading::~ErrorTxtLoading()
{
	delete ui;
}

void ErrorTxtLoading::setLineNum(int l) {
	lineNum = l;

	emit sig_lineNum(l);
}
