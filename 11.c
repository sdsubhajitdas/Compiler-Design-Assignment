#include <stdio.h>
#include <string.h>

int checkForBracket(char [], char);
int parseValidDataType(char []);

/*
INPUT: Filename test.txt
Output: The structure has invalid datatypes

test.txt  inside.
struct demo
{
int a;
float b;
}
*/

int main(){
    FILE *fptr;
    char ch,filename[50],token[50];
    int i=0,bracOpen=0,validTypes = 1;
    char line[500];

    printf("Enter file name:\n");
    scanf("%[^\n]%*c", filename);

    fptr = fopen(filename,"r");

    if(fptr == NULL){
        printf("File not found");
        return 0;
    }

    while (fgets(line,sizeof(line),fptr) != NULL)
    {   
        if(bracOpen != 1)               // Checks for opening bracket
            if(checkForBracket(line,'{'))
                bracOpen = 1;

        else{
            validTypes = parseValidDataType(line);
            if(checkForBracket(line,'}') || validTypes == 0) // closing bracket check
                break;
        }
    }
    
    if(validTypes == 1)
        printf("The structure has defined datatypes\n");
    else
        printf("The structure has invalid datatypes\n");
    
    fclose(fptr);
    return 0;
}


int parseValidDataType(char line[]){
    // Checks if the datatype is known or not
    char type[50];
    int i=0;

    while (line[i]!=' ')
    {
        type[i] = line[i];
        i++;
    }
    
    type[i] = '\0';

    if(checkForBracket(type,'}')==1)
        return 1;
    
    if(!strcmp(type,"int") || !strcmp(type,"char") || !strcmp(type,"float") || !strcmp(type,"double"))
        return 1;
    
    return 0;
}

int checkForBracket(char line[],char bracket){
    // Checks if the bracket is present in the line or not.

    for(int i=0; line[i]!='\0'; i++)
        if(line[i]==bracket)
            return 1;
    
    return 0;
}