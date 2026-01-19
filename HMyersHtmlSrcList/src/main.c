/*
 ============================================================================
 Name        : HMyersHtmlSrcList.c
 Author      : Harry Myers
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//function declarations
int countSrcAttributes(char* html);
void printTagNames(char* html);
void printUrls(char* html);

// Prints the number of valid src attributes
int countSrcAttributes(char* html) {
    const char* find = "src=\"";
    int findLength = strlen(find);
    if (strlen(html) == 0) {
        return 0;
    }

    int count = 0;
    const char* temp = html;

    // Iterate through the HTML document
    for (temp = strstr(temp, find); temp != NULL; temp = strstr(temp + findLength, find)) {
        char prevChar = *(temp - 1);

        // If the character before "src" is a space, tab, or newline, increment the count
        if (prevChar == ' ' || prevChar == '\t' || prevChar == '\n') {
            count++;
        }
    }

    return count;
}

//prints tag names

void printTagNames(char* html) {
    const char* find = "src=\"";
    int findLength = strlen(find);
    const char* temp = html;

    while ((temp = strstr(temp, find))) {
        char prevChar = *(temp - 1);

        if (prevChar != ' ' && prevChar != '\t' && prevChar != '\n' && prevChar != '\r') {
            temp += findLength;
            continue;
        }

        char tagBuffer[100];
        const char* reverseTemp = temp;

        while (*(--reverseTemp) != '<');

        int i = 0;
        // Loop to find the position of the next whitespace, tab, newline or carriage return
        while (1) {
            char nextChar = *(reverseTemp + ++i);

            if (nextChar == ' ' || nextChar == '\t' || nextChar == '\r' || nextChar == '\n') {
                break;
            }
        }

        strncpy(tagBuffer, reverseTemp + 1, i - 1);
        tagBuffer[i - 1] = '\0';

        printf("%s\n", tagBuffer);
        // Clear the tagBuffer for the next iteration
        memset(tagBuffer, 0, sizeof(tagBuffer));

        temp += findLength;
    }
}

// prints urls
void printUrls(char* html) {
    const char* temp = html;
    const char* end = NULL;
    const char* start;

    // Loop through the HTML content to find occurrences of "src=\""
    while ((temp = strstr(temp, "src=\""))) {
        if (*(temp - 1) == '.') {
            temp++;
            continue;
        }

        char URL[200];
        memset(URL, '\0', sizeof(URL));

        // Move the startOfURL pointer to the position after the opening quote
        start = temp + 5;

        // Find the closing position using strchr
        end = strchr(start, '"');

        // Check if the closing position is found
        if (end) {
            int length = end - start;
            strncpy(URL, start, length);
            URL[length] = '\0';

            // Print the URL
            printf("%s\n", URL);
        }
        temp++;
    }
}


int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);

	char buffer[BUFSIZ];
	char inputLink[100];
	char link[100];
	strcpy(link, "curl -s ");

	printf("URL:\n");
	scanf("%s", inputLink);

	strcat(link, inputLink);

	FILE *file;
	file = popen(link, "r");
	if (file == NULL) {
		printf("File error\n");
		return 1;
	}

	char html[99999];

	char* nextLine;
	while ((nextLine = fgets(buffer, BUFSIZ, file)) != 0) {
		strcat(html, nextLine);
	}

	fgetc(stdin); //skips the newline character from the input buffer

	char inputC;
	do {
		printf("Ready\n");
		inputC = fgetc(stdin);
		fgetc(stdin); //skips the newline character from the input buffer

		switch (inputC) {
		case 'c':
			printf("%d\n", countSrcAttributes(html));
			break;
		case 't':
			printTagNames(html);
			break;
		case 'u':
			printUrls(html);
			break;
		default:
			break;
		}

	} while (inputC != 'q');

	printf("Complete\n");
	return 0;
}
