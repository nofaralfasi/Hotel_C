#ifndef __RESERVATION_H
#define __RESERVATION_H

#include"Room.h"
#include"Customer.h"

#define MAX_CUSTOMERS 4

struct Reservation
{
	customer_t* customer; //pointer to one customer
	int numberOfGuests;
	int numberOfBreakfasts;
	room_t* room; //pointer to reservation's room room	
	boolean Bcheckout; // TRUE=room isn't taken; FALSE=room is taken
} typedef reservation_t;

void addReservation(reservation_t* reservation, customer_t* customer, room_t* room);
void getReservationDetails(reservation_t* reservation);
boolean checkIFThereIsOpenReservation(const reservation_t* reservations, int size);

#endif

