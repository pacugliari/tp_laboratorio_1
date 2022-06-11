/*
 * estadoVuelo.h
 *
 *  Created on: 5 jun. 2022
 *      Author: PACugliari
 */

#include "LinkedList.h"

#ifndef TP__3__ESTADOVUELO_H_
#define TP__3__ESTADOVUELO_H_

typedef struct{
    int id;
    char descripcion [25];
}eEstadoVuelo;

#endif /* TP__3__ESTADOVUELO_H_ */


//CONSTRUCTORES
/// @fn eEstadoVuelo EstadoVuelo_new*()
/// @brief crea en memoria una estructura del tipo eEstadoVuelo
///
/// @return retorna la direccion de memoria de la estructura creada
eEstadoVuelo* EstadoVuelo_new();
/// @fn eEstadoVuelo EstadoVuelo_newParametros*(int, char*)
/// @brief crea en memoria una estructura del tipo eEstadoVuelo con los datos pasados por parametro
///
/// @param int id, valor de id a cargar en la estructura
/// @param char* descripcion, cadena a cargar en el campo descripcion de la estructura
/// @return si se pudieron cargar los parametros en la estructura devuelve la direccion en memoria de la misma sino NULL
eEstadoVuelo* EstadoVuelo_newParametros(int id,char* descripcion);
/// @fn LinkedList EstadosVuelos_newLista*()
/// @brief crea una LinkedList con los estados de vuelo hardcodeados
///
/// @return devuelve la direccion de memoria de la LinkedList con los estados de vuelo cargados sino NULL
LinkedList* EstadosVuelos_newLista ();


//DESTRUCTORES
/// @fn int EstadosVuelos_deleteLista(LinkedList*)
/// @brief recorre la lista pasada por parametro haciendo un delete de cada estado de vuelo de la misma
///
/// @param LinkedList* lista, puntero a lista que contiene los estados de vuelo a liberar
/// @return si los parametros pasados son corretos devuelve 1 sino 0
int EstadosVuelos_deleteLista(LinkedList* lista);
/// @fn void EstadoVuelo_delete(eEstadoVuelo*)
/// @brief libera la memoria de la direccion pasada por parametro
///
/// @param eEstadoVuelo* estadoVuelo, puntero a estado de vuelo con la direccion a liberar
void EstadoVuelo_delete(eEstadoVuelo* estadoVuelo);

//SETTERS
/// @fn int EstadoVuelo_setId(eEstadoVuelo*, int)
/// @brief asigna el id pasado por parametro a la estructura pasada por parametro validandola
///
/// @param eEstadoVuelo* this, puntero a estructura eEstadoVuelo
/// @param int id, valor de id que se quiere cargar
/// @return si los parametros y el valor del id son correctos devuelve 1 sino 0
int EstadoVuelo_setId(eEstadoVuelo* this,int id);
/// @fn int EstadoVuelo_setDescripcion(eEstadoVuelo*, char*)
/// @brief asigna la cadena descripcion al campo descripcion de la estructura pasada por parametro validandola
///
/// @param eEstadoVuelo* this, puntero a estructura eEstadoVuelo
/// @param char* descripcion,cadena con la descripcion que se quiere cargar
/// @return si los parametros y la descripcion son correctos devuelve 1 sino 0
int EstadoVuelo_setDescripcion(eEstadoVuelo* this,char* descripcion);

//GETTERS
/// @fn int EstadoVuelo_getId(eEstadoVuelo*, int*)
/// @brief asigna el campo id de la estructura pasada por parametro a la id pasada por referencia
///
/// @param eEstadoVuelo* this, puntero a estructura eEstadoVuelo a la que se le quiere obtener el id
/// @param int* id, puntero a entero donde se quiere guardar la id de la estructura
/// @return si los parametros son correctos devuelve 1 sino 0
int EstadoVuelo_getId(eEstadoVuelo* this,int* id);
/// @fn int EstadoVuelo_getDescripcion(eEstadoVuelo*, char*)
/// @brief asigna el campo descripcion de la estructura pasada por parametro a la cadena pasada por parametro
///
/// @param eEstadoVuelo* this, puntero a estructura eEstadoVuelo a la que se le quiere obtener su descripcion
/// @param char*  descripcion, puntero a cadena donde se almacena la descripcion de la estructura
/// @return si los parametros son correctos devuelve 1 sino 0
int EstadoVuelo_getDescripcion(eEstadoVuelo* this,char* descripcion);

//OTROS
/// @fn int cargarDescripcionEstadoVuelo(LinkedList*, int, char[])
/// @brief carga la descripcion de la estructura cuya id es la pasada por parametro
///
/// @param LinkedList* lista, lista de estados de vuelos
/// @param int id, id de la estructura a la que se le quiere obtener su descripcion
/// @param char descripcion[],cadena donde se almacena la descripcion buscada
/// @return si los parametros son correctos devuelve 1 sino 0
int cargarDescripcionEstadoVuelo (LinkedList* lista,int id,char descripcion[]);
/// @fn int buscarEstadoVueloPorId(LinkedList*, int, int*)
/// @brief busca el indice donde se encuentra la estructura cuya id es la pasada por parametro
///
/// @param LinkedList* lista, lista de estados de vuelos
/// @param int id, id de la estructura que se quiere buscar su indice
/// @param int* indice, puntero a entero donde se almacena el indice de la estructura buscada
/// @return si los parametros son correctos devuelve 1 sino 0
int buscarEstadoVueloPorId (LinkedList* lista,int id,int* indice);
/// @fn int buscarEstadoVueloPorDescripcion(LinkedList*, char*, int*)
/// @brief busca el indice donde se encuentra la estructura cuya descripcion es la pasada por parametro
///
/// @param LinkedList* lista, lista de estados de vuelo
/// @param char* descripcion, descripcion de la estructura que se quiere buscar en la lista
/// @param int* indice, puntero a entero donde se almacena el indice buscado
/// @return si los parametros son correctos devuelve 1 sino 0
int buscarEstadoVueloPorDescripcion (LinkedList* lista,char* descripcion,int* indice);
/// @fn int pedirEstadoVuelo(LinkedList*, int*)
/// @brief pide por consola el id validado de un estado de vuelo
///
/// @param LinkedList* lista, lista de estados de vuelo
/// @param int* id, puntero a entero donde se almacena la id ingresada por el usuario
/// @return si los parametros son correctos devuelve 1 sino 0
int pedirEstadoVuelo(LinkedList* lista,int* id);
/// @fn int validarEstadoVuelo(LinkedList*, int)
/// @brief busca en la lista de estados de vuelo si la id pasada por parametro coincide con alguna de las estructuras
///
/// @param LinkedList* lista, lista de estados de vuelo
/// @param int id, entero con la id a verificar si se encuentra en la lista
/// @return si es valida devuelve 1 sino 0
int validarEstadoVuelo (LinkedList* lista,int id);
/// @fn int listarEstadosVuelos(LinkedList*)
/// @brief hace un lista por consola con los estados de vuelo disponibles
///
/// @param LinkedList* lista, lista con los estados de vuelo
/// @return si los parametros son correctos devuelve 1 sino 0
int listarEstadosVuelos (LinkedList* lista);
