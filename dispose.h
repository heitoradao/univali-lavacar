#ifndef DISPOSE_H
#define DISPOSE_H

#include <QGraphicsItem>
#include <QObject>
#include <QTextStream>
#include "carro.h"
#include "config.h"

/*! \class Dispose
 * Responsável pela remoção das entidades do sistema,
 * bem como análise estatística e geração do relatório
 */
class Dispose : public QObject, public QGraphicsItem
{
	Q_OBJECT
public:
    explicit Dispose(QTextStream *output, QObject *parent, QGraphicsItem *parentGI, Config config);
	void deletaEntidade(Carro* carro);
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	
private:
	int numCarros;
    QTextStream *output;
    int somatorioTempoAtendimento;
    int somatorioTempoSistema;
    Config config;
};

#endif // DISPOSE_H
