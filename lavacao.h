#ifndef LAVACAO_H
#define LAVACAO_H

#include <QObject>
#include <QQueue>
#include <QGraphicsItem>
#include "carro.h"
#include "porta.h"
#include "atendente.h"
#include "dispose.h"

class Lavacao : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Lavacao(QObject *parent = 0, QGraphicsScene *scene = 0);
    Porta porta;
    Atendente atendente;
	Dispose dispose;
    unsigned int limiteDaFila;
	void mostraRelatorio();
	virtual QRectF boundingRect() const;
	virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

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
