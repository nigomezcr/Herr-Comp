#include <iostream>
#include <fstream>
#include <chrono>
#include <stdlib.h> // para el new y delete del arreglo dinamico
#include "functions.hpp"

int nmol;
int lattice;
int Niter;
int seed;

int main(void)
{
  std::fstream file, saveS, saveR, saveM;
  file.open("parameters.csv");
  saveS.open("entropy.txt", std::ios::app);
  saveR.open("drop_size.txt", std::ios::app);
  saveM.open("total_molecules.txt", std::ios::app);

  file >> nmol
       >> lattice
       >> Niter
       >> seed;

  double Entropy;
  double DropR;
  double TotalMol;
  double pos[nmol][2]={};

  double **lattice_array;

  //reservar memoria para el areglo
  lattice_array = new double*[lattice];
    for(int i=0; i<lattice; i++){
      lattice_array[i] = new double[lattice];
      }

      for(int Nsteps = 0; Nsteps < Niter ; Nsteps++)
      {
       for(int i=0; i<lattice; i++){
          for(int j=0; j<lattice; j++){
      *(*(lattice_array+i)+j) = 0;
          }
        }

        walk(1, Nsteps, seed, lattice, pos, lattice_array);

        show_position(1, pos);


        }
/*
  for(int Nsteps = 0; Nsteps < Niter ; Nsteps++)
  {
   for(int i=0; i<lattice; i++){
      for(int j=0; j<lattice; j++){
  *(*(lattice_array+i)+j) = 0;
      }
    }

    walk(nmol, Nsteps, seed, lattice, pos, lattice_array);

    TotalMol = total_molecules(lattice, lattice_array);

    DropR = drop_size(nmol, pos);
    Entropy=entropy(nmol, lattice, pos, lattice_array);

    saveR << Nsteps << "\t" << DropR << '\n';
    saveS << Nsteps << "\t" << Entropy << "\n";
    }

  for(int Nsteps = 0; Nsteps < Niter ; Nsteps++)
  {
    for(int i=0; i<lattice; i++){
      for(int j=0; j<lattice; j++){
	*(*(lattice_array+i)+j) = 0;
      }
    }

    walk_with_hole(nmol, Nsteps, seed, lattice, pos, lattice_array);
    TotalMol = total_molecules(lattice, lattice_array);

    saveM << Nsteps << "\t" << TotalMol << '\n';
  }

//Para visualizar arreglo: descomentar lo siguiente
/* for(int Nsteps = 0; Nsteps < 15 ; Nsteps++)
  {

    for(int i=0; i<lattice; i++){
      for(int j=0; j<lattice; j++){
  *(*(lattice_array+i)+j) = 0;
      }
    }


    std::cout << "-------   t = " << Nsteps << "   --------------" << '\n';
    walk_with_hole(nmol, Nsteps, seed, pos, lattice_array);
    show_lattice(lattice_array);
    TotalMol=total_molecules(lattice_array);
    std::cout << "-------   N =  " << TotalMol << "   --------------" << '\n';
  }*/


  //Para liberar la memoria en el arreglo
  for(int i=0; i<lattice; i++){
    delete[] lattice_array[i];
  }

  delete[] lattice_array;

  file.close();
  saveS.close();
  saveR.close();
  saveM.close();

  return 0;
}
