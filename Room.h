#ifndef __ROOM_H
#define __ROOM_H

#include "Header.h"

struct Room
{
	boolean isTaken;
	int numOfPeopleInRoom;
	int numOfPeopleForBreakfast;

} typedef room_t;

void showRoom(const room_t* room);
void updateRoom(room_t* room, boolean b, int peopleInRoom, int breakfOrders);

#endif