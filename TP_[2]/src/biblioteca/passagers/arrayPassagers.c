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
    int processOk = 1;
    int maxCharacterInputName = sizeof(newPassager.name);

    utn_inputTypeText(
        newPassager.name,
        nameMsj,
        errorRangeMsj,
        MIN_CHARACTER_NAME,
        maxCharacterInputName,
        CHANCE_ERROR);

    utn_inputTypeText(
        newPassager.lastName,
        lastNameMsj,
        errorRangeMsj,
        MIN_CHARACTER_NAME,
        maxCharacterInputName,
        CHANCE_ERROR);

    utn_inputTypeText(
        newPassager.flyCode,
        flyCodeMsj,
        errorNoValidoMsj,
        MIN_CHARACTER_NAME,
        maxCharacterInputName,
        CHANCE_ERROR);

    utn_inputTypeFloat(
        &newPassager.price,
        priceMsj,
        errorRangeMsj,
        MIN_PRICE_PASSAGER,
        MAX_PRICE_PASSAGER,
        CHANCE_ERROR);

    do
    {
        printf("Ingrese '1' si el vuelo es activo o '2' si el vuelo esta inactivo\n");
        utn_inputTypeInt(
            &newPassager.statusFlight,
            statusFlightMsj,
            errorNoValidoMsj,
            MIN_STATUS_FLIGHT,
            MAX_STATUS_FLIGHT,
            CHANCE_ERROR);
        switch (newPassager.statusFlight)
        {
        case 1:
            processOk = 0;
            break;
        case 2:
            processOk = 0;
            break;
        default:
            printf("Estado de vuelo invalido\n");
            system("pause");
            break;
        }
    } while (processOk);

    do
    {
        processOk = 1;
        printf("Ingrese '1' si el tipo de pasajero es standart, o '2' si el pasajero es vip\n");
        utn_inputTypeInt(
            &newPassager.typePassager,
            typePassagerMsj,
            errorNoValidoMsj,
            MIN_TYPE_PASSAGER,
            MAX_TYPE_PASSAGER,
            CHANCE_ERROR);
        switch (newPassager.typePassager)
        {
        case 1:
            processOk = 0;
            break;
        case 2:
            processOk = 0;
            break;
        default:
            printf("Tipo de pasajero invalido\n");
            system("pause");
            break;
        }
    } while (processOk);

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
    int maxCharacterInputName = sizeof(passager.name);
    int maxCharacterInputLastName = sizeof(passager.lastName);

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
            utn_inputTypeText(
                passager.name,
                nameMsj,
                errorRangeMsj,
                MIN_CHARACTER_NAME,
                maxCharacterInputName,
                CHANCE_ERROR);
            utn_capitalizeString(passager.name);
            break;
        case 2:
            utn_inputTypeText(
                passager.lastName,
                lastNameMsj,
                errorRangeMsj,
                MIN_CHARACTER_NAME,
                maxCharacterInputLastName,
                CHANCE_ERROR);
            utn_capitalizeString(passager.lastName);

            break;
        case 3:
            utn_inputTypeText(
                passager.flyCode,
                flyCodeMsj,
                errorNoValidoMsj,
                MIN_CHARACTER_NAME,
                maxCharacterInputName,
                CHANCE_ERROR);
            break;
        case 4:
            utn_inputTypeFloat(
                &passager.price,
                priceMsj,
                errorRangeMsj,
                MIN_PRICE_PASSAGER,
                MAX_PRICE_PASSAGER,
                CHANCE_ERROR);
            break;
        case 5:
            utn_inputTypeInt(
                &passager.typePassager,
                typePassagerMsj,
                errorNoValidoMsj,
                MIN_TYPE_PASSAGER,
                MAX_TYPE_PASSAGER,
                CHANCE_ERROR);
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
            printf("------------------------------------\n");
            printf("Nombre: %s\nApellido: %s\nPrice: %.2f\nCodigo de vuelo: %s\nEstado de vuelo: %d\nTipo de pasajero: %d\nID: %d\n",
                   passagersList[i].name,
                   passagersList[i].lastName,
                   passagersList[i].price,
                   passagersList[i].flyCode,
                   passagersList[i].statusFlight,
                   passagersList[i].typePassager,
                   passagersList[i].id);
        }
    }
    if (i == sizePassagerList)
    {
        printf("------------------------------------\n");
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
                    passagerList[i].statusFlight == 1 && passagerList[j].statusFlight == 1)
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
