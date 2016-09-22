#include <stdio.h>
#include <math.h>
#include "functions.h"

/*definition of functions*/

int factorial(int n)  /*this routine computes the factorial of a integer number n */

{
  int i,f;
  f=1;
  for(i=1;i<=n;i++)
    f=f*i;
  return f;
}
                   
									
double sum(double a, double b)
{

  double c;
  c=a+b;
  return c;

}

double substraction(double a, double b)
{

  double c;
  c=a-b;
  return c;
}

double division(double a, double b)
{

  double c;
  c=a * (1/b);
  return c;
}

double multiplication(double a, double b)
{
  double c;
  c=a*b;
  return c;
}
 
double relativistic_mass(double mo, double v)
{
  double m;
  double speed_light = 2.9979e8;
  m=mo/sqrt(1.0 - ((v*v)/(speed_light * speed_light)));

  return m;
}
