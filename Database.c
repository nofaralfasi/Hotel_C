#pragma warning( disable : 4996 )
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
#include"Database.h"

int roomNumber = 0, i;

void addCustomer(database_t* database)
{
	static int dynamicCusSize;
	database->cusSize++;
	if (database->cusSize == 1 || database->cusSize == dynamicCusSize) // if dynamic allocation is needed
		settingDynamicAllocation(&(database->customers), sizeof(customer_t), &dynamicCusSize);
	newCustomer(&(database->customers[(database->cusSize) - 1]), database->cusSize);
}

void settingDynamicAllocation(void** pointer_address, size_t type_size, int* dynamicSize)
{
	if (*dynamicSize == 0) // if this is the first dynamic allocation
	{
		*dynamicSize = 2;
		*pointer_address = malloc(*dynamicSize * type_size); // allocating 2 places
	}
	else
		*dynamicSize *= 2;
	*pointer_address = realloc(*pointer_address, type_size*(*dynamicSize)); // duplicates the size of the array 		
	if (!*pointer_address)// checks if allocation succeeded
		exit(1);
}

void checkIn(database_t* database)
{
	static int dynamicResSize;
	int custID = 0;
	roomNumber = checkForAvalibaleRoom(&(database->CaliforniaHotel));
	if (roomNumber != 0) // if there is an avaliable room
	{
		database->resSize++;
		if (database->resSize == 1 || database->resSize == dynamicResSize) // if dynamic allocation is needed
			settingDynamicAllocation(&(database->reservations), sizeof(reservation_t), &dynamicResSize);

		if (database->cusSize != 0) // if customers array isn't empty
			custID = choosingCustomerFromArchive(database->customers, database->cusSize); // display customers names and let user choose
		if (!custID)
		{
			printf("\nAdding a new customer:");
			addCustomer(database);
			custID = database->cusSize;
		}
		addReservation(&(database->reservations[database->resSize - 1]), &(database->customers[custID - 1]), &(database->CaliforniaHotel.rooms[(roomNumber / MAX_ROOMS) - 1][roomNumber % MAX_ROOMS]));
	}
	else
		printf("\nThere are no avalibale rooms!\n");
}

int choosingCustomerFromArchive(const customer_t* customers, int size)
{
	int custNum = 0;
	boolean valid = FALSE;
	if (size)
	{
		printf("Reserved customers on database:\n");
		for (i = 0; i < size; i++)
			printf("\n%d: %s", (i + 1), (customers[i].customerName));

		while (!valid)
		{
			printf("\nEnter your number or press 0 to add a new customer: ");
			scanf("%d", &custNum);
			if (custNum < 0 || custNum > size)
				printf("Invalid customer number!\n");
			else
				valid = TRUE;
		}
	}
	return custNum;
}

void checkOut(database_t* database)
{
	if (checkIFThereIsOpenReservation(database->reservations, database->resSize))
	{
		roomNumber = getRoomNumber(&database->CaliforniaHotel);
		if ((database->CaliforniaHotel.rooms[(roomNumber / MAX_ROOMS) - 1][roomNumber % MAX_ROOMS]).isTaken) //checks if the room is taken		
		{
			for (i = 0; i < database->resSize; i++)
				if (database->reservations[i].room == &(database->CaliforniaHotel.rooms[(roomNumber / MAX_ROOMS) - 1][roomNumber % MAX_ROOMS])) //finds room's reservation in the array 	
				{
					database->reservations[i].Bcheckout = TRUE;
					updateRoom(database->reservations[i].room, FALSE, 0, 0);
					printf("\nCheckout is done!\n");
					i = database->resSize;
				}
		}
		else
			printf("Room #%d isn't taken!\n", roomNumber);
	}
	else
		printf("\nThere are no open reservations!\n");
}


void upperCustomersFirstLetters(customer_t* customers, int size)
{
	static int count = 0;

	for (i = count; i < size; i++)
		upperOneCustomerFirstLetters(customers[i].customerName);
	printf("\nCustomers names have been updated!\n");
	if (count < size)
		count = size;
}

void subSringCustomersName(const customer_t* customers, int size)
{
	int counter = 0;
	customer_t* tmp;
	char *pos, str[100] = { '\0' };

	while (str[0] == '\0')
	{
		printf("\nEnter the subString: ");
		scanf("%s", str);
	}

	for (i = 0; i < size; i++)
	{
		pos = strstr(customers[i].customerName, str);
		if (pos) // if pos isn't NULL
		{
			counter++;
			if (counter == 1)
				tmp = (customer_t*)malloc(sizeof(customer_t));
			else
				tmp = (customer_t*)realloc(tmp, sizeof(customer_t)*counter);
			tmp[counter - 1] = customers[i];
		}
	}
	if (counter) // if at least 1 customer is found
	{
		printf("Customers who have the string on their name:\n");
		for (i = 0; i < counter; i++)
			printCustomerDetails(&tmp[i]);
	}
	else
		printf("\nNo customers have found!\n");
}

void freeArchive(database_t* database)
{
	for (i = 0; i < database->cusSize; i++)
		freeCustomer(&(database->customers[i]));
	free(database->customers);
	free(database->reservations);
	freeHotel(&(database->CaliforniaHotel));
}
