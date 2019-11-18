#include <stdio.h>
#include <string.h>

/*
Input: hello world 10 ,??
Output:
Total Alphabets:        10
Total Digits:           2
Total Special Chr:      3
*/

int main(){
    char string[500];
    int alpha=0, digits=0, special=0;

    printf("Enter string\n");
    scanf("%[^\n]%*c", string); // string input with spaces.

    for(int idx=0; string[idx]!= '\0'; idx++){
        if((string[idx]>='a' && string[idx]<='z') || (string[idx]>='A' && string[idx]<='Z'))
            alpha++;

        else if(string[idx]>='0' && string[idx]<='9')
            digits++;
        
        else if(string[idx]!=' ')
            special++;
    }

    printf("Total Alphabets:\t%d\n", alpha);
    printf("Total Digits:\t\t%d\n", digits);
    printf("Total Special Chr:\t%d\n", special);

    return 0;
}