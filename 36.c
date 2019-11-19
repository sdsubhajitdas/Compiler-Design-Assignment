#include <stdio.h>
#include <stdlib.h> // For exit() function
int main()
{
	char c;
	FILE *fptr;
	char path[100];
	int lineNum = 1;

	printf("Enter the path of the file: ");
	scanf("%s", path);

	if ((fptr = fopen(path, "r")) == NULL)
	{
		printf("Error! opening file");
		// Program exits if file pointer returns NULL.
		exit(1);
	}

	printf("Line %d: ", lineNum++);
	while ((c = fgetc(fptr)) != EOF)
    {
		printf("%c", c);
		if (c == '\n')
			printf("Line %d: ", lineNum++);
	}
	
    fclose(fptr);

	return 0;
}
