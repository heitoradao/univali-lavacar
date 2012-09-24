#include "carro.h"

Carro::Carro(QObject *parent)
    :QObject(parent)
    ,estado(ESTADO_SUJO)
{
    tempoSistema.start();
    tempoAtendimento.start();
}

void Carro::limpa()
{
    estado = ESTADO_LIMPO;
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
