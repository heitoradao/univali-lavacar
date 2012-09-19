#ifndef CARRO_H
#define CARRO_H

#include <QObject>

class Carro : public QObject
{
    Q_OBJECT
public:
    explicit Carro(double tempoChegada, QObject *parent = 0);

    double tempoChegada;
    double tempoAtendimento;
    void lava(double tempoAtendimento);

signals:
    void termino(double tempoAtendimento);

};

#endif // CARRO_H
