#include <iostream>
#include <cmath>
#include <stdlib.h>
#include<fstream>

//Global variables declaring
const double G=9.8;
const double dt=0.1; //Step for th method //M_PI/300.0;

class Pendulum
{
public:
  double L; //Lenght
  double q; //Friction coeficient
  double Fd; //External Force
  double Omega; //External force frequency
  double W; //Angular velocity 
  double Theta; //Angle
  Pendulum();// Initial values for the class
  ~Pendulum();//Anihilator
};
Pendulum::Pendulum()
{
  L=0.0;
  q=0.0;
  Fd=0.0;
  Omega=0.0;
  W=0.0;
  Theta=0.0;
}
Pendulum::~Pendulum()
{
}

//------------------------------Function declaring----------------------------
void initial_conditions(Pendulum & p, double F, double inic);
void euler_cromer(Pendulum & p,double t);


int main(int argc, char** argv)
{
  Pendulum p;
  
  
  int MET=atoi(argv[1]);
  int N = atoi(argv[2]);//steps of evolution
  double Fo = 0;//El Fd inicial
  double Ff= 1.35;
  if(N==1){std::cout<<"Hello";}
  else{
    
  for (float jj=Fo; jj<=Ff; jj+=0.05)
    {
      for (double ini=-M_PI; ini<=M_PI; ini+=0.05){
      double t=0.0;//Time 
       // intialization
      initial_conditions(p,jj,ini);
      for (int ii=1; ii<=N; ii++)
        {
          euler_cromer(p,t);
          std::cout << N << "\t" << jj << "\t"<< ini << "\t" << t << "\t" << p.Theta << "\t" << p.W  << std::endl;
          t+=dt;
        }
    }}}
  return 0;
}


// ------------------- Functions ------------------------------------
void euler_cromer(Pendulum & p,double t)
{
  // Euler- Cromer
  p.W=p.W+(-(G/p.L)*sin(p.Theta) - p.q*p.W + p.Fd*sin(p.Omega*t))*dt; // valor de w para una fase de la Fd de 0, 
  p.Theta=p.Theta + p.W*dt;
    
  // lo siguiente es para establecer que Theta este en el rango de PI
  if(p.Theta < - M_PI)
    {
      p.Theta += 2*M_PI;
    }
  else if(p.Theta > M_PI)
    {
      p.Theta += -2*M_PI;
    }
} 
 
void initial_conditions(Pendulum & p, double F, double I)
{
  p.q=0;
  p.Fd=F;
  p.Omega=0.666;
  p.L=G; // con este valor de L se consigue que el cuadrado de laa frecuencia angular sea 1.
  p.W=0.0;
  p.Theta=I;  
}