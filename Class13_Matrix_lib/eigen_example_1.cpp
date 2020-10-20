#include<iostream>
#include<Eigen/Dense>


int main()
{
  Eigen::MatrixXd m(2,2);
  m(0,0) = 3;
  m(1,0) = 2.5;
  m(0,1) = -1;
  m(1,1) = m(1,0) + m(0,1);

  Eigen::MatrixXd n(2,2);
  n(0,0) = 6;
  n(0,1) = 1.1;
  n(1,0) = 0.8;
  n(1,1) = m(0.0) + n(0,0);
  
  std::cout << m << std::endl;
  std::cout << n << std::endl;
  return 0;
}
