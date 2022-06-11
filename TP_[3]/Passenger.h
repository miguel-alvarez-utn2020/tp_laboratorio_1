/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "inputs.h"
#include <ctype.h>
typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[50];
	int estadoVuelo;

} Passenger;

Passenger *Passenger_new();
Passenger *Passenger_newParametros(int id, char *nombre, char *apellido, float precio, char *codigoVuelo, int tipoPasajero, int estadoVuelo);
void Passenger_delete();

int Passenger_setId(Passenger *this, int id);
int Passenger_getId(Passenger *this, int *id);

int Passenger_setNombre(Passenger *this, char *nombre);
int Passenger_getNombre(Passenger *this, char *nombre);

int Passenger_setApellido(Passenger *this, char *apellido);
int Passenger_getApellido(Passenger *this, char *apellido);

int Passenger_setCodigoVuelo(Passenger *this, char *codigoVuelo);
int Passenger_getCodigoVuelo(Passenger *this, char *codigoVuelo);

int Passenger_setTipoPasajero(Passenger *this, int tipoPasajero);
int Passenger_getTipoPasajero(Passenger *this, int *tipoPasajero);

int Passenger_setPrecio(Passenger *this, float precio);
int Passenger_getPrecio(Passenger *this, float *precio);

int Passenger_setStatusFly(Passenger *this, int statusFly);
int Passenger_getStatusFly(Passenger *this, int *statusFly);

void Passenger_printEstadoVuelo(int estadoVuelo);
void Passenger_printTipoPasajero(int tipoPasajero);

void Passenger_mainMenu();
int Passengger_inputName(Passenger *this);
int Passengger_inputLastName(Passenger *this);
int Passengger_inputPrice(Passenger *this);
int Passengger_inputTipoPasajero(Passenger *this);
int Passengger_inputCodigoVuelo(Passenger *this);
void Passenger_applyIsEmpty(Passenger *this);
int Passengger_inputEstadoVuelo(Passenger *this);
Passenger *Passenger_formNewPassenger(int id);
int Passenger_idIsFound(Passenger *passenger, int id);
void Passenger_formEditPassenger(Passenger *this);
void Passenger_printTipoPasajero(int tipoPasajero);
void Passenger_viewPassenger(Passenger *passenger);
int Passenger_asingPassengerId(LinkedList *pArrayListPassenger, int *id);
int Passenger_orderByLastName(void *passengerI, void *passengerJ);
void Passenger_paserTipoPasajero(int tipoPasajero, char *tipoPasajeroStr);
void Passenger_paserEstadoVuelo(int estadoVuelo, char *estadoVueloStr);
int Passenger_orderById(void *passengerI, void *passengerJ);
int Passenger_orderByPrice(void *passengerI, void *passengerJ);
int Passenger_idCmp(int id_1, int id_2);
int Passenger_priceCmp(float price_1, float price_2);
int Passenger_orderByPrice(void *passengerI, void *passengerJ);
int Passenger_orderByLastNameDescent(void *passengerI, void *passengerJ);
int Passenger_orderByTipoPasajero(void *passengerI, void *passengerJ);
int Passenger_saveID(int id);
int Passenger_listPagination();
int Passenger_selectOrder();
int Passenger_orderByLastNameDescend(void *passengerI, void *passengerJ);
int Passenger_orderByPriceDescend(void *passengerI, void *passengerJ);
int Passenger_orderByIdDesced(void *passengerI, void *passengerJ);
void Passenger_menuTipoPasajero();
void Passenger_menuEstadoVuelo();
#endif /* PASSENGER_H_ */
