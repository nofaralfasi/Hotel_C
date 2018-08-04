#ifndef __DATABASE_H
#define __DATABASE_H

#include"Hotel.h"
#include"Reservation.h"

struct Database
{
	int cusSize; // size of the customers array
	int resSize; // size of the reservations array
	hotel_t CaliforniaHotel;
	customer_t* customers;  // array of customers
	reservation_t* reservations;  // array of reservations
} typedef database_t;

void addCustomer(database_t* database);
void checkIn(database_t* database);
void settingDynamicAllocation(void** pointer_address, size_t type_size, int* dynamicSize);
int choosingCustomerFromArchive(const customer_t* customers, int size);
void checkOut(database_t* database);
void upperCustomersFirstLetters(customer_t* customers, int size);
void subSringCustomersName(const customer_t* customers, int size);
void freeArchive(database_t* database);

#endif
