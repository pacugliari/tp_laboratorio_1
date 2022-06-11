/*
 * tipoPasajero.h
 *
 *  Created on: 5 jun. 2022
 *      Author: PACugliari
 */

#include "LinkedList.h"

#ifndef TP__3__TIPOPASAJERO_H_
#define TP__3__TIPOPASAJERO_H_

typedef struct{
    int id;
    char descripcion [25];
}eTipoPasajero;

#endif /* TP__3__TIPOPASAJERO_H_ */

//CONSTRUCTORES
/// @fn eTipoPasajero TipoPasajero_new*()
/// @brief crea en memoria una estructura del tipo eTipoPasajero
///
/// @return retorna la direccion de memoria de la estructura creada
eTipoPasajero* TipoPasajero_new();

/// @fn eTipoPasajero TipoPasajero_newParametros*(int, char*)
/// @brief crea en memoria una estructura del tipo eTipoPasajero con los datos pasados por parametro
///
/// @param int id, valor de id a cargar en la estructura
/// @param char* descripcion, cadena a cargar en el campo descripcion de la estructura
/// @return si se pudieron cargar los parametros en la estructura devuelve la direccion en memoria de la misma sino NULL
eTipoPasajero* TipoPasajero_newParametros(int id,char* descripcion);

/// @fn LinkedList TiposPasajeros_newLista*()
/// @brief crea una LinkedList con los tipos de pasajeros hardcodeados
///
/// @return devuelve la direccion de memoria de la LinkedList con los tipos de pasajeros cargados sino NULL
LinkedList* TiposPasajeros_newLista ();

//DESTRUCTORES
/// @fn int TiposPasajeros_deleteLista(LinkedList*)
/// @brief recorre la lista pasada por parametro haciendo un delete de cada tipo de pasajero de la misma
///
/// @param LinkedList* lista, puntero a lista que contiene los tipos de pasajeros a liberar
/// @return si los parametros pasados son corretos devuelve 1 sino 0
int TiposPasajeros_deleteLista(LinkedList* lista);

/// @fn void TipoPasajero_delete(eTipoPasajero*)
/// @brief libera la memoria de la direccion pasada por parametro
///
/// @param eTipoPasajero* tipoPasajero, puntero a tipo de pasajero con la direccion a liberar
void TipoPasajero_delete(eTipoPasajero* tipoPasajero);

//SETTERS
/// @fn int TipoPasajero_setId(eTipoPasajero*, int)
/// @brief asigna el id pasado por parametro a la estructura pasada por parametro validandola
///
/// @param eTipoPasajero* this, puntero a estructura eTipoPasajero
/// @param int id, valor de id que se quiere cargar
/// @return si los parametros y el valor del id son correctos devuelve 1 sino 0
int TipoPasajero_setId(eTipoPasajero* this,int id);

/// @fn int TipoPasajero_setDescripcion(eTipoPasajero*, char*)
/// @brief asigna la cadena descripcion al campo descripcion de la estructura pasada por parametro validandola
///
/// @param eTipoPasajero* this, puntero a estructura eTipoPasajero
/// @param char* descripcion,cadena con la descripcion que se quiere cargar
/// @return si los parametros y la descripcion son correctos devuelve 1 sino 0
int TipoPasajero_setDescripcion(eTipoPasajero* this,char* descripcion);

//GETTERS
/// @fn int TipoPasajero_getId(eTipoPasajero*, int*)
/// @brief asigna el campo id de la estructura pasada por parametro a la id pasada por referencia
///
/// @param eTipoPasajero* this, puntero a estructura eTipoPasajero a la que se le quiere obtener el id
/// @param int* id, puntero a entero donde se quiere guardar la id de la estructura
/// @return si los parametros son correctos devuelve 1 sino 0
int TipoPasajero_getId(eTipoPasajero* this,int* id);

/// @fn int TipoPasajero_getDescripcion(eTipoPasajero*, char*)
/// @brief asigna el campo descripcion de la estructura pasada por parametro a la cadena pasada por parametro
///
/// @param eTipoPasajero* this, puntero a estructura eTipoPasajero a la que se le quiere obtener su descripcion
/// @param char*  descripcion, puntero a cadena donde se almacena la descripcion de la estructura
/// @return si los parametros son correctos devuelve 1 sino 0
int TipoPasajero_getDescripcion(eTipoPasajero* this,char* descripcion);

//OTROS

/// @fn int listarTiposPasajeros(LinkedList*)
/// @brief hace un lista por consola con los tipos de pasajeros disponibles
///
/// @param LinkedList* lista, lista con los tipos de pasajeros
/// @return si los parametros son correctos devuelve 1 sino 0
int listarTiposPasajeros (LinkedList* list);

/// @fn int cargarDescripcionTipoPasajero(LinkedList*, int, char[])
/// @brief carga la descripcion de la estructura cuya id es la pasada por parametro
///
/// @param LinkedList* lista, lista de tipos de pasajeros
/// @param int id, id de la estructura a la que se le quiere obtener su descripcion
/// @param char descripcion[],cadena donde se almacena la descripcion buscada
/// @return si los parametros son correctos devuelve 1 sino 0
int cargarDescripcionTipoPasajero (LinkedList* list,int id,char descripcion[]);

/// @fn int buscarTipoPasajeroPorId(LinkedList*, int, int*)
/// @brief busca el indice donde se encuentra la estructura cuya id es la pasada por parametro
///
/// @param LinkedList* lista, lista de tipos de pasajeros
/// @param int id, id de la estructura que se quiere buscar su indice
/// @param int* indice, puntero a entero donde se almacena el indice de la estructura buscada
/// @return si los parametros son correctos devuelve 1 sino 0
int buscarTipoPasajeroPorId (LinkedList* list,int id,int* indice);

/// @fn int buscarTipoPasajeroPorDescripcion(LinkedList*, char*, int*)
/// @brief busca el indice donde se encuentra la estructura cuya descripcion es la pasada por parametro
///
/// @param LinkedList* lista, lista de tipos de pasajeros
/// @param char* descripcion, descripcion de la estructura que se quiere buscar en la lista
/// @param int* indice, puntero a entero donde se almacena el indice buscado
/// @return si los parametros son correctos devuelve 1 sino 0
int buscarTipoPasajeroPorDescripcion (LinkedList* list,char* descripcion,int* indice);

/// @fn int validarTipoPasajero(LinkedList*, int)
/// @brief busca en la lista de tipos de pasajeros si la id pasada por parametro coincide con alguna de las estructuras
///
/// @param LinkedList* lista, lista de tipos de pasajeros
/// @param int id, entero con la id a verificar si se encuentra en la lista
/// @return si es valida devuelve 1 sino 0
int validarTipoPasajero (LinkedList* list,int id);

/// @fn int pedirTipoPasajero(LinkedList*, int*)
/// @brief pide por consola el id validado de un tipo de pasajero
///
/// @param LinkedList* lista, lista de tipos de pasajeros
/// @param int* id, puntero a entero donde se almacena la id ingresada por el usuario
/// @return si los parametros son correctos devuelve 1 sino 0
int pedirTipoPasajero(LinkedList* list,int* id);

