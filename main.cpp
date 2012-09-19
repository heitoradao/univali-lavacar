#include <QCoreApplication>
#include <QTextStream>
#include <QTimer>
#include <QList>
#include "lavacao.h"
#include <QSettings>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QTextStream output(stdout, QIODevice::WriteOnly);
    QTextStream input(stdin, QIODevice::ReadOnly);

    output << "Informe o tempo de simulacao (em segundos): ";
    output.flush();
    QString entrada;
    entrada = input.readLine();

    QTimer timer;
	Lavacao lavacao;
    QObject::connect(&timer, SIGNAL(timeout()), &lavacao, SLOT(encerraSimulacao()));
	QObject::connect(&lavacao, SIGNAL(quit()), &app, SLOT(quit()));

    timer.start(entrada.toInt() * 1000);

    return app.exec();
}
