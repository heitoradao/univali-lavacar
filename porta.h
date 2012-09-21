#ifndef PORTA_H
#define PORTA_H

#include "carro.h"
#include <QGraphicsItem>
#include <QObject>
#include <QTextStream>
#include <QTimer>

class Porta : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Porta(QObject *parent = 0, QGraphicsItem *parentGI = 0);
	void mostraRelatorio(QTextStream &output);
	virtual QRectF boundingRect() const;
	virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


signals:
    void eventoEntraCarro(Carro* carro);

private slots:
    void geraCarro();

private:
    QTimer timer;
	int numCarrosGerados;

};

#endif // PORTA_H
