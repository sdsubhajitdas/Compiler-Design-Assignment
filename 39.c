#include <stdio.h>

#define FSIZE 100
 
int main()
{
    FILE *fptr;
    int ctr = 0;  
    char fname[FSIZE];
    int space =0;
    char c; 
    printf("\n\n Read the file and count the number of lines :\n");
	printf("--------------------------------------------------\n"); 
	printf(" Input the file name to be opened : ");
	scanf("%s",fname);

    fptr = fopen(fname, "r");
    if (fptr == NULL)
    {
        printf("Could not open file %s", fname);
        return 0;
    }
    // Extract characters from file and store in character c
    for (c = getc(fptr); c != EOF; c = getc(fptr))
        if (c == '\n') // Increment count if this character is newline
            ctr++;
        else if (c==' ')
        	space++;
        else
        	fclose(fptr);
    fclose(fptr);
    printf(" The lines in the file %s are : %d \n \n", fname, ctr);
    printf(" The spaces in the file %s are : %d \n \n", fname, space);
    return 0;
}