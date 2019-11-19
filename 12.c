#include <stdio.h>
#include <string.h>

int checkIfCommentLine(char []);

/*
Input: Filename test.txt
Output:
void main()
{
int a=10;
printf("%d",a);
}

Inside test.txt
void main()
{
int a=10;
// Printing a variable;
printf("%d",a);
}

*/

int main(){
    FILE *fptr;
    char line[1000], filename[100], ch, program[10000];
    int i=0;

    program[0] = '\0';
    
    printf("Enter file name:\n");
    scanf("%[^\n]%*c", filename);

    fptr = fopen(filename,"r");
    if(fptr == NULL){
        printf("File not found");
        return 0;
    }

    ch = fgetc(fptr);

    while (ch != EOF){
        // Reads a single line and prints it if not a comment.
        if(ch=='\n'){
            line[i] = '\0';
            i=0;
            if(!checkIfCommentLine(line))
                printf("%s\n",line);
        }
        else{               // Making a single line
            line[i] = ch;
            i++;
        }
        ch = fgetc(fptr);
    }
}

int checkIfCommentLine(char line[]){
    if(line[0] == '/' && line[1]=='/')
        return 1;
    return 0;
}