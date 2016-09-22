#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

/*This program evaluates the operation: ((sin(x)+cos(x))/2)* (a+b), but using diferents inplementations, each one given in the external functions f1,f2,f3 and f4. The correct implementation is f4. THe others returns wrong values of the function. The program receives x (in grades), a and b by the command line */


double f1(double x, double a, double b)
{
  double f;

  f=sin(x) +cos(x)/2 * a + b;

  return f;
}

double f2(double x, double a, double b)
{

  double f;

  f=sin(x) + cos(x)/2 * (a+b);

  return f;
}

double f3(double x, double a, double b)
{

  double f;

  f=(sin(x) +cos(x)/2) * a + b;

  return f;
}

double f4(double x, double a, double b)
{

  double f;

  f=((sin(x)+cos(x))/2)* (a+b);

  return f;

}

int main(int argc, char **argv)

{

  double x,a,b;
  double f1x,f2x,f3x,f4x;

  x=(atof(argv[1]))*(PI/180); //convert x to rad
  a=atof(argv[2]);
  b=atof(argv[3]);

  f1x=f1(x,a,b);
  f2x=f2(x,a,b);
  f3x=f3(x,a,b);
  f4x=f4(x,a,b);

printf("----the diffeents implementations of the function returns----\n");
printf("f1(x) = %lf\n",f1x);
printf("f2(x) = %lf\n",f2x);
printf("f3(x) = %lf\n",f3x);
printf("f4(x) = %lf\n",f4x);
printf("----f4(x) = %lf is the correct implementation----\n",f1x);

  return 0;
}
