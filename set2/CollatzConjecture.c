#include <stdio.h>
int cj(int num)
{
	return (num == 1) ?0:( num%2==0 ? cj(num/2) + 1 : cj(3*num+1) + 1 ) ;
}
int main()
{	int input ;
	printf("enter any number :\n");
	scanf("%d",&input);
	input ? (printf("number of steps it took is %d\n",cj(input))):(printf("enter positive number\n" ));
}