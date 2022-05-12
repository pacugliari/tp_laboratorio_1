/*
 * interface.h
 *
 *  Created on: 19 abr. 2022
 *      Author: PACugliari
 */


#include "../Headers/ArrayPassenger.h"
#include "../Headers/pedirDatos.h"

#define CANT_PASAJEROS 2000 	//CANTIDAD MAXIMA DE PASAJEROS
#define TAMT 3	//CANTIDAD DE TIPOS DE PASAJEROS
#define ID_VIAJES 0 //VALOR DONDE COMIENZA EL ID DE PASAJEROS

#ifndef TP__2__HEADERS_INTERFACE_H_
#define TP__2__HEADERS_INTERFACE_H_



#endif /* TP__2__HEADERS_INTERFACE_H_ */

/// @fn void ejecutarPrograma()
/// @brief contiene la logica y muestra las opciones del menu ALTA-MODIFICACION-BAJA-INFORMAR-SALIR
///
void ejecutarPrograma();

/// @fn void listar()
/// @brief contiene la logica y muestra las opciones del menu listar

/// @param Passenger* list,puntero a vector de pasajeros
/// @param eTipoPasajero tiposPasajeros[], vector de tipos de pasajeros
/// @param int tamT,tamanio del vector de tipos de pasajeros
void listar(Passenger* list,eTipoPasajero tiposPasajeros[],int tamT);


/// @fn void alta(Passenger* list,int* id,eTipoPasajero tiposPasajeros[],int tamT)
/// @brief funcion para dar el alta de un pasajero , validando que no se supere el maximo de pasajeros
/// pide los datos al usuario utilizando la funcion pedirDatosAlta(), da el alta en el vector de pasajeros utilizando
/// la funcion addPassenger() y actualiza el valor de id
///
/// @param Passenger*, puntero a vector de pasajeros
/// @param cantdadPasajeros int*, puntero a entero que lleva la cuenta de la cantidad de pasajeros para poder actualizarlo
/// @param int*, puntero a entero de la id para poder actualizar la misma
/// @param eTipoPasajero tiposPasajeros[], vector de tipos de pasajeros
/// @param int tamT,tamanio del vector de tipos de pasajeros
void alta(Passenger* list,int* id,eTipoPasajero tiposPasajeros[],int tamT);

/// @fn void modificar(Passenger* list,eTipoPasajero tiposPasajeros[],int tamT)
/// @brief funcion que realiza la modificacion de un pasajero, validando la id ingresada por el usuario, muestra
/// el pasajero correspondiente a la id ingresada por el usuario pidiendo una confirmacion, si la confirmacion es valida
/// se piden los datos nuevos de modificacion y en caso correcto se realiza la modificacion del pasajero con ayuda de la funcion
/// modifyPassenger()
///
/// @param Passenger*, puntero a vector de pasajeros
/// @param eTipoPasajero tiposPasajeros[], vector de tipos de pasajeros
/// @param int tamT,tamanio del vector de tipos de pasajeros
void modificar(Passenger* list,eTipoPasajero tiposPasajeros[],int tamT);

/// @fn void baja(Passenger* list,eTipoPasajero tiposPasajeros[],int tamT)
/// @brief funcion que realiza la baja de un pasajero validando la id ingresada por el usuario, antes de realizar la baja del sistema
/// muestra el pasajero correspondiente a la id ingresada pidiendo confirmacion de borrado, si la confirmacion es valida se realiza la misma
///
///
/// @param Passenger* , puntero a vector de pasajeros
/// @param int*, puntero a entero de la cantidad de pasajeros del sistema
/// @param eTipoPasajero tiposPasajeros[], vector de tipos de pasajeros
/// @param int tamT,tamanio del vector de tipos de pasajeros
void baja (Passenger* list,eTipoPasajero tiposPasajeros[],int tamT);


