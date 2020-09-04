#include<iostream>
#include<cstdlib>
#include<cmath>

double sum1(int N);
double sum2(int N);
double sum3(int N);

int main(int argc, char *argv[])
{

 std::cout.precision(15);
 std::cout.setf(std::ios::scientific);
 for(int N=4; N<=100; N+=5)
   {
     double exact=sum3(N);
     std::cout << N
	       << "\t"
	       << (exact-sum1(N))/exact 
	       << "\t"
	       << (exact-sum2(N))/exact << "\n";
   }
}



double sum1(int N)
{ 
   double suma = 0.0;
   int sign=-1;
  for (int n=1; n<= 2*N ; n++)
    {
      suma += sign*1.0*n/(n+1);
      sign*=-1;
    }
  return suma;

}
double sum2(int N)
{
  double suma =0.0;
  double suma21 = 0.0;
  double suma22 = 0.0;
  for (int n=1; n<= N ; n++)
    {
      suma21 += - (2.0*n-1)/(2.0*n);
      suma22 += 2.0*n/(2.0*n+1);
      suma = suma21 + suma22;
    }
  return suma;
}

double sum3(int N)
{
   double suma = 0.0;
  for (int n=1; n<= N ; n++)
    {
      suma += 1.0/(2*n*(2*n+1));
    }
  return suma;
}
