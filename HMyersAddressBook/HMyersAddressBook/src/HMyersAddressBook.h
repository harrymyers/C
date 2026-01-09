/*
 * HMyersAddressBook.h
 *
 *  Created on: May 7, 2023
 *      Author: hmyers1
 */

#ifndef HMYERSADDRESSBOOK_H_
#define HMYERSADDRESSBOOK_H_

typedef struct person Person;
struct person{
	char last_name[256];
	char first_name[256];
	char email[256];
	char phone_number[256];
	Person* next;
	Person* prev;
};

Person *createPerson(char *last, char *first, char *email, char *phone);
void addNewContact(int position, char *contactInfo);
void deleteContact(int index);
void getContact(int index);
void getField(int index, char *field);
void getNumber();
void loadFromFile(char *path);
void saveToFile(char *path);


#endif /* HMYERSADDRESSBOOK_H_ */
