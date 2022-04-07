/*
 * calculos.h
 *
 *  Created on: 6 abr. 2022
 *      Author: PACugliari
 */

#ifndef TP__1__HEADERS_CALCULOS_H_
#define TP__1__HEADERS_CALCULOS_H_

#include <stdio.h>
#include <stdlib.h>

/// @fn int calcularCostos(float, float, float, float*)
/// @brief realiza el calculo de todos los precios para tarjeta debito,credito, bitcoin, precio unitario,etc
///
/// @param precioAerolineas float, el precio de Aerolineas ingresado por el usuario ya validado
/// @param precioLatam float, el precio de Latam ingresado por el usuario ya validado
/// @param kilometrosIngresados float, kilometros ingresado por el usuario ya validado
/// @param preciosCalculados float[9], array donde se almacenan todos los valores
/// preciosCalculados [0] : se almacena precio calculado de tarjeta debito de Latam
/// preciosCalculados [1] : se almacena precio calculado de tarjeta credito de Latam
/// preciosCalculados [2] : se almacena precio calculado en bitcoin de Latam
/// preciosCalculados [3] : se almacena el precio unitario ya calculado de Latam
/// preciosCalculados [4] : se almacena precio calculado de tarjeta debito de Aerolineas
/// preciosCalculados [5] : se almacena precio calculado de tarjeta credito de Aerolineas
/// preciosCalculados [6] : se almacena precio calculado en bitcoin de Aerolineas
/// preciosCalculados [7] : se almacena el precio unitario ya calculado de Aerolineas
/// preciosCalculados [8] : se almacena la diferencia en precio de Latam y Aerolineas
///
/// @return int, retorna 0 en caso de que precioAerolineas o precioLatam o kilometrosIngresados sea de un valor cero
/// lo que significa que el usuario no cargo uno de estos datos, retorna 1,  si los datos fueron cargados
int calcularCostos(float precioAerolineas,float precioLatam,float kilometrosIngresados,float* preciosCalculados);

/// @fn void cargaForzada(float*, float*, float*)
/// @brief carga en precioAerolineas, precioLatam y kilometrosIngresados un valor predefinido si necesidad que los cargue el usuario
///
/// @param precioAerolineas float*, dondes se carga precioAerolineas con el valor predefinido
/// @param precioLatam float* , donde se carga  precioLatam con el valor predefinido
/// @param kilometrosIngresados,donde se carga kilometrosIngresados con el valor predefinido
void cargaForzada(float* precioAerolineas,float* precioLatam,float* kilometrosIngresados);

/// @fn void reiniciarValores(float*, float*, float*, int*)
/// @brief reinicia los valores de precioAerolineas, precioLatam, kilometrosIngresados a valor nulo si el valor de esCorrecto es distinto de cero,
/// lo que quiere decir que calcularCostos se ejecuto de manera correcta
///
/// @param precioAerolineas float*, el valor del puntero recibido se almacena el valor de cero
/// @param precioLatam float*, el valor del puntero recibido se almacena el valor de cero
/// @param kilometrosIngresados float*, el valor del puntero recibido se almacena el valor de cero
/// @param esCorrecto float*, el valor del puntero recibido se almacena el valor de cero
void reiniciarValores (float* precioAerolineas,float* precioLatam,float* kilometrosIngresados,int* esCorrecto);

#endif /* TP__1__HEADERS_CALCULOS_H_ */
