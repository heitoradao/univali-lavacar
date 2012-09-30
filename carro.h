#ifndef CARRO_H
#define CARRO_H

#include <QObject>
#include <QTime>

enum EstadoCarro
{
    EstadoSujo,
    EstadoLimpo
};

class Carro : public QObject
{
    Q_OBJECT
public:
    explicit Carro(QObject *parent = 0);
    void limpa();
    EstadoCarro estado;
    int getTempoAtendimento();
    int getTempoSistema();
private:
    QTime tempoAtendimento;
    QTime tempoSistema;
};

#endif // CARRO_H
