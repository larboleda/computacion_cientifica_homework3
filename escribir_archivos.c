#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include"functions.h"

#define PI 3.14159265358979323846

/*code to compute the fuction : f(x)=sin(x)*log(2x+1)*sinh(x)

-The external function "double function()" needs the size of the step. It writtes a file with 3 columns: i,x,f(x) 
-The main fuction calls the prev function and reads the generated file to writte a different file with 2 columns: f(x),x

*/


double funcion(double dx)
{

  int i;
  double a,x,fx;
  FILE *pf;
  
  pf=fopen("written_file.dat","w");

for(i=0;i<=10;i++)
    {
      x=(i*dx)*(PI/180); //x must be in rad
      
      a=2*x+1.0;

      fx=sin(x)*log(a)*sinh(x); 
      fprintf(pf,"%d %lf %lf\n",i,x,fx);    

    }

  fclose(pf);

  return fx;

}


int main(int argc, char *argv[])

{

  int i;
  double dx,f,x,fx;

  dx = atof(argv[1]); 
  
  f=funcion(dx); //it gives the last value of fx that calculate funcion() but what we need with the call is the created 3-col file
 
  FILE *pf,*data;
 

  pf = fopen("written_file.dat","r");
  data = fopen("readed_file.dat","w");
  
  for(i=0;i<=10;i++)
    {
      
      fscanf(pf,"%d %lf %lf\n",&i,&x,&fx);
      
      fprintf(data,"%16.18lf %16.18lf\n",fx,x);    
      
    }
  
  fclose(pf);
  fclose(data);
  
  
  return 0;
}
