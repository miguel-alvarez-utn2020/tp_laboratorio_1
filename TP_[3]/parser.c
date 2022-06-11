#include "parser.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE *pFile, LinkedList *pArrayListPassenger)
{
	char id[50], nombre[50], apellido[50], precio[50], codigoVuelo[50], tipoPasajero[50], estadoVuelo[50];
	Passenger* passengerAux;
	int idAux;
	float precioAux;
	int tipoPasajeroAux;
	int estadoVueloAux;
	int idUpdate;
	Passenger_asingPassengerId(pArrayListPassenger, &idUpdate);
	if (pFile != NULL)
	{
		while (!feof(pFile))
		{
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,\n]\n", id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoVuelo);

			if(strcmp(tipoPasajero, "FirstClass") == 0){
				tipoPasajeroAux = 1;
			}else if(strcmp(tipoPasajero, "ExecutiveClass") == 0){
				tipoPasajeroAux = 2;
			}else{
				tipoPasajeroAux = 3;
			}
			if(strcmp(estadoVuelo, "Aterrizado") == 0){
				estadoVueloAux = 1;
			}else if(strcmp(estadoVuelo, "Demorado") == 0){
				estadoVueloAux = 2;
			}else if(strcmp(estadoVuelo, "En Horario") == 0){
				estadoVueloAux = 3;
			}else{
				estadoVueloAux = 4;
			}
			idAux = atoi(id);
			precioAux = atof(precio);
			passengerAux = Passenger_newParametros(idAux, nombre, apellido, precioAux, codigoVuelo, tipoPasajeroAux, estadoVueloAux);
			ll_add(pArrayListPassenger, passengerAux);

		}
	}
	return 1;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE *pFile, LinkedList *pArrayListPassenger)
{
	Passenger* passengerAux = NULL;
	int idUpdate;
	Passenger_asingPassengerId(pArrayListPassenger, &idUpdate);

	if (pFile != NULL && pArrayListPassenger != NULL)
	{
		while (!feof(pFile))
		{
			passengerAux = Passenger_new();
			fread(passengerAux, sizeof(Passenger), 1, pFile);
			ll_add(pArrayListPassenger, passengerAux);
		}
	}
	return 1;
}
