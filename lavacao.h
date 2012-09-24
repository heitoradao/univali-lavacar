#ifndef LAVACAO_H
#define LAVACAO_H

#include <QGraphicsItem>
#include <QMutex>
#include <QObject>
#include <QQueue>
#include "carro.h"
#include "porta.h"
#include "atendente.h"
#include "dispose.h"
#include "config.h"

class Lavacao : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Lavacao(QTextStream *output, Config config, QObject *parent, QGraphicsScene *scene);
    Porta *porta;
    Atendente *atendente;
    Dispose *dispose;
    unsigned int limiteDaFila;
	void mostraRelatorio();
	virtual QRectF boundingRect() const;
	virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

public slots:
    void insereCarrosNaFila(Carro* carro);
    void despachaCarro(Carro* carro);
	void encerraSimulacao();

private:
    QQueue<Carro*> fila;
    Config config;
    QTextStream *output;
    QMutex mutexChegouCarro;
    QTimer timerTempoSimulacao;
    bool ativa;
};

#endif // LAVACAO_H
