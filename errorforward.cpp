#include <iostream>
#include <cmath>


double f(double x);
double fdevforward(double x, double h);
double fdevcentral(double x, double h);
double fdevrichfor(double x, double h);
double fdevrichcen(double x, double h);
double erpor(double x, double h);

const double PI=acos(-1);

int main(void)
{
  double x=PI/3;
  double h=0.1;
  for(h=1.0;h>=1e-9;h/=1.1)
    {
      std::cout<<h<<'\t'<<std::log(erpor(x,h))<<'\n';
    }
  
  return 0;
}


double f(double x)
{
  double b;
  b=std::sin(x);
  return b;
}

double fdevforward(double x, double h)
{
  double a;
  a=(f(x+(h))-f(x))/(h);
  return a;
}

double fdevcentral(double x, double h)
{
  double a;
  a=(f(x+(h/2))-f(x-(h/2)))/(h);
  return a;
}

double fdevrichfor(double x, double h)
{
  double h2=h/2;
  double res1= fdevforward(x,h);
  double res2= fdevforward(x,h2);
  double res= (4*res2-res1)/3;
  return res;
}

double fdevrichcen(double x, double h)
{
  double h2=h/2;
  double res1= fdevcentral(x,h);
  double res2= fdevcentral(x,h2);
  double res= (4*res2-res1)/3;
  return res;
}

double erpor(double x, double h)
{
  double a;
  a=std::abs(1-(fdevforward(x,h)/std::cos(x)));
  return a;
}

