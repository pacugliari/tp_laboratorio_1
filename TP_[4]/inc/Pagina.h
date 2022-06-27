#include "../inc/LinkedList.h"

#ifndef PAGINA_H_INCLUDED
#define PAGINA_H_INCLUDED



#endif // PAGINA_H_INCLUDED


/// @fn void ejecutarFunciones()
/// @brief carga el archivo con los datos en la lista y ejecuta pagina1,pagina2 y pagina3
///
void ejecutarFunciones();

/// @fn void pagina1(int*, LinkedList*)
/// @brief prueba las funciones del LinkedList ll_newLinkedList,ll_pop,ll_clone,ll_add,ll_isEmpty,ll_len,ll_deleteLinkedList
///
/// @param int*,puntero a entero que lleva el control de la pagina actual
/// @param LinkedList*  lista, puntero a LinkedList con los datos cargados del archivo
void pagina1(int*,LinkedList* lista);

/// @fn void pagina2(int*, LinkedList*)
/// @brief prueba las funciones del LinkedList ll_newLinkedList,ll_clone,ll_add,ll_subList,ll_len,ll_get,ll_sort,ll_deleteLinkedList
///
/// @param int*,puntero a entero que lleva el control de la pagina actual
/// @param LinkedList*  lista, puntero a LinkedList con los datos cargados del archivo
void pagina2(int*,LinkedList* lista);

/// @fn void pagina3(int*, LinkedList*)
/// @brief prueba las funciones del LinkedList ll_newLinkedList,ll_get,ll_add,ll_indexOf,ll_len,ll_set,ll_remove,ll_push,ll_clone,
/// ll_containsAll,ll_contains,ll_isEmpty,ll_clear,ll_deleteLinkedList
///
/// @param int*,puntero a entero que lleva el control de la pagina actual
/// @param LinkedList*  lista, puntero a LinkedList con los datos cargados del archivo
void pagina3(int*,LinkedList* lista);
