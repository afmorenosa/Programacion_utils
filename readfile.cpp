#include <iostream>
#include <fstream>
#include <string>

void readnmrs(std::string name);

int main(void)
{
  readnmrs("datas1.txt");
  readnmrs("datas2.txt");
  
  return 0;
}

void readnmrs(std::string name)
{
  std::ifstream fin(name);
  int n;
  double x;
  double sum=0;
  while(fin){
    fin>>n>>x;
    sum+=x;
  }
  std::cout <<"La suma de los x es: " << sum<<std::endl;

  fin.close();
}
