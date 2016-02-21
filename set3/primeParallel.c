#include <stdio.h>
#include <math.h>
#include <pthread.h>
#include <time.h>
#define  N 2
#define h for
#define l h(i=0;i<N;i++)
#define p printf
int c = 2, r = 1;
void* cP(void * num){int n=*((int*)num);int t=c++,i;h(i=t;i<=(int)sqrt(n)&&r;i=i+N) if(n%i==0)r=0;}
int main(){int i,in;p("enter a number to check:\n");scanf("%d",&in);double s=clock();if(in<2){p("enter number above 1\n");return 0;}
pthread_t t[N];l pthread_create(&t[i],NULL,cP,(void **)&in);l pthread_join(t[i],NULL);
p((r)?"it is prime number\n":"it is not a prime number\n");p("time :%lf \n",((double)clock()-s)/CLOCKS_PER_SEC);}