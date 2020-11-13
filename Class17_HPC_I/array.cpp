#include <iostream>
#include <cstdlib>
#include <cmath>

int main(int argc, char **argv)
{
  const int N = std::atoi(argv[1]);
  double * data = new double[N];
  //Fill the array
  for (int ii = 0; ii < N ; ++ii)
  {
    data[ii] = 2*std::sin(ii) + std::log(ii+1);
  }

  //print
  std::cout << data[N/2] << std::endl;

  delete[] data;
  return 0;

}
