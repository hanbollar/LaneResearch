#ifndef ERRORTXTLOADING_H
#define ERRORTXTLOADING_H

#include <QWidget>

namespace Ui {
class Form;
}

class ErrorTxtLoading : public QWidget
{
    Q_OBJECT

public:
	explicit ErrorTxtLoading(QWidget *parent = 0);
    ~ErrorTxtLoading();

	int lineNum;
	void setLineNum(int);

private:
    Ui::Form *ui;

signals:
	void sig_lineNum(int);
};

#endif // ERRORTXTLOADING_H
