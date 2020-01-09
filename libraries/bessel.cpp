#include <iostream>
#include <gsl/gsl_sf_bessel.h>

int main (void)
{
  const double DX = 0.01;
  for(int ii = 0; ii <= 2000; ++ii) {
    double x = 0 + ii*DX;
    std::cout << x << "    " << gsl_sf_bessel_J0(x) << "\n";
  }
  
  return 0;
}
