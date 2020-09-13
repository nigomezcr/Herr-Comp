#include<iostream>
#include<random>

int main(void)
{
  const int N = 10000;
  const int NBINS = 20;
  const int seed = 1;
  const double Xmin=0.0 , Xmax=1.0, dx=(Xmax-Xmin)/NBINS;

  double histo[NBINS]={0.0};
  
  //std::random_device rd; 
  std::mt19937 gen(seed); //declarando al generador
  std::uniform_real_distribution<double> dis(0,1);

  for(int n = 0; n < N; ++n)
    {
      double r=dis(gen);
      int bin = int((r-Xmin)/dx);
      histo[bin] +=1;
    }

  for(int ii = 0; ii < NBINS; ++ii)
    {
      std::cout << Xmin +  ii*dx << "\t" <<  histo[ii] << "\n";
    }
  return 0;
}
