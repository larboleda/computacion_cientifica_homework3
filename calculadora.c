#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "functions.h"

/*Calculator. the arguments are: first term, operand, second term*/

int main(int argc, char *argv[])

{

  double a,b,c;
  char operand; 
  printf("ingrese la operacion que quiere realizar, ejemplo: a + b\n");
  scanf("%lf %c %lf",&a,&operand,&b);
  printf("has ingresado a=%lf , b=%lf\n",a,b);

  switch(operand)
    {

    case '+':
      c=sum(a,b);
      printf("%lf + %lf = %lf\n",a,b,c);
      break;

 case '-':
      c=substraction(a,b);
      printf("%lf - %lf = %lf\n",a,b,c);
      break;

    case '/':
      c=division(a,b);
      printf("%lf / %lf b = %lf\n",a,b,c);
      break;

    case '*':
      c=multiplication(a,b);
      printf("%lf * %lf = %lf\n",a,b,c);
      break;

    default:
      printf("la operación ingresada es incorrecta\n");
      break;
    
    }


  return 0;
}
