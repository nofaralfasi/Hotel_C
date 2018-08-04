#pragma warning( disable : 4996)
#include<stdio.h>
#include<stdlib.h>
#include"Database.h"

#define SHOW_HOTEL_STATUS 1
#define ADD_CUSTOMER 2
#define CHECKIN 3
#define CHECKOUT 4
#define SHOW_ROOM_DETAILS 5
#define UPPER_FIRST_LETTERS 6
#define SUB_STRING_NAME 7
#define EXIT -1

void main()
{
	int choice = 0;
	database_t database = { 0,0 };
	setNewHotel(&database.CaliforniaHotel);

	while (choice != EXIT)
	{
		printf("\nPress 1 to show hotel status\n");
		printf("Press 2 to add customer\n");
		printf("Press 3 to checkIn\n");
		printf("Press 4 to checkOut\n");
		printf("Press 5 to print room details\n");
		printf("Press 6 to set customer's name's first letter\n");
		printf("Press 7 to enter a name and print customers\n");
		printf("To exit press 0 or any other number..\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case SHOW_HOTEL_STATUS:
			showHotelStatus(&database.CaliforniaHotel);
			break;
		case ADD_CUSTOMER:
			addCustomer(&database);
			break;
		case CHECKIN:
			checkIn(&database);
			break;
		case CHECKOUT:
			checkOut(&database);
			break;
		case SHOW_ROOM_DETAILS:
			showRoomDetails(&database.CaliforniaHotel);
			break;
		case UPPER_FIRST_LETTERS:
			upperCustomersFirstLetters(database.customers, database.cusSize);
			break;
		case SUB_STRING_NAME:
			subSringCustomersName(database.customers, database.cusSize);
			break;
		default:
			freeArchive(&database);
			choice = EXIT;
			printf("\nBye-Bye\n");
			break;
		}
	}
	system("pause");
}



