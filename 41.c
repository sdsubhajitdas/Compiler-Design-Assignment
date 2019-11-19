#include "stdio.h"
#include "string.h"
int main(int argc, char const *argv[])
{
	char str[100];int a=0,i,lower=0,upper=0;
	printf("Enter the string::");
	scanf("%s",&str);
	for(i=0;i<str[i]!='\0';i++)
	{
		if(str[i]>='a' && str[i]<='z')
		{
			lower++;
		}
		else
		{
			upper++;
		}
	}
	printf("\nNO OF UPPER CASE ALPHABETS::%d",upper);
	printf("\nNO LOWER CASE ALPHABETS::%d",lower);
	return 0;
}