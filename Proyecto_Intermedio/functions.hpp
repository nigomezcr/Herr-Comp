#ifndef __functions_HPP
#define __functions_HPP

#include <random>
#include <iostream>


const int lattice=8;



//functions declarations

void walk(int tmol, int Nsteps, int seed, double pos[][2], double la[][lattice]);
void show_position(int nm, double pos[][2]);
void show_lattice(double la[][lattice]);
void walk_with_hole(int tmol, int Nsteps, int seed, double pos[][2], double la[][lattice]);
double entropy(int nmol, double pos[][2], double la[][lattice]);
double drop_size(int nm, double pos[][2]);
double total_molecules(double la[][lattice]);


#endif //__functions_HPP
