#include<iostream>
#include<cmath>

float f1(float x);
float f2(float x);
float f3(float x);


int main(void)
{

 std::cout.precision(7);
 std::cout.setf(std::ios::scientific);
 
  for(float i=0; i<=1.0; i+=0.01)
    {
      std::cout << i << "\t" << f1(i) << "\t" << f2(i) << "\t"<<f3(i)<< "\n"; 
    }

  return 0;

}

float f1(float x)
{
  return 5 - std::sqrt(25 + x*x);
}

float f2(float x)
{
  return -x*x/(5+std::sqrt(25+x*x));
}

float f3(float x)
{
  return 5 - std::sqrt(std::pow(5-x,2) + 10*x);
}
