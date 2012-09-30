#ifndef ATENDENTE_H
#define ATENDENTE_H

#include "carro.h"
#include "gerador.h"
#include "config.h"
#include <QGraphicsItem>
#include <QObject>
#include <QTimer>
#include <QTime>
#include <QTextStream>

/*! \class Atendente
 * \brief Classe que representa o atendente, que é o recurso do sistema.
 */
class Atendente : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Atendente(QTextStream *output, QObject *parent, QGraphicsItem *parentGI, Config config);
    ~Atendente();
    bool estaDesocupado();
    void atendeCarro(Carro* carro);
    void mostraRelatorio();
    void encerraSimulacao();
	virtual QRectF boundingRect() const;
	virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:
    void terminouDeLavarCarro(Carro*);

public slots:
    void finalizaAtendimento();

private:
    int state; // estado que indica o que o atendente está fazendo: ocioso ou atendendo
    QTimer timer; // determina o termino da lavagem
    QTime timeInicio;
    Carro* carroSendoAtendido;
    Carro* carroFinalizado;
	int numCarrosAtendidos;
	double somaTempoAtendimento;
    GeradorTS *gerador;
    QTextStream *output;
    Config config;
    bool ativa;
};

#endif // ATENDENTE_H
