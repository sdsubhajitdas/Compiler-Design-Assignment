#include <stdio.h>
#include <string.h>

int isKeyword(char []);

/*
Input: Filename test.txt
Output: void, int,

inside test.txt
void main()
{
    int a = 10;
}
*/

int main(){
    FILE *fptr;
    char filename[100], ch, word[100];
    int i=0;

    printf("Enter file name:\n");
    scanf("%[^\n]%*c", filename);

    // Reading from a file char by char.
    fptr = fopen(filename,"r");
    if(fptr == NULL){
        printf("File not found");
        return 0;
    }
    ch = fgetc(fptr);

    while (ch != EOF)       //Till End Of File
    {   
        // Tokenizing a word.
        if(ch == ' '|| ch == ';'){
            word[i] = '\0';
            i=0;
            if(isKeyword(word)==1)
                printf("%s, ",word);
        }
        else
            word[i++] = ch;
        ch = fgetc(fptr);       // Reading next char.
    }
    
    fclose(fptr);           // Closing input stream.
    return 0;
}

int isKeyword(char word[]){
    // C has only 32 keywords all are here.
    if (!strcmp(word, "auto") || !strcmp(word, "default")  
        || !strcmp(word, "signed") || !strcmp(word, "enum")  
        ||!strcmp(word, "extern") || !strcmp(word, "for")  
        || !strcmp(word, "register") || !strcmp(word, "if")  
        || !strcmp(word, "else")  || !strcmp(word, "int") 
        || !strcmp(word, "while") || !strcmp(word, "do") 
        || !strcmp(word, "break") || !strcmp(word, "continue")  
        || !strcmp(word, "double") || !strcmp(word, "float") 
        || !strcmp(word, "return") || !strcmp(word, "char") 
        || !strcmp(word, "case") || !strcmp(word, "const") 
        || !strcmp(word, "sizeof") || !strcmp(word, "long") 
        || !strcmp(word, "short") || !strcmp(word, "typedef") 
        || !strcmp(word, "switch") || !strcmp(word, "unsigned") 
        || !strcmp(word, "void") || !strcmp(word, "static") 
        || !strcmp(word, "struct") || !strcmp(word, "goto") 
        || !strcmp(word, "union") || !strcmp(word, "volatile")) 
        return 1; 
    return 0; 
}