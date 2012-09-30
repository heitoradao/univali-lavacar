#ifndef CONFIGURACAOINICIALDIALOG_H
#define CONFIGURACAOINICIALDIALOG_H

#include <QDialog>
#include <config.h>

namespace Ui {
class ConfiguracaoInicialDialog;
}

class ConfiguracaoInicialDialog : public QDialog
{
    Q_OBJECT    
public:
    explicit ConfiguracaoInicialDialog(QWidget *parent = 0);
    ~ConfiguracaoInicialDialog();
    static Config getConfigInicial();
    virtual void done(int r);

    
private:
    Ui::ConfiguracaoInicialDialog *ui;
    void leInformacoesDoArquivo();
    void gravaInformacoesNoArquivo();
    bool camposValidos();
    static Config config;
};

#endif // CONFIGURACAOINICIALDIALOG_H
