//Código para los polinomio de Legendre de orden dos
#include<iostream>
#include<cmath>

int main(void)
{
  std::cout.precision(15); std::cout.setf(std::ios::scientific);
  
  const double Xmin = -1.0, Xmax=1.0, dx = 0.01;
  double n=5;
  
  for(double x = Xmin ; x<= Xmax  ;x+=dx)
    {
      std::cout << x << "\t" << std::legendre(n,x) << "\n";
    }
  
  return 0;
  
}
