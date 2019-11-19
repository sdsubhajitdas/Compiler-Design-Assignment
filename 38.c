#include<stdio.h>
int main()
{
	char s[100],s1[100],s2[200],a=0,b=0,c=0,i,j;
	printf("Input First String : ");
	gets(s);
	printf("Input Second String : ");
	gets(s1);
	while (s[a] != '\0')
	a++;
	while (s1[b] != '\0')
	b++;
	for(i=0;i<a;i++)
	{
		s2[c]=s[i];
		c++;
	}
		for(i=0;i<b;i++)
	{
		s2[c]=s1[i];
		c++;
	}
	s2[c]='\0';
	printf("After Concatenation : %s",s2);
	return 0;
	
}
