#include "Controller.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	FILE* archive;
	int retorno = -1;
	archive = fopen(path, "r");
	if(archive != NULL){
		retorno = 0;
		parser_PassengerFromText(archive, pArrayListPassenger);
	}else{
		printf("EL archivo no existe\n");
	}
	fclose(archive);
    return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE* archive;
	int retorno = -1;
	archive = fopen(path, "rb");
	if(archive != NULL){
		parser_PassengerFromBinary(archive, pArrayListPassenger);
	}else{
		printf("EL archivo no existe\n");
	}
	fclose(archive);
    return retorno;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int id;
	Passenger* newPassenger;
	Passenger_asingPassengerId(pArrayListPassenger, &id);
	id++;
	newPassenger = Passenger_formNewPassenger(id);
	if(newPassenger != NULL && pArrayListPassenger != NULL){
		ll_add(pArrayListPassenger, newPassenger);
		Passenger_saveID(id);
		retorno = 0;
	}

    return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int i;
	int id;
	int retorno = -1;
	int id_min = 1;
	int id_max = 5000;
	int chaceError = 1;
	int sizeList;
	char msg[] = {"Ingrese numero de id para editar: "};
	char msgError[] = {"Error, numero id fuera de rango\n"};
	sizeList = ll_len(pArrayListPassenger);
	Passenger* passenger;
	if(pArrayListPassenger != NULL){
		retorno = 0;
		utn_inputTypeInt(&id, msg, msgError, id_min, id_max, chaceError);
		for(i = 0; i < sizeList; i++){
			passenger = (Passenger*)ll_get(pArrayListPassenger, i);
			if(Passenger_idIsFound(passenger, id)){
				Passenger_formEditPassenger(passenger);
				ll_set(pArrayListPassenger, i, passenger);
				break;
			}
		}
		printf("ID: %d, no existe\n", id);
	}
    return retorno;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int i;
	int id;
	int retorno = -1;
	int id_min = 1;
	int id_max = 1000;
	int chaceError = 1;
	char msg[] = {"Ingrese numero de id a remover: "};
	char msgError[] = {"Error, numero id fuera de rango\n"};
	int sizeList;
	sizeList = ll_len(pArrayListPassenger);
	Passenger* passenger;
	if(pArrayListPassenger != NULL){
		retorno = 0;
		utn_inputTypeInt(&id, msg, msgError, id_min, id_max, chaceError);
		for(i = 0; i < sizeList; i++){
			passenger = (Passenger*)ll_get(pArrayListPassenger, i);
			if(Passenger_idIsFound(passenger, id)){
				ll_remove(pArrayListPassenger, i);
				break;
			}
		}
	}
    return retorno;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int i;
	int retorno = -1;
	int list = 0;
	Passenger* passenger;
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[20];
	int tipoPasajero;
	int estadoVuelo;
	int size;
	int resp;
	size = ll_len(pArrayListPassenger);
	if(size > 0){
		for(i = 0; i < size; i++ ){

				printf("=================================================================================================\n");
				passenger = (Passenger*)ll_get(pArrayListPassenger, i);
				Passenger_getId(passenger, &id);
				Passenger_getNombre(passenger, nombre);
				Passenger_getApellido(passenger, apellido);
				Passenger_getPrecio(passenger, &precio);
				Passenger_getCodigoVuelo(passenger, codigoVuelo);
				Passenger_getTipoPasajero(passenger, &tipoPasajero);
				Passenger_getStatusFly(passenger, &estadoVuelo);

				printf("ID: %d\nNombre: %s\nApellido: %s\nCodigo de vuelo: %s\nPrecio: $%.2f\n", id, nombre, apellido, codigoVuelo, precio);
				Passenger_printTipoPasajero(tipoPasajero);
				Passenger_printEstadoVuelo(estadoVuelo);
				printf("=================================================================================================\n");

				list++;
				if(list == 100){
					resp = Passenger_listPagination();
					if(resp){
						list = 0;
					}else{
						break;
					}
				}

		}
		retorno = 0;
	}
    return retorno;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int option;
	int order = 1;
	int exitMenuSort = 1;
	int retorno = -1;
	int resp;
	if(pArrayListPassenger != NULL){
		retorno = 0;
		do{
			printf("1)Ordenar por Apellido\n2)Ordena por id\n3)Ordenar por tipo de pasajero\n4)Ordenar por precio\n5)SALIR\n");
			utn_inputTypeInt(&option, "Ingrese opcion: ", "Error, opcion incalida\n", 1, 5, 2);
			switch (option) {
				case 1:
					resp = Passenger_selectOrder();
					if(resp){
						printf("Ordenando, Espere por favor...\n");
						ll_sort(pArrayListPassenger, Passenger_orderByLastName, order);
					}else{
						printf("Ordenando, Espere por favor...\n");
						ll_sort(pArrayListPassenger, Passenger_orderByLastNameDescend, order);
					}
					break;
				case 2:
					resp = Passenger_selectOrder();
					if(resp){
						printf("Ordenando, Espere por favor...\n");
						ll_sort(pArrayListPassenger, Passenger_orderById, order);
					}else{
						printf("Ordenando, Espere por favor...\n");
						ll_sort(pArrayListPassenger, Passenger_orderByIdDesced, order);
					}
					break;
				case 3:
					printf("Ordenando, Espere por favor...\n");
					ll_sort(pArrayListPassenger, Passenger_orderByTipoPasajero, order);

					break;
				case 4:
					resp = Passenger_selectOrder();
					if(resp){
						printf("Ordenando, Espere por favor...\n");
						ll_sort(pArrayListPassenger, Passenger_orderByPrice, order);
					}else{
						printf("Ordenando, Espere por favor...\n");
						ll_sort(pArrayListPassenger, Passenger_orderByPriceDescend, order);
					}
					break;
				case 5:
					printf("Saliendo de sort\n");
					exitMenuSort = 0;
					break;
			}
			system("pause");
		}while(exitMenuSort);
	}
    return retorno;
}


/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	FILE* archivo;
	int size;
	int i;
	int id;
	int retorno = -1;
	char nombre[50];
	char apellido[50];
	char codigovuelo[50];
	float precio;
	int tipoPasajero;
	char tipoPasajeroStr[50];
	int estadoVuelo;
	char estadoVueloStr[50];
	archivo = fopen(path, "a");
	size = ll_len(pArrayListPassenger);
	Passenger* passenger;
	if(archivo != NULL){
		retorno = 0;
		for(i = 0; i < size; i++){
			passenger = ll_get(pArrayListPassenger, i);
			Passenger_getId(passenger, &id);
			Passenger_getNombre(passenger, nombre);
			Passenger_getApellido(passenger, apellido);
			Passenger_getCodigoVuelo(passenger, codigovuelo);
			Passenger_getPrecio(passenger, &precio);
			Passenger_getTipoPasajero(passenger, &tipoPasajero);
			Passenger_getStatusFly(passenger, &estadoVuelo);
			Passenger_paserTipoPasajero(tipoPasajero, tipoPasajeroStr);
			Passenger_paserEstadoVuelo(estadoVuelo, estadoVueloStr);
			fprintf(archivo, "%d,%s,%s,%.2f,%s,%s,%s\n", id, nombre, apellido, precio, codigovuelo, tipoPasajeroStr, estadoVueloStr);
		}
	}
	fclose(archivo);
	return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE* archivo;
	int size;
	int i;
	int retorno = -1;
	archivo = fopen(path, "w+b");
	size = ll_len(pArrayListPassenger);
	Passenger* passenger;
	if(archivo != NULL){
		retorno = 0;
		for(i = 0; i < size; i++){
			passenger = ll_get(pArrayListPassenger, i);
			fwrite(passenger, sizeof(Passenger), 1 , archivo);
		}
	}
	fclose(archivo);
	return retorno;
}

