// Uppercase to lowercase and vice-versa
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	FILE *fptr;
	char file[100], ch;
	int a = 0, i;

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
			ch = ch - 32;

		else if (ch >= 'A' && ch <= 'Z')
			ch = ch + 32;

		printf("%c", ch);
	}

	return 0;
}
