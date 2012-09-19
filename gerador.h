#ifndef GERADOR_H_INCLUDED
#define GERADOR_H_INCLUDED

//double uniform(double a, double b, double c);
//double exponencial_negative(double a, double b, double c);
//double normal(double a, double b, double c);
//double log(double a, double b, double c);
//double triangle(double a, double b, double c);

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
