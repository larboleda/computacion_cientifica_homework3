#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "functions.h"

/*This program computes the relativistic mass of a particle for differents velocities*/

#define m0 1.0 //rest mass in MKS 
#define C 2.9979e8 //speed of light in MKS

#include "functions.h"

int main (int argc, char **argv)
{
  int i;
  double dv,v,m;
  dv=atof(argv[1]); //increment between the values of v
  
  FILE *pf;
  pf=fopen("mass_data.dat","w");
  for(i=0;i<C;i +=dv)
    
    {
      v = i;
      m = relativistic_mass(m0,v);
      fprintf(pf,"%lf %16.8e %16.8e\n",v,v/C,m);
    }
  
  fclose(pf);
  
  return 0;
}
