#ifndef DISPOSE_H
#define DISPOSE_H

#include <QObject>
#include "carro.h"

class Dispose : public QObject
{
	Q_OBJECT
public:
	explicit Dispose(QObject *parent = 0);
	void deletaRecurso(Carro* carro);
	
private:
	int numCarros;
};

#endif // DISPOSE_H
