#include <stdio.h>
#define max 40
#include <string.h>
 
int main(int argc, char const *argv[])
{
	char ch[max];
	printf("Enter the statement::");
	scanf("%s",&ch);
	for(int i=0;i<strlen(ch);i++)
	{
		if (ch[i]=='+'||ch[i]=='-'||ch[i]=='*'||ch[i]=='%'||ch[i]=='/'||ch[i]=='=')
			printf("\nOperator:%c is at location%d",ch[i],i);

	}

	return 0;
}
