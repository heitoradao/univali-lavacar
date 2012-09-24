#include "porta.h"
#include <iostream>
#include <QTextStream>
#include <QPainter>

Porta::Porta(QTextStream *output, QObject *parent, QGraphicsItem *parentGI, Config config)
	:QObject(parent)
	,QGraphicsItem(parentGI)
    ,ativa(true)
	,numCarrosGerados(0)
    ,output(output)
    ,config(config)
{
    QObject::connect(&timer, SIGNAL(timeout()), this, SLOT(geraCarro()));
    gerador = new GeradorTEC(config);

    // Usar numero aleatorio
    timer.singleShot(1000, this, SLOT(geraCarro())); // Usar funcao aleatoria
}

Porta::~Porta()
{
    delete gerador;
}

void Porta::geraCarro()
{
    Q_ASSERT(output);
    (*output) << "entrou carro\n";
    output->flush();
    ++numCarrosGerados;
    emit eventoEntraCarro(new Carro);
    if (ativa) timer.singleShot(gerador->proximoValor() * 1000, this, SLOT(geraCarro())); // Usar funcao aleatoria
    update(boundingRect());
}

void Porta::encerraSimulacao()
{
    ativa = false;
    timer.stop();
}

void Porta::mostraRelatorio()
{
    (*output) << "Numero de carros que entraram no sistema: " << numCarrosGerados << "\n";
}

QRectF Porta::boundingRect() const
{
	return QRectF(0, 0, 64, 64);
}

void Porta::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	painter->drawRect(this->boundingRect());
    painter->drawText(QPointF(0,12), "Porta");
    painter->drawText(QPointF(0,24), QString("c: %1").arg(numCarrosGerados));
}
