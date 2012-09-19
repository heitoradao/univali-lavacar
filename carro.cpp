#include "carro.h"

Carro::Carro(double tempoChegada, QObject *parent)
    :QObject(parent)
    ,tempoChegada(tempoChegada)
{
}

void Carro::lava(double tempoAtendimento)
{
    // gera numero aleatorio para tempo de atendimento
    emit termino(tempoAtendimento + 15);
}

