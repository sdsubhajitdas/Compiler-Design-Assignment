#include <stdio.h>
#include <string.h>
#include <math.h>


int getSize(char []);
void getType(char [], char [], int);

/*
Input: malloc(25*sizeof(int))
Output: calloc(25,sizeof(int))

Input: malloc(9*sizeof(float))
Output: calloc(9,sizeof(float))

Input: malloc(256*sizeof(double))
Output: calloc(256,sizeof(double))
*/

int main(){
    char string[500],type[20];
    int size,i;

    printf("Enter the malloc statement\n");
    scanf("%[^\n]%*c", string); // string input with spaces.

    size = getSize(string);
    i = 7 + floor(log10(size))+ 1 + 7 + 1; // Index of sizeof bracket
    getType(string, type, i);

    printf("calloc(%d,sizeof(%s))",size,type);

    return 0;
}

void getType(char string[], char type[],int start){
    /* Separates the type used in malloc
    Eg: malloc(25*sizeof(int))
        Separates int
    */
    int idx;

    for(idx=start; string[idx] != '\0'; idx++)
        if(string[idx] == ')')
            break;
        else
            type[idx-start] = string[idx];

    type[idx] = '\0';
}

int getSize(char string[]){
    /* Returns the size used in malloc
    Eg: malloc(25*sizeof(int))
        Returns 25
    */

    int idx, size = 0;

    for(idx=7; string[idx] != '\0'; idx++)
        if(string[idx] == '*')
            break;
        else
            size = size*10 + (string[idx] - '0');
    
    return size;
}