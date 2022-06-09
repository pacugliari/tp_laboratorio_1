
/*
 * pedirDatos.h
 *
 *  Created on: 25 abr. 2022
 *      Author: PACugliari
 */

#include "Passenger.h"
#include "tipoPasajero.h"
#include "estadoVuelo.h"

#ifndef TP__3__HEADERS_PEDIRDATOS_H_
#define TP__3__HEADERS_PEDIRDATOS_H_

#define ALTA 1
#define MODIFICAR 2
#define BAJA 3

#endif


int pedirId(void);
int pedirDatosAlta (Passenger* pasajero,LinkedList* listaTiposPasajeros,LinkedList* listaEstadosVuelos);
char pedirConfirmacion (Passenger pasajero,int tipo,LinkedList* listaTiposPasajeros,LinkedList* listaEstadosVuelos);
void pedirCodigoVuelo(char codigoVuelo[]);
void pedirPrecio (float* precio);
void pedirApellido (char apellido[]);
void pedirNombre(char nombre[]);
int pedirMenuModificar();

