#include "Passenger.h"

/**
 * @brief pide espacio en memoria para un nuevo pasajero
 *
 * @return Passenger*
 */
Passenger *Passenger_new()
{
	Passenger *passenger;
	passenger = (Passenger *)malloc(sizeof(Passenger));
	return passenger;
}

Passenger *Passenger_newParametros(int id, char *nombre, char *apellido, float precio, char *codigoVuelo, int tipoPasajero, int estadoVuelo)
{
	Passenger *newPassenger;
	newPassenger = Passenger_new();
	if (newPassenger != NULL)
	{
		Passenger_setId(newPassenger, id);
		Passenger_setNombre(newPassenger, nombre);
		Passenger_setApellido(newPassenger, apellido);
		Passenger_setPrecio(newPassenger, precio);
		Passenger_setTipoPasajero(newPassenger, tipoPasajero);
		Passenger_setCodigoVuelo(newPassenger, codigoVuelo);
		Passenger_setStatusFly(newPassenger, estadoVuelo);
	}
	return newPassenger;
}

/**
 * @brief setea el estado de vuelo de un pasajero
 *
 * @param this pasajero
 * @param statusFly nuevo estado de vuelo
 * @return 0 si seteo el estado de vuelo correctamente, de lo contrario -1
 */
int Passenger_setStatusFly(Passenger *this, int statusFly)
{
	int retorno = -1;
	if (this != NULL)
	{
		this->estadoVuelo = statusFly;
		retorno = 0;
	}
	return retorno;
}
/**
 * @brief devuelve el estado de vuelo de un pasajero
 *
 * @param this pasajero
 * @param statusFly variable que donde se guardara el estado de vuelo
 * @return 0 si guardo el estado de vuelo correctamente, de lo contrario -1
 */
int Passenger_getStatusFly(Passenger *this, int *statusFly)
{
	int retorno = -1;
	if (this != NULL)
	{
		*statusFly = this->estadoVuelo;
		retorno = 0;
	}
	return retorno;
}
/**
 * @brief modifica el valor de la propiedad id de un pasajero
 *
 * @param this pasajero
 * @param id nuevo id
 * @return 0 si seteo el id correctamente, y -1 si no se completo la funcion correctamente
 */
int Passenger_setId(Passenger *this, int id)
{
	int retorno = -1;
	if (this != NULL && id > 0)
	{
		this->id = id;
		retorno = 0;
	}
	return retorno;
}
/**
 * @brief devuelve el id de un pasajero
 *
 * @param this pasajero
 * @param id variable donde se guardara el id de dicho pasajero
 * @return 0 si finalizo la funcion correctamente de lo contrario -1
 */
int Passenger_getId(Passenger *this, int *id)
{
	int retorno = -1;
	if (this != NULL && id > 0)
	{
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}
/**
 * @brief modifica el valor de la propiedad nombre de un pasajero
 *
 * @param this pasajero
 * @param nombre nuevo nombre
 * @return 0 si la funcion finalizo correctamente de lo contrario -1
 */
int Passenger_setNombre(Passenger *this, char *nombre)
{
	int retorno = -1;
	if (this != NULL && strlen(nombre) > 2)
	{
		strcpy(this->nombre, nombre);
		retorno = 0;
	}
	return retorno;
}
/**
 * @brief devuelve la propiedad nombre de un pasajero
 *
 * @param this pasajero
 * @param nombre variable donde se guardara el nombre de dicho pasajero
 * @return 0 si la funcion finalizo correctamente de lo contrario -1
 */
int Passenger_getNombre(Passenger *this, char *nombre)
{
	int retorno = -1;
	if (this != NULL)
	{
		strcpy(nombre, this->nombre);
		retorno = 0;
	}
	return retorno;
}
/**
 * @brief modifica el valor de la propiedad apellido de un pasajero
 *
 * @param this pasajero
 * @param apellido nuevo apellido
 * @return int
 */
int Passenger_setApellido(Passenger *this, char *apellido)
{
	int retorno = -1;
	if (this != NULL && strlen(apellido) > 2)
	{
		strcpy(this->apellido, apellido);
		retorno = 0;
	}
	return retorno;
}
/**
 * @brief devuelve el apellido de un pasajero
 *
 * @param this pasajero
 * @param apellido variable donde se guadara el apellido
 * @return 0 si guardo el apellido correctamente, de lo contrario -1
 */
int Passenger_getApellido(Passenger *this, char *apellido)
{
	int retorno = -1;
	if (this != NULL)
	{
		strcpy(apellido, this->apellido);
		retorno = 0;
	}
	return retorno;
}
/**
 * @brief modifica el codigo de vuelo de un pasajero
 *
 * @param this pasajero
 * @param codigoVuelo nuevo codigo de vuelo
 * @return 0 si seteo el codigo de vuelo correctamente, de lo contrario -1
 */
int Passenger_setCodigoVuelo(Passenger *this, char *codigoVuelo)
{
	int retorno = -1;
	if (this != NULL && strlen(codigoVuelo) > 3)
	{
		strcpy(this->codigoVuelo, codigoVuelo);
		retorno = 0;
	}
	return retorno;
}
/**
 * @brief devuelve el codigo de vuelo de un pasajero
 *
 * @param this pasajero
 * @param codigoVuelo variable donde se guardara el codigo de vuelo
 * @return 0 si seteo el codigo de vuelo correctamente, de lo contrario -1
 */
int Passenger_getCodigoVuelo(Passenger *this, char *codigoVuelo)
{
	int retorno = -1;
	if (this != NULL)
	{
		strcpy(codigoVuelo, this->codigoVuelo);
		retorno = 0;
	}
	return retorno;
}
/**
 * @brief modifica el tipo de pasajero de un pasajero
 *
 * @param this pasajero
 * @param tipoPasajero nuevo tipo de pasajero
 * @return 0 si seteo el tipo de pasajero correctamente, de lo contrario -1
 */
int Passenger_setTipoPasajero(Passenger *this, int tipoPasajero)
{
	int retorno = -1;
	if (this != NULL && tipoPasajero > 0)
	{
		this->tipoPasajero = tipoPasajero;
		retorno = 0;
	}
	return retorno;
}
/**
 * @brief devuelve el tipo de pasajero de un pasajero
 *
 * @param this pasajero
 * @param tipoPasajero variable donde se guardara el tipo de pasajero
 * @return 0 si guardo el tipo de pasajero correctamente, de lo contrario -1
 */
int Passenger_getTipoPasajero(Passenger *this, int *tipoPasajero)
{
	int retorno = -1;
	if (this != NULL)
	{
		*tipoPasajero = this->tipoPasajero;
		retorno = 0;
	}
	return retorno;
}
/**
 * @brief setea el precio de un pasajero
 *
 * @param this pasajero
 * @param precio nuevo precio
 * @return 0 si seteo el precio del pasajero correctamente, de lo contrario -1
 */
int Passenger_setPrecio(Passenger *this, float precio)
{
	int retorno = -1;
	if (this != NULL && precio > 1)
	{
		this->precio = precio;
		retorno = 0;
	}
	return retorno;
}
/**
 * @brief devuelve el precio de un pasajero
 *
 * @param this pasajero
 * @param precio variable donde se guardara el precio
 * @return 0 si guardo el precio correctamente, de lo contrario -1
 */
int Passenger_getPrecio(Passenger *this, float *precio)
{
	int retorno = -1;
	if (this != NULL)
	{
		*precio = this->precio;
		retorno = 0;
	}
	return retorno;
}
/**
 * @brief formulario donde se cargan todos los datos de un pasajero
 *
 * @param isValidForm variable que lleva el valor de un formulario valido o invalido
 * @return Passenger* y guarda el valor de formulario valido
 */
Passenger *Passenger_formNewPassenger(int id)
{
	Passenger *passenger = Passenger_new();
	if (passenger != NULL)
	{
		Passengger_inputName(passenger);
		Passengger_inputLastName(passenger);
		Passengger_inputPrice(passenger);
		Passengger_inputTipoPasajero(passenger);
		Passengger_inputCodigoVuelo(passenger);
		Passengger_inputEstadoVuelo(passenger);
		Passenger_setId(passenger, id);
	}
	else
	{
		passenger = NULL;
	}
	return passenger;
}
/**
 * @brief edita segun la opcion requerida cualquier propiedad de un pasajero
 *
 * @param this pasajero
 */
void Passenger_formEditPassenger(Passenger *this)

{
	int optMin = 1;
	int optMax = 7;
	int charceError = 2;
	int exitEditMenu = 1;
	int opcion;
	do
	{

		Passenger_viewPassenger(this);
		utn_inputTypeInt(&opcion, "Ingrese opcion: ", "Error, opcion incorrecta\n", optMin, optMax, charceError);
		switch (opcion)
		{
		case 1:
			printf("Editando nombre...\n");
			Passengger_inputName(this);
			break;
		case 2:
			printf("Editando Apellido...\n");
			Passengger_inputLastName(this);
			break;
		case 3:
			printf("Editando precio...\n");
			Passengger_inputPrice(this);
			break;
		case 4:
			printf("Editando condigo de vuelo...\n");
			Passengger_inputCodigoVuelo(this);
			break;
		case 5:
			printf("Editando tipo de pasajero...\n");
			Passengger_inputTipoPasajero(this);
			break;
		case 6:
			printf("Editando estado de vuelo...\n");
			Passengger_inputEstadoVuelo(this);
			break;
		case 7:
			printf("Saliendo de editar...\n");
			exitEditMenu = 0;
			break;
		}
		system("pause");
	} while (exitEditMenu);
}
/**
 * @brief input de carga de nombre de un pasajero
 *
 * @param this pasajero
 * @return 0 si el nombre fue introducido correctamente, de lo contrario -1
 */
int Passengger_inputName(Passenger *this)
{
	char name[50];
	int charsMimino = 1;
	int charsMaximo = 50;
	int chanceError = 2;
	int isValid = -1;
	int retorno = -1;
	do
	{
		isValid = utn_inputName(name, "Ingrese Nombre: ", "Nombre fuera de rango", charsMimino, charsMaximo, chanceError);
		if (isValid == -1)
		{
			printf("Nombre, invalido\n");
		}
		else
		{
			Passenger_setNombre(this, name);
			retorno = 0;
		}
	} while (isValid != 0);
	return retorno;
}
/**
 * @brief input para cargar el apellido de un pasajero
 *
 * @param this pasajero
 * @return 0 si el apellido fue introducido correctamente, de lo contrario -1
 */
int Passengger_inputLastName(Passenger *this)
{
	char lastName[50];
	int charsMimino = 1;
	int charsMaximo = 50;
	int chanceError = 2;
	int isValid = -1;
	int retorno = -1;
	do
	{
		isValid = utn_inputName(lastName, "Ingrese Apellido: ", "Apellido, fuera de rango", charsMimino, charsMaximo, chanceError);
		if (isValid == -1)
		{
			printf("Apellido, invalido\n");
		}
		else
		{
			Passenger_setApellido(this, lastName);
			retorno = 0;
		}
	} while (isValid != 0);
	return retorno;
}
/**
 * @brief input para cargar el precio de un pasajero
 *
 * @param this pasajero
 * @return 0 si el precio fue cargado correctamente, de lo contrario -1
 */
int Passengger_inputPrice(Passenger *this)
{
	int minPrice = 1;
	int maxPrice = 50000;
	float price;
	int chanceError = 1;
	int isValid = -1;
	int retorno = -1;
	do
	{
		isValid = utn_inputTypeFloat(&price, "Ingrese precio: ", "Precio, fuera de rango", minPrice, maxPrice, chanceError);
		if (isValid == -1)
		{
			printf("Precio, invalido\n");
		}
		else
		{
			Passenger_setPrecio(this, price);
			retorno = 0;
		}
	} while (isValid != 0);
	return retorno;
}
/**
 * @brief input para cargar el tipo de pasajero
 *
 * @param this pasajero
 * @return 0 si el tipo de pasajero fue cargado correctamente, de lo contrario -1
 */
int Passengger_inputTipoPasajero(Passenger *this)
{
	int minTipoPasajero = 1;
	int maxTipoPasajero = 3;
	int tipoPasajero;
	int chanceError = 1;
	int isValid = -1;
	int retorno = -1;
	do
	{
		Passenger_menuTipoPasajero();
		isValid = utn_inputTypeInt(&tipoPasajero, "Ingrese tipo de pasajero: ", "tipo, fuera de rango\n", minTipoPasajero, maxTipoPasajero, chanceError);
		if (isValid == -1)
		{
			printf("Tipo de pasajero, invalido\n");
		}
		else
		{
			Passenger_setTipoPasajero(this, tipoPasajero);
			retorno = 0;
		}
	} while (isValid != 0);
	return retorno;
}
/**
 * @brief input para cargar el tipo de pasajero
 *
 * @param this pasajero
 * @return 0 si el tipo de pasajero fue cargado correctamente, de lo contrario -1
 */
int Passengger_inputEstadoVuelo(Passenger *this)
{
	int minTipoPasajero = 1;
	int maxTipoPasajero = 3;
	int estadoVuelo;
	int chanceError = 1;
	int isValid = -1;
	int retorno = -1;
	do
	{
		Passenger_menuEstadoVuelo();
		isValid = utn_inputTypeInt(&estadoVuelo, "Ingrese estado de vuelo: ", "estado de vuelo, fuera de rango\n", minTipoPasajero, maxTipoPasajero, chanceError);
		if (isValid == -1)
		{
			printf("Estado de vuelo, invalido\n");
		}
		else
		{
			Passenger_setStatusFly(this, estadoVuelo);
			retorno = 0;
		}
	} while (isValid != 0);
	return retorno;
}
/**
 * @brief input para cargar el codigo de vuelo de un pasajero
 *
 * @param this pasajero
 * @return 0 si el codigo de vuelo fue cargado correctamente, de lo contrario -1
 */
int Passengger_inputCodigoVuelo(Passenger *this)
{
	char codigoVuelo[20];
	int charsMimino = 1;
	int charsMaximo = 20;
	int chanceError = 0;
	int isValid = -1;
	int retorno = -1;
	do
	{
		isValid = utn_inputTypeText(codigoVuelo, "Ingrese Codigo de vuelo: ", "Codigo de vuelo, fuera de rango", charsMimino, charsMaximo, chanceError);
		if (isValid == -1)
		{
			printf("Codigo de vuelo, invalido\n");
		}
		else
		{
			Passenger_setCodigoVuelo(this, codigoVuelo);
			retorno = 0;
		}
	} while (isValid != 0);
	return retorno;
}

/**
 * @brief muestra por consola el tipo de pasajero segun su numero de tipo
 *
 * @param tipoPasajero numero de tipo de pasajero
 */
void Passenger_printTipoPasajero(int tipoPasajero)
{
	switch (tipoPasajero)
	{
	case 1:
		printf("| First Class ");
		break;
	case 2:
		printf("| Executive Class ");
		break;
	case 3:
		printf("| Economy Class ");
		break;
	}
}
/**
 * @brief muestra en consola el estado de vuelo de un pasajero segun su numero de estado
 *
 * @param estadoVuelo numero de estado
 */
void Passenger_printEstadoVuelo(int estadoVuelo)
{
	switch (estadoVuelo)
	{
	case 1:
		printf("| Aterrizado ");
		break;
	case 2:
		printf("| Demorado ");
		break;
	case 3:
		printf("| En horario ");
		break;
	case 4:
		printf("| En vuelo ");
		break;
	}
}
/**
 * @brief parsea un tipo de pasajero a string segun su numero
 *
 * @param tipoPasajero numero de tipo
 * @param tipoPasajeroStr variable donde se guarda el tipo en string
 */
void Passenger_paserTipoPasajero(int tipoPasajero, char *tipoPasajeroStr)
{

	switch (tipoPasajero)
	{
	case 1:
		strcpy(tipoPasajeroStr, "FirstClass");
		break;
	case 2:
		strcpy(tipoPasajeroStr, "ExecutiveClass");
		break;
	case 3:
		strcpy(tipoPasajeroStr, "EconomyClass");
		break;
	}
}
/**
 * @brief parsea el estado de vuelo de un pasajero segun su numero a string
 *
 * @param estadoVuelo numero de estado de vuelo
 * @param estadoVueloStr variable donde se guardara su estado en string
 */
void Passenger_paserEstadoVuelo(int estadoVuelo, char *estadoVueloStr)
{

	switch (estadoVuelo)
	{
	case 1:
		strcpy(estadoVueloStr, "Aterrizado");
		break;
	case 2:
		strcpy(estadoVueloStr, "Demorado");
		break;
	case 3:
		strcpy(estadoVueloStr, "En Horario");
		break;
	case 4:
		strcpy(estadoVueloStr, "En Vuelo");
		break;
	}
}
/**
 * @brief compara dos ids el que trae el pasajero y el que entra por parametro
 *
 * @param passenger pasajero
 * @param id id
 * @return retorno 1 si el id que entrapor parametro es igual al id del pasajero, y 0 si no es igual
 */
int Passenger_idIsFound(Passenger *passenger, int id)
{
	int retorno = 0;
	if (passenger->id == id)
	{
		retorno = 1;
	}
	return retorno;
}

/**
 * @brief muetra en consola un menu de opciones
 * 
 */

void Passenger_mainMenu()
{
	printf("====================================================\n");
	printf("1)Cargar datos desde data.csv(modo texto)\n");
	printf("2)Cargar datos desde data.csv(modo binario)\n");
	printf("3)Alta de Pasajero\n");
	printf("4)Modificar Pasajero\n");
	printf("5)Baja de Pasajero\n");
	printf("6)Listar Pasajeros\n");
	printf("7)Ordenar Pasajeros\n");
	printf("8)Guardar datos de pasajero en data.csv(modo texto)\n");
	printf("9)Guardar datos de pasajero en data.csv(modo binario)\n\n");
	printf("10)Salir\n");
	printf("====================================================\n");
}
/**
 * @brief asigna un id disponible que no haya sido usado en ningun pasajero
 * 
 * @param pArrayListPassenger lista de pasajeros
 * @param idAsing 
 * @return int 
 */
int Passenger_asingPassengerId(LinkedList *pArrayListPassenger, int *idAsing)
{
	FILE *archivo;
	int flag = 1;
	int idAux;
	char id[50];
	archivo = fopen("ids.csv", "r");
	if (archivo != NULL)
	{
		while (!feof(archivo))
		{
			fscanf(archivo, "%[^,\n]\n", id);
			if (flag)
			{
				idAux = atoi(id);
				flag = 0;
			}
			else if (atoi(id) > idAux)
			{
				idAux = atoi(id);
			}
		}
	}
	*idAsing = idAux;
	return 1;
}
/**
 * @brief muestra todos los datos de un pasajero por consola con una interface
 * 
 * @param passenger pasajero
 */
void Passenger_viewPassenger(Passenger *passenger)
{

	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[20];
	int tipoPasajero;
	int estadoVuelo;
	Passenger_getNombre(passenger, nombre);
	Passenger_getApellido(passenger, apellido);
	Passenger_getPrecio(passenger, &precio);
	Passenger_getCodigoVuelo(passenger, codigoVuelo);
	Passenger_getTipoPasajero(passenger, &tipoPasajero);
	Passenger_getStatusFly(passenger, &estadoVuelo);
	printf("====================================================\n");
	printf("1)nombre: %s\n", nombre);
	printf("2)Apellido: %s\n", apellido);
	printf("3)Precio: %.2f\n", precio);
	printf("4)Codigo de vuelo: %s\n", codigoVuelo);
	printf("5)Tipo de pasajero: ");
	Passenger_printTipoPasajero(tipoPasajero);
	printf("6)Estado de vuelo: ");
	Passenger_printEstadoVuelo(estadoVuelo);
	printf("7)Salir\n");
	printf("====================================================\n");
}
/**
 * @brief compara si el apellido del pasajeroI es meno al del pasajeroJ
 *
 * @param passengerI
 * @param passengerJ
 * @return retorna 1 si el apellido del pasajeroI es meno al del pasajeroJ, de lo contrario 0
 */
int Passenger_orderByLastName(void *passengerI, void *passengerJ)
{

	Passenger *passengerOne;
	Passenger *passengerTwo;
	int retorno = 0;
	char lastNameP1[50];
	char lastNameP2[50];
	passengerOne = (Passenger *)passengerI;
	passengerTwo = (Passenger *)passengerJ;
	Passenger_getApellido(passengerOne, lastNameP1);
	Passenger_getApellido(passengerTwo, lastNameP2);
	if (strcmp(lastNameP1, lastNameP2) > 0)
	{
		retorno = 1;
	}
	return retorno;
}
/**
 * @brief compara si el apellido del pasajeroI es meno al del pasajeroJ
 *
 * @param passengerI
 * @param passengerJ
 * @return retorna 1 si el apellido del pasajeroI es meno al del pasajeroJ, de lo contrario 0
 */
int Passenger_orderByLastNameDescend(void *passengerI, void *passengerJ)
{

	Passenger *passengerOne;
	Passenger *passengerTwo;
	int retorno = 0;
	char lastNameP1[50];
	char lastNameP2[50];
	passengerOne = (Passenger *)passengerI;
	passengerTwo = (Passenger *)passengerJ;
	Passenger_getApellido(passengerOne, lastNameP1);
	Passenger_getApellido(passengerTwo, lastNameP2);
	if (strcmp(lastNameP1, lastNameP2) < 0)
	{
		retorno = 1;
	}
	return retorno;
}
/**
 * @brief compara si el numero de tipo de pasajero del pasajeroI es mayor al del pasajeroJ
 *
 * @param passengerI
 * @param passengerJ
 * @return retorna 1 si el numero de tipo de pasajero del pasajeroI es mayor al del pasajeroJ, sino 0
 */
int Passenger_orderByTipoPasajero(void *passengerI, void *passengerJ)
{

	Passenger *passengerOne;
	Passenger *passengerTwo;
	int retorno = 0;
	int tipoAuxP1;
	int tipoAuxP2;
	passengerOne = (Passenger *)passengerI;
	passengerTwo = (Passenger *)passengerJ;
	Passenger_getTipoPasajero(passengerOne, &tipoAuxP1);
	Passenger_getTipoPasajero(passengerTwo, &tipoAuxP2);
	if (tipoAuxP1 > tipoAuxP2)
	{
		retorno = 1;
	}
	return retorno;
}
/**
 * @brief compara si el id de pasajero del pasajeroI es mayor al del pasajeroJ
 *
 * @param passengerI
 * @param passengerJ
 * @return retorna 1 si el id de pasajero del pasajeroI es mayor al del pasajeroJ, sino 0
 */
int Passenger_orderById(void *passengerI, void *passengerJ)
{
	int retorno = 0;
	int idAuxP1;
	int idAuxP2;
	Passenger *passengerOne;
	Passenger *passengerTwo;
	passengerOne = (Passenger *)passengerI;
	passengerTwo = (Passenger *)passengerJ;
	Passenger_getId(passengerOne, &idAuxP1);
	Passenger_getId(passengerTwo, &idAuxP2);
	if (Passenger_idCmp(idAuxP1, idAuxP2) < 0)
	{
		retorno = 1;
	}
	return retorno;
}
/**
 * @brief compara si el id de pasajero del pasajeroI es mayor al del pasajeroJ
 *
 * @param passengerI
 * @param passengerJ
 * @return retorna 1 si el id de pasajero del pasajeroI es mayor al del pasajeroJ, sino 0
 */
int Passenger_orderByIdDesced(void *passengerI, void *passengerJ)
{
	int retorno = 0;
	int idAuxP1;
	int idAuxP2;
	Passenger *passengerOne;
	Passenger *passengerTwo;
	passengerOne = (Passenger *)passengerI;
	passengerTwo = (Passenger *)passengerJ;
	Passenger_getId(passengerOne, &idAuxP1);
	Passenger_getId(passengerTwo, &idAuxP2);
	if (Passenger_idCmp(idAuxP1, idAuxP2) < 0)
	{
		retorno = 1;
	}
	return retorno;
}
/**
 * @brief comapara si el precio de pasajero del pasajeroI es mayor al del pasajeroJ
 *
 * @param passengerI
 * @param passengerJ
 * @return retorna 1 si el precio de pasajero del pasajeroI es mayor al del pasajeroJ
 */
int Passenger_orderByPrice(void *passengerI, void *passengerJ)
{
	int retorno = 0;
	float priceAuxP1;
	float priceAuxP2;
	Passenger *passengerOne;
	Passenger *passengerTwo;
	passengerOne = (Passenger *)passengerI;
	passengerTwo = (Passenger *)passengerJ;
	Passenger_getPrecio(passengerOne, &priceAuxP1);
	Passenger_getPrecio(passengerTwo, &priceAuxP2);
	if (Passenger_priceCmp(priceAuxP1, priceAuxP2) > 0)
	{
		retorno = 1;
	}
	return retorno;
}
/**
 * @brief comapara si el precio de pasajero del pasajeroI es mayor al del pasajeroJ
 *
 * @param passengerI
 * @param passengerJ
 * @return retorna 1 si el precio de pasajero del pasajeroI es mayor al del pasajeroJ
 */
int Passenger_orderByPriceDescend(void *passengerI, void *passengerJ)
{
	int retorno = 0;
	float priceAuxP1;
	float priceAuxP2;
	Passenger *passengerOne;
	Passenger *passengerTwo;
	passengerOne = (Passenger *)passengerI;
	passengerTwo = (Passenger *)passengerJ;
	Passenger_getPrecio(passengerOne, &priceAuxP1);
	Passenger_getPrecio(passengerTwo, &priceAuxP2);
	if (Passenger_priceCmp(priceAuxP1, priceAuxP2) < 0)
	{
		retorno = 1;
	}
	return retorno;
}
/**
 * @brief compara 2 precios
 *
 * @param price_1
 * @param price_2
 * @return retorna 1 si el precio1 es mayor al precio2, retorna 0 si el precio1 es menor al precio2, y 0 si son iguales
 */
int Passenger_priceCmp(float price_1, float price_2)
{
	int retorno = 0;
	if (price_1 > price_2)
	{
		retorno = 1;
	}
	else if (price_1 < price_2)
	{
		retorno = -1;
	}
	return retorno;
}
/**
 * @brief compara 2 id
 *
 * @param id_1
 * @param id_2
 * @return retorna 1 si el id1 es mayor al id2, retorna 0 si el id1 es menor al id2, y 0 si son iguales
 */
int Passenger_idCmp(int id_1, int id_2)
{
	int retorno = 0;
	if (id_1 > id_2)
	{
		retorno = 1;
	}
	else if (id_1 < id_2)
	{
		retorno = -1;
	}
	return retorno;
}
/**
 * @brief guarda el ultimo id en un archivo
 * 
 * @param id 
 * @return retorna 0 si guardo el id, y -1 si no lo guardo 
 */
int Passenger_saveID(int id)
{
	FILE *archivo = NULL;
	int retorno = -1;
	archivo = fopen("ids.csv", "a");
	if (archivo != NULL)
	{
		fprintf(archivo, "%d\n", id);
		retorno = 0;
	}
	fclose(archivo);
	return retorno;
}
/**
 * @brief opciones de paginacion de listar
 * 
 * @return int 
 */
int Passenger_listPagination(){
	int retorno = -1;
	int exit = 1;
	char optionPages;
	do{
		inputTypeChar(&optionPages, "Pagina siguiente? 's' o 'n': ", "Error, opcion", 1);
		optionPages = tolower(optionPages);
		switch (optionPages) {
			case 's':
				retorno = 1;
				exit = 0;
				break;
			case 'n':
				retorno = 0;
				exit = 0;
				break;
			default:
				printf("Opcion, incorrecta\n");
				break;
		}
	}while(exit);


	return retorno;
}
/**
 * @brief menu de opciones para ordenar por un criterio
 * 
 * @return retorna 1 si elige ascendente, 0 si es Descendente 
 */
int Passenger_selectOrder(){
	int retorno = -1;
	int exit = 1;
	int optionOrder;
	do{
		printf("1)Acendente\n2)Descendente\n");
		utn_inputTypeInt(&optionOrder, "Ingrese opcion: ", "Error, fuera de rango\n", 1, 2, 2);
		switch (optionOrder) {
			case 1:
				retorno = 1;
				exit = 0;
				break;
			case 2:
				retorno = 0;
				exit = 0;
				break;
			default:
				printf("Opcion, incorrecta\n");
				break;
		}
	}while(exit);


	return retorno;
}

void Passenger_menuTipoPasajero(){
	printf("=====================\n");
	printf("-Ingrese opcion:\n");
	printf("1)First Class\n");
	printf("2)Executive Class\n");
	printf("3)Economy Class\n");
	printf("=====================\n");
}

void Passenger_menuEstadoVuelo(){
	printf("=====================\n");
		printf("-Ingrese opcion:\n");
		printf("1)Aterrizado\n");
		printf("2)Demorado\n");
		printf("3)En Horario\n");
		printf("4)En Vuelo\n");
		printf("=====================\n");
}


