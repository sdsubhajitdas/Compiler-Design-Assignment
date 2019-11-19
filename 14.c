// With a bit of modification, this code can be used to replace any word with another word in any file.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1000

/* Function declaration */
void replaceAll(char *str, const char *oldWord, const char *newWord);

int main()
{
	/* File pointer to hold reference of input file */
	FILE *fPtr;
	FILE *fTemp;
	char path[100];

	char buffer[BUFFER_SIZE];
	char oldWord[100], newWord[100];

	printf("Enter path of source file: ");
	scanf("%s", path);
	/*
	printf("Enter word to replace: ");
	scanf("%s", oldWord);

	printf("Replace '%s' with: ");
	scanf("%s", newWord);
	*/
	/*  Open all required files */
	fPtr = fopen(path, "r");
	fTemp = fopen("replace.tmp", "w");

	/* fopen() return NULL if unable to open file in given mode. */
	if (fPtr == NULL || fTemp == NULL)
	{
		/* Unable to open file hence exit */
		printf("\nUnable to open file.\n");
		printf("Please check whether file exists and you have read/write privilege.\n");
		exit(EXIT_SUCCESS);
	}

	/*
	 * Read line from source file and write to destination 
	 * file after replacing given word.
	 */
	 
	strcpy(oldWord, "\\n");
	strcpy(newWord, "\n");
	while ((fgets(buffer, BUFFER_SIZE, fPtr)) != NULL)
	{
		strcpy(oldWord, "\\n");
		strcpy(newWord, "\n");
		// Replace all occurrence of word from current line
		replaceAll(buffer, oldWord, newWord);

		strcpy(oldWord, "\\t");
		strcpy(newWord, "\t");
		// Replace all occurrence of word from current line
		replaceAll(buffer, oldWord, newWord);

		// After replacing write it to temp file.
		fputs(buffer, fTemp);
	}

	/* Close all files to release resource */
	fclose(fPtr);
	fclose(fTemp);

	/* Delete original source file */
	remove(path);

	/* Rename temp file as original file */
	rename("replace.tmp", path);

	//printf("\nSuccessfully replaced all occurrences of '%s' with '%s'.", oldWord, newWord);
	printf("\nSuccessfully replaced all occurrences of \\n and \\t with their corresponding spaces.");

	return 0;
}

/**
 * Replace all occurrences of a given a word in string.
 */
void replaceAll(char *str, const char *oldWord, const char *newWord)
{
	char *pos, temp[BUFFER_SIZE];
	int index = 0;
	int owlen;

	owlen = strlen(oldWord);

	/*
	 * Repeat till all occurrences are replaced. 
	 */
	while ((pos = strstr(str, oldWord)) != NULL)
	{
		// Bakup current line
		strcpy(temp, str);

		// Index of current found word
		index = pos - str;

		// Terminate str after word found index
		str[index] = '\0';

		// Concatenate str with new word
		strcat(str, newWord);

		// Concatenate str with remaining words after
		// oldword found index.
		strcat(str, temp + index + owlen);
	}
}
