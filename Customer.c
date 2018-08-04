#pragma warning( disable : 4996 4013)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include"Customer.h"

boolean valid = FALSE;
int i;

void newCustomer(customer_t* customer, int id)
{
	customer->id = id;
	readName(&customer->customerName);
	getCreditCard(customer->credit_card, customer->credit_expire);
}

void readName(char** customerName)
{
	int len = NAME_LEN;
	char c;
	char *input = (char*)malloc(len * sizeof(char));
	if (!input)
		exit(1);

	printf("\nEnter Customer's name: ");
	for (i = 0; (c = getche()) != '\r'; i++)
	{
		if (i >= len)
		{
			len *= 2;
			input = (char*)realloc(input, (len * sizeof(char)));
		}
		input[i] = c;
	}
	input[i] = '\0'; /// end of string 
	*customerName = strdup(input);
}

void getCreditCard(char credit[], int expir[])
{
	valid = FALSE;
	while (!valid)
	{
		printf("\nEnter credit number: ");
		scanf("%s", credit);
		if (!checkCreditNumber(credit))
			printf("Invalid credit number!\n");
		else
			valid = TRUE;
	}
	valid = FALSE;
	while (!valid)
	{
		printf("\nEnter expiration date(month and year): ");
		scanf("%d %d", &(expir[0]), &(expir[1]));
		if (!checkCardExpiration(expir[0], expir[1]))
			printf("Invalid expiration date!\n");
		else
			valid = TRUE;
	}
}

boolean checkCreditNumber(const char* creditNum)
{
	if (strlen(creditNum) < CARD_DIGITS - 1 || strlen(creditNum) > CARD_DIGITS - 1)
		return FALSE;
	for (i = 0; i < CARD_DIGITS - 1; i++)
		if (creditNum[i] < '0' || creditNum[i] > '9')
			return FALSE;
	return TRUE;
}

boolean checkCardExpiration(int month, int year)
{
	if (month < FIRST_MONTH || month > LAST_MONTH)
		return FALSE;
	if (year < MIN_YEAR || year > MAX_YEAR)
		return FALSE;
	return TRUE;
}

void printCustomerDetails(const customer_t* customer)
{
	printf("id: %d\nname: %s\nCredit number: %s\nExpiration: %d/%d\n", customer->id, customer->customerName, customer->credit_card, customer->credit_expire[0], customer->credit_expire[1]);
}

void upperOneCustomerFirstLetters(char* customerName)
{
	char spaceChar = ' ', *spacePos;
	int letters = 0;

	if (islower(customerName[0]))
		customerName[0] += ASCII_DIFFRENCE;
	///// the rest of this method is for the second name/family name 
	while (spacePos = strchr(&(customerName[letters]), spaceChar)) // while it's not the end of name
	{
		letters = 1 + (spacePos - customerName);
		if (islower(customerName[letters]))
			customerName[letters] += ASCII_DIFFRENCE;
	}
	letters = 0; // resets length of the name 
}

void freeCustomer(customer_t* customer)
{
	free(customer->customerName);
}