#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

Node* ll_newNode(void* pElement)
{
    Node* newNode=NULL;

    newNode=(Node*)malloc(sizeof(Node));

    if(newNode!=NULL)
    {
        newNode->pElement=pElement;
    }

    return newNode;
}

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;

    this = (LinkedList*) malloc(sizeof(LinkedList));
    if(this!=NULL)
    {
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
    if(this!=NULL)
    {
        returnAux = this->size;
    }


    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    int i;
    int len;
    Node* pNode=NULL;

    if(this!=NULL && nodeIndex>=0)
    {
        len=ll_len(this);
        if(len!=0 && nodeIndex<len)
        {
            pNode=this->pFirstNode;
            if(pNode!=NULL)
            {
                for(i=0;i<len;i++)
                {
                    if(nodeIndex==i)
                    {
                        break;
                    }
                    else
                    {
                        pNode=pNode->pNextNode;

                    }
                }
            }
        }
    }

    return pNode;
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
    int ifError = -1;
    Node* prev;
    Node* next;
    Node* nuevoNodo;
    int len;

    if(this != NULL && nodeIndex >= 0)
    {
        len = ll_len(this);
        if(nodeIndex<=len && len>=0)
        {
            nuevoNodo = ll_newNode(pElement);
            if(nuevoNodo!= NULL)
            {
                if(!nodeIndex)
                {
                    prev = this->pFirstNode;
                    this->pFirstNode = nuevoNodo;
                    nuevoNodo->pNextNode = prev;
                    this->size ++;
                    ifError = 0;

                }
                else
                {
                    prev=getNode(this,nodeIndex-1);
                    if(prev!=NULL)
                    {
                        next=prev->pNextNode;
                        prev->pNextNode=nuevoNodo;
                        nuevoNodo->pNextNode=next;

                        this->size++;
                        ifError=0;

                    }
                }
            }
        }
    }
    return ifError;
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
    int ifError = -1;
    int len;
    int valid;
    if(this!=NULL)
    {
        len=ll_len(this);
        ifError=addNode(this,len,pElement);
    }

    return ifError;
}
//  ******* OJO CORREGIR *******************
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
    int len;
    void* pVoid = NULL;
    Node* pNode;

    if(this!=NULL)
    {
        len=ll_len(this);

        if(index >= 0 && index < len)
        {
            pNode=getNode(this,index);
            if(pNode!=NULL)
            {
                pVoid=pNode->pElement;
            }

        }
    }
    return pVoid;
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
    int ifError = -1;
    Node* pNode;
    int len;

    if(this!=NULL && index>=0)
    {
        len=ll_len(this);
        if(index<len)
        {
            pNode=getNode(this,index);
            if(pNode!=NULL)
            {
                pNode->pElement=pElement;
                ifError=0;
            }
        }
    }

    return ifError;
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
    int ifError = -1;
    Node* pNode;
    Node* next;
    Node* prev;
    int len;

    if(this!=NULL && index>=0)
    {
        len=ll_len(this);
        if(index<len && len>0)
        {
            if(!index)
            {
                pNode=getNode(this,index);
                if(pNode!=NULL)
                {
                    next=pNode->pNextNode;
                    this->pFirstNode=next;
                    free(pNode);
                    pNode=NULL;
                    this->size--;
                    ifError=0;
                }
            }
            else
            {
                prev=getNode(this,index-1);
                pNode=getNode(this,index);
                //PREGUNTAR SI ESTA BIEN
                if(prev!=NULL && pNode!=NULL)
                {
                    //next=pNode->pNextNode;
                    //prev->pNextNode=next;
                    prev->pNextNode=pNode->pNextNode;
                    free(pNode);
                    pNode=NULL;
                    this->size--;
                    ifError=0;
                }

            }
        }
    }

    return ifError;
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
    int ifError = -1;

    int i;
    int len;

    if(this!=NULL)
    {
        len=ll_len(this);
        i=len;
        while(ll_len(this)!=0)
        {
            ll_remove(this,i);
            i--;
        }
        ifError=0;
    }


    return ifError;
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
    int ifError = -1;

    if(this!=NULL)
    {
        if(!ll_clear(this))
        {
            free(this);
            this=NULL;
            ifError=0;
        }
    }

    return ifError;
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
    int ifError = -1;
    int i;
    int len;
    Node* pNode;

    if(this!=NULL)
    {
        len=ll_len(this);
        for(i=0;i<len;i++)
        {
            pNode=getNode(this,i);
            if(pNode->pElement==pElement)
            {
                ifError=i;
                break;
            }
        }
    }


    return ifError;
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
    int isEmpty = -1;

    if(this != NULL)
    {
        if( ll_len(this))
        {
            isEmpty = 0;
        }
        else
        {
            isEmpty = 1;
        }
    }
    return isEmpty;
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
    int ifError = -1;

    if(this!=NULL)
    {
        if(!addNode(this,index,pElement))
        {
            ifError=0;
        }
    }

    return ifError;
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
    void* pElement=NULL;
    Node* poppedNode;
    int len;



    if(this!=NULL)
    {
        len=ll_len(this);
        if(index>=0 && index<=len && len!=0)
        {
            poppedNode=getNode(this,index);
            if(poppedNode!=NULL )
            {
                pElement=poppedNode->pElement;


                if(ll_remove(this,index)==-1)
                {
                    pElement=NULL;
                }
            }
        }
    }


    return pElement;
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
    int ifError = -1;
    int i;
    int len;
    Node* pNode;

    if(this!=NULL)
    {
        ifError=0;
        len=ll_len(this);
        for(i=0;i<len;i++)
        {
            pNode=getNode(this,i);
            if(pNode!=NULL)
            {
                if(pElement==pNode->pElement)
                {
                    ifError=1;
                    break;
                }
            }
        }
    }

    return ifError;
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
    int ifError = -1;
    int i;
    int len2;
    Node* pNode;
    void* pElement;

    if(this!=NULL && this2!=NULL)
    {
        ifError = 1;
        len2=ll_len(this2);
        for(i=0;i<len2;i++)
        {
            pNode=getNode(this2,i);
            pElement=pNode->pElement;
            if(ll_contains(this,pElement)==0)
            {
                ifError=0;
                break;
            }
        }
    }


    return ifError;
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
    int len;
    int i;
    void* pElement;

    len=ll_len(this);

    if(this!=NULL && from>=0 && to<=len && from<to)
    {
        cloneArray=ll_newLinkedList();

        for(i=from;i<=to;i++)
        {
            pElement=ll_get(this,i);
            ll_add(cloneArray,pElement);
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

    if(this!=NULL)
    {
        cloneArray=ll_newLinkedList();
        if(cloneArray!=NULL)
        {
            cloneArray=this;
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
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int i;
    int j;
    int len;
    int ifError =-1;
    void* pAux1;
    void* pAux2;

    if(this!=NULL && pFunc != NULL && (order==1 || order == 0))
    {
        len=ll_len(this);
        for(i=0;i<len-1;i++)
        {
            for(j=i+1;j<len;j++)
            {
                pAux1=ll_get(this,i);
                pAux2=ll_get(this,j);

                if(order)
                {
                    if(pFunc(pAux1,pAux2)==1)
                    {
                        ll_set(this,i,pAux2);
                        ll_set(this,j,pAux1);
                    }
                }
                else
                {
                    if(pFunc(pAux1,pAux2)==-1)
                    {
                        ll_set(this,i,pAux2);
                        ll_set(this,j,pAux1);
                    }
                }
            }
        }
        ifError=0;
    }

    return ifError;
}

