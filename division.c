#include<stdlib.h>
#include<stdio.h>
#include<math.h>

/*this code return how many times a number n can be divided by 2. You must pass n */

int main(int argc, char *argv[])

{

  int i;
  double n,div;
  n=atof(argv[1]); 
  div=floor(n);
  printf("initially div = %lf\n",div);

   for(i=1;;)
    {
      div=floor(div)*0.5;
       if(div==1)
	 {      
	   printf("%lf puede ser dividido %d veces por 2\n",n,i);
	   break; 
	 }
       i++;
    }

  return 0;
}
