#ifndef MAINWINDOW_H
#define MAINWINDOW_H

class QGraphicsScene;

namespace Ui {
class MainWindow;
}
#include <QMainWindow>

/*!
 * \brief The MainWindow class
 */
class MainWindow : public QMainWindow
{
	Q_OBJECT
	
public:
	explicit MainWindow(QWidget *parent = 0, QGraphicsScene *scene = 0);
	~MainWindow();
	
private:
	Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
