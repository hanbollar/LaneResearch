#include "mylistwidget.h"
#include <stdio.h>
#include <iostream>

MyListWidget::MyListWidget(QWidget* q) : QListWidget(q) {
    this->setFocusPolicy(Qt::ClickFocus);
}

void MyListWidget::slot_addItem(QListWidgetItem * it) {
    QListWidget::addItem(it);
}

void MyListWidget::slot_selectItem(QListWidgetItem * it) {
    QListWidget::setCurrentItem(it);
}

void MyListWidget::slot_removeItem(QListWidgetItem * it) {
	int idNum = ((Vertex*)(it))->id;

	bool looking = true;
	int count = QListWidget::count();
	for (int i = 0; i < count && looking; i++) {
		Vertex* v = (Vertex*)(QListWidget::item(i));
		if (v->id == idNum) {
			QListWidget::takeItem(i);
			if (QListWidget::currentRow() > 0) {
				slot_highlightItemByRowNum(QListWidget::currentRow());
			}
			looking = false;
		}
	}
}

void MyListWidget::slot_selectVertexByIdNum(int idNum) {
	bool looking = true;
	int count = QListWidget::count();

	for (int i = 0; i < count && looking; i++) {
		if (((Vertex*)(QListWidget::item(i)))->id == idNum) {
			QListWidget::setCurrentRow(i);
			looking = false;
			emit sig_highlightById(idNum);
		}
	}
}

void MyListWidget::slot_selectPointByIdNum(int idNum) {
	bool looking = true;
	int count = QListWidget::count();

	for (int i = 0; i < count && looking; i++) {
		if (((Point*)(QListWidget::item(i)))->id == idNum) {
			QListWidget::setCurrentRow(i);
			looking = false;
			emit sig_highlightById(idNum);
		}
	}
}

void MyListWidget::slot_highlightItemByRowNum(int num) {
	emit QListWidget::itemClicked(QListWidget::item(num));
}

void MyListWidget::keyPressEvent(QKeyEvent *e) {
	float amount = 2.0f;
	if (e->modifiers() & Qt::ShiftModifier) {
		amount = 10.0f;
	}

	if (e->key() == Qt::Key_Enter || e->key() == Qt::Key_Return) {
		sig_addVertexAsPoint();
	}else if (e->key() == Qt::Key_Delete || e->key() == Qt::Key_Backspace) {
		sig_removePoint();
	// up arrow or w pressed: go up
	} else if (e->key() == Qt::Key_Up || e->key() == Qt::Key_W) {
		if (QListWidget::currentRow() > 0) {
			QListWidget::setCurrentRow(QListWidget::currentRow() - 1);
			slot_highlightItemByRowNum(QListWidget::currentRow());
		}
	// down arrow or s pressed: go down
	} else if (e->key() == Qt::Key_Down || e->key() == Qt::Key_S) {
		if (QListWidget::currentRow() < QListWidget::count() - 1) {
			QListWidget::setCurrentRow(QListWidget::currentRow() + 1);
			slot_highlightItemByRowNum(QListWidget::currentRow());
		}
	}
}
