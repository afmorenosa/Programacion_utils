#include <iostream>
#include <cmath>

using fun=double(double);
const double pi=std::acos(-1);

double trap(const double a, const double b, const int n, fun f);
double rich(const double a, const double b, const int n, fun f);
double simp(const double a, const double b, const int n, fun f);

int main (void)
{
	std::cout<<"con trap: "<<trap(0,pi,20,std::sin)<<std::endl;
	std::cout<<"con rich: "<<rich(0,pi,20,std::sin)<<std::endl;
	std::cout<<"con simp: "<<simp(0,pi,20,std::sin)<<std::endl;
	return 0;
}

double trap(const double a, const double b, const int n, fun f)
{
	const double h= std::abs((b-a)/n);
	double r1=(f(a)+f(b))/2;
	double r2;
	for(r2=a+h; r2<(b-h); r2+=h)
	{
		r1+=f(r2);
	}
	return h*r1;
}

double rich(const double a, const double b, const int n, fun f)
{
	return (4*trap(a, b, 2*n, f)-trap(a, b, n, f))/3;
}

double simp(const double a, const double b, const int n, fun f)
{
	const double h= std::abs((b-a)/n);
	double res=f(a)+f(b);
	double sum=0;
	int ii;
	double x;
	
	for(ii=1;ii<=n/2 - 1; ++ii)
	{
	x=a+2*ii*h;
	sum+=f(x);
	}
	res+= 2*sum;
	
	sum=0;
	for(ii=1;ii<=n/2; ++ii)
	{
	x=a+(2*ii-1)*h;
	sum+=f(x);
	}
	
	res+= 4*sum;
	
	return h*res/3;
}
