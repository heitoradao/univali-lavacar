#ifndef LAVACAO_H
#define LAVACAO_H

#include <QObject>
#include <QQueue>
#include "carro.h"
#include "porta.h"
#include "atendente.h"
#include "dispose.h"

class Lavacao : public QObject
{
    Q_OBJECT
public:
    explicit Lavacao(QObject *parent = 0);
    Porta porta;
    Atendente atendente;
	Dispose dispose;
    unsigned int limiteDaFila;
	void mostraRelatorio();

public slots:
    void insereCarrosNaFila(Carro* carro);
    void despachaCarro(Carro* carro);
	void encerraSimulacao();

signals:
	void quit();

private:
    QQueue<Carro*> fila;
};

#endif // LAVACAO_H
