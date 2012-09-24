#include "lavacao.h"
#include <QPainter>
#include <QTextStream>
#include <QTextCodec>
#include <QGraphicsScene>
#include <QColor>


Lavacao::Lavacao(QTextStream *output, Config config, QObject *parent, QGraphicsScene *scene)
    :QObject(parent)
	,QGraphicsItem(NULL, scene)
    ,limiteDaFila(4)
    ,config(config)
    ,output(output)
    ,ativa(true)
{
    atendente = new Atendente(output, 0, this, config);
    porta = new Porta(output, 0, this, config);
    dispose = new Dispose(output, 0, this);

    if (config.tempoSimulacao > 0)
        timerTempoSimulacao.singleShot(config.tempoSimulacao * 1000, this, SLOT(encerraSimulacao()));

    // tratar os eventos gerados pela porta
    // insere o carro na fila
    // faz o atendente trabalhar
    QObject::connect(porta, SIGNAL(eventoEntraCarro(Carro*)), this, SLOT(insereCarrosNaFila(Carro*)));
    QObject::connect(atendente, SIGNAL(terminouDeLavarCarro(Carro*)), this, SLOT(despachaCarro(Carro*)));

	porta->setPos(24, 64);
    atendente->setPos(128, 64);
    dispose->setPos(256, 64);
}

void Lavacao::insereCarrosNaFila(Carro* carro)
{
    mutexChegouCarro.lock();
    if (fila.isEmpty() && atendente->estaDesocupado()) {
        (*output) << "Chegou carro, atendente esta LIVRE, carro é atendido.\n";
        //verifica se atendente esta desocupado e faz ele atender o carro.
        atendente->atendeCarro(carro);
    } else if (fila.size() < 4) {
        (*output) << "Chegou carro, entrou na fila (" << fila.size() << ")\n";
        fila.append(carro);
    } else {
        (*output) << "Chegou carro, fila está cheia, carro foi embora.\n";
        dispose->deletaEntidade(carro);
    }
    mutexChegouCarro.unlock();
    update(boundingRect());
}

void Lavacao::despachaCarro(Carro* carro)
{
    dispose->deletaEntidade(carro);
    if (!fila.isEmpty()) {
        atendente->atendeCarro(fila.takeFirst());
    }
}

void Lavacao::mostraRelatorio()
{
	QTextStream output(stdout, QIODevice::WriteOnly);
	output << "====================================================\n";
	output.flush();
    porta->mostraRelatorio();
    atendente->mostraRelatorio();
	output << "Numero de clientes na fila: " << fila.size() << "\n";
	output << "====================================================\n";
	output.flush();
}

void Lavacao::encerraSimulacao()
{
    ativa = false;
    porta->encerraSimulacao();
    //atendente->encerraSimulacao();
	mostraRelatorio();
}

QRectF Lavacao::boundingRect() const
{
    return QRectF(0, 0, 530, 150);
}

void Lavacao::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	//painter-> drawLine(20, 30, 40, 60);
	painter->drawRect(boundingRect());
    painter->drawText(QPointF(2,12), trUtf8("Lavação"));
    painter->drawText(QPointF(2,24), QString(trUtf8("Fila: %1")).arg(fila.size()));
    if (!ativa) painter->fillRect(QRect(55,4,10,10),QBrush(QColor(255,32,32)));
}
