#include <stdio.h>
#include <string.h>

int parseLine(char []);
int countVariables(char []);
void parseType(char [], char []);

/*
Input: int a,b,c;float x,y;
Output: Total memory required 20 bytes
*/


int main(){
    char string[1000];
    char *line;
    int totalSize = 0;

    scanf("%[^\n]%*c", string);

    line = strtok(string, ";");

    do{
        totalSize += parseLine(line);
        line = strtok(NULL,";");

    }while(line != NULL);

    printf("Total memory required %d bytes",totalSize);
    return 0;
}

int parseLine(char line[]){
    /* Parses a single line for data type used and no. of variables.
    */
    char type[50];
    int varCount,size = 0;

    parseType(line,type);
    varCount = countVariables(line);

    // Calculating the space required according to the datatype.
    if(strcmp(type,"int") == 0)
        size = sizeof(int);
    else if(strcmp(type,"char") == 0)
        size = sizeof(char);
    else if(strcmp(type,"double") == 0)
        size = sizeof(double);
    else if(strcmp(type,"float") == 0)
        size = sizeof(float);

    return size * varCount;
}

int countVariables(char line[]){
    // Counts number of variable used
    char *ch = line;
    int count = 1;

    while(*ch != '\0'){
        if(*ch == ',')
            count++;
        ch+=1;
    }
    return count;
}


void parseType(char line[], char type[]){
    // Parser to identify the datatype used.

    char *ch = line;
    int i=0;
    while(*ch != ' '){
        type[i] = *ch;
        ch +=1;
        i++;
    }
    type[i] = '\0';
}
