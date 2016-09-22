#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* code to compute the all the prime numbers less than or equal to a given integer n */

int main(int argc, char **argv)

{

  int n,i,j,k,a,n_primos;
  int r;

  n=atoi(argv[1]);
  n_primos = 1;

  FILE *pf;
  pf=fopen("nprimos.dat","w");

  fprintf(pf,"los primos menores que %d son\n",n);

  fprintf(pf,"#n \t primo n \t  \n ");

  
  if(n >= 2)
    {
      fprintf(pf,"1 \t 2 \t 0\n");
    }

  int *primos=NULL;

  primos = (int *) malloc((size_t) n_primos*sizeof(int)); //maximo tamaño de primos. 
  

  primos[0]=2;

  for(i=3;i<=n;i++)
    {
	  
      r=floor(sqrt(i));  //criterio para buscar divisores 
      
      for(j=0;j<=n_primos;j++)//j se mueve sobre las casillas de primos, no sobre los valores guardados
	{
	  
	  if(primos[j]<=r)
	    {
	      a=i%primos[j];
	      
	      if(a == 0)    //encontro un divisor     //primo[j] divide a i => i no es primo
		{
		  //printf("%d no es primo y no se agregara a la lista de primos\n",i);
		  break; 
		}    
     	    }
	  else
	    {
	      n_primos++;
	      primos = (int *) realloc(primos, (size_t)n_primos*sizeof(int));
	      primos[n_primos-1]=i;//agrego i a la lista de primos
	      fprintf(pf,"%d \t %d \n",n_primos,i);	  
	      break;
	    }
	}
      
    }
  fclose(pf);
  return 0;
}
