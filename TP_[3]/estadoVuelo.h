/*
 * estadoVuelo.h
 *
 *  Created on: 5 jun. 2022
 *      Author: PACugliari
 */

#ifndef TP__3__ESTADOVUELO_H_
#define TP__3__ESTADOVUELO_H_

typedef struct{
    int id;
    char descripcion [25];
}eEstadoVuelo;

#endif /* TP__3__ESTADOVUELO_H_ */

#define TAMEV 3

int hardcodearEstadosVuelo(eEstadoVuelo* vector,int tam);
int cargarDescripcionEstadoVuelo (eEstadoVuelo estadoV[],int tamE,int id,char descripcion[]);
int buscarEstadoVueloPorId (eEstadoVuelo estadoV[],int tamEstadoV,int id,int* pIndice);
int buscarEstadoVueloPorDescripcion (eEstadoVuelo estadoV[],int tamEstadoV,char* descripcion,int* pIndice);
int pedirEstadoVuelo(eEstadoVuelo estadosV[],int tamE,int* idEstadoV);
int validarEstadoVuelo (eEstadoVuelo estadosV[],int tamE,int id);
int listarEstadosVuelos (eEstadoVuelo estadosV[],int tamE);
