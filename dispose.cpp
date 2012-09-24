#include "dispose.h"
#include <QPainter>

Dispose::Dispose(QTextStream *output, QObject *parent, QGraphicsItem *parentGI)
	:QObject(parent)
    ,QGraphicsItem(parentGI)
	,numCarros(0)
    ,output(output)
    ,somatorioTempoSistema(0)
    ,somatorioTempoAtendimento(0)
{
}

void Dispose::deletaEntidade(Carro* carro)
{
	numCarros++;
    somatorioTempoSistema += carro->getTempoSistema();
    somatorioTempoAtendimento +=carro->getTempoAtendimento();
	delete carro;
}

QRectF Dispose::boundingRect() const
{
    return QRectF(0, 0, 256, 64);
}

void Dispose::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawRect(boundingRect());
    painter->drawText(QPointF(2,1*12), trUtf8("Dispose"));
    if (numCarros > 0) {
		painter->drawText(QPointF(2,1*12+12), trUtf8("1) numero medio de entidades na fila: %1").arg(0));
		painter->drawText(QPointF(2,3*12+12), trUtf8("3) tempo medio em fila: %1").arg((somatorioTempoSistema - somatorioTempoAtendimento) / numCarros));
        painter->drawText(QPointF(2,4*12+12), trUtf8("4) tempo medio no sistema: %1").arg(somatorioTempoSistema / numCarros));
		painter->drawText(QPointF(2,5*12+12), trUtf8("5) contador entidades: %1").arg(numCarros));
		//painter->drawText(QPointF(2,5*12), trUtf8("tempo medio de atendimento: %1").arg(somatorioTempoAtendimento / numCarros));
    }
}
