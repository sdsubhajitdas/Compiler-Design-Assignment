#include <stdio.h>
#define max 40
void print_all(char set[], char prefix[max], int n,int k )
{
	if(k==0)
	{
		printf("\n%s",prefix);
		return;
	}
	for(int i=0;i<n;i++)
	{
		char newPrefix[max];
		newPrefix[i] = prefix[i] + set[i];
		print_all(set,newPrefix,n,k-1); 
	}
}
void print_all_set(char set[],int n,int k)
{
	print_all(set,"",n,k-1);
}
int main(int argc, char const *argv[])
{
	
	char set[]= {'a','b','c'};
	int k=3;
	print_all_set(set,k,2);
	return 0;
}