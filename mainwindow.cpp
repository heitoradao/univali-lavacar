#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "configuracaoinicialdialog.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
	:QMainWindow(parent)
    ,output(stdout, QIODevice::WriteOnly)
	,ui(new Ui::MainWindow)
{
	ui->setupUi(this);
    Config config = ConfiguracaoInicialDialog::getConfigInicial();
	ui->graphicsView->setScene(&scene);
    lavacao = new Lavacao(&output, config, this, &scene);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_actionStop_triggered()
{
    lavacao->encerraSimulacao();
}

void MainWindow::on_actionSobre_triggered()
{
    QMessageBox::information(this, "", trUtf8("Trabalho de simulação discreta.\n"
                                              "Docentes: Maira Stella da Silva\n"
                                              "          Heitor Adão Júnior"));
}
