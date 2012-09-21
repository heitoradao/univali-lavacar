#include "configuracaoinicialdialog.h"
#include "ui_configuracaoinicialdialog.h"

ConfiguracaoInicialDialog::ConfiguracaoInicialDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::ConfiguracaoInicialDialog)
{
	ui->setupUi(this);
}

ConfiguracaoInicialDialog::~ConfiguracaoInicialDialog()
{
	delete ui;
}
