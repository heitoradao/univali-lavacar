#ifndef GERADOR_H_INCLUDED
#define GERADOR_H_INCLUDED

class GeradorTEC
{
public:
    double proximoValor();
    GeradorTEC();
private:
	double (*funcaoGeradora)(double, double, double);
	double parametroA;
	double parametroB;
	double parametroC;
};

class GeradorTS
{
public:
	double proximoValor();
	GeradorTS();
private:
	double (*funcaoGeradora)(double, double, double);
	double parametroA;
	double parametroB;
	double parametroC;
};

#endif // GERADOR_H_INCLUDED
