#include <iostream>
#include <fstream>
#include <string>

void prntnmrs(int a, int b, std::string name);

int main(void)
{
  prntnmrs(1,100, "datas1.txt");
  prntnmrs(1,200, "datas2.txt");
  
  return 0;
}

void prntnmrs(int a, int b, std::string name)
{
  std::ofstream fout(name);
  int ii;
  fout.precision(16);
  fout.setf(std::ios::scientific);     
  for (ii=a; ii<=b; ++ii)
    {
      fout<< ii << '\t' << 1.0/ii<< '\n';
    }
  fout.close();
}
