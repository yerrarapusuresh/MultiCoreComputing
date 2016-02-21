/******************************************************************************************************************************************************************************************************
*AUTHOR : YERRARAPU SURESH
*
*DESCRIPTION : THIS PROGRAM CHECKS GIVEN ROLL NUMBE VALID OR NOT VALID ACCORDING TO STRUCTURE OF ROLL NUMBER 
*			   HERE TWO FUNCTION SAME ISVALID() ONE FOR GENERALITY AND ANOTHER FOR ONLY UOHYD FORMAT(UNDER COMMENTS )
*
*
*
******************************************************************************************************************************************************************************************/




#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct regno
{
	int size ; /* size of reg. number */
	int charposition ; /* first char position */
	int charslenth ; /* num of characters */
	char *deptDatabase ;/* dept names which used identify */
} RegNoType ;

/***************  IT IS ONLY CHECKS FOR UNIVERSITY OF HYD. REGISTER NUMBER ************************************************************************************************************************************************************************************************
	
	const char * DATABASE = "mcmt mcmi mcmb immm ipmp icmc mcpc";

	bool isValidHcuNum(char * regnum )
	{
		char  substr[5];
		substr[4] = '\0';
		return (strlen(regnum) == 8) && isdigit(regnum[0]) && isdigit(regnum[1]) && isdigit(regnum[6]) && isdigit(regnum[7]) && !strchr(strncpy(substr,&regnum[2],4),' ') && strcasestr(DATABASE,substr) ;
		
	}

//*********************************************************************************************************************************************************************************************************************************************************/

bool isValid(char regnum[], RegNoType * ref) /* isValid takes two parameters  REGISTERED NUMBER  and TYPE OF REGISTERED . return boolean type */
{
	
	bool flag = true,result  ;
	int i ;
	char * dept = malloc(ref->charslenth*sizeof(char));
	for(i = 0 ; i < ref->size ; i++ )
	{
		if(i == ref->charposition)
			i+= ref->charslenth;
		flag = flag && isdigit(regnum[i]);
	}
	
	result = flag && (ref->charslenth > 0 ?!strchr(strncpy(dept,&regnum[ref->charposition],ref->charslenth),' ') && strcasestr(ref->deptDatabase,dept) : true);

	if(ref->charslenth > 0 );
		free(dept);

	return result ;

}

int main()
{
	/*some university's examples  */
	RegNoType uoh ={8,2,4,"mcmt mcmi mcpc "};/*university of hyderabad */
	RegNoType sbtet ={10,5,2,"cm ec mc ee"};/*state board of technical dept format*/
	RegNoType jntu = {10,5,1,"a b c d f g j"};/*B.Tech roll number */
	RegNoType iitb = {9,0,0,NULL};/*iit bombay roll number */

	/*some test cases */
	printf(isValid("14mcmt43",&uoh) ? "It is valid UOHYD roll number format\n":"It is not valid rollnumber format of UOHYD\n");
	printf(isValid("14mctt43",&uoh) ? "It is valid UOHYD roll number format\n":"It is not valid rollnumber format of UOHYD\n");
	printf(isValid("14m mt43",&uoh) ? "It is valid UOHYD roll number format\n":"It is not valid rollnumber format of UOHYD\n");
	printf(isValid("07072ec033",&sbtet) ? "It is valid SBTET roll nuber format \n":"It is not valid SBTET roll number format\n");
	printf(isValid("10335a0512",&jntu)?"It is valid JNTUK number format\n":"It is not valid JNTUK format \n");
	printf(isValid("110010027",&iitb) ? "It is valid IITB number format\n":"It is not valid IITB format\n"); 


/**********************************TEST CASES FOR isValidHcuNum()  *****************************************************************************************************************************
	printf(isValidHcuNum("14mcmt43") ? "Number is valid UOHYD format\n" :"number is not valid format\n");
	printf(isValidHcuNum("14MCMT43") ? "Number is valid UOHYD format\n":"nuber is not valid format \n");
	printf(isValidHcuNum("14mctt43") ? "Number is valid UOHYD format\n" :"number is not valid format\n");
	printf(isValidHcuNum("14mc t43") ? "Number is valid UOHYD format\n" :"number is not valid format\n");
	printf(isValidHcuNum("1489898943") ? "Number is valid UOHYD format\n" :"number is not valid format\n");
	printf(isValidHcuNum("\0") ? "Number is valid UOHYD format\n" :"number is not valid format\n");

//*********************************************************************************************************************************************************************************************/
	//FURTHER IMPLEMENTATION CHECK NUMBER OF SEATS , ESTABLISHMENT OF DEPT BASED ON DEPT EX. 19MCMT99 IS NOT VALID (IT CAN BE VERIFIED BY NUMBER OF SEATS OF DEPT AS WELL AS YEAR ) FOR THAT WE HAVE DEFINE SEPARATE DEPT STRUCTURE WHICH CONTAINS NUMBER OF SEATS , NUMBER OF COURSES , ESTABLISHMENT YEAR  AND CURRENT YEAR AND SO ON
	return 0 ;
	


}