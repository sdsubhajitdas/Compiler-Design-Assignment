#include <stdio.h>
#include <string.h>

void substring(char[], char[], int, int);

int main()
{
    char str[500];
    char token[50];
    int idx, i = 0;

    printf("Enter a string:\n");
    scanf("%[^\n]%*c", str); // string input with spaces.

    for (idx = 0; str[idx] != '\0'; idx++)
    {
        // Tokenizing at space and semicolon.
        if (str[idx] == ' ' || str[idx] == ';')
        {
            substring(str, token, i, idx);
            printf("%s \n", token);
            i = idx + 1;
        }
    }
}

void substring(char string[], char sub[], int start, int end)
{
    /* Substring function.
    string - Actual String from which substring will be made.
    sub - Substring created will be stored here.
    start - Starting index.
    end - Ending index + 1.
    */
    int idx = 0;

    while (start < end)
    {
        sub[idx] = string[start];
        idx++;
        start++;
    }
    sub[idx] = '\0';
}