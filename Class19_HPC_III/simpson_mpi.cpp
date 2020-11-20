#include <iostream>
#include <cmath>
#include <functional>
#include <mpi.h>


using fptr  = double(double);

void suma(double *data, int NSlocal, int pid, int nproc, double vl);
double f(double x);
double simpson(fptr fun, double a, double b, int N);

const int N = 8000000;
const double xmin = 0.0;
const double xmax = 100.0;

int main(int argc, char **argv)
{

  std::cout.precision(5); std::cout.setf(std::ios::scientific);
    
    MPI_Init(&argc, &argv);
    int pid = 0, nthreads = 0;

    MPI_Comm_rank(MPI_COMM_WORLD, &pid);
    MPI_Comm_size(MPI_COMM_WORLD, &nthreads);
    
    double NSlocal = xmax/nthreads;
    double valorlocal = 0, *data = 0;
    
    double start = MPI_Wtime();
    valorlocal = simpson(f,NSlocal*pid,NSlocal*(pid+1),N/nthreads);

    
    
    data = &valorlocal;
    /* 
    std::cout << "pid: " << pid << "\n"
	      << "valorlocal: " << *data << "\n";
    
    std::cout << "\n\n";
    */

    suma(data, NSlocal, pid, nthreads, valorlocal);
    double end = MPI_Wtime();
    if (pid==0){
    std::cout  << end- start << "\n";
    }
    MPI_Finalize();
    
    return 0;
}

double f(double x)
{
    return std::pow(x,2);
}


double simpson(fptr fun, double a, double b, int N)
{

    const double h = (b-a)/N;
    double suma = 0;
    double aux1 = 0, aux2 = 0;
 
      for(int ii = 1; ii <= N/2 - 1; ++ii) {
        double x = a + 2*ii*h;
        aux1 += fun(x);
      }
      for(int ii = 1; ii <= N/2; ++ii) {
        double x = a + (2*ii-1)*h;
        aux2 += fun(x);
      }
      suma = h*(fun(a) + 2*aux1 + 4*aux2 + fun(b))/3;

    return suma;
}


void suma(double *data, int NSlocal, int pid, int nproc, double vl)
{
  int tag = 0;
  double sum = 0.0;
  if (0 == pid) {
    sum = vl;
    double aux;
    for (int src = 1; src < nproc; ++src) {
      MPI_Recv(&aux, 1, MPI_DOUBLE, src, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      sum += aux;
    }
    //  std::cout << "valor de la integral con " << nproc << " procesos: "  << sum << '\n';
  } else {
    int dest = 0;
    MPI_Send(data, 1, MPI_DOUBLE, dest, tag, MPI_COMM_WORLD);
  }
}
