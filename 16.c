#include <stdio.h>
#include <string.h>
#define max 40
void main ()
{
    int a,b;
    char arr[max];
    char dest[2];
    printf("Enter the line\n");
    scanf("%s",arr);
    strncpy(dest,arr,2);
    if ((a=strncmp(dest,"//",2))  && (b=strncmp(dest,"/*",2)))
        printf("IT IS NOT A COMMENT\n"); 
    else
        printf("IT IS A COMMENT\n"); 

}