#include<stdio.h>
static int c;
static int d;
void fun()
{
	c++;
}
void fun2()
{
	d++;
}
int main()
{
	c=0;
	d=0;
	fun();
	fun();
	fun();
	fun();
	fun2();
	fun2();
	fun2();
	if(c==1)
	printf("Function fun is called %d time\n",c);
	else 
	printf("Function fun is called %d times\n",c);
	if(d==1)
	printf("Function fun2 is called %d time",d);
	else
	printf("Function fun2 is called %d times",d);
	
	return 0;
}


