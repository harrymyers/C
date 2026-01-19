/*
 ============================================================================
 Name        : HMyersNucleotideCounter.c
 Author      : Harry Myers
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	int a = 0;
	int c = 0;
	int g = 0;
	int t = 0;
	char temp;
	char inputFile[100];
	char outputFile[100];

	puts("Enter input filename:");
	fgets(inputFile, 100, stdin);
	puts("Enter output filename:");
	fgets(outputFile, 100, stdin);

	int len = strlen(inputFile);
	inputFile[len - 1] = '\0';

	FILE *input = fopen(inputFile, "r");

	int lengthOutFile = strlen(outputFile);
	outputFile[lengthOutFile - 1] = '\0';

	FILE *output = fopen(outputFile, "w");

	if (input != NULL) {


		while (!feof(input)) {
			temp = fgetc(input);
			switch (temp) {
			case 'A':
				a++;
				break;
			case 'C':
				c++;
				break;
			case 'G':
				g++;
				break;
			case 'T':
				t++;
				break;
			case '\n':
				fprintf(output, " %d %d %d %d\n", a, c, g, t);
				a = 0;
				c = 0;
				g = 0;
				t = 0;
				break;
			}

		}

	}
	fclose(input);
	fclose(output);
	printf("Complete\n");
	return EXIT_SUCCESS;
}
