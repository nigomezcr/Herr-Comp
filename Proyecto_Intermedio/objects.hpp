#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <cmath>


struct Parameters{
  int xrange = 0;
  int nmol = 0;
  int lattice = 0;
  int Niter = 0;
  int seed = 0;
  double eps = 0;

  void read(const std::string & file);
};

struct Molecule{
  std::vector<double> r{0.0,0.0,0.0};
  void start(const int xrange, const int mol, const int i, const int j);
  void step(int Niter, int seed);
};
