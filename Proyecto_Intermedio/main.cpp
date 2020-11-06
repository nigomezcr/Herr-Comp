#include <iostream>
#include <fstream>
#include "functions.hpp"

int nmol;
int Niter;
int seed;
int lattice2;

int main(void)
{
  std::fstream file, saveS, saveR;
  file.open("parameters.csv");
  saveS.open("entropy.txt", std::ios::app);
  saveR.open("drop_size.txt", std::ios::app);

  file >> nmol
       >> lattice2
       >> Niter
       >> seed;

  double Entropy;
  double DropR;
  double TotalMol;
  double pos[nmol][2]={};
/*
  for(int Nsteps = 0; Nsteps < Niter ; Nsteps++)
  {
    double lattice_array[lattice][lattice]={};

    walk(nmol, Nsteps, seed, pos, lattice_array);

    DropR = drop_size(nmol, pos);
    Entropy=entropy(nmol, pos, lattice_array);

    saveR << Nsteps << "\t" << DropR << '\n';
    saveS << Nsteps << "\t" << Entropy << "\n";
  }
*/
  for(int Nsteps = 0; Nsteps < Niter ; Nsteps++)
  {
    double lattice_array[lattice][lattice]={};

    walk_with_hole(nmol, Nsteps, seed, pos, lattice_array);
    TotalMol = total_molecules(lattice_array);

    std::cout << Nsteps << "\t" << TotalMol << '\n';
  }
/*
//Para visualizar arreglo: descomentar lo siguiente
 for(int Nsteps = 0; Nsteps < 55 ; Nsteps++)
  {
    double lattice_array[lattice][lattice]={};
    std::cout << "-------   t = " << Nsteps << "   --------------" << '\n';
    walk_with_hole(nmol, Nsteps, seed, pos, lattice_array);
    show_lattice(lattice_array);
    TotalMol=total_molecules(lattice_array);
    std::cout << "-------   N =  " << TotalMol << "   --------------" << '\n';
  }*/

  file.close();
  saveS.close();
  saveR.close();

  return 0;
}
