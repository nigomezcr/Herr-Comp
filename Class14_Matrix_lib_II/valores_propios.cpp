#include <iostream>
#include <cstdlib>
#include <eigen3/Eigen/Eigenvalues>
#include <chrono>

double eigenvalue(int n);

int main(int argc, char **argv)
{
    std::cout.precision(15); std::cout.setf(std::ios::scientific);
    int N = std::atoi(argv[1]);
    int REPS = std::atoi(argv[2]);

    double t = 0;
    for (int irep = 0; irep < REPS; ++irep) {
        t += eigenvalue(N);
    }
    std::cout << t/REPS << std::endl;

    return 0;
}


double eigenvalue(int n)
{
   Eigen::MatrixXd A(n, n);
   A = Eigen::MatrixXd::Random(n, n);
   auto start = std::chrono::steady_clock::now();
   Eigen::EigenSolver<Eigen::MatrixXd> b(A, false);
   Eigen::EigenSolver<Eigen::MatrixXd> B(A);

   //std::cout << "Here is the matrix A:\n" << A << std::endl;
   //std::cout << "Here is the Eigenvalues of A:\n" << b.eigenvalues() << std::endl;
   //std::cout << "Here is the first eigenvector of A:\n" << B.eigenvectors().col(0) << std::endl;

   auto end = std::chrono::steady_clock::now();
   double time = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count()*1.0e-9;
   
   return time;

}
