#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
//#include <omp.h>
bool checkPrime(int num)
{
        int i ;
        for(i = 2 ; i <= (int) sqrt(num);i++)
                if(num% i == 0)
                        return false ;
        return true ;
}

int main()
{
        int input,i,c=0 ;
        printf("enter a number to check : \n");
        scanf("%d",&input);
        double  t = clock();
        if(checkPrime(input))
                printf("it is prime number\n");
        else
                printf("it is not prime number\n");
    double end = clock();
    double tot = (double)(end-t)/CLOCKS_PER_SEC;
      printf("it tooks %lf time\n",tot);
        
}