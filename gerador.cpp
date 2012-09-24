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

double (*funcoes[6])(double, double, double) =
    {constante, exponencial_negative, log,normal, triangle, uniform};

GeradorTEC::GeradorTEC(Config config)
	:funcaoGeradora(NULL)
    ,config(config)
{
    funcaoGeradora = funcoes[config.distribuicaoTEC];
}

double GeradorTEC::proximoValor()
{
	Q_ASSERT(funcaoGeradora);
    return funcaoGeradora(config.parametroATEC, config.parametroBTEC, config.parametroCTEC);
}

GeradorTS::GeradorTS(Config config)
    :funcaoGeradora(NULL)
    ,config(config)
{
    funcaoGeradora = funcoes[config.distribuicaoTS];
}

double GeradorTS::proximoValor()
{
	Q_ASSERT(funcaoGeradora);
    return funcaoGeradora(config.parametroATS, config.parametroBTS, config.parametroCTS);
}
