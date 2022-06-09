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
eTipoPasajero* TipoPasajero_new();
eTipoPasajero* TipoPasajero_newParametros(int id,char* descripcion);
LinkedList* TiposPasajeros_newLista ();

//DESTRUCTORES
int TiposPasajeros_deleteLista(LinkedList* lista);
void TipoPasajero_delete(eTipoPasajero* tipoPasajero);

//SETTERS
int TipoPasajero_setId(eTipoPasajero* this,int id);
int TipoPasajero_setDescripcion(eTipoPasajero* this,char* descripcion);

//GETTERS
int TipoPasajero_getId(eTipoPasajero* this,int* id);
int TipoPasajero_getDescripcion(eTipoPasajero* this,char* descripcion);

//OTROS
int listarTiposPasajeros (LinkedList* list);
int cargarDescripcionTipoPasajero (LinkedList* list,int id,char descripcion[]);
int buscarTipoPasajeroPorId (LinkedList* list,int id,int* indice);
int buscarTipoPasajeroPorDescripcion (LinkedList* list,char* descripcion,int* indice);
int validarTipoPasajero (LinkedList* list,int id);
int pedirTipoPasajero(LinkedList* list,int* id);

