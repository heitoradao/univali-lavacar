#ifndef MAINWINDOW_H
#define MAINWINDOW_H

class QGraphicsScene;

namespace Ui {
class MainWindow;
}
#include <QMainWindow>
#include "lavacao.h"
#include <QGraphicsScene>

/*!
 * \brief The MainWindow class
 */
class MainWindow : public QMainWindow
{
	Q_OBJECT
	
public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();
	
private:
	Ui::MainWindow *ui;
	QTimer timer;
	Lavacao *lavacao;
	QGraphicsScene scene;
};

#endif // MAINWINDOW_H
