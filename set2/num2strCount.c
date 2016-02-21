#include <stdio.h>
#include <string.h>
#define n2s numToChar
#define MAX 1000
#define sc strcat
char *db []={"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
char *tens [] = {"twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
void numToChar(long int n , char s[])
{
if(n == 0) 
	sc(s,db[0]); 
else
 	while(n != 0)
 		(n >= 0 && n <= 19)?(sc(s,db[n]),(n >9) ? (n = n/100) :(n = n /10)):(n >=20 && n <= 99)?(n%10 == 0 )?(sc(s,tens[n/10-2]),n = n /100):(sc(s,tens[n/10-2]),sc(s,db[n%10]),n = n /100 ):((n >= 100 && n <=999)?(n%100 == 0 )?(sc(s,db[n/100]),sc(s,"hundred"),n = n/1000 ):(sc(s,db[n/100]),sc(s,"hundred"),n = n %100 ):((n >= 1000 && n <=99999)?(n % 1000 == 0)?(n2s(n/1000,s),sc(s,"thousand"),n = n/100000):(n2s(n/1000,s),sc(s,"thousand"),n = n%1000):((n >= 100000 && n <= 9999999)?(n%100000 == 0)?(n2s(n/100000,s),sc(s,"lakh"),n = n/10000000):(n2s(n/100000,s),sc(s,"lakh"),n = n%100000):((n >=10000000)?(n % 10000000 == 0)?(n2s(n/10000000,s),sc(s,"crore"),n = n/1000000000):(n2s(n/10000000,s),sc(s,"crore"),n = n%10000000):1))));
}
int itr(long int n)
{
	char s[MAX]; int counter = 0 ;
	while(n!=4)(memset(s,'\0',MAX),n2s(n,s),printf("n = %ld, s = %s , new = %ld\n",n,s,strlen(s)),n = strlen(s),counter++);
	return counter;
}
int main()
{
	long int i ;
	printf("\n enter any nber to convert to text:");
	scanf("%ld",&i);
	printf("\nit took : %d number of steps\n",itr(i));
}
