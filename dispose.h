#ifndef DISPOSE_H
#define DISPOSE_H

#include <QObject>
#include <QTextStream>
#include "carro.h"
#include <QGraphicsItem>

class Dispose : public QObject, public QGraphicsItem
{
	Q_OBJECT
public:
    explicit Dispose(QTextStream *output, QObject *parent, QGraphicsItem *parentGI);
	void deletaEntidade(Carro* carro);
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	
private:
	int numCarros;
    QTextStream *output;
    int somatorioTempoAtendimento;
    int somatorioTempoSistema;
};

#endif // DISPOSE_H
