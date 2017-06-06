#include "doesnotload.h"
#include "ui_doesnotload.h"

DoesNotLoad::DoesNotLoad(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::Form)
{
	ui->setupUi(this);
}

DoesNotLoad::~DoesNotLoad()
{
	delete ui;
}

void DoesNotLoad::setVertexId(int l) {
	vertexId = l;

	emit sig_vertexId(l);
}
