/*
 * menu.h
 *
 *  Created on: 1 abr. 2022
 *      Author: PACugliari
 */

#ifndef TP__1__HEADERS_MENU_H_
#define TP__1__HEADERS_MENU_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/// @fn int mostrarMenu(void)
/// @brief muestra el menu de opciones pidiendo el valor validandolo
///
/// @return int , devuelve el valor de la opcion elegida por el usuario
int mostrarMenu(void);

/// @fn void mostrarResultados(float*, float, float, float, int)
/// @brief muestra los resultados ya calculados
///
/// @param resultados float*, array con todos los resultados tanto para latam y aerolineas
/// @param kilometros float, kilometros ingresados por el usuario
/// @param precioAerolineas float, precio de Aerolineas ingresado por el usuario
/// @param precioLatam float, precio de Latam ingresado por el usuario
/// @param esCorrecto int, recibe un flag para saber si fue ejecutado la funcion calcularPrecios siendo 1: se ejecuto o 0: no se ejecuto
void mostrarResultados(float* resultados,float kilometros,float precioAerolineas, float precioLatam,int esCorrecto);

/// @fn float obtenerKilometros(void)
/// @brief pide por consola los kilometros validando que sea un numero mayor a cero
///
/// @return float, retorna el valor ingresado por el usuario
float obtenerKilometros(void);

/// @fn char mostrarOpcionesVuelos(void)
/// @brief muestra las opciones para Aerolineas o Latam y pide el ingreso del usuario validando que sea y o z
///
/// @return char, retorna la opcion de vuelo ingresado por el usuario
char mostrarOpcionesVuelos(void);

/// @fn void calcularPrecios(char, float*, float*)
/// @brief evalua que tipo de vuelo selecciono el usuario en la funcion mostrarOpcionesVuelos y llama a la funcion
/// obtenerPrecios cuyo valor que retorna lo guarda en el precio de Latam o Aerolineas
/// @param opcionesVuelos char, valores y: aerolineas o z:latam
/// @param precioLatam float, donde se almacena el valor del precio de latam retornado por la funcion obtenerPrecio
/// @param precioAerolineas float, donde se almacena el valor del precio de aerolineas retornado por la funcion obtenerPrecio
void calcularPrecios(char opcionesVuelos,float* precioLatam,float* precioAerolineas);

/// @fn void mostrarMensajeFinPrograma(void)
/// @brief muestra un mensaje que se finalizo el programa cuando el usuario selecciona la opcion de salida (6)
///
void mostrarMensajeFinPrograma(void);

/// @fn void mostrarMensajeErrorMenu(void)
/// @brief muestra un mensaje de error del menu cuando el usuario selecciona una opcion invalida
///
void mostrarMensajeErrorMenu(void);

#endif /* TP__1__HEADERS_MENU_H_ */
