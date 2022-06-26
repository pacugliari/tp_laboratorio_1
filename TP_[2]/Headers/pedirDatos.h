#include "../Headers/tipoPasajero.h"
#include "../Headers/ArrayPassenger.h"

/*
 * pedirDatos.h
 *
 *  Created on: 25 abr. 2022
 *      Author: PACugliari
 */

#ifndef TP__2__HEADERS_PEDIRDATOS_H_
#define TP__2__HEADERS_PEDIRDATOS_H_

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
int pedirDatosAlta (Passenger* pasajero,eTipoPasajero tiposPasajeros[],int tamT);

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
char pedirConfirmacion (Passenger pasajero,int tipo,eTipoPasajero tiposPasajeros[],int tamT);

/// @fn void pedirEstadoVuelo(int*)
/// @brief pide al usuario que ingrese el estado de vuelo validando los valores
///
/// @param int* estadoVuelo, puntero a entero donde se almacena el valor ingresado por el usuario
void pedirEstadoVuelo(int* estadoVuelo);

/// @fn void pedirCodigoVuelo(char[])
/// @brief pide al usuario que ingrese el codigo de vuelo validando los valores
///
/// @param char codigoVuelo[],vector de caracteres donde se almacena el valor ingresado por el usuario
void pedirCodigoVuelo(char codigoVuelo[]);

/// @fn void pedirTipoPasajero(int*, eTipoPasajero[], int)
/// @brief pide al usuario que ingrese el tipo de pasajero validando los valores
///
/// @param int* pId, puntero a entero donde se almacena la id del tipo de pasajero ingresado por el usuario
/// @param eTipoPasajero tiposPasajeros[],vector de tipos de pasajeros
/// @param int tamT, tamanio del vector de tipos de pasajeros
void pedirTipoPasajero (int* pId,eTipoPasajero tiposPasajeros[],int tamT);

/// @fn void pedirPrecio(float*)
/// @brief pide al usuario que ingrese el precio validando los valores
///
/// @param float* precio, puntero a flotante donde se almacena el valor ingresado por el usuario
void pedirPrecio (float* precio);

/// @fn void pedirApellido(char[])
/// @brief pide al usuario que ingrese el apellido del pasajero validando los valores
///
/// @param char apellido[],vector de caracteres donde se almacena el valor ingresado por el usuario
void pedirApellido (char apellido[]);

/// @fn void pedirNombre(char[])
/// @brief pide al usuario que ingrese el nombre del pasajero validando los valores
///
/// @param char nombre[],vector de caracteres donde se almacena el valor ingresado por el usuario
void pedirNombre(char nombre[]);

/// @fn int pedirMenuModificar()
/// @brief muestra el menu de opciones con los distintos campos que permite la funcion modificar
///
/// @return retorna la respuesta del tipo entera ingresada por el usuario
int pedirMenuModificar();

/// @fn int esValidoNombreOApellido(char*)
/// @brief valida si la cadena pasada por parametro es un nombre o apellido valido
///
/// @param char* cadena, puntero a cadena que se quiere validar
/// @return si la cadena es valida retorna 1 sino 0
int esValidoNombreOApellido (char* cadena);


/// @fn int esCodigoVueloValido(char*)
/// @brief valida si la cadena pasada por parametro es un codigo de vuelo valido
///
/// @param char* cadena, puntero a cadena que se quiere validar
/// @return si la cadena es valida retorna 1 sino 0
int esCodigoVueloValido(char* cadena);
