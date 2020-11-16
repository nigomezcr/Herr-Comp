#include <iostream>
#include <cmath>
#include <functional>
#include <omp.h>
#include <chrono>

using fptr  = double(double);

void print_elapsed(auto start, auto end);
double f(double x);
double simpson(fptr fun, double a, double b, int nthreads);

const int N = 1000000;
const double xmin = 0.0;
const double xmax = 10.0;

int main(int argc, char **argv)
{
    const int NTH = std::atoi(argv[1]);
    std::cout.precision(6); std::cout.setf(std::ios::scientific);

    auto start  = std::chrono::steady_clock::now();
    double integral  = simpson(f, xmin, xmax, NTH);
    auto end  = std::chrono::steady_clock::now();
    print_elapsed(start, end);

    //std::cout << integral << '\n';

    return 0;
}

double f(double x)
{
    return std::pow(x,2);
}



double simpson(fptr fun, double a, double b, int nthreads)
{

    const double h = (b-a)/N;
    double suma = 0;

    #pragma omp parallel num_threads (nthreads)
    {
      double aux1 = 0, aux2 = 0;
      int nth = omp_get_num_threads();
      int tid = omp_get_thread_num();
      int SL = N/nth;

      for(int ii = 1; ii <= N/2 - 1; ++ii) {
        double x = a + 2*ii*h;
        aux1 += fun(x);
      }
      for(int ii = 1; ii <= N/2; ++ii) {
        double x = a + (2*ii-1)*h;
        aux2 += fun(x);
      }

      #pragma omp critical
      suma = h*(fun(a) + 2*aux1 + 4*aux2 + fun(b))/3;
    }
    return suma;
}

void print_elapsed(auto start, auto end)
{
  std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count()/1000.0 << "\n";
}
