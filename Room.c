#include<stdio.h>
#include"Room.h"

void showRoom(const room_t* room)
{
	if (!room->isTaken)
		printf("isn't taken\n");
	else
	{
		printf("is taken: ");
		printf("%d guests ", room->numOfPeopleInRoom);
		printf("%d breakfasts\n", room->numOfPeopleForBreakfast);
	}
}

void updateRoom(room_t* room, boolean b, int peopleInRoom, int breakfastOrders)
{
	room->isTaken = b;
	room->numOfPeopleInRoom = peopleInRoom;
	room->numOfPeopleForBreakfast = breakfastOrders;
}
