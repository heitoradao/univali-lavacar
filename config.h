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
        ,filaLimitada(true)
        ,limiteFila(4)
    {}
    TipoDistribuicao distribuicaoTS;
    double parametroATS;
    double parametroBTS;
    double parametroCTS;

    TipoDistribuicao distribuicaoTEC;
    double parametroATEC;
    double parametroBTEC;
    double parametroCTEC;

    bool filaLimitada;
    int limiteFila;
    int tempoSimulacao;
    double rapidezAnimacao;
};

#endif // CONFIG_H
