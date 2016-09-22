#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "functions.h"

/*implementation of compute a sum breaking it in several terms. the firs wutin computes the standard way to do the sum. it gives the execution time for every way.*/

clock_t tbegin,tend;

double standard_way(double *x, int N)
{
 
  double t_total;
  int i;
  double sum;

  sum = 0.0;
  tbegin = clock();
  for (i=0;i<N;i++)
   {
     sum += sum + x[i];
   }
  tend=clock();
  t_total = (double)((1.0*tend -1.0*tbegin)/CLOCKS_PER_SEC);
  
  return t_total;
}


int main (int argc, char **argv)

{
  double *x,sum,cpu_time,cpu_time_standard;
  int N,i,s,step;
  double t_total;
                                                                                                                                   
  N=atoi(argv[1]); //array size
  step =atoi(argv[2]); //sumas de a cuantos terminos ? 
                                                                                                  
  x = (double *)malloc(N * sizeof(double));

  for(i=0;i<N;i++)
    {
      x[i]=i*1.0;
    }

  //time standard way
 cpu_time_standard = standard_way(x,N);
 printf("for the standard way it takes %lf seg\n",cpu_time_standard);

 //back to the initial values of *x
for(i=0;i<N;i++)
    {
      x[i]=i*1.0;
    }

  //second way to made the sum:
 tbegin = clock();
 sum = 0.0;
 for(s=step;s<N;s+=step)
   {
     for(i=0;i<N;i+=s)
       {
	 
	 x[i] = x[i] + x[i+s/2];
	 
       }
   }
 tend = clock();
 t_total = (double)((1.0*tend - 1.0*tbegin)/CLOCKS_PER_SEC);


 //time non-standard way
 printf("for the non-standard way it takes %lf seg\n",t_total);

 free(x);

  return 0;
}
