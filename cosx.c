#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include"functions.h"

/*this code return cos(x). It receives by the comand line the value of the angle in grades and the number of terms that will be used in the taylor expansion */

#define PI 3.14159265358979323846

int main(int argc, char *argv[])

{

  double x,xrad,cosx;
  int N,i;
  int term, fac;

  x=atof(argv[1]); //angle in grades
  N=atoi(argv[2]); //numbers of terms to use in the serie
  
  xrad=(x*PI)/180;
  cosx=0;
  term=0;
  for(i=0;i<=N;i++)
    {
      
      term=2*i;
      fac=factorial(term);
      cosx += (pow(-1,i)/fac) * pow(xrad,term);

    }
  
printf("cos(x) = %lf\n",cosx);
  
  return 0;
}
