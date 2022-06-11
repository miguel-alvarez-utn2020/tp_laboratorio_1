#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
#include <math.h>
#include <unistd.h>

/**
 * @brief inicializa valor en cero, para usar de contador.
 * 
 * @param precio1 
 * @param precio2 
 * @param km 
 * @param pUnitarioA 
 * @param pUnitarioL 
 */
void inicalizarAppVuelos(float* precio1, float* precio2, float* km, float* pUnitarioA, float* pUnitarioL){
    *precio1 = 0;
    *precio2 = 0;
    *km = 0;
    *pUnitarioA = 0;
    *pUnitarioL = 0;
}

/**
 * @brief inicializa un array con el valor -1
 * 
 * @param arr array pasado para inializar
 * @param len size del array
 * @return 1 si fue exitoso y 0 si hubo fallo
 */
int utn_inicializarArr(int arr[], int len){
    int i;
    int retorno = 0;
    int carga = -1;
    if(arr != NULL){
        for ( i = 0; i < len; i++)
        {
            arr[i] = carga;
            retorno = 1;
        }
        
    }
    return retorno;
}