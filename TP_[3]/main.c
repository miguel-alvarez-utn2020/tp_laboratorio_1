#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "parser.h"
#include "inputs.h"
#define MIN_OPT_MAIN_MENU 1
#define MAX_OPT_MAIN_MENU 10
#define MIN_CHARS_NAME 3
#define MAX_CHARS_NAME 50
#define MAIN_MENU_CHANCE_ERROR 2
#define NAME_CHANCE_ERROR 2
/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	char path[] = {"data.csv"};
	char pathBin[] = {"dataBin.bin"};
	int optionMainMenu;
	int exitMainMenu = 0;
	int exitMainMenu2 = 1;
	int isSaved = 0;
	int sizelist;
	int flagLoadArchive = 1;
	setbuf(stdout, NULL);
	LinkedList *listPassenger = ll_newLinkedList();
	do
	{
		sizelist = ll_len(listPassenger);
		Passenger_mainMenu();
		utn_inputTypeInt(&optionMainMenu, "Ingrese opcion: ", "Error, opcion invalida\n\n", MIN_OPT_MAIN_MENU, MAX_OPT_MAIN_MENU, MAIN_MENU_CHANCE_ERROR);
		switch (optionMainMenu)
		{
		case 1:
			if(flagLoadArchive){
				controller_loadFromText(path, listPassenger);
				flagLoadArchive = 0;
			}else{
				printf("Un archivo ya a sido cargado\n");
			}
			break;
		case 2:
			if(flagLoadArchive){
				controller_loadFromBinary(pathBin, listPassenger);
				flagLoadArchive = 0;
			}else{
				printf("Un archivo ya a sido cargado\n");
			}
			break;
		case 3:
			controller_addPassenger(listPassenger);
			break;
		case 4:
			if(sizelist){
				controller_ListPassenger(listPassenger);
				controller_editPassenger(listPassenger);
			}else{
				printf("No hay datos cargados para editar...\n");
			}
			break;
		case 5:
			if(sizelist){
				controller_ListPassenger(listPassenger);
				controller_removePassenger(listPassenger);
			}else{
				printf("No hay datos cargados para remover\n");
			}
			break;
		case 6:

			if(sizelist){
				system("cls");
				controller_ListPassenger(listPassenger);
			}else{
				printf("No hay datos cargados para listar\n");
			}
			break;
		case 7:
			if(sizelist){
				controller_sortPassenger(listPassenger);
			}
			else{
				printf("No hay datos cargados para ordenar\n");
			}
			break;
		case 8:
			exitMainMenu2 = 1;
			printf("1)Desea cambiar la ruta del archivo, para guarda?\n2)no\n");
			utn_inputTypeInt(&optionMainMenu, "Ingrese opcion", "Error, opcion invalida\n", 1, 2, 1);
			do{
				switch (optionMainMenu) {
					case 1:
						utn_inputTypeText(path, "Puede ingresar un nuevo path: ", "Error, fuera de rango\n", 1, 50, 1);
						controller_saveAsText(path, listPassenger);
						exitMainMenu2 = 0;
						isSaved = 1;
						break;
					case 2:
						controller_saveAsText(path, listPassenger);
						exitMainMenu2 = 0;
						isSaved = 1;
						break;
					default:
						printf("Opcion invalida\n");
						break;
				}
			}while(exitMainMenu2);
			break;

		case 9:
			exitMainMenu2 = 1;
			printf("1)Desea cambiar la ruta del archivo, para guarda?\n2)no\n");
			utn_inputTypeInt(&optionMainMenu, "Ingrese opcion", "Error, opcion invalida\n", 1, 2, 1);
			do{

				switch (optionMainMenu) {
					case 1:
						utn_inputTypeText(pathBin, "Puede ingresar un nuevo path: ", "Error, fuera de rango\n", 1, 50, 1);
						controller_saveAsBinary(pathBin, listPassenger);
						exitMainMenu2 = 0;
						isSaved = 1;
						break;
					case 2:
						controller_saveAsBinary(pathBin, listPassenger);
						exitMainMenu2 = 0;
						isSaved = 1;
						break;
					default:
						printf("Opcion invalida\n");
						break;
				}
			}while(exitMainMenu2);
			break;
		case 10:
			printf("SALIR\n");
			if(isSaved == 1){
				exitMainMenu = 1;
			}else{
				printf("Asegurese de guardar los datos en los archivos antes de salir\n");
			}
			break;
		default:
			printf("Opcion fuera de rango\n");
			break;
		}
		system("pause");
	} while (!exitMainMenu);

	return EXIT_SUCCESS;
}

