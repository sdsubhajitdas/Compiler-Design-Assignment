// Count uppercase and lowercase letters
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	FILE *fptr;
	char file[100], ch;
	int i, lower = 0, upper = 0;

	printf("Enter the filename: ");
	scanf("%s", &file);

	fptr = fopen(file, "r");
	if (fptr == NULL)
	{
		/* Unable to open file hence exit */
		printf("\nUnable to open file.\n");
		printf("Please check whether file exists and you have read/write privilege.\n");
		exit(EXIT_SUCCESS);
	}

	while ((ch = fgetc(fptr)) != EOF)
	{
		if (ch >= 'a' && ch <= 'z')
			lower++;
		else if (ch >= 'A' && ch <= 'Z')
			upper++;
	}

	printf("\nNUMBER OF UPPER CASE ALPHABETS: %d", upper);
	printf("\nNUMBER LOWER CASE ALPHABETS: %d", lower);
	return 0;
}
