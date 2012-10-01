#include "configuracaoinicialdialog.h"
#include "ui_configuracaoinicialdialog.h"
#include "QSettings"
#include <stdexcept>
#include <QMessageBox>

Config ConfiguracaoInicialDialog::config;

ConfiguracaoInicialDialog::ConfiguracaoInicialDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfiguracaoInicialDialog)
{
    ui->setupUi(this);
    leInformacoesDoArquivo();
    ui->comboBoxTecDistribuicao->setCurrentIndex(config.distribuicaoTEC);
    ui->spinBoxTecParametro1->setValue(config.parametroATEC);
    ui->spinBoxTecParametro2->setValue(config.parametroBTEC);
    ui->spinBoxTecParametro3->setValue(config.parametroCTEC);
    ui->comboBoxTsDistribuicao->setCurrentIndex(config.distribuicaoTS);
    ui->spinBoxTsParametro1->setValue(config.parametroATS);
    ui->spinBoxTsParametro2->setValue(config.parametroBTS);
    ui->spinBoxTsParametro3->setValue(config.parametroCTS);
    ui->spinBoxTempoSimulacao->setValue(config.tempoSimulacao);
}

ConfiguracaoInicialDialog::~ConfiguracaoInicialDialog()
{
    gravaInformacoesNoArquivo();
    delete ui;
}

Config ConfiguracaoInicialDialog::getConfigInicial()
{
    ConfiguracaoInicialDialog dialog;
    dialog.exec();
    return ConfiguracaoInicialDialog::config;
}

void ConfiguracaoInicialDialog::done(int r)
{
    config.distribuicaoTEC = (TipoDistribuicao) ui->comboBoxTecDistribuicao->currentIndex();
    config.parametroATEC = ui->spinBoxTecParametro1->value();
    config.parametroBTEC = ui->spinBoxTecParametro2->value();
    config.parametroCTEC = ui->spinBoxTecParametro3->value();

    config.distribuicaoTS = (TipoDistribuicao) ui->comboBoxTsDistribuicao->currentIndex();
    config.parametroATS = ui->spinBoxTsParametro1->value();
    config.parametroBTS = ui->spinBoxTsParametro2->value();
    config.parametroCTS = ui->spinBoxTsParametro3->value();
    config.tempoSimulacao = ui->spinBoxTempoSimulacao->value();

    config.filaLimitada = ui->checkBoxFilaLimitada->isChecked();
    config.limiteFila = ui->spinBoxLimiteFila->value();

    if (ui->comboBoxRapidez->currentIndex() == 0)
        config.rapidezAnimacao = 0.33;
    else if (ui->comboBoxRapidez->currentIndex() == 1)
        config.rapidezAnimacao = 0.5;
    else if (ui->comboBoxRapidez->currentIndex() >= 2)
        config.rapidezAnimacao = ui->comboBoxRapidez->currentIndex() - 1;


    if (!camposValidos()) {
        QMessageBox::critical(this, "", trUtf8("os valores dos campos estão inválidos.\n"
                                               "As parametros 1, 2 e 3 precisam estar em ordem crescente."));
        return;
    }
    QDialog::done(r);
}

void ConfiguracaoInicialDialog::leInformacoesDoArquivo()
{
    QSettings settings("config.ini", QSettings::IniFormat);

    settings.beginGroup("lavacar");
    QString distribuicaoTec(settings.value("distribuicao_TEC", "constante").toString());

    if (distribuicaoTec == "exponencial")
        config.distribuicaoTEC = EXPONENCIAL;
    else if (distribuicaoTec == "log")
        config.distribuicaoTEC = LOG;
    else if (distribuicaoTec == "normal")
        config.distribuicaoTEC = NORMAL;
    else if (distribuicaoTec == "triangular")
        config.distribuicaoTEC = TRIANGULAR;
    else if (distribuicaoTec == "uniform")
        config.distribuicaoTEC = UNIFORME;
    else {
        config.distribuicaoTEC = CONSTANTE;
    }
    config.parametroATEC = settings.value("parametro_TEC_1", 1).toDouble();
    config.parametroBTEC = settings.value("parametro_TEC_2", 1).toDouble();
    config.parametroCTEC = settings.value("parametro_TEC_3", 1).toDouble();
    //------------------------------
    QString distribuicaoTs(settings.value("distribuicao_TS", "constante").toString());

    if (distribuicaoTs == "exponencial")
        config.distribuicaoTS = EXPONENCIAL;
    else if (distribuicaoTs == "log")
        config.distribuicaoTS = LOG;
    else if (distribuicaoTs == "normal")
        config.distribuicaoTS = NORMAL;
    else if (distribuicaoTs == "triangular")
        config.distribuicaoTS = TRIANGULAR;
    else if (distribuicaoTs == "uniform")
        config.distribuicaoTS = UNIFORME;
    else {
        config.distribuicaoTS = CONSTANTE;
    }
    config.parametroATS = settings.value("parametro_TS_1", 1).toDouble();
    config.parametroBTS = settings.value("parametro_TS_2", 1).toDouble();
    config.parametroCTS = settings.value("parametro_TS_3", 1).toDouble();
    config.tempoSimulacao = settings.value("tempo_simulacao", 30).toInt();
    settings.endGroup();
}

void ConfiguracaoInicialDialog::gravaInformacoesNoArquivo()
{
    QSettings settings("config.ini", QSettings::IniFormat);
    settings.beginGroup("lavacar");
    QString distribuicaoTec;
    if (config.distribuicaoTEC == EXPONENCIAL)
        distribuicaoTec = "exponencial";
    else if (config.distribuicaoTEC == LOG)
        distribuicaoTec = "log";
    else if (config.distribuicaoTEC == NORMAL)
        distribuicaoTec = "normal";
    else if (config.distribuicaoTEC == TRIANGULAR)
        distribuicaoTec = "triangular";
    else if (config.distribuicaoTEC == UNIFORME)
        distribuicaoTec = "uniform";
    else if (config.distribuicaoTEC == CONSTANTE)
        distribuicaoTec = "constante";
    else {
        throw std::out_of_range("Valor inesperado na variável config.distribuicaoTEC.");
    }
    settings.setValue("distribuicao_TEC", distribuicaoTec);
    settings.setValue("parametro_TEC_1", config.parametroATEC);
    settings.setValue("parametro_TEC_2", config.parametroBTEC);
    settings.setValue("parametro_TEC_3", config.parametroCTEC);

    QString distribuicaoTs;
     if (config.distribuicaoTS == EXPONENCIAL)
         distribuicaoTs = "exponencial";
     else if (config.distribuicaoTS == LOG)
         distribuicaoTs = "log";
     else if (config.distribuicaoTS == NORMAL)
         distribuicaoTs = "normal";
     else if (config.distribuicaoTS == TRIANGULAR)
         distribuicaoTs = "triangular";
     else if (config.distribuicaoTS == UNIFORME)
         distribuicaoTs = "uniform";
     else if (config.distribuicaoTS == CONSTANTE)
         distribuicaoTs = "constante";
     else {
         throw std::out_of_range("Valor inesperado na variável config.distribuicaoTEC.");
     }
    settings.setValue("distribuicao_TS", distribuicaoTs);
    settings.setValue("parametro_TS_1", config.parametroATS);
    settings.setValue("parametro_TS_2", config.parametroBTS);
    settings.setValue("parametro_TS_3", config.parametroCTS);
    settings.setValue("tempo_simulacao", config.tempoSimulacao);
    settings.endGroup();
}

bool ConfiguracaoInicialDialog::camposValidos()
{
    if (config.parametroATEC > config.parametroBTEC ||
            config.parametroATEC > config.parametroCTEC ||
            config.parametroBTEC > config.parametroCTEC ||
            config.parametroATS > config.parametroBTS ||
            config.parametroATS > config.parametroCTS ||
            config.parametroBTS > config.parametroCTS) {
        return false;
    }
    return true;
}
