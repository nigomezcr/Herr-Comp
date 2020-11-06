#include "functions.hpp"



void walk(int tmol, int Nsteps, int seed, double pos[][2], double la[][lattice])
{
    //std::random_device rd;
  std::mt19937 gen(seed);    //declarando al generador
  std::uniform_real_distribution<double> dis(-1,1);

  for(int i = 0; i < tmol ; i++)
  {
    for(int t = 0; t <= Nsteps; t++)
    {
      pos[i][0] += dis(gen);
      pos[i][1] += dis(gen);

      if(pos[i][0] >= lattice/2){
  	     pos[i][0] += -abs(dis(gen)) - 1;
      }
      if(pos[i][0] < -lattice/2){
  	     pos[i][0] += abs(dis(gen)) + 1;
      }
      if(pos[i][1] >= lattice/2){
  	     pos[i][1] += -abs(dis(gen)) - 1;
      }
      if(pos[i][1] < -lattice/2){
  	     pos[i][1] += abs(dis(gen)) + 1;
      }
    }

    double x = pos[i][0]+0.5*lattice;
    double y = pos[i][1]+0.5*lattice;

    la[(int)x][(int)y] += 1;
  }
}




void show_position(int nm, double pos[][2])
{

  for(int i=0; i<nm; i++)
  {
    std::cout << pos[i][0] << "\t" << pos[i][1] << std::endl;
  }
  std::cout << std::endl;

}



void show_lattice(double la[][lattice])
{
    for(int i=(lattice-1); i>=0; i--){
      for(int j=0; j<lattice; j++){
        std::cout << la[i][j] << " ";
      }
      std::cout << std::endl;
    }
}




double entropy(int nmol, double pos[][2], double la[][lattice])
{
  double S = 0;
  double Prob[lattice][lattice]={};

  for(int i = 0; i < lattice; i++)
  {
    for(int j = 0; j < lattice; j++)
    {
      Prob[i][j] = la[i][j]/nmol;
      if(la[i][j]==0){
        0;
      }
      else{
        S += -Prob[i][j]*std::log(Prob[i][j]);
      }
    }
  }
  return S;

}



double drop_size(int nm, double pos[][2])
{

  double r2[nm] = {};
  double rms = 0;

  for (int i = 0; i < nm; i++)
  {
    r2[i] = pos[i][0]*pos[i][0] + pos[i][1]*pos[i][1];
    rms += r2[i] ;
  }
  return std::sqrt(rms / nm );

}



void walk_with_hole(int tmol, int Nsteps, int seed, double pos[][2], double la[][lattice]){

  std::mt19937 gen(seed);    //declarando al generador
  std::uniform_real_distribution<double> dis(-1,1);
  int hole = 4;

  for(int i = 0; i < tmol ; i++)
  {
    for(int t = 0; t <= Nsteps; t++)
    {
      pos[i][0] += dis(gen);
      pos[i][1] += dis(gen);

      if(pos[i][0] >= lattice/2 && pos[i][1] >= hole/2){
	       pos[i][0] += -abs(dis(gen)) - 1;
      }
      if(pos[i][0] >= lattice/2 && pos[i][1] <= -hole/2){
	       pos[i][0] += -abs(dis(gen)) - 1;
      }
      if(pos[i][0] < -lattice/2){
	       pos[i][0] += abs(dis(gen)) + 1;
      }
      if(pos[i][1] >= lattice/2){
	       pos[i][1] += -abs(dis(gen)) - 1;
      }
      if(pos[i][1] < -lattice/2){
	       pos[i][1] += abs(dis(gen)) + 1;
      }
    }

    double x = pos[i][0]+0.5*lattice;
    double y = pos[i][1]+0.5*lattice;

    la[(int)y][(int)x] += 1;
  }
}


double total_molecules(double la[][lattice])
 {

   int cont = 0.0;

   for(int i = 0; i < lattice; i++)
   {
     for(int j = 0; j < lattice; j++)
     {
       if(la[i][j]==0){
         0;
       }
       else{
         cont += la[i][j];
       }
     }
   }
   return cont;
}
