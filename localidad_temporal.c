#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI  3.14159265358979323846

/*this coe computes the cpu time for  
  t1 = sin(alpha)*x + cos(alpha)*y;
  t2 = -cos(alpha)*x + sin(alpha)*y;
 
  and using the variable change s=sin(alpha) and c=cos(alpha)

  t1 = s*x + c*y;
  t2 = -c*x + s*y;

  the inputs are: alpha (in grades), the number of iterations, x and y.
*/
int main(int argc, char **argv)

{
  clock_t tbegin, tend;
  int i,N,j;
  double x,y,alpha,t_total;
  double s,c,t1,t2;
  char mode;
  
  alpha = atof(argv[1])*(PI / 180.0); //convert alpha to double rad
  N=atoi(argv[2]); //Number of iteration  
  x=atof(argv[3]);
  y=atof(argv[4]);

  printf("enter S or N to run with or whitout  optimization\n");
  scanf("%c",&mode);

  s=sin(alpha);
  c=cos(alpha);

  FILE *pf;
  pf = fopen("opti_timedata.dat","a");

  switch(mode)

    {

    case 'S':
      {
	
	for(j=10;j<=N;j*=10)
	  {
	    tbegin=clock();
	    for(i=0;i<j;i++)
	      
	      {
		t1 = s*x + c*y;
		t2 = -c*x + s*y;
	      }
	    
	    tend = clock();
	    
	    t_total = (double)((1.0*tend - 1.0*tbegin) / CLOCKS_PER_SEC);
	
	    printf("the total amount of time spent in the cicle using optimization was %lf segundos with %d iterations \n",t_total,j);
	    fprintf(pf,"%lf %d\n",t_total,j);
	  }
	fclose(pf);
	break;
      }	
    case 'N':
      {
	pf = fopen("nonopti_timedata.dat","a");

	for(j=10;j<=N;j*=10)

	  {

	    tbegin = clock();
	    for(i=0;i<j;i++)
	  
	      {
		t1 = sin(alpha)*x + cos(alpha)*y;
		t2 = -cos(alpha)*x + sin(alpha)*y;
	      }
	    
	    tend = clock();
	    
	    t_total = (double)((1.0*tend - 1.0*tbegin) / CLOCKS_PER_SEC);
	    
	    printf("the total amount of time spent in the cicle without optimization was %lf segundos\n",t_total);
	    fprintf(pf,"%lf %d\n",t_total,j);
	  }
	fclose(pf);
	    break;	
	  }
	
    default:
      printf("optimization option was incorrect, use S or N for a run with or without optimization respectively\n");
      break;

    }
  
  

   return 0;
}
