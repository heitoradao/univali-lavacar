#include "carro.h"

Carro::Carro(QTime momentoEntradaNoSistema, QObject *parent)
    :QObject(parent)
    ,estado(EstadoSujo)
    ,momentoEntradaNoSistema(momentoEntradaNoSistema)
{
    tempoSistema.start();
    tempoAtendimento.start();
}

void Carro::limpa()
{
    estado = EstadoLimpo;
    tempoAtendimento.start();
}

int Carro::getTempoAtendimento()
{
    return tempoAtendimento.elapsed()/1000;
}

int Carro::getTempoSistema()
{
    return tempoSistema.elapsed()/1000;
}
