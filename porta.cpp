#include "porta.h"
#include <iostream>
#include <QTextStream>

Porta::Porta(QObject *parent)
	:QObject(parent)
	,numCarrosGerados(0)
{
    QObject::connect(&timer, SIGNAL(timeout()), this, SLOT(geraCarro()));

    // Usar numero aleatorio
    timer.singleShot(1000, this, SLOT(geraCarro())); // Usar funcao aleatoria
}

void Porta::geraCarro()
{
	++numCarrosGerados;
    QTextStream output(stdout, QIODevice::WriteOnly);
    output << "entrou carro\n";
    output.flush();
    emit eventoEntraCarro(new Carro(1000));
    timer.singleShot(1000, this, SLOT(geraCarro())); // Usar funcao aleatoria
}

void Porta::mostraRelatorio(QTextStream &output)
{
	output << "Numero de carros que entraram no sistema: " << numCarrosGerados << "\n";
}
