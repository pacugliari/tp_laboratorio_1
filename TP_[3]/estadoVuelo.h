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
eEstadoVuelo* EstadoVuelo_new();
eEstadoVuelo* EstadoVuelo_newParametros(int id,char* descripcion);
LinkedList* EstadosVuelos_newLista ();


//DESTRUCTORES
int EstadosVuelos_deleteLista(LinkedList* lista);
void EstadoVuelo_delete(eEstadoVuelo* estadoVuelo);

//SETTERS
int EstadoVuelo_setId(eEstadoVuelo* this,int id);
int EstadoVuelo_setDescripcion(eEstadoVuelo* this,char* descripcion);

//GETTERS
int EstadoVuelo_getId(eEstadoVuelo* this,int* id);
int EstadoVuelo_getDescripcion(eEstadoVuelo* this,char* descripcion);

//OTROS
int cargarDescripcionEstadoVuelo (LinkedList* lista,int id,char descripcion[]);
int buscarEstadoVueloPorId (LinkedList* lista,int id,int* indice);
int buscarEstadoVueloPorDescripcion (LinkedList* lista,char* descripcion,int* indice);
int pedirEstadoVuelo(LinkedList* lista,int* id);
int validarEstadoVuelo (LinkedList* lista,int id);
int listarEstadosVuelos (LinkedList* lista);
