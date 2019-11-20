#include<stdio.h>
char a[100][100];
int n;
int main()
{
	char a[100][100],b[100],e[100];
	int i,j,c=0,d,n,k=0,c1=0,flag=0;
	printf("Enter no of words to be entered in dictionary :");
	scanf("%d",&n);
	printf("Input the words in dictionary :");
    for(i=0;i<n;i++)
	scanf("%s",a[i]);
	
	
	
	
	
	
	
	
 printf("Input a word :");
 scanf("%s",b);
 	while (b[c] != '\0')
	c++;
	
	for(i=0;i<n;i++)
	{
		while (a[i][k] != '\0')
	k++;
	for(j=0;j<c;j++)
	{
		if(b[j]==a[i][j])
		c1++;	
	}
	if(c1==k)
	{
		printf("Word : %s",b);
		break;
	}
	flag++;
	k=0;
	c1=0;
}

if(c==1)
printf("%s",b);
else
{
if(flag==n)
{
	for(i=0;i<n;i++)
	{
			while (a[i][k] != '\0')
	k++;
	for(j=0;j<c;j++)
	{
		if(b[j]==a[i][j])
		c1++;	
	}
	if(c1>=2 && c1!=k)
	{
		printf("Autocorrect suggest : %s\n",a[i]);
	printf("Is this the corrected word ? (y/n) : ");
	scanf("%s",e);
	if(e[0]=='y')
	{
	printf("Corrected Word : %s",a[i]);
	break;
}
	}
	c1=0;
	k=0;
	}
}
}
	return 0;
}
