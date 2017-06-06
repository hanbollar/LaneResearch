#ifndef DOESNOTLOAD_H
#define DOESNOTLOAD_H

#include <QWidget>

namespace Ui {
	class Form;
}

class DoesNotLoad : public QWidget
{
	Q_OBJECT

public:
	explicit DoesNotLoad(QWidget *parent = 0);
	~DoesNotLoad();

	int vertexId;
	void setVertexId(int);

private:
	Ui::Form *ui;

signals:
	void sig_vertexId(int);
};

#endif // ERRORTXTLOADING_H
