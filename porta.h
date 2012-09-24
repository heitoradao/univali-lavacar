#ifndef PORTA_H
#define PORTA_H

#include "carro.h"
#include <QGraphicsItem>
#include <QObject>
#include <QTextStream>
#include <QTimer>
#include "config.h"
#include "gerador.h"

class Porta : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Porta(QTextStream *output, QObject *parent, QGraphicsItem *parentGI, Config config);
    ~Porta();
    void mostraRelatorio();
	virtual QRectF boundingRect() const;
	virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void encerraSimulacao();

signals:
    void eventoEntraCarro(Carro* carro);

private slots:
    void geraCarro();

private:
    bool ativa;
    QTimer timer;
	int numCarrosGerados;
    QTextStream *output;
    Config config;
    GeradorTEC *gerador;
};

#endif // PORTA_H
