#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;
    this = (LinkedList*)malloc(sizeof(LinkedList));
    if(this != NULL){
    	this->size = 0;
    	this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
	int returnAux = -1;
	if(this != NULL){
		returnAux = this->size;
	}
	return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	int i;
	Node* node = NULL;
	if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this)){
		node = this->pFirstNode;
		for(i = 0; i < nodeIndex; i++){
			node = node->pNextNode;
		}
	}
    return node;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
int returnAux = -1;
	int i;
	Node* nodeAux;
	Node* temp;
	if(this != NULL && nodeIndex >= 0){
		Node* node = (Node*)malloc(sizeof(Node));
		node->pElement = pElement;
		nodeAux = this->pFirstNode;
		if(nodeIndex == 0){
			node->pNextNode = nodeAux;
			this->pFirstNode = node;
		}
		else if(nodeIndex > 0){
			for(i = 0; i < nodeIndex -1; i++){
				nodeAux = nodeAux->pNextNode;
			}
			temp = nodeAux->pNextNode;
			nodeAux->pNextNode = node;
			node->pNextNode = temp;
		}
		returnAux = 0;
		this->size++;
	}
	return returnAux;
}
/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
	int returnAux = -1;
		Node* nodeAux;
		if(this != NULL){
			Node* node = (Node*)malloc(sizeof(Node));
			node->pElement = pElement;
			node->pNextNode = NULL;
			if(this->pFirstNode == NULL){
				this->pFirstNode = node;
			}
			else{
				nodeAux = this->pFirstNode;
				while(nodeAux->pNextNode != NULL){
					nodeAux = nodeAux->pNextNode;
				}
				nodeAux->pNextNode = node;
			}
			returnAux = 0;
			this->size++;
		}
		return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* aux;
    if(this != NULL && index >= 0 && index < ll_len(this)){
    	aux = getNode(this, index);
    	returnAux = aux->pElement;
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    int i = 0;
    Node* aux;
    if(this != NULL && index >= 0 && index < this->size){
		aux = this->pFirstNode;
		while(i++ < index){
			aux = aux->pNextNode;
		}
		aux->pElement = pElement;
		returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    int i = 0;
    Node* temp;
    Node* aux;
    if(this != NULL && index >= 0 && index < this->size){
    	aux = this->pFirstNode;
    	while(i++ < index -1){
    		aux = aux->pNextNode;
    	}
    	if(index == 0){
    		this->pFirstNode = aux->pNextNode;
    		free(aux);
    	}
    	else if(index > 0){
    		temp = aux->pNextNode->pNextNode;
    		free(aux->pNextNode);
    		aux->pNextNode = temp;
    	}
    	this->size--;
    	returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    Node* node;
    if(this != NULL){
    	node = this->pFirstNode;
    	while(node->pNextNode != NULL){
    		node = node->pNextNode;
    		this->size--;
    	}
    	this->pFirstNode = node->pNextNode;
		this->size--;
		free(node);
		returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    Node* node;
    if(this != NULL){
    	node = this->pFirstNode;
		while(node->pNextNode != NULL){
			node = node->pNextNode;
			this->size--;
		}
		this->pFirstNode = node->pNextNode;
		this->size--;
		free(node);
		free(this);
       returnAux = 0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    Node* aux;
    if(this != NULL){
    	aux = this->pFirstNode;
    	for(i = 0; i < ll_len(this); i++){
    		if(aux->pElement == pElement){
    			returnAux = i;
    			break;
    		}else{
    			aux = aux->pNextNode;
    		}
    	}
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL){
    	if(this->pFirstNode != NULL){
    		returnAux = 0;
    	}else{
    		returnAux = 1;
    	}
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    if(this != NULL && index >= 0 && index < ll_len(this)){
    	addNode(this, index, pElement);
    	returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    Node *node;
    Node* temp;
    int i;
    if(this != NULL && index >= 0 && index < this->size){
    	node = this->pFirstNode;
    	for(i = 0; i < index -1; i++){
    		node = node->pNextNode;
    	}
    	if(index == 0){
    		returnAux = this->pFirstNode->pElement;
    		this->pFirstNode = node->pNextNode;
    		free(node);
    	}
    	else if(index > 0){
    		returnAux = node->pNextNode->pElement;
    		temp = node->pNextNode->pNextNode;
    		free(node->pNextNode);
    		node->pNextNode = temp;
    	}
    	this->size--;
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int i;
    int returnAux = -1;
    if(this != NULL){
    	for(i = 0; i < ll_len(this); i++){
    		if(getNode(this, i)->pElement == pElement){
    			returnAux = 1;
    			break;
    		}
    	}
    	returnAux = 0;
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int i;
    int j;
    void* auxThis;
    void* auxThis2;
    int len1 = ll_len(this);
    int len2 = ll_len(this2);
    printf("\nLEN1 %d\n", len1);
    printf("LEN2 %d\n", len2);
    int contain = 0;
    if(this != NULL && this2 != NULL){
    	for(i = 0; i < ll_len(this2); i++){
    		for(j = 0; j < ll_len(this); j++){
    			auxThis2 = ll_get(this2, i);
    			auxThis = ll_get(this, j);
    			if(auxThis2 == auxThis){
    				contain++;
    			}
    		}
    	}
    	if(contain == ll_len(this2)){
    		returnAux = 1;
    	}else{
			returnAux = 0;
    	}
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int i;
    void* aux;
    if(this != NULL){
    	cloneArray = ll_newLinkedList();
    	if(cloneArray != NULL){
			for(i = from; i <= to; i++){
				aux = ll_get(this, i);
				ll_add(cloneArray, aux);
			}
    	}
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    void* aux;
    int i;
    if(this != NULL){
		cloneArray = ll_newLinkedList();
    	for(i = 0; i < ll_len(this); i++){
    		aux = ll_get(this, i);
    		ll_add(cloneArray, aux);
    	}
    }
    return cloneArray;
}

/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int i;
    int j;
    void* Aux;
    if(this != NULL && pFunc != NULL){
    	for(i = 0; i < ll_len(this); i++){
    		for(j = i+1; j < ll_len(this); j++){
    			if(pFunc(ll_get(this, i), ll_get(this, j)) > 0 && order == 1){
    				Aux = ll_get(this, i);
    				ll_set(this, i, ll_get(this, j));
    				ll_set(this, j, Aux);
    				returnAux = 0;
    			}
    			else if(pFunc(ll_get(this, i), ll_get(this, j)) < 0 && order == 0){
    				Aux = ll_get(this, j);
    				ll_set(this, j, ll_get(this, i));
    				ll_set(this, i, Aux);
    				returnAux = 0;
    			}

    		}
    	}

    }
    return returnAux;
}
