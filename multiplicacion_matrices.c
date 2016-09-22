#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


/*matrix multiplication*/

int i,j,k;
clock_t tbegin, tend;
double t_total;

double case_a(int n, int a[][n], int b[][n])  

{

  int c[n][n];

  for(i=1;i<=n;i++)
    {
      for(j=1;j<=n;j++)
	{
	  for(k=1;k<=n;k++)
	    {
	      c[i][j] += a[i][k]*b[k][j];  //local temporality of c[i,j]
	    }
	}
    }

  tend = clock();

  t_total = (double)((tend*1.0 - tbegin*1.0)/ CLOCKS_PER_SEC);

  return t_total;
}

double case_b(int n, int a[][n], int b[][n])

{

  int c[n][n];

  for(k=1;k<=n;k++)
    {
      for(i=1;i<=n;i++)
	{
	  for(j=1;j<=n;j++)
	    {
	      c[i][j] += a[i][k]*b[k][j];
	    }
	}
    }

  tend = clock();

  t_total = (double)((tend*1.0 - tbegin*1.0)/ CLOCKS_PER_SEC);

  return t_total;
}


int main(int argc, char **argv)

{

 
  int n;
  double t_casea,t_caseb;

  n = atoi(argv[1]); //size of matrices nxn

  int a[n][n],b[n][n];

  //create the matrices a and b. 

  for(i=1;i<=n;i++)
    {
      for(j=1;j<=n;j++)
	{
	  a[i][j]=i;
	  b[i][j]=i*i;
	  //printf("%d\n",a[i][j]);
	}
    }
  //calling every case

  t_casea=case_a(n,a,b); //this implementation should take less time.
  t_caseb=case_b(n,a,b);                                             
                                                          
  printf("****cpu time for two differents way for a matrix multiplication****\n");
  printf("case a: time = %lf \t this takes less time\n",t_casea);
  printf("case b: time = %lf\n",t_caseb);

  return 0;
}
