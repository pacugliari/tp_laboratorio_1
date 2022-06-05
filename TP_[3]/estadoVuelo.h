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


int buscarEstadoVuelo (eEstadoVuelo estadoV[],int tamEstadoV,char* descripcion,int* pIndice);
