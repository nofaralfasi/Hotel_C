#pragma warning( disable : 4996)
#include<stdio.h>
#include <stdlib.h>
#include"Hotel.h"

void setNewHotel(hotel_t* hotel)
{
	int i = 0, j = 0;
	getHotelSize(hotel); // gets number of floors and rooms
	hotel->rooms = (room_t**)calloc(hotel->numOfFloors, sizeof(room_t*));
	for (i = 0; i < hotel->numOfFloors; i++)
	{
		hotel->rooms[i] = (room_t*)calloc(hotel->numOfRooms, sizeof(room_t));
		for (j = 0; j < hotel->numOfRooms; j++)
			updateRoom(&(hotel->rooms[i][j]), FALSE, 0, 0);
	}
}

void getHotelSize(hotel_t* hotel)
{
	while (!hotel->numOfFloors)
	{
		printf("Enter number of floors (1-9): ");
		scanf("%d", &(hotel->numOfFloors)); // rows
		if (hotel->numOfFloors >= MAX_FLOORS || hotel->numOfFloors<0)
			hotel->numOfFloors = 0;
	}
	while (!hotel->numOfRooms)
	{
		printf("Enter number of rooms (1-99): ");
		scanf("%d", &(hotel->numOfRooms)); // cols
		if (hotel->numOfRooms >= MAX_ROOMS || hotel->numOfRooms<0)
			hotel->numOfRooms = 0;
	}
}

void showHotelStatus(const hotel_t* hotel)
{
	int i = 0, j = 0;
	for (i = 0; i < hotel->numOfFloors; i++)
	{
		printf("\n ------ floor #%d ------ \n", (i + 1));
		for (j = 0; j < hotel->numOfRooms; j++)
		{
			printf("Room #%d: ", (100 * (i + 1) + j));
			showRoom(&hotel->rooms[i][j]);
		}
	}
}

int getRoomNumber(const hotel_t* hotel)
{
	int roomNumber = 0;
	boolean valid = FALSE;
	while (!valid)
	{
		printf("\nEnter room's number: ");
		scanf("%d", &roomNumber);
		if (!checkRoomNumber(hotel, roomNumber))
			printf("Invalid room number!\n");
		else
			valid = TRUE;
	}
	return roomNumber;
}

void showRoomDetails(const hotel_t* hotel)
{
	int roomNumber = getRoomNumber(hotel);
	printf("\nRoom #%d ", roomNumber);
	showRoom(&(hotel->rooms[(roomNumber / MAX_ROOMS) - 1][roomNumber %MAX_ROOMS]));
}


boolean checkRoomNumber(const hotel_t* hotel, int roomNum)
{
	if (roomNum / MAX_ROOMS > hotel->numOfFloors || roomNum / MAX_ROOMS <= 0)
		return FALSE;
	if (roomNum % MAX_ROOMS >= hotel->numOfRooms)
		return FALSE;
	return TRUE;
}

int checkForAvalibaleRoom(const hotel_t* hotel)
{
	int i = 0, j = 0;
	for (i = 0; i < hotel->numOfFloors; i++)
		for (j = 0; j < hotel->numOfRooms; j++)
			if (!hotel->rooms[i][j].isTaken)
				return (100 * (i + 1)) + j;
	return 0;
}

void freeHotel(hotel_t* hotel)
{
	int i = 0;
	for (i = 0; i < hotel->numOfFloors; i++)
		free(hotel->rooms[i]);
}
