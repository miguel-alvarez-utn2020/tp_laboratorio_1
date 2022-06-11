#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CHARS 50
/**
 * @brief
 *
 * @param string1
 * @param string2
 * @param size
 * @return int
 */
int utn_orderComeTwoString(char string1[][CHARS], char string2[][CHARS], int size)
{
    int retorno = -1;
    int i;
    int j;
    char auxiliary[50];
    if (string1 != NULL && string2 != NULL && size > 0)
    {
        for (i = 0; i < size - 1; i++)
        {
            for (j = i + 1; j < size; j++)
            {
                if (strcmp(string1[i], string1[j]) > 1)
                {
                    strcpy(auxiliary, string1[i]);
                    strcpy(string1[i], string1[j]);
                    strcpy(string1[j], auxiliary);
                    strcpy(auxiliary, string2[i]);
                    strcpy(string2[i], string2[j]);
                    strcpy(string2[j], auxiliary);
                }
            }
        }
    }
    if (i == size - 1)
    {
        retorno = 0;
    }
    return retorno;
}
