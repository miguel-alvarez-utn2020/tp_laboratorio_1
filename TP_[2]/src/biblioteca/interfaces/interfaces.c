#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
#include <math.h>
#include <unistd.h>

/**
 * @brief crear una espera obligatoria, para cargar datos
 * 
 * @param time valor del tiempo que se quiere dejar en loading
 * @param mensaje mensaje para dejar al usuario
 */
void utn_loading(int time, char* mensaje){
    printf("%s.",mensaje);
    sleep(time);
    system("cls");
    printf("%s..",mensaje);
    sleep(time);
    system("cls");
    printf("%s...",mensaje);
    sleep(time);
}

/**
 * @brief menu de inicio de app agencia de viajes TP_1 UTN
 * 
 * @param mensaje1 Aerolineas
 * @param mensaje2 Latam
 * @param valor1 precio Aerolineas
 * @param valor2 precio Latam
 * @param update interface que aparece si hubo algun cambio en los valores
 */
void menuInicio(char* mensaje1, char* mensaje2, float valor1, float valor2, int update){
    printf("|---------------------------------------|\n");
    printf("|----------App Agencia de viajes--------|\n");
    printf("|---------------------------------------|\n");
    printf("|---------------Menu Inicio-------------|\n");
    printf("|---------------------------------------|\n");
    printf("|  1-> Ingresar kilometros.             |\n");
    printf("|  2-> Ingresar precio de vuelos.       |\n");
    printf("|  3-> Calcular todos los costos.       |\n");
    printf("|  4-> Informar resultados.             |\n");
    printf("|  5-> Cargar forzada de datos.         |\n");
    printf("|  6-> Salir                            |\n");
    printf("|---------------------------------------|\n");

    if(valor1 > 0){
        printf("| Precio %s: $%.2f\n", mensaje1, valor1);
        printf("|---------------------------------------|\n");

    }
    if(valor2 > 0){
        printf("| Precio %s: $%.2f\n", mensaje2, valor2);
        printf("|---------------------------------------|\n");
    }

    if(update > 0){
        printf("| Hay datos para actualizar...\n");
        printf("| Puede calcular con la opcion -> 3\n");
        printf("|---------------------------------------|\n");
    }
    


}
/**
 * @brief subMenu de agencia de viejas TP_1 UTN
 * 
 */
void subMenu(){
    printf("|---------------------------------|\n");
    printf("|------App Agencia de viajes------|\n");
    printf("|---------------------------------|\n");
    printf("|-----------Menu precios----------|\n");
    printf("|---------------------------------|\n");
    printf("|  1-> Precio de vuelo Aerolines. |\n");
    printf("|  2-> Precio de vuelo Latam.     |\n");
    printf("|  3-> volver a menu inicio       |\n");
    printf("|---------------------------------|\n");
}
/**
 * @brief menu de app cargar array
 * 
 */
void cargarArr(){
    printf("|---------------------------------|\n");
    printf("|-----------Cargar arr------------|\n");
    printf("|---------------------------------|\n");
    printf("|---------------------------------|\n");
    printf("|  1-> cargar numero arr.	  |\n");
    printf("|  2-> edirtar numero arr.	  |\n");
    printf("|  3-> eliminar numero arr.	  |\n");
    printf("|  4-> listar numeros.		  |\n");
    printf("|  5-> salir.			  |\n");
    printf("|---------------------------------|\n");
}
/**
 * @brief Interface de informe app agencia de viajes TP_1 UTN
 * 
 * @param mensaje Nombre de aerolinea
 * @param precio precio de aerolinea
 * @param precioDescuento precio con terjeta de debito
 * @param precioRecargo precio con targeta de credito
 * @param precioBitCoin precio con bitcoin
 * @param precioUnitario precio Unitario
 */
void informe(
            char* mensaje,
            float precio,
            float precioDescuento, 
            float precioRecargo, 
            float precioBitCoin, 
            float precioUnitario)
{
  
    printf("Precio %s: $%.2f              \n", mensaje, precio);
    printf("a) Precio con Tarjeta de debito: $%.2f \n", precioDescuento);
    printf("b) Precio con Tarjeta de credito: $%.2f\n", precioRecargo);
    printf("c) Precio pagando con bitCoin: %.2f BTC  \n", precioBitCoin);
    if(precioUnitario > 1){
        printf("d) Precio Unitario: $%.2f              \n\n", precioUnitario);
    }
   
}