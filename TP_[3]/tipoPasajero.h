/*
 * tipoPasajero.h
 *
 *  Created on: 5 jun. 2022
 *      Author: PACugliari
 */

#ifndef TP__3__TIPOPASAJERO_H_
#define TP__3__TIPOPASAJERO_H_

typedef struct{
    int id;
    char descripcion [25];
}eTipoPasajero;

#endif /* TP__3__TIPOPASAJERO_H_ */

#define TAMTP 3

int listarTiposPasajeros (eTipoPasajero tiposP[],int tamP);
int hardcodearTiposPasajeros (eTipoPasajero* vector,int tam);
int cargarDescripcionTipoPasajero (eTipoPasajero tiposP[],int tamP,int id,char descripcion[]);
int buscarTipoPasajeroPorId (eTipoPasajero tiposP[],int tamP,int id,int* pIndice);
int buscarTipoPasajeroPorDescripcion (eTipoPasajero tiposP[],int tamP,char* descripcion,int* pIndice);
int validarTipoPasajero (eTipoPasajero tiposP[],int tamP,int id);
int pedirTipoPasajero(eTipoPasajero tiposP[],int tamP,int* idDestino);

