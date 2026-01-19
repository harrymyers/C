/*
 ============================================================================
 Name        : HMyersTestScoreStats.c
 Author      : Harry Myers
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);

	int count = -1;
	float sum = 0.0;
	float sumSquares = 0.0;
	char score[100];
	float max = 0.0;
	float min = 0.0;
	float num = 0.0;
	float average = 0.0;
	float sd = 0.0;

	printf(
			"Enter scores, one per line.  Press <ENTER> on a blank line to end.\n");
	do {
		fgets(score, 100, stdin);
		num = atof(score);

		if (count == -1) {
			max = num;
			min = num;
		}

		if (num > max) {
			max = num;
		} else if (num != 0 && num < min) {
			min = num;
		}

		count++;
		sum += num;
		sumSquares += (num * num);
	} while (score[0] != '\n');


	if(count != 0 ){
	average = sum / count;
	sd = sqrt((sumSquares - ((sum * sum) / count)) / count);
	}
	printf("%d\t", count);
	printf("%f\t", min);
	printf("%f\t", max);
	printf("%f\t", average);
	printf("%f\t", sd);

	return EXIT_SUCCESS;
}
