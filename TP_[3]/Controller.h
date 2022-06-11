#include "Passenger.h"
#include "LinkedList.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*, direccion donde se encuentra el archivo
 * \param LinkedList* pArrayListPassenger, lista de pasajeros
 * \param int* pId, puntero a id para ir actualizando su valor
 * \param LinkedList* tiposPasajeros, lista de tipos de pasajeros
 * \param LinkedList* estadosVuelos, lista de estados de vuelos
 * \return int, si los parametros pasados por parametros son correctos retorna 1 sino 0
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger,int* pId,LinkedList* tiposPasajeros,LinkedList* estadosVuelos);

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*, direccion donde se encuentra el archivo
 * \param LinkedList* pArrayListPassenger, lista de pasajeros
 * \param int* pId, puntero a id para ir actualizando su valor
 * \return int, si los parametros pasados por parametros son correctos retorna 1 sino 0
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger,int* pId);

/** \brief Alta de pasajero
 *
 * \param LinkedList* pArrayListPassenger, lista de pasajeros
 * \param int* pId, puntero a id para ir actualizando su valor
 * \param LinkedList* tiposPasajeros, lista de tipos de pasajeros
 * \param LinkedList* estadosVuelos, lista de estados de vuelos
 * \return int, si los parametros pasados por parametros son correctos retorna 1 sino 0
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger,int* pId,LinkedList* tiposPasajeros,LinkedList* estadosVuelos);

/** \brief Modificar datos de pasajero
 *
 * \param LinkedList* pArrayListPassenger, lista de pasajeros
 * \param LinkedList* tiposPasajeros, lista de tipos de pasajeros
 * \param LinkedList* estadosVuelos, lista de estados de vuelos
 * \return int, si los parametros pasados por parametros son correctos retorna 1 sino 0
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger,LinkedList* tiposPasajeros,LinkedList* estadosVuelos);

/** \brief Baja de pasajero
 *
 * \param LinkedList* pArrayListPassenger, lista de pasajeros
 * \param LinkedList* tiposPasajeros, lista de tipos de pasajeros
 * \param LinkedList* estadosVuelos, lista de estados de vuelos
 * \return int, si los parametros pasados por parametros son correctos retorna 1 sino 0
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger,LinkedList* tiposPasajeros,LinkedList* estadosVuelos);

/** \brief Listar pasajeros
 *
 * \param LinkedList* pArrayListPassenger, lista de pasajeros
 * \param LinkedList* tiposPasajeros, lista de tipos de pasajeros
 * \param LinkedList* estadosVuelos, lista de estados de vuelos
 * \return int, si los parametros pasados por parametros son correctos retorna 1 sino 0
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger,LinkedList* tiposPasajeros,LinkedList* estadosVuelos);

/** \brief Ordenar pasajeros
 *
 * \param LinkedList* pArrayListPassenger, lista de pasajeros
 * \return int, si los parametros pasados por parametros son correctos retorna 1 sino 0
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger);

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*, direccion donde se encuentra el archivo
 * \param LinkedList* pArrayListPassenger, lista de pasajeros
 * \param LinkedList* tiposPasajeros, lista de tipos de pasajeros
 * \param LinkedList* estadosVuelos, lista de estados de vuelos
 * \return int, si los parametros pasados por parametros son correctos retorna 1 sino 0
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger,LinkedList* tiposPasajeros,LinkedList* estadosVuelos);

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*, direccion donde se encuentra el archivo
 * \param LinkedList* pArrayListPassenger, lista de pasajeros
 * \return int, si los parametros pasados por parametros son correctos retorna 1 sino 0
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);


