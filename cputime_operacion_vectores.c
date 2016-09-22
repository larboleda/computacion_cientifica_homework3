#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*this coe computes the cpu time for a loop :  
  
  a[i]=b[i] * c
  
  and for a loop computing the matrix A

  A[i][k]=B[i][k] *c[k]

  the inputs are the dimension of the arrays rows (length) and columns (nvectors)
*/

clock_t tbegin, tend;
double t_total;
int length, nvectors;

double vector_case(double *a, double *b)
//int vector_case(int *a, int *b)
{

   double c = 2.0;
  //  int c =2;
  int i;
  tbegin=clock();

  for(i=0;i<length;i++)

    {
      a[i]=b[i]*c;
    } 

  tend=clock();
  t_total = (double)((1.0*tend - 1.0*tbegin) / CLOCKS_PER_SEC);
  
  return t_total;
}

double matrix_case(double A[][nvectors],double B[][nvectors], double *c)
//int matrix_case(int A[][nvectors],int B[][nvectors], int *c)
{

  int i,k;
  tbegin=clock();
  for(k=1;k<nvectors;k++)
    {
      for(i=0;i<length;i++)

	{
	  
 	  A[i][k]=B[i][k]*c[k];

	} 

    }      
      tend=clock();
      t_total = (double)((1.0*tend - 1.0*tbegin) / CLOCKS_PER_SEC);
      
      return t_total;
    }
  

int main(int argc, char **argv)

{

  int i,j;

  double t__total;
  double tcpu_vectors, tcpu_matrix;  

  length = atoi(argv[1]);
  nvectors = atoi(argv[2]);   

  double a[length],b[length];
  //  int a[length],b[length];
  double A[length][nvectors],B[length][nvectors];
  //int A[length][nvectors],B[length][nvectors];
  double c[nvectors];
  //int c[nvectors];

  for (i=0;i<length;i++)
    {
      b[i]=i*1.0;
      //  b[i]=i;
      //a[i]=0;
      printf("%lf \n",b[i]);
      //printf("%d \n",b[i]);
    }

  for(j=0;j<nvectors;j++)
    {
      c[j]=1;

      for (i=0;i<length;i++)
	{
	  A[i][j]=0;
	  B[i][j]=i;
	  printf("%lf %lf\n",B[i][j],c[j]);

	  //  printf("%d %d\n",B[i][j],c[j]);
	}
    }


  tcpu_vectors = vector_case(a,b);

  tcpu_matrix = matrix_case(A,B,c);
  
 printf("******total cpu time is*******\n");
 printf("vector array: %e\n",tcpu_vectors);
 printf("matrix array: %e\n", tcpu_matrix);

   return 0;
}
