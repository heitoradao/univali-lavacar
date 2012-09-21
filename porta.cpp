#include "porta.h"
#include <iostream>
#include <QTextStream>
#include <QPainter>

Porta::Porta(QObject *parent, QGraphicsItem *parentGI)
	:QObject(parent)
	,QGraphicsItem(parentGI)
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

QRectF Porta::boundingRect() const
{
	return QRectF(0, 0, 64, 64);
}

void Porta::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	painter->drawRect(this->boundingRect());
	painter->drawText(boundingRect(), "Porta");
}
