#include<stdlib.h>
#include<stdio.h>
#include<math.h>

/*this code aproximates the value of pi by using two different series: 2/pi  and pi/4  */

double pi1(int N)  //2/pi 
{
  int i;
  double sum,p;
  
  sum = 0;
  p=0;
  for(i=0;i<=N;i++)
    {
      sum += pow(-1,i) / (1+2*i);
    }

  p = 0.5 * (1/sum);
  return p;
}

double pi2(int N) //pi/4

{
  int i;
  double sum,p;

  sum = 0;
  p=0;
  for(i=0;i<=N;i++)
    {
      p += pow(-1,i) / (1+2*i);
    }

    return p;

}

int main(int argc, char *argv[])

{
  double pi_1,pi_2;
  int N;

  N=atoi(argv[1]); //numbers of terms to be used in the serie

  pi_1=2.0/pi1(N);
  pi_2=4.0*pi2(N);  
  
  printf("***********pi was aproximated by 2/pi and pi/4***********\n");
  printf("using the firs aprox: pi = %lf\n",pi_1);
  printf("using the second aprox: pi = %lf\n",pi_2);
  return 0;
}
