#ifndef __HOTEL_H
#define __HOTEL_H

#include"Room.h"

#define MAX_FLOORS 10
#define MAX_ROOMS 100

struct Hotel
{
	int numOfFloors;
	int numOfRooms;
	room_t** rooms; //matrix of rooms
} typedef hotel_t;

void setNewHotel(hotel_t* hotel);
void showHotelStatus(const hotel_t* hotel);
void getHotelSize(hotel_t* hotel);
int getRoomNumber(const hotel_t* hotel);
void showRoomDetails(const hotel_t* hotel);
boolean checkRoomNumber(const hotel_t* hotel, int roomNum);
int checkForAvalibaleRoom(const hotel_t* hotel);
void freeHotel(hotel_t* hotel);

#endif
