/*
 ============================================================================
 Name        : HMyersAddressBook.c
 Author      : Harry Myers
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "HMyersAddressBook.h"

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	char command[1] = "\0";
	printf("Ready\n");
	while (command[0] != 'q') {
	    fgets(command, BUFSIZ, stdin);
	    switch (command[0]) {
	        case 'a': { // Add a contact
	            char sIndex[BUFSIZ];
	            fgets(sIndex, BUFSIZ, stdin);
	            int index = atoi(sIndex);
	            char contact[BUFSIZ];
	            fgets(contact, BUFSIZ, stdin);
	            contact[strlen(contact) - 1] = '\0';
	            addNewContact(index, contact);
	            break;
	        }
	        case 'd': { // Delete a contact
	            char sIndex[BUFSIZ];
	            fgets(sIndex, BUFSIZ, stdin);
	            int index = atoi(sIndex);
	            deleteContact(index);
	            break;
	        }
	        case 'g': { // Get a contact
	            char sIndex[BUFSIZ];
	            fgets(sIndex, BUFSIZ, stdin);
	            int index = atoi(sIndex);
	            getContact(index);
	            break;
	        }
	        case 'f': { // Get a field
	            char sIndex[BUFSIZ];
	            fgets(sIndex, BUFSIZ, stdin);
	            int index = atoi(sIndex);
	            char field[BUFSIZ];
	            fgets(field, BUFSIZ, stdin);
	            field[strlen(field) - 1] = '\0';
	            getField(index, field);
	            break;
	        }
	        case 'n': { // Get the number of contacts
	            getNumber();
	            break;
	        }
	        case 'l': { // Load a file
	            char path[BUFSIZ];
	            fgets(path, BUFSIZ, stdin);
	            path[strlen(path) - 1] = '\0';
	            loadFromFile(path);
	            break;
	        }
	        case 's': { // Save contacts to a file
	            char path[BUFSIZ];
	            fgets(path, BUFSIZ, stdin);
	            path[strlen(path) - 1] = '\0';
	            saveToFile(path);
	            break;
	        }
	        case 'q': { // Quit
	            printf("Complete\n");
	            break;
	        }
	        default:
	            printf("Not a valid command\n");
	    }
	}
	return EXIT_SUCCESS;
}
