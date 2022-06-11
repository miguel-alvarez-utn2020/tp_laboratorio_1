/*
 ============================================================================
 Name        : TP_1_1F.c
 Author      : Alvarez Miguel Angel
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : App para registrar vuelos.(Para una mejor experiencia abra el programa desde el .exe);
 ============================================================================
 */
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "./biblioteca/utn.h"
#include "./biblioteca/interfaces.h"
#define OPCION_MIN 1
#define OPCION_MAX 6
#define REINTENTOS 2
#define KILOMETROS_MIN 100
#define KILOMETROS_MAX 20000
#define PRECIO_MIN 1000
#define PRECIO_MAX 15000000
#define PRECIO_BITCOIN 4606954.55
#define D_TARJETA_DEBITO 10.0
#define R_TARJETA_CREDITO 25.0

int main(void)
{
	int opcion;
	int update = 0;
	int mostrarOn = 0;
	int opcionSub;
	int flag = 1;
	int flagsub = 1;
	float kilometros;
	float pVueloAerolineas;
	float pVueloLatam;
	float pDebitoAerolineas;
	float pDebitoLatam;
	float pCreditoAerolineas;
	float pCreditoLatam;
	float pBitCoinAerolineas;
	float pBitCoinLatam;
	float pUnitarioAerolineas;
	float pUnitarioLatam;
	float valorDiferencia;

	system("cls");
	setbuf(stdout, NULL);
	inicalizarAppVuelos(&pVueloAerolineas, &pVueloLatam, &kilometros, &pUnitarioAerolineas, &pVueloLatam);
	do
	{
		system("cls");
		menuInicio("Aerolineas", "Latam", pVueloAerolineas, pVueloLatam, update);
		utn_inputTypeInt(&opcion,
						 "| Ingrese una opcion: ",
						 "Error, opcion no valida\n",
						 OPCION_MIN,
						 OPCION_MAX,
						 REINTENTOS);
		switch (opcion)
		{
		case 1:
			system("cls");
			utn_inputTypeFloat(&kilometros,
							   "Ingrese Kilometros: ",
							   "Error, fuera de rango",
							   KILOMETROS_MIN,
							   KILOMETROS_MAX,
							   REINTENTOS);
			update = 1;

			break;

		case 2:
			do
			{
				system("cls");
				subMenu();
				utn_inputTypeInt(&opcionSub,
								 "Ingrese una opcion: ",
								 "Error, opcion no valida",
								 OPCION_MIN,
								 OPCION_MAX,
								 REINTENTOS);

				switch (opcionSub)
				{
				case 1:
					utn_inputTypeFloat(&pVueloAerolineas,
									   "Ingrese el precio en aerolineas: ",
									   "Error, fuera de rango\n",
									   PRECIO_MIN,
									   PRECIO_MAX,
									   REINTENTOS);
					update = 1;

					break;

				case 2:
					utn_inputTypeFloat(&pVueloLatam,
									   "Ingrese el precio en Latam: ",
									   "Error, fuera de rango\n",
									   PRECIO_MIN,
									   PRECIO_MAX,
									   REINTENTOS);
					update = 1;

					break;

				case 3:
					printf("Saliendo del menu precios...\n");
					flagsub = 0;
					break;
				}

			} while (flagsub != 0);
			break;

		case 3:
			if (pVueloAerolineas != 0 || pVueloLatam != 0)
			{
				system("cls");
				utn_loading(1, "Calculando costos");
				update = 0;
				if (pVueloAerolineas > 0)
				{
					utn_calcDescuento(&pDebitoAerolineas, D_TARJETA_DEBITO, pVueloAerolineas);
					utn_calcInteres(&pCreditoAerolineas, R_TARJETA_CREDITO, pVueloAerolineas);
					utn_pesosToBitCoin(&pBitCoinAerolineas, pVueloAerolineas, PRECIO_BITCOIN);
					utn_volorUnidad(&pUnitarioAerolineas, pVueloAerolineas, kilometros);
					mostrarOn = 1;
				}

				if (pVueloLatam > 0)
				{
					utn_calcDescuento(&pDebitoLatam, D_TARJETA_DEBITO, pVueloLatam);
					utn_calcInteres(&pCreditoLatam, R_TARJETA_CREDITO, pVueloLatam);
					utn_pesosToBitCoin(&pBitCoinLatam, pVueloLatam, PRECIO_BITCOIN);
					utn_volorUnidad(&pUnitarioLatam, pVueloLatam, kilometros);
					mostrarOn = 1;
				}

				if (pVueloAerolineas > 0 && pVueloLatam > 0)
				{
					utn_diferenciaValores(&valorDiferencia, pVueloAerolineas, pVueloLatam);
				}
				system("cls");
				printf("Costos calculados exitosamente\n");
			}
			else
			{
				printf("Faltan valores por cargar...\n");
				printf("Asegurese, de tener por lo menos, los kilometros y el precio de alguna Aerolinea..\n");
			}
			break;

		case 4:
			system("cls");
			if (mostrarOn && update == 0)
			{
				if (kilometros > 0)
				{
					printf("KMs Ingresados: %.2f km\n\n", kilometros);
				}
				if (pVueloAerolineas > 0)
				{
					informe("Aerolineas", pVueloAerolineas, pDebitoAerolineas, pCreditoAerolineas, pBitCoinAerolineas, pUnitarioAerolineas);
				}
				if (pVueloLatam > 0)
				{
					informe("Latam", pVueloLatam, pDebitoLatam, pCreditoLatam, pBitCoinLatam, pUnitarioLatam);
				}
				if (pVueloAerolineas > 0 && pVueloLatam > 0)
				{
					printf("La diferencia de precio es: %.2f\n", valorDiferencia);
				}
			}
			else if (update == 1)
			{
				printf("Hay datos para actualizar...\n");
			}
			else
			{
				printf("No hay datos para mostrar, \nasegurese de cargarlos y calcularlos\n");
			}
			break;

		case 5:
			system("cls");
			utn_loading(2, "Cargando datos");
			system("cls");
			kilometros = 7090;
			pVueloAerolineas = 13350000.66;
			pVueloLatam = 13500000.76;
			printf("KMs Ingresados: %.2f km\n\n", kilometros);

			utn_calcDescuento(&pDebitoAerolineas, D_TARJETA_DEBITO, pVueloAerolineas);
			utn_calcInteres(&pCreditoAerolineas, R_TARJETA_CREDITO, pVueloAerolineas);
			utn_pesosToBitCoin(&pBitCoinAerolineas, pVueloAerolineas, PRECIO_BITCOIN);
			utn_volorUnidad(&pUnitarioAerolineas, pVueloAerolineas, kilometros);

			utn_calcDescuento(&pDebitoLatam, D_TARJETA_DEBITO, pVueloLatam);
			utn_calcInteres(&pCreditoLatam, R_TARJETA_CREDITO, pVueloLatam);
			utn_pesosToBitCoin(&pBitCoinLatam, pVueloLatam, PRECIO_BITCOIN);
			utn_volorUnidad(&pUnitarioLatam, pVueloLatam, kilometros);

			utn_diferenciaValores(&valorDiferencia, pVueloAerolineas, pVueloLatam);

			printf("KMs Ingresados: %.2f km\n\n", kilometros);

			informe("Aerolineas", pVueloAerolineas, pDebitoAerolineas, pCreditoAerolineas, pBitCoinAerolineas, pUnitarioAerolineas);

			informe("Latam", pVueloLatam, pDebitoLatam, pCreditoLatam, pBitCoinLatam, pUnitarioLatam);

			printf("La diferencia de precio es: %.2f\n", valorDiferencia);

			update = 0;
			mostrarOn = 1;
			break;

		case 6:
			printf("Saliendo del programa\n");
			break;
		}
		flagsub = 1;
		system("pause");

	} while (flag != 0);

	return EXIT_SUCCESS;
}
