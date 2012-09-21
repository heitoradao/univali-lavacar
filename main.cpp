#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QList>
#include <QSettings>
#include <QTextStream>
#include <QTimer>
#include "lavacao.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTextStream output(stdout, QIODevice::WriteOnly);
    QTextStream input(stdin, QIODevice::ReadOnly);

    output << "Informe o tempo de simulacao (em segundos): ";
    output.flush();
    QString entrada;
    entrada = input.readLine();

	QGraphicsScene scene;
	MainWindow mainWindow(0, &scene);
	mainWindow.show();

    QTimer timer;
	Lavacao lavacao(0, &scene);
    QObject::connect(&timer, SIGNAL(timeout()), &lavacao, SLOT(encerraSimulacao()));
	//QObject::connect(&lavacao, SIGNAL(quit()), &app, SLOT(quit()));

    timer.start(entrada.toInt() * 1000);

    return app.exec();
}
