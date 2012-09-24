#ifndef CONFIG_H
#define CONFIG_H

#include <QString>

enum TipoDistribuicao
{
    CONSTANTE,
    EXPONENCIAL,
    LOG,
    NORMAL,
    TRIANGULAR,
    UNIFORME
};

enum TipoSemente
{
    SEMENTE_ALEATORIA,
    SEMENTE_DETERMINISTICA
};

class Config
{
public:
    Config()
        :distribuicaoTS(CONSTANTE)
        ,parametroATS(1)
        ,parametroBTS(1)
        ,parametroCTS(1)
        ,distribuicaoTEC(CONSTANTE)
        ,parametroATEC(1)
        ,parametroBTEC(1)
        ,parametroCTEC(1)
    {}
    TipoDistribuicao distribuicaoTS;
    double parametroATS;
    double parametroBTS;
    double parametroCTS;

    TipoDistribuicao distribuicaoTEC;
    double parametroATEC;
    double parametroBTEC;
    double parametroCTEC;

    int tempoSimulacao;
    TipoSemente semente;
};

#endif // CONFIG_H
