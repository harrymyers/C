/*
 ============================================================================
 Name        : HMyersThreeNPlusOne.c
 Author      : Harry Myers
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int computeMaxSequenceLength();
int computeSequenceLength();
int computeNextValue();
// takes a min and a max and finds the length of the max sequence length
int computeMaxSequenceLength(int min, int max) {
	int maxLen = 1;
	int temp = 0;
	for (int i = min; i <= max; i++) {
		temp = computeSequenceLength(i);
		if (temp > maxLen) {
			maxLen = temp;
		}
	}
	return maxLen;
}
// takes an integer num and returns the length of its 3n+1 sequence
int computeSequenceLength(int num) {
	int value = num;
	int count = 1;
	while (value != 1) {
		value = computeNextValue(value);
		count++;
	}
	return count;
}
// computes next value in sequence
int computeNextValue(int value) {
	if (value % 2 == 0) {
		return value / 2;
	} else {
		return 3 * value + 1;
	}
}

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	int min = 0;
	int max = 0;
	int maxLength = 0;
	char outputFile[100];
	char first[100];
	char second[100];

	printf("Enter output filename:\n");
	fgets(outputFile, 100, stdin);

	int lengthOutFile = strlen(outputFile);
	outputFile[lengthOutFile - 1] = '\0';

	// opens file
	FILE *output = fopen(outputFile, "w");

	do {
		fgets(first, 100, stdin);
		if(first[0] == '\n'){
			break;
		}
		min = atoi(first);
		fgets(second, 100, stdin);
		max = atoi(second);
		if(second[0] == '\n'){
					break;
				}
		// finds maxLength
		maxLength = computeMaxSequenceLength(min, max);
		fprintf(output, "%d\t%d\t%d\n", min, max, maxLength);
	} while (second[0] != '\n' && first[0] != '\n');

	// closes file

	fclose(output);
	printf("Complete\n");
	return EXIT_SUCCESS;
}

