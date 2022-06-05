#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int todoOk =0;
	int contador=0;
	if(path && pArrayListPassenger){
		FILE* arch = fopen(path,"r");
		contador = parser_PassengerFromText(arch,pArrayListPassenger);
		printf("Cantidad de pasajeros cargados desde el archivo de texto: %s es: %d \n",path,contador);
		todoOk=1;
	}
    return todoOk;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int todoOk =0;
	int contador=0;
	if(path && pArrayListPassenger){
		FILE* arch = fopen(path,"rb");
		contador = parser_PassengerFromBinary(arch,pArrayListPassenger);
		printf("Cantidad de pasajeros cargados desde el archivo binario: %s es: %d \n",path,contador);
		todoOk=1;
	}
    return todoOk;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */

int pasajeroAString(Passenger pasajero,char* string){
	int todoOk = 0;
	if(string){
		todoOk = 1;
	}
	return todoOk;
}

int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int todoOk = 0;
	int cursor = 0;
	Passenger* pasajeroActual;
	FILE* aux = fopen("auxiliar.txt","w");
	int contador = 0;
	//char lineaDato [400]={""};

	if( path && pArrayListPassenger && aux){
		 while(ll_len(pArrayListPassenger) > cursor){
			 pasajeroActual = ll_get(pArrayListPassenger,cursor);
			 //strcat(lineaDato,pasajero)
			 if(fwrite(pasajeroActual,sizeof(Passenger),1,aux) == 1 )
				 contador++;
			 cursor++;
		 }
	}
	fclose(aux);
	if(contador == ll_len(pArrayListPassenger)){
		remove(path);
		rename("auxiliar.txt",path);
		todoOk =1;
	}else {
		printf("No se pudieron guardar los pasajeros como archivo texto \n");
		remove("auxiliar.txt");
	}

    return todoOk;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int todoOk = 0;
	int cursor = 0;
	Passenger* pasajeroActual;
	FILE* aux = fopen("auxiliar.csv","wb");
	int contador = 0;

	if( path && pArrayListPassenger && aux){
		 while(ll_len(pArrayListPassenger) > cursor){
			 pasajeroActual = ll_get(pArrayListPassenger,cursor);
			 if(fwrite(pasajeroActual,sizeof(Passenger),1,aux) == 1 )
				 contador++;
			 cursor++;
		 }
	}
	fclose(aux);
	if(contador == ll_len(pArrayListPassenger)){
		remove(path);
		rename("auxiliar.csv",path);
		todoOk =1;
	}else {
		printf("No se pudieron guardar los pasajeros como archivo binario \n");
		remove("auxiliar.csv");
	}

    return todoOk;
}

