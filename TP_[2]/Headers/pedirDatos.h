/*
 * pedirDatos.h
 *
 *  Created on: 25 abr. 2022
 *      Author: PACugliari
 */

#ifndef TP__2__HEADERS_PEDIRDATOS_H_
#define TP__2__HEADERS_PEDIRDATOS_H_

#include "../Headers/ArrayPassenger.h"

#define ALTA 1
#define MODIFICAR 2
#define BAJA 3

#endif /* TP__2__HEADERS_PEDIRDATOS_H_ */

/// @fn int pedirId(void)
/// @brief pide un id al usuario
///
/// @return int, devuelve el valor ingresado por el usuario
int pedirId(void);

/// @fn void pedirDatosPasajero(Passenger*, int)
/// @brief pide todos los datos necesarios para ALTA o MODIFICACION para cargar la estructura Passenger
///
/// @param Passenger*, puntero a pasajero
/// @param int, tipo de ingreso, si es 1-ALTA o 2-MODIFICACION
void pedirDatosPasajero(Passenger* ,int );

/// @fn int pedirDatosMenu(void)
/// @brief muestra el menu de opciones ALTA-MODIFICACION-BAJA-INFORMAR-SALIR
///
/// @return int, retorna el valor de respuesta validado elegido por el usuario
int pedirDatosMenu(void);

/// @fn int pedirDatosSubMenu(void)
/// @brief muestra las opciones del submenu que se encuentra dentro de la opcion INFORMAR
///
/// @return int, retorna el valor de respuesta validado elegido por el usuario
int pedirDatosSubMenu(void);

/// @fn char preguntaConfirmacion(Passenger, int)
/// @brief muestra la informacion de un pasajero y pide la confirmacion para la ALTA/MODIFICACION ingresando 's' o 'n'
///
/// @param pasajero Passenger, pasajero a mostrar la informacion
/// @param tipo int, dependiendo del tipo 1-ALTA o 2-MODIFICACION , muestra un mensaje diferente
/// @return char, devuelve el char validado ingresado por el usuario
char pedirConfirmacion (Passenger pasajero,int tipo);
