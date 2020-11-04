#include<iostream>
#include<random>
#include "objects.hpp"

int main(void)
{

  Parameters data;
  Molecule mol;

  data.read("parameters.txt");
  mol.step(data.Niter, data.seed);




  return 0;
}
