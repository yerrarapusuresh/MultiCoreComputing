#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
const char * DATABASE = "mcmt mcmi mcmb immm ipmp icmc mcpc";
bool isValid(char * regnum )
{
	char  substr[4];
	return  (strlen(regnum) == 8) && isdigit(regnum[0]) && isdigit(regnum[1]) && isdigit(regnum[6]) && isdigit(regnum[7]) && !strchr(strncpy(substr,&regnum[2],4),' ') && strcasestr(DATABASE,substr) ;
}

int main()
{
	char regnum[8];
	printf("enter roll number to test \n");
	scanf("%s",regnum);
	printf((true == isValid(regnum))?"Given number is  valid \n":"Given number is not valid\n");
}
