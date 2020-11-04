#include "objects.hpp"


void Parameters::read(const std::string & filename)
{
std::fstream file;
file.open(filename);

file >> nmol
     >> lattice
     >> Niter
     >> seed;

     file.close();
}

void Molecule::start(const int xrange, const int nmol, const int i, const int j)
{
  r[0] = xrange/2 - std::sqrt(nmol)/2 + i;
  r[1] = xrange/2 - std::sqrt(nmol)/2 + j;
  r[2] = r[0] + r[1]*xrange;
  std::cout << r[0] << "\t" << r[1] << std::endl;
}

void Molecule::step(int Niter, int seed)
{
  //std::random_device rd;
  std::mt19937 gen(seed); //declarando al generador
  std::uniform_real_distribution<double> dis(0,1);

  for(int t = 0; t <= Niter; t++)
    {
      r[0] += (dis(gen)- 0.5);
      r[1] += (dis(gen)- 0.5);
      std::cout << r[0] << "\t" << r[1] << std::endl;
    }

}
