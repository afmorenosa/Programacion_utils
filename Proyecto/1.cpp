#include <iostream>
#include <cmath>
#include <vector>

const double c=340.0;
const double v=100.0;
const double R=10.0;
const double L=10.5;
const double w=1000.0;
const double A=1.0;

double X(double l, double r, double t);
double f(double l, double r, double t, double a);
double df(double l, double r, double t, double a);
double dp(double l, double r, double WW, double t);

int main(void)
{
	double r,l,WW;
	WW=v/R;
	r=WW*R/c;
	l=WW*L/c;
	
	int N=1000;
	
	for(double i=0;i<1.25;i+=1/(WW*N))
	{
		std::cout<<i<<'\t'<<std::abs(dp(l,r,WW,i))<< '\t' << X(l,r,i)<<'\n';
		}
	
	
	return 0;
}

double X(double l, double r, double t)
{
	double x0=1.0;
	for(int i=0; i<=50;++i)
	{
		x0=x0 -(f(l,r,t,x0)/df(l,r,t,x0));
		}
		return x0;
}

double f(double l, double r, double t, double a)
{
	return (r*r+l*l+2*r*l*std::sin(t-a)-a*a);
}

double df(double l, double r, double t, double a)
{
	return (-2*(l*r*std::cos(t-a)+a));	
}

double dp(double l, double r, double WW, double t)
{
	double p;
	p=A*std::cos(w*(t-X(l,r, t*WW)/c))/X(l,r,t*WW);
	return p;
}
