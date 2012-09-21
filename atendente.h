#ifndef ATENDENTE_H
#define ATENDENTE_H

#include <QObject>
#include <QTimer>
#include "carro.h"
#include <QTextStream>
#include <QGraphicsItem>
#include "gerador.h"

class Atendente : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Atendente(QObject *parent = 0, QGraphicsItem *parentGI = 0);
    bool estaDesocupado();
    void atendeCarro(Carro* carro);
	void mostraRelatorio(QTextStream &output);
	virtual QRectF boundingRect() const;
	virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

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
