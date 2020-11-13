//Program to simulate a falling body under the influence of gravity
#include<iostream>
#include<fstream>
#include<vector>
/*We need to define the 'body' class: an object with
        - mass(density),
        - form=sphere,
        - position r(3),
        - velocity v(3),
        - force f(3)

  External conditions:
        - gravity

  Functions:
        - initial conditions

        - timestep (new position and velocity)
        - strat time integration
        - compute_force

        - print system
        -visualization
*/

//body
struct body {
  double mass;
  double r[3],v[3], f[3];
};

//simulation conditions
const int N = 1;
const int g = 9.8;
const double DT = 0.1;

//helper functions
void initial_conditions(std::vector<body> & bodies);
void time_step(std::vector<body> & bodies, double dt);
void start_time_integration(std::vector<body> & bodies, double dt);
void compute_force(std::vector<body> & bodies);
void print_system(const std::vector<body> & bodies, double time);

int main(void)
{
  std::vector<body> bodies(N);

  initial_conditions(bodies);
  compute_force(bodies);
  print_system(bodies, 0);
  return 0;
}

void initial_conditions(std::vector<body> & bodies)
{
  /*
        z |
          |
          |
          |_ _ _ _ _ y
         /
       /
    x/ */

  bodies[0].mass = 1.23;
  bodies[0].r[2] = 7.86;
  bodies[0].v[2] = 1.32;

}

void time_step(std::vector<body> & bodies, double dt);
void start_time_integration(std::vector<body> & bodies, double dt);

void compute_force(std::vector<body> & bodies)
{
  //reset forces
  for(auto & cuerpo: bodies)
  {
    cuerpo.f[0] = cuerpo.f[1] = cuerpo.f[2] = 0.0;
  }

  for(auto & cuerpo: bodies)
  {
    //add gravity
    cuerpo.f[2] -= cuerpo.mass*g;
  }

}

void print_system(const std::vector<body> & bodies, double time)
{
  std::ofstream fout("dataMD.txt", std::ofstream::out);
  fout.precision(5); fout.setf(std::ios::scientific);

  for(const auto & cuerpo: bodies)
  {
      fout << cuerpo.r[0] << " " << cuerpo.r[1] << " " << cuerpo.r[2] << "  "
           << cuerpo.v[0] << " " << cuerpo.v[1] << " " << cuerpo.v[2] << "  "
           << cuerpo.f[0] << " " << cuerpo.f[1] << " " << cuerpo.f[2] << "  "
           << cuerpo.mass << "\n";
  }
}
