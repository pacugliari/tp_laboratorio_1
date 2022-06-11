/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
	void* pElement;//DATO
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif



//Publicas

Node* test_getNode(LinkedList* this, int nodeIndex);
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);
int ll_set(LinkedList* this, int index,void* pElement);
int ll_clear(LinkedList* this);
int ll_indexOf(LinkedList* this, void* pElement);
int ll_isEmpty(LinkedList* this);
int ll_push(LinkedList* this, int index, void* pElement);
void* ll_pop(LinkedList* this,int index);//void*
int ll_contains(LinkedList* this, void* pElement);
int ll_containsAll(LinkedList* this,LinkedList* this2);
LinkedList* ll_subList(LinkedList* this,int from,int to);
LinkedList* ll_clone(LinkedList* this);


//FUNCIONAS A USAR

/// @fn int ll_remove(LinkedList*, int)
/// @brief Elimina un elemento del LinkedList, en el índice especificado
///
/// @param LinkedList* this, lista
/// @param int index, indice del elemento a eliminar
/// @return Si la verificación falla la función retorna (-1) y si tiene éxito (0).
int ll_remove(LinkedList* this,int index);//USAR

/// @fn void ll_get*(LinkedList*, int)
/// @brief Retorna un puntero al elemento que se encuentra en el índice especificado
/// si laverificación falla la función retorna (NULL) y si tiene éxito retorna el elemento.
///
/// @param LinkedList* this, lista
/// @param int index, indice del elemento a obtener
/// @return void* , puntero a elemento en la posicion buscada
void* ll_get(LinkedList* this, int index);//void* USAR

/// @fn int ll_len(LinkedList*)
/// @brief Retorna el tamaño del LinkedList.
///
/// @param LinkedList* this, lista a ver su tamanio
/// @return Si la verificación falla la función retorna (-1) y si tiene éxito retorna la longitud del array.
int ll_len(LinkedList* this); //USAR

/// @fn LinkedList ll_newLinkedList*(void)
/// @brief Crea y retorna un nuevo LinkedList.
///
/// @return direccion de memoria de la lista creada
LinkedList* ll_newLinkedList(void); //USAR

/// @fn int ll_add(LinkedList*, void*)
/// @brief Agrega un elemento al final de LinkedList
///
/// @param LinkedList* this, lista
/// @param void* pElement, elemento de cualquier tipo a agregar a la lista
/// @return Si la verificación falla la función retorna (-1) y si tiene éxito (0).
int ll_add(LinkedList* this, void* pElement); //USAR

/// @fn int ll_deleteLinkedList(LinkedList*)
/// @brief Elimina el LinkedList
///
/// @param LinkedList* this, lista a liberar memoria
/// @return Si la verificación falla la función retorna (-1), si esta vacío (1) y si contiene elementos (0).
int ll_deleteLinkedList(LinkedList* this); //USAR

/// @fn int ll_sort(LinkedList*, int(*)(void*, void*), int)
/// @brief Ordena los elementos del array recibiendo como parámetro la función que sera la encargada
///de determinar que elemento es mas grande que otro y si se debe ordenar de manera
///ascendente o descendente.
///
/// @param LinkedList* this, lista a ordenar
/// @param int (*pFunc)(void* ,void*), puntero a funcion que se encarga de comparar los elementos de la lista a ordenar
/// @param int order, 1 ascendente o 0 descendente
/// @return Si la verificación falla (-1) caso contrario retorna (1).
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);
