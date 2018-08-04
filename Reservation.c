#pragma warning( disable : 4996)
#include<stdio.h>
#include <conio.h>

#include"Reservation.h"

void addReservation(reservation_t* reservation, customer_t* customer, room_t* room)
{
	reservation->customer = customer;
	getReservationDetails(reservation); // gets number of guests and breakfasts from user
	reservation->room = room;
	reservation->Bcheckout = FALSE;
	updateRoom(room, TRUE, reservation->numberOfGuests, reservation->numberOfBreakfasts);
	printf("\nCheckIn is done!\n");
}

void getReservationDetails(reservation_t* reservation)
{
	char c;
	boolean valid = FALSE;
	while (!valid)
	{
		printf("\nEnter number of guests(1-4): ");
		scanf("%d", &(reservation->numberOfGuests));
		if (reservation->numberOfGuests <= 0 || reservation->numberOfGuests > MAX_CUSTOMERS)
			printf("Invalid guests number!\n");
		else
			valid = TRUE;
	}
	valid = FALSE;
	while (!valid)
	{
		printf("\nEnter number of breakfast orders: ");
		scanf("%d", &(reservation->numberOfBreakfasts));
		if (reservation->numberOfBreakfasts < 0 || reservation->numberOfBreakfasts > MAX_CUSTOMERS)
			printf("Invalid breakfasts number!\n");
		else if (reservation->numberOfBreakfasts > reservation->numberOfGuests)
		{
			flushall();
			printf("The number of breakfasts is bigger than the number of guests\nWould you like to correct it?(Y/N) ");
			c = getche();
			if (c == 'N' || c == 'n')
				valid = TRUE;
		}
		else
			valid = TRUE;
	}
}

boolean checkIFThereIsOpenReservation(const reservation_t* reservations, int size)
{
	int i;
	if (size > 0)
		for (i = 0; i < size; i++)
			if (reservations[i].room->isTaken) // if there is an open reservation
				return TRUE;
	return FALSE;
}

