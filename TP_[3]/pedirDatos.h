
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

/// @fn int pedirId(void)
/// @brief pide por consola que el usuario ingrese un id
///
/// @return retorna el id ingresada por el usuario
int pedirId(void);

/// @fn int pedirDatosAlta(Passenger*, LinkedList*, LinkedList*)
/// @brief pide por consola los datos necesarios para dar de alta un Passenger
///
/// @param Passenger* pasajero, puntero a Passenger donde se almacena los datos ingresados
/// @param LinkedList* listaTiposPasajeros, lista de tipos de pasajeros
/// @param LinkedList* listaEstadosVuelos, lista de estados de vuelos
/// @return si los parametros son correctos devuelve 1 sino 0
int pedirDatosAlta (Passenger* pasajero,LinkedList* listaTiposPasajeros,LinkedList* listaEstadosVuelos);

/// @fn char pedirConfirmacion(Passenger, int, LinkedList*, LinkedList*)
/// @brief pide por consola la confirmacion del usuario cuando quiere hacer una baja o modificacion
/// mostrando los datos del usuario afectado
///
/// @param Passenger pasajero, estructura Passenger al cual se lo quiere dar de baja o modificar
/// @param int tipo, dependiendo el valor de tipo muestra el mensaje de modificar o baja
/// @param LinkedList* listaTiposPasajeros, lista de tipos de pasajeros
/// @param LinkedList* listaEstadosVuelos, lista de estados de vuelos
/// @return devuelve 's' si el usuario confirma con si o 'n' si confirma que no
char pedirConfirmacion (Passenger pasajero,int tipo,LinkedList* listaTiposPasajeros,LinkedList* listaEstadosVuelos);

/// @fn void pedirCodigoVuelo(char[])
/// @brief pide por consola que el usuario ingrese un condigo de vuelo valido
///
/// @param char codigoVuelo[], cadena donde se almacena el codigo de vuelo ingresado
void pedirCodigoVuelo(char codigoVuelo[]);

/// @fn void pedirPrecio(float*)
/// @brief pide por consola que el usuario ingrese un precio valido mayor que cero y menor que 1000000
///
/// @param float* precio, puntero a float donde se guarda el precio ingresado
void pedirPrecio (float* precio);

/// @fn void pedirApellido(char[])
/// @brief pide por consola que el usuario ingrese un apellido validando que el tamanio sea mayor que 1 y menor que 50
///
/// @param char apellido[], cadena donde se almacena el apellido ingresado
void pedirApellido (char apellido[]);

/// @fn void pedirNombre(char[])
/// @brief pide por consola que el usuario ingrese un nombre validando que el tamanio sea mayor que 1 y menor que 50
///
/// @param char apellido[], cadena donde se almacena el nombre ingresado
void pedirNombre(char nombre[]);

/// @fn int pedirMenuModificar()
/// @brief pide por consola la opcion ingresada por el usuario del menu modificar
///
/// @return retorna la opcion ingresada por el usuario
int pedirMenuModificar();

/// @fn int pedirMenuOrdenar()
/// @brief pide por consola la opcion ingresada por el usuario del menu ordenar
///
/// @return retorna la opcion ingresada por el usuario
int pedirMenuOrdenar();

/// @fn int pedirMenuOrdenarTipo()
/// @brief pide por consola la opcion ingresada por el usuario del menu ordenar tipo
///
/// @return retorna la opcion ingresada por el usuario
int pedirMenuOrdenarTipo();

/// @fn int pedirPath(char*)
/// @brief pide al usuario que ingrese por consola un Path de un archivo validandolo
///
/// @param char* path, cadena donde se almacena el path ingresado por el usuario
/// @return si los parametros son correctos retorna 1 sino 0
int pedirPath(char* path);

/// @fn int pedirMenu()
/// @brief pide por consola la opcion ingresada por el usuario del menu principal
///
/// @return retorna la opcion ingresada por el usuario
int pedirMenu();

