#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "cameracontrolshelp.h"
#include "errortxtloading.h"

#include <QFileDialog>

#include <iostream>
#include <stdio.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->mygl->setFocus();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionQuit_triggered()
{
    QApplication::exit();
}

void MainWindow::on_actionCamera_Controls_triggered()
{
    CameraControlsHelp* c = new CameraControlsHelp();
    c->show();
}

void MainWindow::on_actionLoad_Given_Object_triggered() {
    QString file = QFileDialog::getOpenFileName(this,
             tr("Opening an Object File"), "./_objFiles", tr("OBJ Files (*.obj)"));

    emit sig_filePathString(file);
}

void MainWindow::on_actionLoad_ImportantPoints_triggered() {
	QString file = QFileDialog::getOpenFileName(this,
		tr("Opening a Points Text File"), "./_pointTxtFiles", tr("TEXT Files (*.txt)"));

	emit sig_pointsFilePathString(file);
}

void MainWindow::on_actionSave_ImportantPoints_triggered() {
	QString file = QFileDialog::getSaveFileName(this,
		tr("Opening a Points Text File"), "./_pointTxtFiles", tr("TEXT Files (*.txt)"));

	emit sig_saveCurrentPointsFilePath(file);
}

void MainWindow::slot_txtFileLoadingError(int lineNum)
{
	ErrorTxtLoading* c = new ErrorTxtLoading();
	c->setLineNum(lineNum);
	c->show();
}

void MainWindow::slot_addedPreExistingPointError(int vertexId)
{
	DoesNotLoad* c = new DoesNotLoad();
	c->setVertexId(vertexId);
	c->show();
}

/*void MainWindow::resizeEvent(QResizeEvent* e) {
	int widthDiff = 10;
	int heightDiff = 10;

	int oldWidth = ui->mygl->width();
	int oldHeight = ui->mygl->height();

	if (width() > oldWidth || height() > oldHeight) {
		int newWidth = qMax(width() - widthDiff, oldWidth);
		int newHeight = qMax(height() - heightDiff, oldHeight);
		ui->mygl->resizeGL(newWidth, newHeight);
		update();
	}

	// this->ui->mygl->resizeGL(width() - widthdiff, height() - heightdiff);
	// update();

	// QWidget::resizeEvent(e);
}*/
