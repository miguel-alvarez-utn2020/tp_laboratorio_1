#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
#include <math.h>
#include <unistd.h>
#define CHARS 50
/**
 * @brief Lista un array de enteros
 *
 * @param arr El array que se listara
 * @param size El tamaño del array que viene por parametro
 */
void utn_listarInt(int arr[], int size)
{
    int i;
    if (arr != NULL && size > 0)
    {

        for (i = 0; i < size; i++)
        {
            if (arr[i] != -1)
            {
                printf("%d\n", arr[i]);
            }
        }
    }
}

/**
 * @brief Lista los numero pares que vienen dentro de un array
 *
 * @param arr Array que contiene los elementos para procesar la tarea
 * @param size Tamaño del array que viene por parametro
 */
void utn_listarParesArr(int arr[], int size)
{
    int i;
    if (arr != NULL && size > 0)
    {

        for (i = 0; i < size; i++)
        {
            if (arr[i] % 2 == 0)
            {
                printf("%d\n", arr[i]);
            }
        }
    }
}
/**
 * @brief Lista los numero impares que vienen dentro de un array
 *
 * @param arr Array que contiene los elementos para procesar la tarea
 * @param size Tamaño del array que viene por parametro
 */
void utn_listarImparesArr(int arr[], int size)
{
    int i;
    if (arr != NULL && size > 0)
    {
        for (i = 0; i < size; i++)
        {
            if (arr[i] % 2 != 0)
            {
                printf("pos: %d -> %d\n", i, arr[i]);
            }
        }
    }
}
/**
 * @brief
 *
 * @param string
 * @param size
 */
void utn_listStringArr(char string[][CHARS], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%s\n", string[i]);
    }
}