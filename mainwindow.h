#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStack>
#include <QFileDialog>
#include <QTextStream>
#include <Vec.h>
#include <Mat.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();
	Mat toPostfix(QString &inputStr);
	void calc(QString &inst,QStack<Mat> &numStack);

private slots:
	void on_pushButton_clicked();

	void on_actionOpen_triggered();

	void on_lineEdit_returnPressed();

	void on_comboBox_3_activated(const QString &arg1);

	void on_comboBox_activated(const QString &arg1);

	void on_comboBox_2_activated(const QString &arg1);

	void on_pushButton_2_clicked();

	void on_pushButton_3_clicked();

	void on_pushButton_4_clicked();

	void on_pushButton_5_clicked();

	void on_actionSave_triggered();

private:
	Ui::MainWindow *ui;
	QVector<Vec> v;
	QVector<Mat> m;
};

#endif // MAINWINDOW_H
