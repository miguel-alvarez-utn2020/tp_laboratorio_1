#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
#include <math.h>
#include <unistd.h>

static int esInt(char *cadena);
static int getInt(int *pResultado);
static int myGets(char *cadena, int longitud);
static int getFloat(float *pResultado);
static int esFloat(char *cadena);
static int getDni(char *pResultado);
static int esDni(char *cadena);
static int getText(char* pResultado);
static int cargarAuto(int arr[], int size);
int esPositivo(int valor);
int esPar(int valor);

/**
 * \brief Solicita un numero al usuario, leuego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int utn_inputTypeInt(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos)
{
    int bufferInt;
    int retorno = -1;
    while (reintentos > 0)
    {
        reintentos--;
        printf("%s", mensaje);
        if (getInt(&bufferInt) == 0)
        {
            if (bufferInt >= minimo && bufferInt <= maximo)
            {
                *pResultado = bufferInt;
                retorno = 0;
                break;
            }
        }
        printf("%s", mensajeError);
    }
    return retorno;
}

/**
 * \brief Solicita un numero flotante al usuario, leuego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int utn_inputTypeFloat(float* pResultado, char* mensaje, char* msjError, float vMinimo, float vMaximo, int reintentos){

    float bufferFloat;
    int retorno = -1;

    if(pResultado != NULL && mensaje != NULL && msjError != NULL && vMinimo <= vMaximo && reintentos >= 0){

        while (reintentos > 0){
        reintentos--;
        printf("%s", mensaje);
        if (getFloat(&bufferFloat) == 0)
        {
            if (bufferFloat >= vMinimo && bufferFloat <= vMaximo)
            {
                *pResultado = bufferFloat;
                retorno = 0;
                break;
            }
        }
        printf("%s", msjError);
    }

    }
    return retorno;
}

/**
 * \brief Solicita un numero DNI al usuario, leuego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int utn_inputTypeDni(char* pResultado, char* mensaje, char* msjError, int vMinimo, int vMaximo, int reintentos){

    char bufferDni[50];
    int retorno = -1;

    if(pResultado != NULL && mensaje != NULL && msjError != NULL && vMinimo <= vMaximo && reintentos >= 0){

        while (reintentos > 0){
        reintentos--;
        printf("%s", mensaje);
        if (getDni(bufferDni) == 0)
        {
            if (strlen(bufferDni) >= vMinimo && strlen(bufferDni) <= vMaximo)
            {
                strcpy(pResultado, bufferDni);
                retorno = 0;
                break;
            }
        }
        printf("%s", msjError);
    }

    }
    return retorno;
}
/**
 * \brief Solicita texto al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int utn_inputTypeText(char* pResultado, char* mensaje, char* msjError, int charsMimino, int charsMaximo, int reintentos){
    int retorno = -1;
    char bufferText[charsMaximo];

    if(pResultado != NULL && mensaje != NULL && msjError != NULL && charsMimino <= charsMaximo && reintentos >= 0){

        while (reintentos >= 0)
        {
            reintentos --;
            printf("%s", mensaje);
            if(getText(bufferText)==0){
                if(strlen(bufferText) >= charsMimino && strlen(bufferText)<= charsMaximo ){
                    strcpy(pResultado, bufferText);
                    retorno = 0;
                    break;
                }
            }
            strcpy(pResultado, msjError);

        }
        
    }
    return retorno;
}

/**
 * \brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * un máximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 *
 */
static int myGets(char *cadena, int longitud)
{
    if (cadena != NULL && longitud > 0 && fgets(cadena, longitud, stdin) == cadena)
    {
        fflush(stdin); // LINUX-> __fpurge o WIN-> fflush o MAC-> fpurge
        if (cadena[strlen(cadena) - 1] == '\n')
        {
            cadena[strlen(cadena) - 1] = '\0';
        }
        return 0;
    }
    return -1;
}
/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 *
 */
static int getInt(int *pResultado)
{
    int retorno = -1;
    char buffer[64];
    if (pResultado != NULL)
    {
        if (myGets(buffer, sizeof(buffer)) == 0 && esInt(buffer))
        {
            *pResultado = atoi(buffer);
            retorno = 0;
        }
    }
    return retorno;
}


/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */
static int getFloat(float *pResultado)
{
    int retorno = -1;
    char buffer[64];
    if (pResultado != NULL)
    {
        if (myGets(buffer, sizeof(buffer)) == 0 && esFloat(buffer))
        {
            *pResultado = atof(buffer);
            retorno = 0;
        }
    }
    return retorno;
}
/**
 * \brief Verifica si la cadena ingresada es un numero DNI
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */
static int getDni(char *pResultado)
{
    int retorno = -1;
    char buffer[64];
    if (pResultado != NULL)
    {
        if (myGets(buffer, sizeof(buffer)) == 0 && esDni(buffer))
        {
            strcpy(pResultado, buffer);
            retorno = 0;
        }
    }
    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es texto
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */
int getText(char* pResultado){

    int retorno = -1;
    char buffer[1000];
    if(pResultado != NULL){
        if(myGets(buffer, sizeof(buffer)) == 0){
            strcpy(pResultado, buffer);
            retorno = 0;
        }   
    }
    return retorno;
}
/**
 * @brief Lista un array de enteros
 * 
 * @param arr El array que se listara 
 * @param size El tamaño del array que viene por parametro
 */
void utn_listarInt(int arr[], int size){
    int i;
    if(arr != NULL && size > 0){
        for(i = 0; i < size; i++){
            printf("%d\n", arr[i]);
        }
    }
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
int utn_cantidadPares(int arr[],int size, int* cantPares){
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
int utn_cantPositivos(int arr[], int size, int* cantPositivos){
    int retorno = -1;
    int i;
    int aux = 0;
    if(arr != NULL && size > 0 && cantPositivos != NULL){

        for(i = 0; i < size; i++){

            if(arr[i] > 0){
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
int utn_cantNegativos(int arr[], int size, int* cantNegativos){
    int retorno = -1;
    int i;
    int aux = 0;
    if(arr != NULL && size > 0 && cantNegativos != NULL){

        for(i = 0; i < size; i++){

            if(arr[i] < 0){
                aux ++;
                retorno = 0;
            }
        }

    }
    *cantNegativos = aux;
    return retorno;
}
/**
 * @brief Lista los numero pares que vienen dentro de un array
 * 
 * @param arr Array que contiene los elementos para procesar la tarea
 * @param size Tamaño del array que viene por parametro
 */
void utn_listarParesArr(int arr[], int size){
    int i;
    if(arr != NULL && size > 0){

        for(i = 0; i < size; i++){
            if(arr[i] % 2 == 0){
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
void utn_listarImparesArr(int arr[], int size){
    int i;
    if(arr != NULL && size > 0){
        for(i = 0; i < size; i++){
            if(arr[i] % 2 != 0){
                printf("pos: %d -> %d\n", i, arr[i]);
            }
        }
    }
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
            if(arr[i] % 2 != 0 ){
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
/**
 * @brief Solisita al usuario cargar un cantidad espesifica de numero enteros en un array
 * 
 * @param arr Array que contiene los elementos para procesar la tarea
 * @param size Tamaño del array que viene por parametro 
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * 
 * @param automatico Permite cambiar la funcion a modo carga automatica, si
 *                   se manda por paramtro false o true. true si queremos la carga automatica
 *                   false para carga manual.
 * @return Retorna 0 si se obtuvo el numero y -1 si no
 */
int utn_cargarArrInt(int arr[], 
int size, 
char* mensaje, 
char* msjError, 
int minimo, 
int maximo, 
int reintentos, 
int automatico){
    int retorno = -1;
    int i;
    int aux;
    if(arr != NULL && size > 0 && mensaje != NULL && msjError != NULL && minimo <= maximo && reintentos >= 0){

        if(automatico){
            cargarAuto(arr, size);
        }else{
            
            for(i = 0; i < size; i++){
                utn_inputTypeInt(&aux, mensaje, msjError, minimo, maximo, reintentos);
                arr[i] = aux;
            }
            retorno = 0;
        }
    }
    return retorno;
}
/**
 * @brief Carga un array automaticamente de 0 a size
 * 
 * @param arr Array que contiene los elementos para procesar la tarea
 * @param size Tamaño del array que viene por parametro
 * @return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */
static int cargarAuto(int arr[], int size){
    int i;
    int retorno = -1;
    if(arr != NULL && size > 0){
        for(i = 0; i < size; i++){
            arr[i] = i;
        }
        retorno = 0;
    }
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
 * @brief 
 * 
 * @param valor 
 * @param interes 
 * @return int 
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
 * @brief 
 * 
 * @param bitCoin 
 * @param pesos 
 * @return int 
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
 * @brief 
 * 
 * @param pResultado 
 * @param dividendo 
 * @param divisor 
 * @return int 
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
 * @brief 
 * 
 * @param pResultado 
 * @param valor1 
 * @param valor2 
 * @return int 
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
 * @brief 
 * 
 * @param time 
 * @param mensaje 
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
void inicalizarAppVuelos(float* precio1, float* precio2, float* km, float* pUnitarioA, float* pUnitarioL){
    *precio1 = 0;
    *precio2 = 0;
    *km = 0;
    *pUnitarioA = 0;
    *pUnitarioL = 0;
}
///////////////////////////////////////////////////////////////////////////
/////////////////////--------VALIDADORES-----------////////////////////////
///////////////////////////////////////////////////////////////////////////
/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
 */

static int esFloat(char *cadena)
{
    int i = 0;
    int retorno = 0;
     if (cadena != NULL && strlen(cadena) > 0)
    {
        while (cadena[i] != '\0')
        {
            if (cadena[i] >=  '0' && cadena[i] <= '9')
            {
                retorno = 1;
                break;
            }
            i++;
        }
    }

    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
 */
static int esInt(char *cadena)
{
    int i = 0;
    int retorno = 1;
    if (cadena != NULL && strlen(cadena) > 0)
    {
        while (cadena[i] != '\0')
        {
            if (cadena[i] < '0' || cadena[i] > '9')
            {
                retorno = 0;
                break;
            }
            i++;
        }
    }
    return retorno;
}
/**
 * \brief Verifica si la cadena ingresada es un numero DNI
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
 */
static int esDni(char *cadena)
{
    int i = 0;
    int retorno = 0;
    if (cadena != NULL && strlen(cadena) > 0)
    {
        while (cadena[i] != '\0')
        {
            if(strlen(cadena) == 10){
                if(cadena[2] != '.' && cadena[6] != '.'){
                    retorno = 0;
                    break;
                }
                retorno = 1;
            }else{
                retorno = 0;
                break;
            }
            i++;
        }
    }
    return retorno;
}

int esPar(int valor){
    int retorno = 0;
    if(valor % 2 == 0){
        retorno = 1;
    }
    return retorno;
}

int esPositivo(int valor){
    int retorno = 0;
    if(valor > 0){
        retorno = 1;
    }
    return retorno;
}
