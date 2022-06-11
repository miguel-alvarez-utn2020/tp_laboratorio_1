#include "inputs.h"

static int myGets(char *cadena, int longitud);
static int getInt(int *pResultado);
static int esInt(char *cadena);
static int getFloat(float *pResultado);
static int esFloat(char *cadena);
static int esDni(char *cadena);
static int getDni(char *pResultado);
static int getText(char *pResultado);
static int cargarAuto(int arr[], int size);
static int esChar(char pRespuesta);
int esNombre(char* nombre);
int containNumbersSymbols(char character);
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
                     char *mensaje,
                     char *msjError,
                     int minimo,
                     int maximo,
                     int reintentos,
                     int automatico)
{
    int retorno = -1;
    int i;
    int aux;
    if (arr != NULL && size > 0 && mensaje != NULL && msjError != NULL && minimo <= maximo && reintentos >= 0)
    {

        if (automatico)
        {
            cargarAuto(arr, size);
        }
        else
        {

            for (i = 0; i < size; i++)
            {
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
static int cargarAuto(int arr[], int size)
{
    int i;
    int retorno = -1;
    if (arr != NULL && size > 0)
    {
        for (i = 0; i < size; i++)
        {
            arr[i] = i;
        }
        retorno = 0;
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
int utn_inputTypeText(char *pResultado, char *mensaje, char *msjError, int charsMimino, int charsMaximo, int reintentos)
{
    int retorno = -1;
    char bufferText[100];
    int flag = 1;
    if (pResultado != NULL && mensaje != NULL && msjError != NULL && charsMimino <= charsMaximo && reintentos >= 0)
    {

		while (reintentos >= 0)
		{
			reintentos--;
			if(flag){
				printf("%s",mensaje);
				flag = 0;
			}
			if (getText(bufferText) == 0)
			{
				if (strlen(bufferText) >= charsMimino && strlen(bufferText) <= charsMaximo)
				{
					strcpy(pResultado, bufferText);
					retorno = 0;
					break;
				}
			}else{
				printf("%s",msjError);
			}
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
int utn_inputTypeDni(char *pResultado, char *mensaje, char *msjError, int vMinimo, int vMaximo, int reintentos)
{

    char bufferDni[50];
    int retorno = -1;
    int flag = 1;
    if (pResultado != NULL && mensaje != NULL && msjError != NULL && vMinimo <= vMaximo && reintentos >= 0)
    {

        while (reintentos > 0)
        {
            reintentos--;
            if(flag){
            	 printf("%s", mensaje);
            	 flag = 0;
            }

            if (getDni(bufferDni) == 0)
            {
                if (strlen(bufferDni) >= vMinimo && strlen(bufferDni) <= vMaximo)
                {
                    strcpy(pResultado, bufferDni);
                    retorno = 0;
                    break;
                }
            }else{
            	printf("%s", msjError);
            }

        }
    }
    return retorno;
}

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
    int flag = 1;
    while (reintentos > 0)
    {
        reintentos--;
        if(flag){
        	printf("%s", mensaje);
        	flag = 0;
        }
        if (getInt(&bufferInt) == 0)
        {
            if (bufferInt >= minimo && bufferInt <= maximo)
            {
                *pResultado = bufferInt;
                retorno = 0;
                break;
            }
        }
        else{
        	printf("%s", mensajeError);
        }

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
int utn_inputTypeFloat(float *pResultado, char *mensaje, char *msjError, float vMinimo, float vMaximo, int reintentos)
{

    float bufferFloat;
    int retorno = -1;
    int flag = 1;
    if (pResultado != NULL && mensaje != NULL && msjError != NULL && vMinimo <= vMaximo && reintentos >= 0)
    {

        while (reintentos > 0)
        {
            reintentos--;
            if(flag){
            	printf("%s", mensaje);
            	flag = 0;
            }

            if (getFloat(&bufferFloat) == 0)
            {
                if (bufferFloat >= vMinimo && bufferFloat <= vMaximo)
                {
                    *pResultado = bufferFloat;
                    retorno = 0;
                    break;
                }
            }else{
            	printf("%s", msjError);
            }

        }
    }
    return retorno;
}
/**
 * @brief
 *
 * @param pResultado
 * @param mensaje
 * @param msjError
 * @param reintentos
 * @return int
 */
int inputTypeChar(char *pResultado, char *mensaje, char *msjError, int reintentos)
{

    int retorno = -1;
    char buffer;
    int flag = 1;
    if (pResultado != NULL && mensaje != NULL && msjError != NULL && reintentos >= 0)
    {

        while (reintentos > 0)
        {
            reintentos--;
            if(flag){
				printf("%s",mensaje);
				flag = 0;
            }
            fflush(stdin);
            scanf("%c", &buffer);
            fflush(stdin);
            if (esChar(buffer))
            {
                *pResultado = buffer;
                retorno = 0;
                break;
            }
            else
            {
                printf("%s",msjError);
            }
        }
    }
    return retorno;
}
/**
 * @brief
 *
 * @param pRespuesta
 * @return int
 */
static int esChar(char pRespuesta)
{
    int retorno = 0;
    if ((pRespuesta >= 'a' && pRespuesta <= 'z') || (pRespuesta >= 'A' && pRespuesta <= 'Z'))
    {
        retorno = 1;
    }
    return retorno;
}
/////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////VALIDATORS/////////////////////////////////////////
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
            if (cadena[i] >= '0' && cadena[i] <= '9')
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
            if (strlen(cadena) == 10)
            {
                if (cadena[2] != '.' && cadena[6] != '.')
                {
                    retorno = 0;
                    break;
                }
                retorno = 1;
            }
            else
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
 * \brief Verifica si la cadena ingresada es texto
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */
static int getText(char *pResultado)
{

    int retorno = -1;
    char buffer[1000];
    if (pResultado != NULL)
    {
        if (myGets(buffer, sizeof(buffer)) == 0)
        {
            strcpy(pResultado, buffer);
            retorno = 0;
        }
    }
    return retorno;
}
/**
 * @brief Get the Int object
 *
 * @param pResultado
 * @return int
 */

int utn_inputName(char *pResultado, char *mensaje, char *msjError, int charsMimino, int charsMaximo, int reintentos){
	int retorno = -1;
	char auxNombre[50];
	utn_inputTypeText(auxNombre, mensaje, msjError, charsMimino, charsMaximo, reintentos);
	if(strlen(auxNombre) > 3){
		if(esNombre(auxNombre)){
			utn_UpperCaseCharString(auxNombre);
			strcpy(pResultado, auxNombre);
			retorno = 0;
		}
	}
	return retorno;
}

/**
 * @brief comprueba si el string nombre es un nombre
 * 
 * @param nombre nombre para ser evaluado
 * @return 0 si el string no es un nombre, y 1 si lo es
 */
int esNombre(char* nombre){
	int i;
	int retorno = 0;
	for(i = 0; i < strlen(nombre)-1; i++){
		if(containNumbersSymbols(nombre[i])){
			retorno = 1;
		}else{
			retorno = 0;
			break;
		}
	}
	return retorno;
}
/**
 * @brief crea una pausa para usar como paginacion en lista largas
 * 
 * @param list numero lista que vuelve a 0 cuando se quiere volver a pagina un rango
 */
void utn_nextPage(int* list){
	printf("Pagina siguiente ->\n");
	system("pause");
	*list = 0;
}
/**
 * @brief comprueba si el caracter esta dentro del rago de las letras
 * 
 * @param character 
 * @return 0 si el caracter es un simbolor o numero, 1 si es una letra
 */
int containNumbersSymbols(char character){
	int retorno = 0;

	if((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z')){
		retorno = 1;
	}
	return retorno;
}

void utn_UpperCaseCharString(char * string){
	 string[0] = toupper(string[0]);
}
