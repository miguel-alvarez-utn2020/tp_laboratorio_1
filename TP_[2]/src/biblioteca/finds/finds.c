#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
#include <math.h>
#include <unistd.h>
static int posLibre(int valor);


/**
 * @brief busca un numero en el array pasado por parametro
 * 
 * @param arr array donde se busca en numero
 * @param len size del array
 * @param numero numero a buscar dentro de dicho array
 * @return retorna el numero si lo encuentra y -1 si no lo encuentra
 */
int utn_findArrNumber(int arr[], int len, int numero){
    int i;
    int retorno = -1;
    int buffer;
    if(arr != NULL && len > 0){
        for ( i = 0; i < len; i++)
        {
            if(arr[i] == numero ){
                buffer = i;
                retorno = buffer;
                break;
            }
        }
        
    }
    return retorno;
}

/**
 * @brief busca una posicion en un array que sea == -1
 * 
 * @param arr array donde busca la posicion con el valor -1
 * @param len size del array
 * @return retorno la posicion si fue exitosa y -1 si no hubo exito 
 */
int utn_posLibreArr(int arr[], int len){
    int i;
    int retorno = -1;
    int buffer;
    if(arr != NULL && len > 0){
        for ( i = 0; i < len; i++)
        {   
            if(posLibre(arr[i])){
                buffer = i;
                retorno = buffer;
                printf("pos libre: %d\n", retorno);
                break;
            }
        }

    }
    return retorno;
}
/**
 * @brief valida si el valor pasado es -1
 * 
 * @param valor 
 * @return retorna 1 si el valor pasado es -1 y 0 si es distinto a -1;
 */
static int posLibre(int valor){
    int retorno = 0;
    if(valor == -1){
        retorno = 1;
    }
    return retorno;
}