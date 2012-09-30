#include "atendente.h"
#include "gerador.h"
#include <QPainter>

Atendente::Atendente(QTextStream *output, QObject *parent, QGraphicsItem *parentGI, Config config)
    :QObject(parent)
	,QGraphicsItem(parentGI)
    ,carroSendoAtendido(NULL)
    ,carroFinalizado(NULL)
	,numCarrosAtendidos(0)
	,somaTempoAtendimento(0)
    ,output(output)
    ,config(config)
    ,ativa(true)
{
    QObject::connect(&timer, SIGNAL(timeout()), this, SLOT(finalizaAtendimento()));
    gerador= new GeradorTS(config);
    timeInicio.start();
}

Atendente::~Atendente()
{
    delete gerador;
}

bool Atendente::estaDesocupado()
{
    return !carroSendoAtendido;
}

void Atendente::encerraSimulacao()
{
    ativa = false;
}

void Atendente::atendeCarro(Carro* carro)
{
    carro->limpa();
    (*output) << "atendente: Comecou a lavar um carro.\n";
    numCarrosAtendidos++;
    Q_ASSERT(!carroSendoAtendido);
	carroSendoAtendido = carro;
    double proxValor = gerador->proximoValor();
	somaTempoAtendimento += proxValor;
    (*output) << "debug: gerador ts.proxValor = " << proxValor << "\n";
    timer.singleShot(config.rapidezAnimacao * proxValor * 1000, this, SLOT(finalizaAtendimento()));
    output->flush();
	//carro// starta um timer com o tempo de serviço.
	// grava o tempo atual.
	// pega da função geradora de números aleatórios, e grava o TS
}

void Atendente::finalizaAtendimento()
{
    Q_ASSERT(output);
    (*output) << "atendente: terminou de lavar um carro.\n";
    output->flush();
    carroFinalizado = carroSendoAtendido;
    carroSendoAtendido = NULL;
    emit terminouDeLavarCarro(carroFinalizado);
    update(this->boundingRect());
}

void Atendente::mostraRelatorio()
{
    Q_ASSERT(output);
    (*output) << "Numero de carros atendidos: " << numCarrosAtendidos << "\n";
    (*output) << "Tempo médio de atendimenot: " << ("XXXXX") << "\n";
    output->flush();
}

QRectF Atendente::boundingRect() const
{
    return QRectF(0, 0, 70, 70);
}

void Atendente::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	//painter-> drawLine(20, 30, 40, 60);

	painter->drawRect(boundingRect());
    painter->drawText(QPointF(0,1*12), trUtf8("Atendente"));
    painter->drawText(QPointF(0,2*12), QString("ca: %1").arg(numCarrosAtendidos));
    if (!ativa)
        painter->drawText(QPointF(0,3*12), QString("ocupacao: %1").arg(somaTempoAtendimento/config.tempoSimulacao));
    //painter->drawText(QPointF(0,3*12), QString("ocupacao: %1").arg(somaTempoAtendimento/timeInicio.elapsed()));
    if (!carroSendoAtendido) painter->drawText(QPointF(0,4*12), QString("(ocioso)"));

}
