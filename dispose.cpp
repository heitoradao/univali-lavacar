#include "dispose.h"

Dispose::Dispose(QObject *parent)
	:QObject(parent)
	,numCarros(0)
{
}

void Dispose::deletaRecurso(Carro* carro)
{
	numCarros++;
	delete carro;
}
