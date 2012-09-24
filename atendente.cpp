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
{
    QObject::connect(&timer, SIGNAL(timeout()), this, SLOT(finalizaAtendimento()));
    gerador= new GeradorTS(config);
}

Atendente::~Atendente()
{
    delete gerador;
}

bool Atendente::estaDesocupado()
{
    return !carroSendoAtendido;
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
	timer.singleShot(proxValor * 1000, this, SLOT(finalizaAtendimento()));
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
	return QRectF(0, 0, 64, 64);
}

void Atendente::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	//painter-> drawLine(20, 30, 40, 60);
	painter->drawRect(boundingRect());
    painter->drawText(QPointF(0,12), trUtf8("Atendente"));
    painter->drawText(QPointF(0,24), QString("ca: %1").arg(numCarrosAtendidos));
    if (!carroSendoAtendido) painter->drawText(QPointF(0,36), QString("(ocioso)"));
}
