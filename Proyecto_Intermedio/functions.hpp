#ifndef __functions_HPP
#define __functions_HPP

#include <random>
#include <iostream>

//const int lattice=50;

//functions declarations

void walk(int tmol, int Nsteps, int seed, int lattice, double pos[][2], double **la);
void walk_with_hole(int tmol, int Nsteps, int seed, int lattice, double pos[][2], double **la);
void show_position(int nm, double pos[][2]);
void show_lattice(int lattice, double **la);
double entropy(int nmol, int lattice, double pos[][2], double **la);
double drop_size(int nm, double pos[][2]);
double total_molecules(int lattice, double **la);


#endif //__functions_HPP
