#ifndef GERADOR_H_INCLUDED
#define GERADOR_H_INCLUDED

#include "config.h"

class GeradorTEC
{
public:
    double proximoValor();
    GeradorTEC(Config config);
private:
	double (*funcaoGeradora)(double, double, double);
    Config config;
};

class GeradorTS
{
public:
	double proximoValor();
    GeradorTS(Config config);
private:
	double (*funcaoGeradora)(double, double, double);
    Config config;
};

#endif // GERADOR_H_INCLUDED
