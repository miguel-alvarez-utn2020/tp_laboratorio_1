

#ifndef INPUTS_H_
#define INPUTS_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <unistd.h>
#include "LinkedList.h"


int utn_inputTypeInt(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);
int utn_inputTypeFloat(float *pResultado, char *mensaje, char *msjError, float vMinimo, float vMaximo, int reintentos);
int utn_inputTypeDni(char *pResultado, char *mensaje, char *msjError, int vMinimo, int vMaximo, int reintentos);
int utn_inputTypeText(char *pResultado, char *mensaje, char *msjError, int charsMimino, int charsMaximo, int reintentos);
int utn_cargarArrInt(int arr[], int size, char *mensaje, char *msjError, int minimo, int maximo, int reintentos, int automatico);
int inputTypeChar(char *pResultado, char *mensaje, char *msjError, int reintentos);
int utn_inputName(char *pResultado, char *mensaje, char *msjError, int charsMimino, int charsMaximo, int reintentos);
void utn_nextPage(int* list);
void utn_UpperCaseCharString(char * string);
#endif /*INPUTS_H_*/
