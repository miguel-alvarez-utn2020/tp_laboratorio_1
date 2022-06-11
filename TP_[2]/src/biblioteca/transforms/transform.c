#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
#include <math.h>
#include <unistd.h>
#include <ctype.h>
#define CHARS 50

/**
 * @brief
 *
 * @param string
 * @param size
 * @return int
 */
int utn_capitalizeString(char string[])
{
    int retorno = -1;
    if (string != NULL)
    {
        printf("OK CAP\n");
        string[0] = toupper(string[0]);
        retorno = 0;
    }
    return retorno;
}
