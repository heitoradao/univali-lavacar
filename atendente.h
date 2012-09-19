#ifndef ATENDENTE_H
#define ATENDENTE_H

#include <QObject>
#include <QTimer>
#include "carro.h"
#include <QTextStream>
#include "gerador.h"

class Atendente : public QObject
{
    Q_OBJECT
public:
    explicit Atendente(QObject *parent = 0);
    bool estaDesocupado();
    void atendeCarro(Carro* carro);
	void mostraRelatorio(QTextStream &output);

signals:
    void terminouDeLavarCarro(Carro*);

public slots:
    void finalizaAtendimento();

private:
    int state; // estado que indica o que o atendente está fazendo: ocioso ou atendendo
    QTimer timer; // determina o termino da lavagem
    Carro* carroSendoAtendido;
	int numCarrosAtendidos;
	double somaTempoAtendimento;
	GeradorTS gerador;
};

#endif // ATENDENTE_H
