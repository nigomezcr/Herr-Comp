//Program to solve Ax=b
#include <iostream>
#include <Eigen/Dense>


int main()
{
  int N = 3;
  Eigen::MatrixXd A(N,N);
  Eigen::VectorXd b(N);
   A << 1,2,3,  4,5,6,  7,8,10;
   b << 3, 3, 4;
   
   std::cout << "Here is the matrix A:\n" << A << std::endl;
   std::cout << "Here is the vector b:\n" << b << std::endl;
   
   Eigen::VectorXd x(N) ;
   x = A.colPivHouseholderQr().solve(b);
   std::cout << "The solution is:\n" << x << std::endl;
   std::cout << "Error" << (A*x-b).norm() << std::endl;
   
}
