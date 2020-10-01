#include<iostream>

int main(int argc, char **argv)
{
  double under=1.;
  double over=1.;
  int N = 1100;
  
  for(int ii=1 ; ii<N; ii++)
    {
      under = under /2.;
      over=over*2.;
      std::cout << ii << "\t" << under << "\t" << over << "\n";
    }


  return 0;

  
}
