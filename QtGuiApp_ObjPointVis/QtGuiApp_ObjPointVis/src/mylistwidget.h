#ifndef MYLISTWIDGET_H
#define MYLISTWIDGET_H


#include <QListWidget>
#include <QListWidgetItem>

#include <QKeyEvent>

#include "vertex.h"
#include "point.h"


class MyListWidget : public QListWidget
{
    Q_OBJECT
public:
    MyListWidget(QWidget *q);

	void keyPressEvent(QKeyEvent *e);

public slots:
      void slot_addItem(QListWidgetItem *);

      void slot_selectItem(QListWidgetItem *);
	  void slot_removeItem(QListWidgetItem *);

	  void slot_selectVertexByIdNum(int);
	  void slot_selectPointByIdNum(int);

	  void slot_highlightItemByRowNum(int);

  signals: 
	  void sig_highlightById(int);

	  void sig_addPoint();
	  void sig_removePoint();

	  void sig_addVertexAsPoint(); //adds the current highlighted Vertex as a point
};

#endif // MYLISTWIDGET_H
