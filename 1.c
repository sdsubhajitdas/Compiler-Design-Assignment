#include<stdio.h>
#include<string.h>
void main()
{
char string[25];
int count=0,flag;
printf("enter any string: ");
gets(string);
//checking for 1st value of the string
if( (string[0]>='a'&&string[0]<='z') || (string[0]>='A'&&string[0]<='Z') || (string[0]=='_') )
 {
   //Traversing the whole string
   for(int i=0;i<strlen(string);i++)
   {
   if((string[i]>='a'&& string[i]<='z') || (string[i]>='A' && string[i]<='Z') || (string[i]>='0'&& string[i]<='9') || (string[i]=='-') )
     count++;
 }
 if(count==strlen(string))
  flag=0;
}
else
  flag=1;

if(flag==1)
   printf("%s is not valid identifier",string);
else
   printf("%s is valid identifier",string);
}