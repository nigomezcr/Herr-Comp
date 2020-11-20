#include <iostream>
#include <cmath>
#include <functional>
#include <mpi.h>
#include <chrono>

using fptr  = double(double);


double f(double x);
double simpson(fptr fun, double *data, int ns, int nslocal, int pid, int nproc);
void print(double *data, int ns, int nslocal, int pid, int nproc);
void print_local(double *data, int ns, int nslocal, int pid, int nproc);


const int N = 6000000;
const double xmin = 0.0;
const double xmax = 100.0;

int main(int argc, char **argv)
{
    MPI_Init(&argc, &argv);
    int pid = 0, nthreads = 0;

    MPI_Comm_rank(MPI_COMM_WORLD, &pid);
    MPI_Comm_size(MPI_COMM_WORLD, &nthreads);

    const int NSlocal = N/nthreads;
    const double h = (xmax-xmin)/N;
    double * array = new double [N] {0.0};
    double * data = new double [nthreads] {0.0};

    for (int i = 0; int < N; i++)
    {
      array[i] = xmin + i*h;
    }   
    std::cout.precision(05); std::cout.setf(std::ios::scientific);


    double integral  = simpson(f, array, N, NSlocal, nthreads);


    std::cout << "tiempo:\t";


    std::cout << "valor de la integral:\t" << integral << '\n';

    MPI_Finalize();
    return 0;
}

double f(double x)
{
    return std::pow(x,2);
}


void print(double *data, int ns, int nslocal, int pid, int nproc)
{
 int tag = 0;
  if (0 == pid) {
    double * aux = new double [nslocal] {0.0};
    print_local(data, ns, nslocal, pid, nproc);
    for (int src = 1; src < nproc; ++src) {
      MPI_Recv(aux, nslocal, MPI_DOUBLE, src, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      print_local(aux, ns, nslocal, src, nproc);
    }
    delete [] aux;
  } else {
    int dest = 0;
    MPI_Send(data, nslocal, MPI_DOUBLE, dest, tag, MPI_COMM_WORLD);
  }
}


void print_local(double *data, int ns, int nslocal, int pid, int nproc)
{
  std::cout << "pid: " << pid << "\n";
  for (int ilocal = 0; ilocal < nslocal; ++ilocal) {
    std::cout << data[ilocal] << "  ";
  }
  std::cout << "\n";
}




double simpson(fptr fun, double *data, int ns, int nslocal, int pid, int nproc)
{
  int tag = 0;
    double suma = 0;
    double aux1 = 0, aux2 = 0;

    sum = std::accumulate(data, data+nslocal, 0.0);

    if(0 == pid){
      double aux;
      for(int ii = 1; ii <= N/2-1; ++ii) {
        MPI_Recv(&aux, 1, MPI_DOUBLE, ii, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        data[ii] = xmin + 2*ii*h;
        aux1 += fun(data[ii]);
      }
      for(int ii = 1; ii <= N/2; ++ii) {
        MPI_Recv(&aux, 1, MPI_DOUBLE, ii, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        data[ii] = xmin + (2*ii-1)*h;
        aux2 += fun(data[ii]);
      }
      suma = h*(fun(a) + 2*aux1 + 4*aux2 + fun(xmax))/3;
    }  else {
      int dest = 0;
      MPI_Send(&suma, 1, MPI_DOUBLE, dest, tag, MPI_COMM_WORLD);
    }
    return suma;
}
