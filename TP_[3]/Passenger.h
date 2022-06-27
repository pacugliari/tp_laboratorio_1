/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#include "LinkedList.h"

#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int idTipoPasajero;
	char codigoVuelo[8];//TIENEN 7 CARACTERES EN LOS ARCHIVOS
	int idEstadoVuelo;
}Passenger;

#endif /* PASSENGER_H_ */


//Constructores
/// @fn Passenger Passenger_new*()
/// @brief crea en memoria una estructura del tipo Passenger
///
/// @return puntero a la direccion de memoria de la estructura reservada
Passenger* Passenger_new();

/// @fn Passenger Passenger_newParametros*(int, char*, char*, float, char*, int, int)
/// @brief crea en memoria una estructura del tipo Passenger con los datos pasados por parametros validandolos
///
/// @param int id, id a cargar en la estructura
/// @param char* nombre, cadena con el nombre a cargar en la estructura
/// @param char* apellido, apellido a cargar en la estructura
/// @param float precio, precio a cargar en la estructura
/// @param char* codigoVuelo, codigo de vuelo a cargar en la estructura
/// @param int idTipoPasajero, id del tipo de pasajero a cargar en la estructura
/// @param int idEstadoVuelo, id del estado de vuelo a cargar en la estructura
/// @return si se pudo crear el Passenger en memoria con los datos devuelve la direccion de memoria del a misma sino NULL
Passenger* Passenger_newParametros(int id,char* nombre,char* apellido,float precio,char* codigoVuelo,int idTipoPasajero,int idEstadoVuelo);

/// @fn Passenger Passenger_newPassenger*(Passenger)
/// @brief crea en memoria un Passenger copiando los datos del Passenger por parametro
///
/// @param Passenger pasajero, estructura Passenger a copiar datos
/// @return si se pudo crear el Passenger en memoria con los datos devuelve la direccion de memoria del a misma sino NULL
Passenger* Passenger_newPassenger (Passenger pasajero);

/// @fn Passenger Passenger_newParametrosString*(char*, char*, char*, char*, char*, char*, char*)
/// @brief crea en memoria una estructura del tipo Passenger con los datos pasados por parametros validandolos y casteandolos
///
/// @param char* id, id a cargar en la estructura
/// @param char* nombre, cadena con el nombre a cargar en la estructura
/// @param char* apellido, apellido a cargar en la estructura
/// @param char* precio, precio a cargar en la estructura
/// @param char* codigoVuelo, codigo de vuelo a cargar en la estructura
/// @param char* idTipoPasajero, id del tipo de pasajero a cargar en la estructura
/// @param char* idEstadoVuelo, id del estado de vuelo a cargar en la estructura
/// @return si se pudo crear el Passenger en memoria con los datos devuelve la direccion de memoria del a misma sino NULL
/// @return
Passenger* Passenger_newParametrosString(char* id,char* nombre,char* apellido,char* precio,char* codigoVuelo,char* idTipoPasajero,char* idEstadoVuelo);

//Destructores
/// @fn void Passenger_delete(Passenger*)
/// @brief libera la memoria del pasajero pasado por parametro
///
/// @param Passenger* pasajero, puntero a pasajero a liberar su memoria
void Passenger_delete(Passenger* pasajero);

/// @fn void Passenger_deleteLista(LinkedList*)
/// @brief recorre la lista pasada por parametro haciendo un delete de cada Passenger de la misma
///
/// @param LinkedList* lista, puntero a lista que contiene los Passenger a liberar
/// @return si los parametros pasados son corretos devuelve 1 sino 0
void Passenger_deleteLista (LinkedList* listaPasajeros);


//Setters
/// @fn int Passenger_setId(Passenger*, int)
/// @brief guarda la id del parametro en el campo id de la estructura Passenger pasada por referencia
///
/// @param Passenger* this, puntero a estructura Passenger donde se guarda el id
/// @param int id, valor de id a guardar en la estructura
/// @return si los parametros y la id son validos devuelve 1 sino 0
int Passenger_setId(Passenger* this,int id);

/// @fn int Passenger_setNombre(Passenger*, char*)
/// @brief guarda el nombre del parametro en el campo nombre de la estructura Passenger pasada por referencia
///
/// @param Passenger* this, puntero a estructura Passenger donde se guarda el nombre
/// @param char* nombre, valor de nombre a guardar en la estructura
/// @return si los parametros y la nombre son validos devuelve 1 sino 0
int Passenger_setNombre(Passenger* this,char* nombre);

/// @fn int Passenger_setApellido(Passenger*, char*)
/// @brief guarda el apellido del parametro en el campo apellido de la estructura Passenger pasada por referencia
///
/// @param Passenger* this, puntero a estructura Passenger donde se guarda el apellido
/// @param char* apellido, valor de apellido a guardar en la estructura
/// @return si los parametros y la apellido son validos devuelve 1 sino 0
int Passenger_setApellido(Passenger* this,char* apellido);

/// @fn int Passenger_setCodigoVuelo(Passenger*, char*)
/// @brief guarda el codigo de vuelo del parametro en el campo codigo de vuelo  de la estructura Passenger pasada por referencia
///
/// @param Passenger* this, puntero a estructura Passenger donde se guarda el codigo de vuelo
/// @param char* codigoVuelo , valor de codigoVuelo a guardar en la estructura
/// @return si los parametros y la codigoVuelo son validos devuelve 1 sino 0
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);

/// @fn int Passenger_setTipoPasajero(Passenger*, int)
/// @brief guarda el id del tipoPasajero del parametro en el campo id del tipoPasajero  de la estructura Passenger pasada por referencia
///
/// @param Passenger* this, puntero a estructura Passenger donde se guarda el id del tipoPasajero
/// @param char* tipoPasajero , valor de id del tipoPasajero a guardar en la estructura
/// @return si los parametros y la id del tipoPasajero son validos devuelve 1 sino 0
int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);

/// @fn int Passenger_setPrecio(Passenger*, float)
/// @brief guarda el precio del parametro en el campo precio  de la estructura Passenger pasada por referencia
///
/// @param Passenger* this, puntero a estructura Passenger donde se guarda el precio
/// @param char* tipoPasajero , valor de precio a guardar en la estructura
/// @return si los parametros y la precio son validos devuelve 1 sino 0
int Passenger_setPrecio(Passenger* this,float precio);

/// @brief guarda el idEstadoVuelo del parametro en el campo idEstadoVuelo  de la estructura Passenger pasada por referencia
///
/// @param Passenger* this, puntero a estructura Passenger donde se guarda el idEstadoVuelo
/// @param char* tipoPasajero , valor de idEstadoVuelo a guardar en la estructura
/// @return si los parametros y la idEstadoVuelo son validos devuelve 1 sino 0
int Passenger_setStatusFlight(Passenger* this,int idEstadoVuelo);

//Getters
/// @fn int Passenger_getId(Passenger*, int*)
/// @brief guarda en la referencia id del parametro el valor del campo id de la estructura del parametro
///
/// @param Passenger* this, puntero a estructura Passenger a obtener el id
/// @param int* id, puntero a id donde se almacena el valor de id de la estructura
/// @return si los parametros son validos devuelve 1 sino 0
int Passenger_getId(Passenger* this,int* id);

/// @brief guarda en nombre del parametro el valor del campo nombre de la estructura del parametro
///
/// @param Passenger* this, puntero a estructura Passenger a obtener el nombre
/// @param int* id, puntero a nombre donde se almacena el valor de nombre de la estructura
/// @return si los parametros son validos devuelve 1 sino 0
int Passenger_getNombre(Passenger* this,char* nombre);

/// @fn int Passenger_getApellido(Passenger*, char*)
/// @brief guarda en apellido del parametro el valor del campo apellido de la estructura del parametro
///
/// @param Passenger* this, puntero a estructura Passenger a obtener el apellido
/// @param int* id, puntero a apellido donde se almacena el valor de apellido de la estructura
/// @return si los parametros son validos devuelve 1 sino 0
int Passenger_getApellido(Passenger* this,char* apellido);

/// @fn int Passenger_getCodigoVuelo(Passenger*, char*)
/// @brief guarda en codigoVuelo del parametro el valor del campo codigoVuelo de la estructura del parametro
///
/// @param Passenger* this, puntero a estructura Passenger a obtener el codigoVuelo
/// @param int* id, puntero a codigoVuelo donde se almacena el valor de codigoVuelo de la estructura
/// @return si los parametros son validos devuelve 1 sino 0
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

/// @fn int Passenger_getTipoPasajero(Passenger*, int*)
/// @brief guarda en la referencia tipoPasajero del parametro el valor del campo tipoPasajero de la estructura del parametro
///
/// @param Passenger* this, puntero a estructura Passenger a obtener el tipoPasajero
/// @param int* id, puntero a tipoPasajero donde se almacena el valor de tipoPasajero de la estructura
/// @return si los parametros son validos devuelve 1 sino 0
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

/// @brief guarda en la referencia precio del parametro el valor del campo precio de la estructura del parametro
///
/// @param Passenger* this, puntero a estructura Passenger a obtener el precio
/// @param int* id, puntero a precio donde se almacena el valor de precio de la estructura
/// @return si los parametros son validos devuelve 1 sino 0
int Passenger_getPrecio(Passenger* this,float* precio);

/// @fn int Passenger_getStatusFlight(Passenger*, int*)
/// @brief guarda en la referencia idEstadoVuelo del parametro el valor del campo idEstadoVuelo de la estructura del parametro
///
/// @param Passenger* this, puntero a estructura Passenger a obtener el idEstadoVuelo
/// @param int* id, puntero a idEstadoVuelo donde se almacena el valor de idEstadoVuelo de la estructura
/// @return si los parametros son validos devuelve 1 sino 0
int Passenger_getStatusFlight(Passenger* this,int* idEstadoVuelo);

//Comparadores

/// @fn int pasajeroComparaId(void*, void*)
/// @brief compara las id de los Passenger pasados por parametro
///
/// @param void* a, puntero a void, dentro se castea a Passenger*
/// @param void* b, puntero a void, dentro se castea a Passenger*
/// @return si id del a es mayor a b devuelve 1 sino -1 si son iguales 0
int pasajeroComparaId (void* a,void* b);

/// @fn int pasajeroComparaNombre(void*, void*)
/// @brief compara los nombres de los Passenger pasados por parametro
///
/// @param void* a, puntero a void, dentro se castea a Passenger*
/// @param void* b, puntero a void, dentro se castea a Passenger*
/// @return si nombre del a es mayor a b devuelve 1 sino -1 si son iguales 0
int pasajeroComparaNombre (void* a,void* b);

/// @fn int pasajeroComparaApellido(void*, void*)
/// @brief compara los apellidos de los Passenger pasados por parametro
///
/// @param void* a, puntero a void, dentro se castea a Passenger*
/// @param void* b, puntero a void, dentro se castea a Passenger*
/// @return si apellidos del a es mayor a b devuelve 1 sino -1 si son iguales 0
int pasajeroComparaApellido (void* a,void* b);

/// @fn int pasajeroComparaPrecio(void*, void*)
/// @brief compara los precios de los Passenger pasados por parametro
///
/// @param void* a, puntero a void, dentro se castea a Passenger*
/// @param void* b, puntero a void, dentro se castea a Passenger*
/// @return si precios del a es mayor a b devuelve 1 sino -1 si son iguales 0
int pasajeroComparaPrecio (void* a,void* b);

/// @fn int pasajeroComparaCodigoVuelo(void*, void*)
/// @brief compara los codigos de vuelo de los Passenger pasados por parametro
///
/// @param void* a, puntero a void, dentro se castea a Passenger*
/// @param void* b, puntero a void, dentro se castea a Passenger*
/// @return si codigos de vuelo del a es mayor a b devuelve 1 sino -1 si son iguales 0
int pasajeroComparaCodigoVuelo (void* a,void* b);

/// @fn int pasajeroComparaTipoPasajero(void*, void*)
/// @brief compara las descripcion de los id tipo de pasajero de los Passenger pasados por parametro
///
/// @param void* a, puntero a void, dentro se castea a Passenger*
/// @param void* b, puntero a void, dentro se castea a Passenger*
/// @return si descripcion del id tipo de pasajero del a es mayor a b devuelve 1 sino -1 si son iguales 0
int pasajeroComparaTipoPasajero (void* a,void* b);


/// @fn int pasajeroComparaEstadoVuelo(void*, void*)
/// @brief compara las descripcion de los id estado de vuelo de los Passenger pasados por parametro
///
/// @param void* a, puntero a void, dentro se castea a Passenger*
/// @param void* b, puntero a void, dentro se castea a Passenger*
/// @return si descripcion del id estado de vuelo del a es mayor a b devuelve 1 sino -1 si son iguales 0
int pasajeroComparaEstadoVuelo (void* a,void* b);


//OTROS
/// @fn int buscarPasajeroPorId(LinkedList*, int*, int)
/// @brief busca en lista el Passenger cuyo campo es igual a la id del parametro
///
/// @param LinkedList* pArrayListPassenger, lista de pasajeros
/// @param int* pIndice, puntero a indice donde se almacena el indice del Passenger buscado
/// @param int id, id a buscar en la lista
/// @return si los parametros son correctos devuelve 1 sino 0
int buscarPasajeroPorId(LinkedList* pArrayListPassenger,int* pIndice,int id);

/// @fn void printPassengerData(Passenger, LinkedList*, LinkedList*)
/// @brief imprime por consola los datos de la estructura Passenger
///
/// @param Passenger p, estructura pasajero con los datos a mostrar
/// @param LinkedList* listaTiposPasajeros, lista de tipos de pasajeros
/// @param LinkedList* listaEstadosVuelos, lista de estados de vuelos
void printPassengerData (Passenger p,LinkedList* listaTiposPasajeros,LinkedList* listaEstadosVuelos);



