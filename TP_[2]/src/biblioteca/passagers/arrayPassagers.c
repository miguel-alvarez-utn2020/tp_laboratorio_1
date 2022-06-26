#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include "arrayPassagers.h"
#include "../inputs/inputs.h"
#include "../transforms/transform.h"


#define MIN_STATUS_FLIGHT 1
#define MAX_STATUS_FLIGHT 10
#define MIN_TYPE_PASSAGER 1
#define MAX_TYPE_PASSAGER 10
#define MIN_CHARACTER_NAME 1
#define MIN_PRICE_PASSAGER 1
#define MAX_PRICE_PASSAGER 5000000
#define CHANCE_ERROR 2


static int aleatorio_en_rango(int minimo, int maximo);
static void cadena_aleatoria(int longitud, char *destino);
static int Intcmp(int valor1, int valor2);

static void menuEditPassager(
    char name[],
    char lastName[],
    char flyCode[],
    float price,
    int typePassager);

/**
 * @brief Inicia una array de passagers con el valor 0
 *
 * @param listPasaggers array de passager a inicializar
 * @param sizeListPassager size del array a inicializar
 * @return 0
 */
int initPassagers(Passager listPasaggers[], int sizeListPassager)
{
    int i;

    if (listPasaggers != NULL && sizeListPassager > 0)
    {
        for (i = 0; i < sizeListPassager; i++)
        {
            listPasaggers[i].isEmpty = 0;
        }
    }

    return 0;
}
/**
 * @brief hace una carga forzada automatica de passagers para testiar la app
 *
 * @param passagersList array de passagers para cargar
 * @param amountPassagerCharge cantidad de passagers que desea hardcodiar
 * @return 0
 */
int chargePassagerAuto(Passager passagersList[], int amountPassagerCharge)
{
    int i;
    int num;
    char snum[10];
    int sizeCharsFlyCode = 8;
    char flyCodeAuto[8 + 1] = "";
    Passager passagerAux;
    srand(getpid());
    if (amountPassagerCharge > 0)
    {

        for (i = 0; i < amountPassagerCharge; i++)
        {
            num = i + 1;
            itoa(num, snum, 10);
            strcpy(passagerAux.name, "name-passager");
            strcat(passagerAux.name, snum);
            strcpy(passagerAux.lastName, "last-name-passager");
            strcat(passagerAux.lastName, snum);
            cadena_aleatoria(sizeCharsFlyCode, flyCodeAuto);
            strcpy(passagerAux.flyCode, flyCodeAuto);
            passagerAux.id = i + 1;
            passagerAux.price = 5000 * (i + 1);
            passagerAux.isEmpty = 1;
            passagerAux.statusFlight = 800 * (i + 1);
            passagerAux.typePassager = i + 1;
            passagersList[i] = passagerAux;
            strcpy(passagerAux.name, "name-user");
            strcpy(passagerAux.lastName, "last-name-user");
            strcpy(passagerAux.flyCode, "fc25stp36");
        }
    }
    return 0;
}
/**
 * @brief busca una posicion en un array que tenga cargado un 0
 *
 * @param passagersList array donde busca esa posicion
 * @param sizePassagerList tamaño del array
 * @return retorna la posicion del array si encontro una posicion con valor 0 y -1 sino en contro
 */
int findPositionFree(Passager passagersList[], int sizePassagerList)
{
    int i;
    int retorno = -1;
    if (sizePassagerList > 0)
    {
        for (i = 0; i < sizePassagerList; i++)
        {
            if (passagersList[i].isEmpty == 0)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
int findPositionPassagerById(Passager passagerList[], int sizePassagerList, int idPassager)
{
    int i;
    int retorno = -1;
    if (passagerList != NULL && sizePassagerList > 0 && idPassager > 0)
    {

        for (i = 0; i < sizePassagerList; i++)
        {
            if (passagerList[i].id == idPassager && passagerList[i].isEmpty != 0)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
/**
 * @brief añade un pasajero a un array de tipo passager
 *
 * @param newPassager nuevo passager
 * @return retorna un nuevo passager
 */
Passager addPassager(
    Passager newPassager,
    char nameMsj[],
    char lastNameMsj[],
    char flyCodeMsj[],
    char priceMsj[],
    char statusFlightMsj[],
    char typePassagerMsj[],
    char errorRangeMsj[],
    char errorNoValidoMsj[])
{

    Passengger_inputName(&newPassager);

    Passengger_inputLastName(&newPassager);

    Passengger_inputCodigoVuelo(&newPassager);

    Passengger_inputPrice(&newPassager);

    Passengger_inputEstadoVuelo(&newPassager);

    Passengger_inputTipoPasajero(&newPassager);

    return newPassager;
}

Passager editPassager(
    Passager passager,
    char nameMsj[],
    char lastNameMsj[],
    char flyCodeMsj[],
    char priceMsj[],
    char typePassagerMsj[],
    char errorRangeMsj[],
    char errorNoValidoMsj[])
{

    int option;
    int exitMenuEdit = false;

    do
    {
        system("cls");
        menuEditPassager(
            passager.name,
            passager.lastName,
            passager.flyCode,
            passager.price,
            passager.typePassager);
        utn_inputTypeInt(&option, "Ingrese Opcion: ", "Error, opcion fuera de rango\n", 1, 6, 2);

        switch (option)
        {
        case 1:
        	Passengger_inputName(&passager);
            break;
        case 2:
        	Passengger_inputLastName(&passager);

            break;
        case 3:
        	Passengger_inputCodigoVuelo(&passager);
            break;
        case 4:
        	Passengger_inputPrice(&passager);
            break;
        case 5:
        	Passengger_inputTipoPasajero(&passager);
            break;
        case 6:
            exitMenuEdit = true;
            printf("Saliendo de menu, editar pasajero...\n");
            break;

        default:
            printf("Opcion no valida\n");
            break;
        }
    } while (!exitMenuEdit);

    return passager;
}

/**
 * @brief busca un passajero que cumpla con el id recibido por parametro
 *
 * @param passagerList lista de pasajeros
 * @param sizePassagerList tamaño de la lista de pasajeros
 * @param passagerId id del pasajero a buscar
 * @return retorna el passajero encontrado
 */
Passager findPassagerById(Passager passagerList[], int sizePassagerList, int passagerId)
{
    int i;
    Passager retorno;
    if (passagerList != NULL && passagerId > 0)
    {
        for (i = 0; i < sizePassagerList; i++)
        {
            if (passagerList[i].id == passagerId)
            {
                retorno = passagerList[i];
                break;
            }
        }
    }
    return retorno;
}
/**
 * @brief remueve un pasajero del array segun el iD
 *
 * @param passagerList lista de pasajero
 * @param sizePassagerList tamaño de la lista de pasajeros
 * @param passagerId id del pasajero a eliminar
 * @return retorna la posicion del pasajero a eliminar, si no existe -1
 */
int removePassager(Passager passagerList[], int sizePassagerList, int passagerId)
{
    int i;
    int retorno = -1;
    if (passagerList != NULL && sizePassagerList > 0 && passagerId > 0)
    {
        for (i = 0; i < sizePassagerList; i++)
        {
            if (passagerList[i].id == passagerId)
            {
                retorno = i;
                break;
            }
        }
    }

    return retorno;
}
/**
 * @brief ordena una lista de pasajeros de manera ascendente y descendente
 *
 * @param passagerList lista de pasajeros a ordenar
 * @param sizePassagerList tamaño de la lista a ordenar
 * @param orderMode modo de ordenar, -1 ascendente y 1 para descendente
 * @return retorna 0 si todo salio bien, -1 si no completo la tarea
 */
int sortPassagerByName(Passager passagerList[], int sizePassagerList, int orderMode)
{
    int i;
    int j;
    int retorno = -1;
    Passager passagerAux;

    if (passagerList != NULL && sizePassagerList > 0 && orderMode >= -1 && orderMode <= 1)
    {

        for (i = 0; i < sizePassagerList - 1; i++)
        {
            for (j = i + 1; j < sizePassagerList; j++)
            {
                if (strcmp(passagerList[i].lastName, passagerList[j].lastName) == orderMode && passagerList[i].typePassager < passagerList[j].typePassager)
                {
                    passagerAux = passagerList[i];
                    passagerList[i] = passagerList[j];
                    passagerList[j] = passagerAux;
                }
            }
            retorno = 0;
        }
    }
    return retorno;
}
/**
 * @brief muestra todos los pasajero que existen en una lista de pasajeros
 *
 * @param passagersList lista de pasajeros
 * @param sizePassagerList tamaño de la lista
 */
void viewPassagers(Passager passagersList[], int sizePassagerList)
{
    int i;

    for (i = 0; i < sizePassagerList; i++)
    {
        if (passagersList[i].isEmpty != 0)
        {
            printf("ID: %d | Nombre: %s | Apellido: %s | Precio: U$D%.2f | Codigo Vuelo: %s ",
			    passagersList[i].id,
			    passagersList[i].name,
			    passagersList[i].lastName,
			    passagersList[i].price,
			    passagersList[i].flyCode);
            	Passenger_printEstadoVuelo( passagersList[i].statusFlight);
            	Passenger_printTipoPasajero(passagersList[i].typePassager);
            	printf("\n");
        }
    }
    if (i == sizePassagerList)
    {
        printf("========================================\n");
    }
}
/**
 * @brief crea un rango aleatorio para una cadena de caracteres
 *
 * @param minimo minimo de caracters
 * @param maximo maximo de caracteres
 * @return retorna el rango de caracteres
 */
static int aleatorio_en_rango(int minimo, int maximo)
{
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}
/**
 * @brief crear una cadena aleatoria de caracteres
 *
 * @param longitud longitud de la cadena
 * @param destino destino donde va a ser guardada la cadena aleatoria
 */
static void cadena_aleatoria(int longitud, char *destino)
{
    char muestra[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    for (int x = 0; x < longitud; x++)
    {
        int indiceAleatorio = aleatorio_en_rango(0, (int)strlen(muestra) - 1);
        destino[x] = muestra[indiceAleatorio];
    }
}
/**
 * @brief ordena una lista de pasajeros con dos criterios, ascendente o descendente
 *
 * @param passagerList lista de pasajeros
 * @param sizePassagerList tamaño de la lista
 * @param orderMode mode de ordenamiento, -1 ascendente, 1 descentente
 * @return retorna 0 si cumplio con el ordenamiento, -1 si no cumplio el ordenamiento
 */
int sortPassengersByCode(Passager passagerList[], int sizePassagerList, int orderMode)
{
    int i;
    int j;
    int retorno = -1;
    Passager passagerAux;
    if (passagerList != NULL && sizePassagerList > 0)
    {

        for (i = 0; i < sizePassagerList - 1; i++)
        {
            for (j = i + 1; j < sizePassagerList; j++)
            {
                if (
                    strcmp(
                        passagerList[i].flyCode,
                        passagerList[j].flyCode) == orderMode &&
                    Intcmp(passagerList[i].statusFlight,
                           passagerList[j].statusFlight) == orderMode &&
                    passagerList[i].statusFlight == 4 && passagerList[j].statusFlight == 4)
                {
                    passagerAux = passagerList[i];
                    passagerList[i] = passagerList[j];
                    passagerList[j] = passagerAux;
                }
            }
        }
        retorno = 0;
    }
    return retorno;
}
/**
 * @brief calcula el total y promedio de precios y cantidad que superan ese precio
 *
 * @param passagerList lista de pasajeros
 * @param passagerSize tamaño de lista
 * @param amontPassagers cantidad de pasajeros que superan el promedio
 * @param totalPrice total del precio
 * @param avarage promedio de precio
 * @return int
 */
int totalAndAvaragePrices(Passager passagerList[], int passagerSize, int *amontPassagers, float *totalPrice, float *avarage)
{
    int i;
    int retorno = -1;
    int passagerAmountAux;
    float totalPriceAux = 0;
    float avarageAuxCant = 0;
    float avarageAux;
    if (passagerList != NULL && passagerSize > 0)
    {
        for (i = 0; i < passagerSize; i++)
        {
            if (passagerList[i].isEmpty != 0)
            {
                totalPriceAux += passagerList[i].price;
                avarageAuxCant++;
            }
        }
        retorno = 0;
    }
    avarageAux = totalPriceAux / avarageAuxCant;
    highPriceAvarage(passagerList, passagerSize, avarageAux, &passagerAmountAux);
    *amontPassagers = passagerAmountAux;
    *totalPrice = totalPriceAux;
    *avarage = avarageAux;
    return retorno;
}

/**
 * @brief busca en el array de pasajeros los que superan el promedio que viene por parametro
 *
 * @param passagerList array de pasajeros
 * @param sizeList tamaño de array pasajeros
 * @param avarage promedio
 * @param passagerAmount puntero donde se asignara la cantidad que superan el promedio
 * @return retorno 0 si todo salio bien y -1 si algo fue mal
 */

int highPriceAvarage(Passager passagerList[], int sizeList, float avarage, int *passagerAmount)
{
    int i;
    int retorno = -1;
    int passagerAmountAux = 0;
    if (passagerList != NULL && sizeList > 0)
    {
        for (i = 0; i < sizeList; i++)
        {
            if (passagerList[i].isEmpty != 0)
            {
                if (passagerList[i].price > avarage)
                {
                    passagerAmountAux++;
                }
            }
        }
        retorno = 0;
    }
    *passagerAmount = passagerAmountAux;
    return retorno;
}

/**
 * @brief compara dos valores enteros
 *
 * @param valor1
 * @param valor2
 * @return retorna -1 si el valor1 es menor que el valor 2, 0 si son iguales, 1 si el valor 1 es mayor que el 2
 */
static int Intcmp(int valor1, int valor2)
{
    int retorno;
    if (valor1 == valor2)
    {
        retorno = 0;
    }
    else if (valor1 > valor2)
    {
        retorno = -1;
    }
    else
    {
        retorno = 1;
    }
    return retorno;
}
void viewToPassager(Passager passager)
{
    printf("-------------------------------------\n");
    printf("Nombre: %s\n", passager.name);
    printf("Apellido: %s\n", passager.lastName);
    printf("Codigo de vuelo: %s\n", passager.flyCode);
    printf("Precio de vuelo: %.2f\n", passager.price);
    printf("Estados de vuelo: %d\n", passager.statusFlight);
    printf("Tipo de pasajeros: %d\n", passager.typePassager);
    printf("-------------------------------------\n");
}
/**
 * @brief
 *
 * @param name
 * @param lastName
 * @param flyCode
 * @param price
 * @param statusFlight
 * @param typePassager
 */
static void menuEditPassager(
    char name[],
    char lastName[],
    char flyCode[],
    float price,
    int typePassager)
{
    printf("--------------------------------------\n");
    printf("1) Nombre  : %s\n", name);
    printf("2) Apellido: %s\n", lastName);
    printf("3) Codigo de vuelo: %s\n", flyCode);
    printf("4) Precio: $%.2f\n", price);
    printf("5) Tipo de pasajero: %d\n", typePassager);
    printf("--------------------------------------\n");
    printf("6) SALIR\n");
}

void menuOption()
{
    printf("==============================\n");
    printf(" 1)Alta pasajero\n");
    printf(" 2)Modificard pasajero\n");
    printf(" 3)Baja de pasajero\n");
    printf(" 4)Informes\n");
    printf(" 5)SALIR\n");
    printf("==============================\n");
}

void menuOptionInfo()
{
    printf("1)Lista de pasajeros por nombre y tipo de pasajero\n");
    printf("2)Total y promedio de los pasajero y cuantos superan el promedio\n");
    printf("3)Listado de pasajeros por codigo de vuelo y estado de vuelo activo\n");
    printf("4)SALIR\n");
}

/**
 * @brief input de carga de nombre de un pasajero
 *
 * @param this pasajero
 * @return 0 si el nombre fue introducido correctamente, de lo contrario -1
 */
int Passengger_inputName(Passager *this)
{
	char name[50];
	int charsMimino = 1;
	int charsMaximo = 50;
	int chanceError = 2;
	int isValid = -1;
	int retorno = -1;
	do
	{
		isValid = utn_inputName(name, "Ingrese Nombre: ", "Nombre fuera de rango", charsMimino, charsMaximo, chanceError);
		if (isValid == -1)
		{
			printf("Nombre, invalido\n");
		}
		else
		{
			strcpy(this->name, name);
			retorno = 0;
		}
	} while (isValid != 0);
	return retorno;
}
/**
 * @brief input para cargar el apellido de un pasajero
 *
 * @param this pasajero
 * @return 0 si el apellido fue introducido correctamente, de lo contrario -1
 */
int Passengger_inputLastName(Passager *this)
{
	char lastName[50];
	int charsMimino = 1;
	int charsMaximo = 50;
	int chanceError = 2;
	int isValid = -1;
	int retorno = -1;
	do
	{
		isValid = utn_inputName(lastName, "Ingrese Apellido: ", "Apellido, fuera de rango", charsMimino, charsMaximo, chanceError);
		if (isValid == -1)
		{
			printf("Apellido, invalido\n");
		}
		else
		{
			strcpy(this->lastName, lastName);
			retorno = 0;
		}
	} while (isValid != 0);
	return retorno;
}

/**
 * @brief input para cargar el precio de un pasajero
 *
 * @param this pasajero
 * @return 0 si el precio fue cargado correctamente, de lo contrario -1
 */
int Passengger_inputPrice(Passager *this)
{
	int minPrice = 1;
	int maxPrice = 50000;
	float price;
	int chanceError = 1;
	int isValid = -1;
	int retorno = -1;
	do
	{
		isValid = utn_inputTypeFloat(&price, "Ingrese precio: ", "Precio, fuera de rango", minPrice, maxPrice, chanceError);
		if (isValid == -1)
		{
			printf("Precio, invalido\n");
		}
		else
		{
			this->price = price;
			retorno = 0;
		}
	} while (isValid != 0);
	return retorno;
}

/**
 * @brief input para cargar el codigo de vuelo de un pasajero
 *
 * @param this pasajero
 * @return 0 si el codigo de vuelo fue cargado correctamente, de lo contrario -1
 */
int Passengger_inputCodigoVuelo(Passager *this)
{
	char codigoVuelo[20];
	int charsMimino = 1;
	int charsMaximo = 20;
	int chanceError = 0;
	int isValid = -1;
	int retorno = -1;
	do
	{
		isValid = utn_inputTypeText(codigoVuelo, "Ingrese Codigo de vuelo: ", "Codigo de vuelo, fuera de rango", charsMimino, charsMaximo, chanceError);
		if (isValid == -1)
		{
			printf("Codigo de vuelo, invalido\n");
		}
		else
		{
			strcpy(this->flyCode, codigoVuelo);
			retorno = 0;
		}
	} while (isValid != 0);
	return retorno;
}


/**
 * @brief input para cargar el tipo de pasajero
 *
 * @param this pasajero
 * @return 0 si el tipo de pasajero fue cargado correctamente, de lo contrario -1
 */
int Passengger_inputTipoPasajero(Passager *this)
{
	int minTipoPasajero = 1;
	int maxTipoPasajero = 3;
	int tipoPasajero;
	int chanceError = 1;
	int isValid = -1;
	int retorno = -1;
	do
	{
		Passenger_menuTipoPasajero();
		isValid = utn_inputTypeInt(&tipoPasajero, "Ingrese tipo de pasajero: ", "tipo, fuera de rango\n", minTipoPasajero, maxTipoPasajero, chanceError);
		if (isValid == -1)
		{
			printf("Tipo de pasajero, invalido\n");
		}
		else
		{
			this->typePassager = tipoPasajero;
			retorno = 0;
		}
	} while (isValid != 0);
	return retorno;
}

void Passenger_menuTipoPasajero(){
	printf("=====================\n");
	printf("-Ingrese opcion:\n");
	printf("1)First Class\n");
	printf("2)Executive Class\n");
	printf("3)Economy Class\n");
	printf("=====================\n");
}

/**
 * @brief input para cargar el tipo de pasajero
 *
 * @param this pasajero
 * @return 0 si el tipo de pasajero fue cargado correctamente, de lo contrario -1
 */
int Passengger_inputEstadoVuelo(Passager *this)
{
	int minTipoPasajero = 1;
	int maxTipoPasajero = 4;
	int estadoVuelo;
	int chanceError = 1;
	int isValid = -1;
	int retorno = -1;
	do
	{
		Passenger_menuEstadoVuelo();
		isValid = utn_inputTypeInt(&estadoVuelo, "Ingrese estado de vuelo: ", "estado de vuelo, fuera de rango\n", minTipoPasajero, maxTipoPasajero, chanceError);
		if (isValid == -1)
		{
			printf("Estado de vuelo, invalido\n");
		}
		else
		{
			this->statusFlight = estadoVuelo;
			retorno = 0;
		}
	} while (isValid != 0);
	return retorno;
}

void Passenger_menuEstadoVuelo(){
	printf("=====================\n");
		printf("-Ingrese opcion:\n");
		printf("1)Aterrizado\n");
		printf("2)Demorado\n");
		printf("3)En Horario\n");
		printf("4)En Vuelo\n");
		printf("=====================\n");
}


/**
 * @brief muestra por consola el tipo de pasajero segun su numero de tipo
 *
 * @param tipoPasajero numero de tipo de pasajero
 */
void Passenger_printTipoPasajero(int tipoPasajero)
{
	switch (tipoPasajero)
	{
	case 1:
		printf("| First Class ");
		break;
	case 2:
		printf("| Executive Class ");
		break;
	case 3:
		printf("| Economy Class ");
		break;
	}
}
/**
 * @brief muestra en consola el estado de vuelo de un pasajero segun su numero de estado
 *
 * @param estadoVuelo numero de estado
 */
void Passenger_printEstadoVuelo(int estadoVuelo)
{
	switch (estadoVuelo)
	{
	case 1:
		printf("| Aterrizado ");
		break;
	case 2:
		printf("| Demorado ");
		break;
	case 3:
		printf("| En horario ");
		break;
	case 4:
		printf("| En vuelo ");
		break;
	}
}
