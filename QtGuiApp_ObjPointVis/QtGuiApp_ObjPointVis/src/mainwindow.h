#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


#include <qevent.h>
#include <qwidget.h>

#include "doesnotload.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionQuit_triggered();
    void on_actionCamera_Controls_triggered();
    void on_actionLoad_Given_Object_triggered();

	void on_actionLoad_ImportantPoints_triggered();
	void on_actionSave_ImportantPoints_triggered();

	void slot_txtFileLoadingError(int);
	void slot_addedPreExistingPointError(int);

private:
    Ui::MainWindow *ui;

protected:
	//void MainWindow::resizeEvent(QResizeEvent* e);

signals:
    void sig_filePathString(QString);
	void sig_pointsFilePathString(QString);
	void sig_saveCurrentPointsFilePath(QString);
};


#endif // MAINWINDOW_H
