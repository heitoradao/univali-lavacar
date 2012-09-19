#include "atendente.h"
#include "gerador.h"

Atendente::Atendente(QObject *parent)
    :QObject(parent)
    ,carroSendoAtendido(NULL)
	,numCarrosAtendidos(0)
	,somaTempoAtendimento(0)
{
    QObject::connect(&timer, SIGNAL(timeout()), this, SLOT(finalizaAtendimento()));
}

bool Atendente::estaDesocupado()
{
    return !carroSendoAtendido;
}

void Atendente::atendeCarro(Carro* carro)
{
	numCarrosAtendidos++;
	QTextStream output(stdout, QIODevice::WriteOnly);
	output << "atendente: Comecou a lavar um carro.\n";
	Q_ASSERT(!carroSendoAtendido);
	carroSendoAtendido = carro;
	double proxValor = gerador.proximoValor();
	somaTempoAtendimento += proxValor;
	output << "debug: gerador ts.proxValor = " << proxValor << "\n";
	timer.singleShot(proxValor * 1000, this, SLOT(finalizaAtendimento()));
	//carro// starta um timer com o tempo de serviço.
	// grava o tempo atual.
	// pega da função geradora de números aleatórios, e grava o TS
}

void Atendente::finalizaAtendimento()
{
    QTextStream output(stdout, QIODevice::WriteOnly);
    output << "atendente: terminou de lavar um carro.\n";
	output.flush();
    emit terminouDeLavarCarro(carroSendoAtendido);
    carroSendoAtendido = NULL;
}

void Atendente::mostraRelatorio(QTextStream &output)
{
    output << "Numero de carros atendidos: " << numCarrosAtendidos << "\n";
	output << "Tempo médio de atendimenot: " << ("XXXXX") << "\n";
	output.flush();
}
