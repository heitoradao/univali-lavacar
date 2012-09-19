#include "lavacao.h"
#include <QTextStream>
#include <QTextCodec>

Lavacao::Lavacao(QObject *parent)
    :QObject(parent)
    ,limiteDaFila(4)
{
    // tratar os eventos gerados pela porta
    // insere o carro na fila
    // faz o atendente trabalhar
    QObject::connect(&porta, SIGNAL(eventoEntraCarro(Carro*)), this, SLOT(insereCarrosNaFila(Carro*)));
    QObject::connect(&atendente, SIGNAL(terminouDeLavarCarro(Carro*)), this, SLOT(despachaCarro(Carro*)));

}

void Lavacao::insereCarrosNaFila(Carro* carro)
{
    QTextStream output(stdout, QIODevice::WriteOnly);
    if (fila.size() < 4) {
        fila.append(carro);
        if (atendente.estaDesocupado()) {
            atendente.atendeCarro(fila.front());
            fila.removeFirst();
        } else {
            output << "Atendente esta ocupado, carro entra na fila\n";
        }
    } else {
        output << "Carro foi embora porque a fila está cheia.\n";
    }
    output << "Fila = " << fila.size() << " elementos\n";
}

void Lavacao::despachaCarro(Carro* carro)
{
    QTextStream output(stdout, QIODevice::WriteOnly);
    output << "terminou atendimento de carro\n";
    delete carro; // ou
    //verifica se tem carros na fila e por o atendente pra trabalhar
    if (!fila.empty()) {
        atendente.atendeCarro(fila.front());
        fila.removeFirst();
    }
}

void Lavacao::mostraRelatorio()
{
	QTextStream output(stdout, QIODevice::WriteOnly);
	output << "====================================================\n";
	output.flush();
	porta.mostraRelatorio(output);
	atendente.mostraRelatorio(output);
	output << "Numero de clientes na fila: " << fila.size() << "\n";
	output << "====================================================\n";
	output.flush();
}

void Lavacao::encerraSimulacao()
{
	mostraRelatorio();
	emit quit();
}
