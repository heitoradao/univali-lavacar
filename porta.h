#ifndef PORTA_H
#define PORTA_H

#include <QObject>
#include <QTimer>
#include "carro.h"
#include <QTextStream>

class Porta : public QObject
{
    Q_OBJECT
public:
    explicit Porta(QObject *parent = 0);
	void mostraRelatorio(QTextStream &output);

signals:
    void eventoEntraCarro(Carro* carro);

private slots:
    void geraCarro();

private:
    QTimer timer;
	int numCarrosGerados;

};

#endif // PORTA_H
