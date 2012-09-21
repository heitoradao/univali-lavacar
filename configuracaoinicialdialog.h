#ifndef CONFIGURACAOINICIALDIALOG_H
#define CONFIGURACAOINICIALDIALOG_H

#include <QDialog>

namespace Ui {
class ConfiguracaoInicialDialog;
}

class ConfiguracaoInicialDialog : public QDialog
{
	Q_OBJECT
	
public:
	explicit ConfiguracaoInicialDialog(QWidget *parent = 0);
	~ConfiguracaoInicialDialog();
	
private:
	Ui::ConfiguracaoInicialDialog *ui;
};

#endif // CONFIGURACAOINICIALDIALOG_H
