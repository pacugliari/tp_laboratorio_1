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
/// @brief
///
/// @return
int pedirId(void);

/// @fn void pedirDatosPasajero(Passenger*, int)
/// @brief
///
/// @param
/// @param
void pedirDatosPasajero(Passenger* ,int );

/// @fn int pedirDatosMenu(void)
/// @brief
///
/// @return
int pedirDatosMenu(void);

/// @fn int pedirDatosSubMenu(void)
/// @brief
///
/// @return
int pedirDatosSubMenu(void);

/// @fn char preguntaConfirmacion(Passenger, int)
/// @brief
///
/// @param pasajero
/// @param tipo
/// @return
char pedirConfirmacion (Passenger pasajero,int tipo);
