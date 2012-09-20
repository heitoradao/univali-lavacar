#include "gerador.h"
#include <QSettings>
#include <QTextStream>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>
#include <boost/random/exponential_distribution.hpp>
#include <boost/random/lognormal_distribution.hpp>
#include <boost/random/normal_distribution.hpp>
#include <boost/random/triangle_distribution.hpp>

boost::mt19937 gen;

double triangle(double a, double b, double c) {
    boost::random::triangle_distribution<> dist(a, b, c);
    return dist(gen);
}

double uniform(double a, double b, double c){
    boost::random::uniform_int_distribution<> dist(a, b);
    return dist(gen);
}

double exponencial_negative(double a, double b, double c){
    boost::random::exponential_distribution<> dist(a);
    return dist(gen);
}

double normal(double a, double b, double c){
    boost::random::uniform_int_distribution<> dist(a, b);
    return dist(gen);
}

double log(double a, double b, double c){
    boost::random::uniform_int_distribution<> dist(a, b);
    return dist(gen);
}

double constante(double a, double b, double c)
{
    return a;
}

GeradorTEC::GeradorTEC()
	:funcaoGeradora(NULL)
{
	QTextStream output(stdout, QIODevice::WriteOnly);
	output << "lendo configuracao.ini\n";
	QSettings settings("configuracao.ini", QSettings::IniFormat);
	QString distribuicaoTS = settings.value("lavacar/distribuicao_TEC").toString();
	output << "distribuicaoTs = " << distribuicaoTS << "\n";
	parametroA = settings.value("lavacar/parametro_TEC_1").toDouble();
	parametroB = settings.value("lavacar/parametro_TEC_2").toDouble();
	parametroC = settings.value("lavacar/parametro_TEC_3").toDouble();
	output << QString("A = %1\nB = %2\nC = %3\n").arg(parametroA).arg(parametroB).arg(parametroC);

	if (distribuicaoTS.compare("triangular", Qt::CaseInsensitive) == 0) {
		funcaoGeradora = triangle;
	} else if (distribuicaoTS.compare("log", Qt::CaseInsensitive) == 0) {
		funcaoGeradora = log;
	} else if (distribuicaoTS.compare("normal", Qt::CaseInsensitive) == 0) {
		funcaoGeradora = normal;
    } else if (distribuicaoTS.compare("exponencial", Qt::CaseInsensitive) == 0) {
		funcaoGeradora = exponencial_negative;
    } else { //constante
        funcaoGeradora = constante;
    }
}

double GeradorTEC::proximoValor()
{
	Q_ASSERT(funcaoGeradora);
	return funcaoGeradora(parametroA, parametroB, parametroC);
}

GeradorTS::GeradorTS()
    :funcaoGeradora(NULL)
{
	QSettings settings("configuracao.ini", QSettings::IniFormat);
    QString distribuicaoTS = settings.value("lavacar/distribuicao_TS").toString().trimmed().toLower();
	parametroA = settings.value("lavacar/parametro_TS_1").toDouble();
	parametroB = settings.value("lavacar/parametro_TS_2").toDouble();
	parametroC = settings.value("lavacar/parametro_TS_3").toDouble();

	if (distribuicaoTS.compare("triangular", Qt::CaseInsensitive) == 0) {
		funcaoGeradora = triangle;
	} else if (distribuicaoTS.compare("log", Qt::CaseInsensitive) == 0) {
		funcaoGeradora = log;
	} else if (distribuicaoTS.compare("normal", Qt::CaseInsensitive) == 0) {
		funcaoGeradora = normal;
    } else if (distribuicaoTS.compare("exponencial", Qt::CaseInsensitive) == 0) {
		funcaoGeradora = exponencial_negative;
    } else { //constante
        funcaoGeradora = constante;
    }
}

double GeradorTS::proximoValor()
{
	Q_ASSERT(funcaoGeradora);
	return funcaoGeradora(parametroA, parametroB, parametroC);
}
