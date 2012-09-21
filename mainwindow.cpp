#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "configuracaoinicialdialog.h"

MainWindow::MainWindow(QWidget *parent)
	:QMainWindow(parent)
	,ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	ConfiguracaoInicialDialog dialog;
	dialog.exec();
	ui->graphicsView->setScene(&scene);
	lavacao = new Lavacao(this, &scene);
}

MainWindow::~MainWindow()
{
	delete ui;
}
