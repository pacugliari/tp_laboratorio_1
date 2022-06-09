#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */

#include "tipoPasajero.h"
#include "estadoVuelo.h"
#include <string.h>



//FORMATO id,name,lastname,price,flycode,typePassenger,statusFlight

int esCadenaValida(char* cadena){
	int todoOk = 1;
	if(cadena){
		char cadenaAux [strlen(cadena)+1];
		strcpy(cadenaAux,cadena);
		strlwr(cadenaAux);
		for(int i=0;i<strlen(cadenaAux);i++){
			if((cadenaAux[i] < 97 || cadenaAux[i] > 122) && cadenaAux[i] != ' '){
				todoOk = 0;
				break;
			}
		}

	}
	return todoOk;
}

int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger,int* pId)
{
	int datosLeidos,datosCargados=0;
	char buffer [7][50];
    int indiceTipoPasajero;
    int indiceEstadoVuelo;
    char encabezados[7][20];
    eTipoPasajero tiposP [TAMTP];
    eEstadoVuelo estadosV [TAMEV];
    Passenger* pasajeroNuevo = NULL;
    int mayorId;
    int esPrimero = 1;

    hardcodearTiposPasajeros(tiposP,TAMTP);
    hardcodearEstadosVuelo(estadosV,TAMEV);

    //FORMATO id,name,lastname,price,flycode,typePassenger,statusFlight
    fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",encabezados[0],encabezados[1],encabezados[2],encabezados[3],encabezados[4],
    		encabezados[5],encabezados[6]); //LECTURA FANTASMA PARA ELMINAR ENCABEZADO

	do{
		datosLeidos = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],
				buffer[4],buffer[5],buffer[6]);
		if(datosLeidos==7 && esCadenaValida(buffer[1]) && esCadenaValida(buffer[2])){
			buscarTipoPasajeroPorDescripcion(tiposP,TAMTP,buffer[5],&indiceTipoPasajero);
			buscarEstadoVueloPorDescripcion(estadosV,TAMEV,buffer[6],&indiceEstadoVuelo);
			pasajeroNuevo = Passenger_newParametros(atoi(buffer[0]),buffer[1],buffer[2],atof(buffer[3]),buffer[4],tiposP[indiceTipoPasajero].id,
					estadosV[indiceEstadoVuelo].id);
			if(pasajeroNuevo){
				if(pasajeroNuevo->id > mayorId || esPrimero){
					mayorId = pasajeroNuevo->id;
					esPrimero = 0;
				}
				ll_add(pArrayListPassenger,pasajeroNuevo);
				datosCargados++;
			}
		}
	}while(!feof(pFile));

	(*pId) = mayorId +1;
	return datosCargados;
}


/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger,int* pId)
{
	int datosLeidos,datosCargados=0;
	Passenger pasajeroLeido;
	int mayorId;
	int esPrimero = 1;

	do
	{
		datosLeidos = fread(&pasajeroLeido,sizeof(Passenger),1,pFile);
		if(datosLeidos==1)
		{
			if(esPrimero || pasajeroLeido.id > mayorId){
				mayorId = pasajeroLeido.id;
				esPrimero = 0;
			}
			ll_add(pArrayListPassenger,Passenger_newPassenger(pasajeroLeido));
			datosCargados++;
		}
	}
	while(!feof(pFile));

	(*pId) = mayorId +1;
	return datosCargados;
}
