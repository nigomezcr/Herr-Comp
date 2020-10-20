#include<iostream>
#include<Eigen/Dense>


int main(int argc, char **argv)
{
  //uniforme entre -1, 1
  Eigen::MatrixXd m = Eigen::MatrixXd::Random(3,3);
  std::cout << m << std::endl;

  return 0;
}
