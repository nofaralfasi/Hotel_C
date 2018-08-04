#ifndef __CUSTOMER_H
#define __CUSTOMER_H

#include "Header.h"

#define ASCII_DIFFRENCE 'Z'-'z'
#define NAME_LEN 15 
#define CARD_DIGITS 13
#define MIN_YEAR 2010
#define MAX_YEAR 2020
#define FIRST_MONTH 1
#define LAST_MONTH 12

struct Customer
{
	int id;
	char* customerName;
	char credit_card[CARD_DIGITS];
	int credit_expire[2];
} typedef customer_t;

void newCustomer(customer_t* customer, int id);
void readName(char** customerName);
void getCreditCard(char credit[], int expir[]);
int choosingCustomerFromArchive(const customer_t* customers, int size);
boolean checkCreditNumber(const char* creditNum);
boolean checkCardExpiration(int month, int year);
void printCustomerDetails(const customer_t* customer);
void upperOneCustomerFirstLetters(char* customerName);
void freeCustomer(customer_t* customer);

#endif