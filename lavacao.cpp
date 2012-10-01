#include "lavacao.h"
#include <QPainter>
#include <QTextStream>
#include <QGraphicsScene>
//#include <QColor>

Lavacao::Lavacao(QTextStream *output, Config config, QObject *parent, QGraphicsScene *scene)
    :QObject(parent)
    ,porta(NULL),atendente(NULL),dispose(NULL)
    ,QGraphicsItem(NULL, scene)
    ,limiteDaFila(4)
    ,config(config)
    ,output(output)
    ,ativa(true)
    ,somatorioTotalFila(0.0)
{
    porta = new Porta(output, 0, this, config);
    atendente = new Atendente(output, 0, this, config);
    dispose = new Dispose(output, 0, this, config);

    tempoFila.start();

    if (config.tempoSimulacao > 0)
        timerTempoSimulacao.singleShot(config.tempoSimulacao * 1000, this, SLOT(encerraSimulacao()));

    filaTempo.resize(config.limiteFila+1);
    // tratar os eventos gerados pela porta
    // insere o carro na fila
    // faz o atendente trabalhar
    QObject::connect(porta, SIGNAL(eventoEntraCarro(Carro*)), this, SLOT(insereCarrosNaFila(Carro*)));
    QObject::connect(atendente, SIGNAL(terminouDeLavarCarro(Carro*)), this, SLOT(despachaCarro(Carro*)));

    porta->setPos(24, 42);
    atendente->setPos(128, 42);
    dispose->setPos(256, 42);
}

void Lavacao::insereCarrosNaFila(Carro* carro)
{
    mutexChegouCarro.lock();
    int indiceVetor = fila.size();
    filaTempo[fila.size()] += tempoFila.elapsed();
    tempoFila.start();
    if (fila.isEmpty() && atendente->estaDesocupado()) {
        (*output) << "Chegou carro, atendente esta LIVRE, carro é atendido.\n";
        //verifica se atendente esta desocupado e faz ele atender o carro.
        atendente->atendeCarro(carro);
    } else if (!config.filaLimitada || fila.size() < config.limiteFila) {
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
    atendente->encerraSimulacao();
    //mostraRelatorio();
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
    if (config.filaLimitada)
        painter->drawText(QPointF(2,24), trUtf8("Fila: %1").arg(fila.size()));
    else
        painter->drawText(QPointF(2,24), trUtf8("Fila sem limite"));
    if (!ativa) painter->fillRect(QRect(55,4,10,10),QBrush(QColor(255,32,32)));

    if (tempoTotal.elapsed() > 0) {
        double tempSomatorio = 0;
        for (int i = 0; i < filaTempo.size(); ++i) {
            tempSomatorio = filaTempo[i] * i;
        }
        tempSomatorio /= tempoTotal.elapsed();
        painter->drawText(QPointF(2,3*12), trUtf8("3) tempo médio de entidade na fila: %1")
                          .arg(tempSomatorio));
    }
}

void Lavacao::criaAnimacaoEntrada()
{

}
