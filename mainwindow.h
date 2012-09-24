#ifndef MAINWINDOW_H
#define MAINWINDOW_H

class QGraphicsScene;

namespace Ui {
class MainWindow;
}
#include <QMainWindow>
#include "lavacao.h"
#include <QGraphicsScene>
#include <QTextStream>

/*!
 * \brief The MainWindow class
 */
class MainWindow : public QMainWindow
{
	Q_OBJECT
	
public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();
	
private slots:
    void on_actionStop_triggered();

private:
	Ui::MainWindow *ui;
	Lavacao *lavacao;
    QTextStream output;
	QGraphicsScene scene;
};

#endif // MAINWINDOW_H
