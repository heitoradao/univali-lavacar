#ifndef CARRO_H
#define CARRO_H

#include <QObject>
#include <QTime>

enum EstadoCarro
{
    EstadoSujo,
    EstadoLimpo
};

/*! \class Carro
 * \brief Entidade principal.
 */
class Carro : public QObject
{
    Q_OBJECT
public:
    explicit Carro(QTime momentoEntradaNoSistema, QObject *parent = 0);
    void limpa();
    EstadoCarro estado;
    int getTempoAtendimento();
    int getTempoSistema();
private:
    QTime tempoAtendimento;
    QTime tempoSistema;
    QTime momentoEntradaNoSistema;
};

#endif // CARRO_H
