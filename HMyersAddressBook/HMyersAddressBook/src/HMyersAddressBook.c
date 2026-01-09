/*
 * HMyersAddressBook.c
 *
 *  Created on: May 7, 2023
 *      Author: hmyers1
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "HMyersAddressBook.h"

Person *top;
int numPeople = 0;

Person *createPerson(char *last, char *first, char *email, char *phone) {
	Person *newPerson = (Person*) malloc(sizeof(Person));
	strcpy(newPerson->last_name , last);
	strcpy(newPerson->first_name , first);
	strcpy(newPerson->email , email);
	strcpy(newPerson->phone_number , phone);
	newPerson->next = NULL;
	newPerson->prev = NULL;
	return newPerson;
}

void addNewContact(int position, char *contactInfo) {
    char lastName[256];
    char firstName[256];
    char emailAddress[256];
    char phoneNumber[256];
    char *delimiter = ",";
    char *token;
    char *infoElements[] = {lastName, firstName, emailAddress, phoneNumber};

    token = strtok(contactInfo, delimiter);
    for (int i = 0; i < 4; i++) {
        strcpy(infoElements[i], token);
        token = strtok(NULL, delimiter);
    }

    Person *newEntry = createPerson(lastName, firstName, emailAddress, phoneNumber);
    Person *cursor;

    if (numPeople == 0) {
        top = newEntry;
        numPeople++;
    } else if (position == 0) {
        top->prev = newEntry;
        newEntry->next = top;
        top = newEntry;
        numPeople++;
    } else if (position == numPeople) {
        cursor = top;
        while (cursor->next != NULL) {
            cursor = cursor->next;
        }
        cursor->next = newEntry;
        newEntry->prev = cursor;
        numPeople++;
    } else if (position < numPeople) {
        cursor = top;
        for (int i = 0; i < position; i++) {
            cursor = cursor->next;
        }
        Person *previous = cursor->prev;
        previous->next = newEntry;
        newEntry->prev = previous;
        newEntry->next = cursor;
        cursor->prev = newEntry;
        numPeople++;
    } else {
        // Do nothing if the position is out of range
    }
}


void deleteContact(int position) {
    Person *cursor = top;

    // Return if the position is out of range
    if (position > numPeople - 1) {
        return;
    }

    // Move the cursor to the given position
    for (int i = 0; i < position; i++) {
        cursor = cursor->next;
    }

    // Update the previous node's 'next' pointer if the cursor is not at the beginning
    if (cursor->prev != NULL) {
        cursor->prev->next = cursor->next;
    } else {
        // Update the top if the cursor is at the beginning of the address book
        top = cursor->next;
    }

    // Update the next node's 'prev' pointer if the cursor is not at the end
    if (cursor->next != NULL) {
        cursor->next->prev = cursor->prev;
    }

    // Decrement the number of people
    numPeople--;

    // Free the memory occupied by the cursor
    free(cursor);
}

void getContact(int position) {
    Person *cursor = top;

    // Return if the position is out of range
    if (position > numPeople - 1) {
        return;
    }

    // Move the cursor to the given position
    for (int i = 0; i < position; i++) {
        cursor = cursor->next;
    }

    // Print the contact information at the position
    printf("%s,%s,%s,%s\n", cursor->last_name, cursor->first_name, cursor->email, cursor->phone_number);
}

void getField(int position, char *field) {
    Person *cursor = top;

    // Return if the position is out of range
    if (position > numPeople - 1) {
        return;
    }

    // Move the cursor to the given position
    for (int i = 0; i < position; i++) {
        cursor = cursor->next;
    }

    // Print the desired field value
    if (strcmp("lastName", field) == 0) {
        printf("%s\n", cursor->last_name);
    } else if (strcmp("firstName", field) == 0) {
        printf("%s\n", cursor->first_name);
    } else if (strcmp("email", field) == 0) {
        printf("%s\n", cursor->email);
    } else if (strcmp("phoneNumber", field) == 0) {
        printf("%s\n", cursor->phone_number);
    } else {
        // Do nothing if the field is not recognized
    }
}

void getNumber() { // gets the number of people in the address book
	printf("%d\n", numPeople);
}

void loadFromFile(char *filePath) {
    FILE *inputFile = fopen(filePath, "r");
    char line[BUFSIZ];

    fgets(line, BUFSIZ, inputFile);
    while (fgets(line, BUFSIZ, inputFile) != NULL) {
        line[strlen(line) - 1] = '\0';
        addNewContact(numPeople, line);
    }
    fclose(inputFile);
}

void saveToFile(char *filePath) {
    FILE *outputFile = fopen(filePath, "w");
    fprintf(outputFile, "lastName,firstName,email,phoneNumber\n");

    Person *cursor = top;
    while (cursor != NULL) {
        fprintf(outputFile, "%s,%s,%s,%s\n", cursor->last_name, cursor->first_name, cursor->email, cursor->phone_number);
        cursor = cursor->next;
    }
    fclose(outputFile);
}


