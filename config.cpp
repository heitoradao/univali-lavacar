#include "config.h"
#include "gerador.h"
#include <QSettings>

Config* Config::instance = 0;

Config::Config()
{
    QSettings settings("configuracao.ini", QSettings::IniFormat);
    //settings.beginGroup();

    distribuicaoTS = settings.value("lavacar/distribuicao_TEC").toString();

}

Config* Config::getInstance()
{
    if (!instance) instance = new Config;
    return instance;
}
