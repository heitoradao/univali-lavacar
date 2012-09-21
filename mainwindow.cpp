#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "configuracaoinicialdialog.h"

MainWindow::MainWindow(QWidget *parent, QGraphicsScene *scene) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	ui->graphicsView->setScene(scene);
	ConfiguracaoInicialDialog dialog;
	dialog.exec();
}

MainWindow::~MainWindow()
{
	delete ui;
}
