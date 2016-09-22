#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int i,j;
clock_t tbegin,tend;
double t_total;
double *x,*y;

/* TEMPORAL LOCALITY*/

/*loop1: in this implementation we must move through the whole array x (every direction of mem) for every single j iteration, so at the end, x[i] won't be at the cachefor enough time. We use x[i] with a period of N times per j */

double loop1(int N, double *x)

{

  //double y[N];
  tbegin = clock();

  for(j=0;j<10;j++)
    {
      for(i=0;i<N;i++)
	{

	  y[i]=x[i]*j;
	  
	}
    }
  tend = clock();

  t_total = (double)((1.0*tend - 1.0*tbegin) / CLOCKS_PER_SEC);

  return t_total;
}

/*

in the following implementation lopp2: x[i] will be more time in the cache, because  for every iteration of j, we are fixing i, so, x[i] register is called once for all j. So, at the end, we call the register of x[i] N times in total.   We call x[i] every 10 operations. 

*/
double loop2(int N, double *x) //this implementation should take less time.  

{

  //  double y[N];
  tbegin = clock();

      for(i=0;i<N;i++)
	{
	  
	  for(j=0;j<10;j++)
	    {
      
	      y[i]=x[i]*j;
	      
	    }
	}
      tend = clock();
      
      t_total = (double)((1.0*tend - 1.0*tbegin) / CLOCKS_PER_SEC);
      
      return t_total;
}


int main (int arg, char **argv)

{

  int N;
  N = atoi(argv[1]); //array size
  double t_loop1,t_loop2;

  //allocating memory for arrays

  x = (double *)malloc(N*sizeof(double));
  y = (double *)malloc(N*sizeof(double));

  for(i=0;i<N;i++)

    {
     
      x[i]=1.0*i;

    }

  t_loop1=loop1(N,x);
  t_loop2=loop2(N,x); //this implementation should take less time.

  printf("****cpu time for two differents implementation of a loop (operating with x[i])****\n");
  printf("internal loop i: time = %lf\n",t_loop1);
  printf("external loop i: time = %lf \t this takes less time\n",t_loop2);


  free(x);
  free(y);
  
  return 0;
}
