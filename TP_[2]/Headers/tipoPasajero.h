/*
 * tipoPasajero.h
 *
 *  Created on: 12 may. 2022
 *      Author: PACugliari
 */

#ifndef TP__2__HEADERS_TIPOPASAJERO_H_
#define TP__2__HEADERS_TIPOPASAJERO_H_

typedef struct{
	int id;
	char descripcion[30];
}eTipoPasajero;

#endif /* TP__2__HEADERS_TIPOPASAJERO_H_ */

/// @fn int mostrarTiposPasajeros(eTipoPasajero[], int)
/// @brief muestra el listado de tipos de pasajeros, mostrando ID y Descripcion
///
/// @param eTipoPasajero tiposPasajeros[],vector de tipos de pasasjeros
/// @param int tamT,tamanio del vector de tipos de pasajeros
/// @return si los parametros son correctos retorna 1, de lo contrario 0
int mostrarTiposPasajeros (eTipoPasajero tiposPasajeros[],int tamT);

/// @fn int buscarTipoPasajero(eTipoPasajero[], int, int, int*)
/// @brief busca en el vector de tipos de pasajeros el que corresponde con el id pasado por parametro, en caso de no encontrar almacena -1
///
/// @param eTipoPasajero tiposPasajeros[],vector de tipos de pasajeros
/// @param int tamT, tamanio del vector de tipos de pasajeros
/// @param int id, id que se quiere buscar en el vector
/// @param int* pIndice, puntero a entero donde se almacena la posicion del vector cuyo campo id es el mismo que el del parametro id
/// @return si los parametros son correctos retorna 1, de lo contrario 0
int buscarTipoPasajero (eTipoPasajero tiposPasajeros[],int tamT,int id,int* pIndice);

/// @fn int validarTipoPasajero(eTipoPasajero[], int, int)
/// @brief valida que la id pasada por parametro sea una id valida
///
/// @param eTipoPasajero tiposPasajeros[],vector de tipos de pasajeros
/// @param int tamT, tamanio del vector de tipos de pasajeros
/// @param int id, id que se quiere validad
/// @return si la id es valida retorna 1, si la id es invalida o alguno de los parametros es invalido 0
int validarTipoPasajero (eTipoPasajero tiposPasajeros[],int tamT,int id);

/// @fn int cargarDescripcionTipoPasajero(eTipoPasajero[], int, int, char[])
/// @brief carga la descripcion del elemento del vector tipo de pasajeros cuyo campo id es igual a la id pasada por parametro
///
/// @param eTipoPasajero tiposPasajeros[],vector de tipos de pasajeros
/// @param int tamT, tamanio del vector de tipos de pasajeros
/// @param int id, id del elemento que se quiere obtener su descripcion
/// @param char descripcion[], vector de caracteres donde se almacena el campo descripcion
/// @return si los parametros son correctos retorna 1, de lo contrario 0
int cargarDescripcionTipoPasajero (eTipoPasajero tiposPasajeros[],int tamT,int id,char descripcion[]);
