#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
#include <math.h>
#include <unistd.h>
static int esPar(int valor);
static int esPositivo(int valor);
static int esNegativo(int valor);

/**
 * @brief calcula la resta entre 2 valores 
 * 
 * @param pResultado variable donde se va asignar el resultado
 * @param valor1 
 * @param valor2 
 * @return 0 si fue exitoso y -1 si hubo algun fallo 
 */
int utn_diferenciaValores(float* pResultado, float valor1, float valor2){
    int retorno = -1;
    float buffer;
    if(pResultado != NULL && valor1 > 0 && valor2 > 0){
        if(valor1 > valor2){
            buffer = valor1 - valor2;
            retorno = 0;

        }else{
            buffer = valor2 - valor1;
            retorno = 0;
        }
        
    }
    *pResultado = buffer;
    return retorno;

}

/**
 * @brief calcula el valor por unidad dividiendo 2 valores
 * 
 * @param pResultado resultado de la division
 * @param dividendo valor dividendo
 * @param divisor valor divisor
 * @return 0 si fue exitoso -1 si hubo algun fallo
 */
int utn_volorUnidad(float* pResultado, float dividendo, float divisor){
    int retorno = -1;
    float buffer;
    if(pResultado != NULL && dividendo > 0 && divisor > 0){
        buffer = dividendo / divisor;
        retorno = 0;
    }
    *pResultado = buffer;
    return retorno;
}
/**
 * @brief calcula la cantidad de pesos y los devuelve en bitcoin
 * 
 * @param bitCoin cantidad de bitcoin
 * @param pesos cantidad de pesos para calcular
 * @param precioBitCoin precio de bit coin actual
 * @return 0 si fue exitoso -1 si hubo algun fallo
 */
int utn_pesosToBitCoin(float* bitCoin, float pesos, float precioBitCoin){

    int retorno = -1;
    float buffer;
    if(bitCoin != NULL && pesos > 0){
        buffer = pesos / precioBitCoin;
        retorno = 0;
    }
    *bitCoin = buffer;
    return retorno;
}

/**
 * @brief Le suma valor en porcentaje a un valor que recibe 
 *        por parametro y los asigna a una variable pasada por ref
 * 
 * @param pResultado valariable pasada por referencia para asignar el resultado nuevo
 * @param interes el porcentaje que se le suma al valor 
 * @param valor  valor pasado por parametro para ser aumentado por el porcentaje
 * @return retorna 0 si la funcion fue exitosa, y -1 si hubo algun fallo
 */
int utn_calcInteres(float* pResultado, float interes, float valor){
    int retorno = -1;
    float buffer;
    float aux;

    if(pResultado != NULL && interes > 0){
        aux = valor;
        buffer = aux + aux * interes / 100;
        retorno = 0;
    }
    *pResultado = buffer;
    return retorno;
}

/**
 * @brief Calcula el descuento en porcentaje de un valor
 * 
 * @param valor puntero donde se va a guardar el resultado final
 * @param descuento valor del descuento para ser procesado
 * @return retorna -1 en caso de algun error, y 0 si todo salio bien
 */
int utn_calcDescuento(float* pResultado, float descuento, float valor){
    int retorno = -1;
    float buffer;
    float aux;

    if(pResultado != NULL && descuento > 0){
        aux = valor;
        buffer = aux - aux * descuento / 100;
        retorno = 0;
    }
    *pResultado = buffer;
    return retorno;
}

/**
 * @brief Suma todos los numero enteros que vienen detro del array
 * 
 * @param arr Array que contiene los elementos para ser sumados
 * @param size Tamaño del array que viene por parametro
 * @param suma Puntero al espacio de memoria donde se dejara el resultado
 * @return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */
int utn_sumarIntArr(int arr[], int size, int* suma){

    int retorno = -1;
    int aux = 0;
    int i;
    if(arr != NULL && size > 0 && suma != NULL){
        for(i = 0; i < size; i++){
            aux += arr[i]; 
        }
        retorno = 0;
    }
    *suma = aux;
    return retorno;
}
/**
* @brief Calcula la cantidad de numeros pares que vienen destro de un array
 * 
 * @param arr Array que contiene los elementos para procesar la tarea
 * @param size Tamaño del array que viene por parametro
 * @param cantPares Puntero al espacio de memoria donde se dejara el resultado
 * @return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */
int utn_cantidadParesArr(int arr[],int size, int* cantPares){
    int retorno = -1;
    int i;
    int aux = 0;
    if(arr != NULL && size > 0 && cantPares != NULL){

        for(i = 0; i < size; i++){
            if(esPar(arr[i])){
                aux ++;
                retorno = 0;
            }
        }
    }
    *cantPares = aux;
    return retorno;
}
/**
* @brief Calcula la cantidad de numeros positivos que vienen destro de un array
 * 
 * @param arr Array que contiene los elementos para procesar la tarea
 * @param size Tamaño del array que viene por parametro
 * @param cantPositivos Puntero al espacio de memoria donde se dejara el resultado
 * @return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */
int utn_cantPositivosArr(int arr[], int size, int* cantPositivos){
    int retorno = -1;
    int i;
    int aux = 0;
    if(arr != NULL && size > 0 && cantPositivos != NULL){

        for(i = 0; i < size; i++){

            if(esPositivo(arr[i])){
                aux ++;
                retorno = 0;
            }
        }

    }
    *cantPositivos = aux;
    return retorno;
}
/**
* @brief Calcula la cantidad de numeros negativos que vienen destro de un array
 * 
 * @param arr Array que contiene los elementos para procesar la tarea
 * @param size Tamaño del array que viene por parametro
 * @param cantNegativos Puntero al espacio de memoria donde se dejara el resultado
 * @return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */
int utn_cantNegativosArr(int arr[], int size, int* cantNegativos){
    int retorno = -1;
    int i;
    int aux = 0;
    if(arr != NULL && size > 0 && cantNegativos != NULL){

        for(i = 0; i < size; i++){

            if(esNegativo(arr[i])){
                aux ++;
                retorno = 0;
            }
        }

    }
    *cantNegativos = aux;
    return retorno;
}
/**
 * @brief Calcula el mayor numero impar que viene dentro de un array
 * 
 * @param arr Array que contiene los elementos para procesar la tarea
 * @param size Tamaño del array que viene por parametro
 * @param mayorImp Puntero al espacio de memoria donde se dejara el resultado
 * @return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */
int utn_mayorInparArr(int arr[], int size, int* mayorImp){
    int retorno = -1;
    int i;
    int aux;
    int flag = 1;
    if(arr != NULL && size > 0){

        for(i = 0; i < size; i++){
            if(!esPar(arr[i])){
                if(flag){
                    aux = arr[i];
                    flag = 0;
                    retorno = 0;
                }
                else if (arr[i] > aux){
                    aux = arr[i];
                }
            }
        }
    }
    *mayorImp = aux;
    return retorno;
}

//////////////////////////////////////////////////////////////////////
/////////////////////VALIDATORS//////////////////////////////////////
/**
 * @brief Valida que el numero que viene por parametro sea par
 * 
 * @param valor valor entero para ser evaluado
 * @return retorno 1 si es par y 0 si no es par
 */
static int esPar(int valor){
    int retorno = 0;
    if(valor % 2 == 0){
        retorno = 1;
    }
    return retorno;
}
/**
 * @brief Valida si el valor que entra por parametro es positivo
 * 
 * @param valor valor para ser evaluado si es positivo
 * @return retorno 1 si es positivo 0 si no lo es
*/
static int esPositivo(int valor){
    int retorno = 0;
    if(valor > 0){
        retorno = 1;
    }
    return retorno;
}
/**
 * @brief Valida si el valor que entra por parametro es negativo
 * 
 * @param valor valor para ser evaluado si es positivo
 * @return retorno 1 si es negativo 0 si no lo es
*/
static int esNegativo(int valor){
    int retorno = 0;
    if(valor < 0){
        retorno = 1;
    }
    return retorno;
}