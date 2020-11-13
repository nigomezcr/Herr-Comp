#include<iostream>
#include<omp.h>
int main(int argc, char **argv)
{
  double x = 25; //global variable
  #pragma omp parallel
  {
     int tid = omp_get_thread_num();
     int nth = omp_get_thread_num();

     double y = 50.1; //private variable
     std::cout << "My tid: " << tid << std::endl;
     std::cout << "Hello World, from tid: " << tid << "\n";
  }
  
  return 0;
}
