/*
 ============================================================================
 Name        : name_proyect.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "biblioteca/inputs/inputs.h"
#include "biblioteca/passagers/arrayPassagers.h"

#define PASSAGERS 10
#define MAX_PASSAGER_ID 5
#define MIN_PASSAGER_ID 1
#define MAX_OPTION_SELECT 5
#define MIN_OPTION_SELECT 1
#define MIN_OPTION_INFO 1
#define MAX_OPTION_INFO 4

#define CHANCE_ERROR_OPTION 2

int main(void)
{
	Passager passager;
	Passager newPassager;
	Passager passagersList[PASSAGERS];
	int positionFree;
	int idPassagerFind;
	int positionPassagerFind;
	int amountPassagerList = 0;
	int optionMenuInicio;
	int optionMenuInfo;
	char removeOption;
	int exitMenuInfo = 1;
	int orderModeByName = -1;
	int orderModeByCode = 1;
	int amountPassagerHighAvaragePrice;
	float avaragePrice;
	float totalPrice;
	bool exitMenuInicio = false;
	setbuf(stdout, NULL);
	initPassagers(passagersList, PASSAGERS);
	do
	{
		system("cls");
		menuOption();
		utn_inputTypeInt(
			&optionMenuInicio,
			"Ingrese opcion: ",
			"Error, Opcion no valida\n",
			MIN_OPTION_SELECT,
			MAX_OPTION_SELECT,
			CHANCE_ERROR_OPTION);

		positionFree = findPositionFree(passagersList, PASSAGERS);

		switch (optionMenuInicio)
		{
		case 1:
			if (positionFree > -1)
			{
				passagersList[positionFree] = addPassager(
					newPassager,
					"Ingrese Nombre: ",
					"Ingrese Apellido: ",
					"Ingrese codigo de vuelo: ",
					"Ingrese precio de vuelo: ",
					"Ingrese estado de vuelo : ",
					"Ingrese tipo de pasajero: ",
					"Error, fuera de rango\n",
					"Error, dato no valido\n");
				amountPassagerList++;
				passagersList[positionFree].id = amountPassagerList;
			}
			break;
		case 2:
			if (amountPassagerList > 0)
			{
				sortPassagerByName(passagersList, PASSAGERS, orderModeByName);
				viewPassagers(passagersList, PASSAGERS);
				utn_inputTypeInt(
					&idPassagerFind,
					"Ingrese ID del pasajero a modificar: ",
					"Error, id invalido\n",
					MIN_PASSAGER_ID,
					MAX_PASSAGER_ID,
					CHANCE_ERROR_OPTION);

				positionPassagerFind = findPositionPassagerById(passagersList, PASSAGERS, idPassagerFind);
				passager = findPassagerById(passagersList, PASSAGERS, idPassagerFind);

				passagersList[positionPassagerFind] =
					editPassager(
						passager,
						"Ingrese Nuevo Nombre: ",
						"Ingrese Nuevo Apellido: ",
						"Ingrese Nuevo codigo de vuelo: ",
						"Ingrese Nuevo precio de vuelo: ",
						"Ingrese Nuevo tipo de pasajero: ",
						"Error, fuera de rango\n",
						"Error, dato no valido\n");
			}
			else
			{
				printf("No hay datos cargados para editar\n");
			}
			break;
		case 3:
			if (amountPassagerList > 0)
			{
				sortPassagerByName(passagersList, PASSAGERS, orderModeByName);
				viewPassagers(passagersList, PASSAGERS);
				utn_inputTypeInt(
					&idPassagerFind,
					"Ingrese ID del pasajero a Eliminar: ",
					"Error, id invalido\n",
					MIN_PASSAGER_ID,
					MAX_PASSAGER_ID,
					CHANCE_ERROR_OPTION);

				positionPassagerFind = findPositionPassagerById(passagersList, PASSAGERS, idPassagerFind);
				if (positionPassagerFind >= 0)
				{
					passager = findPassagerById(passagersList, PASSAGERS, idPassagerFind);
					viewToPassager(passager);
					inputTypeChar(&removeOption, "Quiere eleminar? 's' o 'n': ", "Error, opcion fuera de rango\n", 2);
					fflush(stdin);
					removeOption = towlower(removeOption);
					if (removeOption == 's')
					{
						passagersList[positionPassagerFind].isEmpty = 0;
						amountPassagerList--;
						printf("Pasajero eliminado..\n");
					}
					else
					{
						printf("Cancelado...\n");
					}
				}
				else
				{
					printf("No hay pasajeros con ese ID...\n");
				}
			}
			else
			{
				printf("No hay datos cargados para dar de baja\n");
			}
			break;
		case 4:
			if (amountPassagerList > 0)
			{

				do
				{
					exitMenuInfo = 1;
					menuOptionInfo();
					utn_inputTypeInt(
						&optionMenuInfo,
						"Ingrese opcion: ",
						"Error, opcion no valida\n",
						MIN_OPTION_SELECT,
						MAX_OPTION_SELECT,
						CHANCE_ERROR_OPTION);
					switch (optionMenuInfo)
					{
					case 1:
						sortPassagerByName(passagersList, PASSAGERS, orderModeByName);
						viewPassagers(passagersList, PASSAGERS);
						system("pause");
						break;
					case 2:
						totalAndAvaragePrices(passagersList, PASSAGERS, &amountPassagerHighAvaragePrice, &totalPrice, &avaragePrice);
						printf("Precio Total: %.2f\n", totalPrice);
						printf("Promedio de precios: %.2f\n", avaragePrice);
						printf("Cantidad de pasajeros que superan el promedio: %d\n", amountPassagerHighAvaragePrice);
						system("pause");
						break;
					case 3:
						sortPassengersByCode(passagersList, PASSAGERS, orderModeByCode);
						viewPassagers(passagersList, PASSAGERS);
						system("pause");
						break;
					case 4:
						printf("Saliendo de informes..\n");
						exitMenuInfo = 0;
						break;

					default:
						printf("Opcion invalida");
						break;
					}

				} while (exitMenuInfo);
			}
			else
			{
				printf("No hay datos cargados para listar...\n");
			}
			break;
		}
		system("pause");
	} while (!exitMenuInicio);

	return EXIT_SUCCESS;
}
