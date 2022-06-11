#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

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


