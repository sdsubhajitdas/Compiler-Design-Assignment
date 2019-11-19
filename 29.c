#include "stdio.h"
#include "string.h"
int main(int argc, char const *argv[])
{
	char str[100];int a=0,i;
	printf("Enter the string::");
	scanf("%s",&str);
	for(i=0;i<str[i]!='\0';i++)
	{
		if(str[i]>='a' && str[i]<='z')
		{
			str[i]=str[i]-32;
			a=1;
		}
		else
		{
			str[i]=str[i]+32;
			a=0;
		}
	}
	if (a==1)
		printf("\nUPPER CASE ALPHABETS::%s",str);
	else
		printf("\nLOWEER CASE ALPHABETS::%s",str);
	return 0;
}