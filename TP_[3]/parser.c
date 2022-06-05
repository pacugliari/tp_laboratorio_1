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

#define TAMTP 3
#define TAMEV 3

//FORMATO id,name,lastname,price,flycode,typePassenger,statusFlight

int esCadenaValida(char* cadena){
	int todoOk = 1;
	if(cadena){
		char cadenaAux [strlen(cadena)+1];
		strcpy(cadenaAux,cadena);
		strlwr(cadenaAux);
		for(int i=0;i<strlen(cadenaAux);i++){
			if(cadenaAux[i] < 97 || cadenaAux[i] > 122){
				todoOk = 0;
				break;
			}
		}

	}
	return todoOk;
}

int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int r,i=0;
	char id[50],name[50],lastname[50],price[50],flycode[50],typePassenger[50],statusFlight[50];

    eTipoPasajero tiposP [TAMTP] = {{10000,"FirstClass"},
                                  {10001,"ExecutiveClass"},
                                  {10002,"EconomyClass"}};

    eEstadoVuelo estadosV [TAMEV] = {{20000,"Aterrizado"},
                                  {20001,"En Horario"},
                                  {20002,"Demorado"}};

    int indiceTipoPasajero;
    int indiceEstadoVuelo;
    Passenger* pasajeroNuevo;

	if(pFile == NULL && pArrayListPassenger)
	{
		printf("\nEl archivo no puede ser abierto");
	    return -1;
	}else{
		do
			{
			    r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,name,lastname,price,flycode,typePassenger,statusFlight);
			    if(r==7 && esCadenaValida(name) && esCadenaValida(lastname))
			    {
					buscarTipoPasajero(tiposP,TAMTP,typePassenger,&indiceTipoPasajero);
					buscarEstadoVuelo(estadosV,TAMEV,statusFlight,&indiceEstadoVuelo);
					pasajeroNuevo = Passenger_newParametros(atoi(id),name,lastname,flycode,tiposP[indiceTipoPasajero].id,
							atof(price),estadosV[indiceEstadoVuelo].id);
					ll_add(pArrayListPassenger,pasajeroNuevo);
			        i++;
			    }
			}
			while(!feof(pFile));
	}

	fclose(pFile);
	return i;
}


/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int r,i=0;
	Passenger pasajeroLeido;
	rewind(pFile);
	if(pFile == NULL && pArrayListPassenger)
	{
		printf("\nEl archivo no puede ser abierto");
	    return -1;
	}else{
			do
			{
			    r = fread(&pasajeroLeido,sizeof(Passenger),1,pFile);
			    if(r==1)
			    {

					ll_add(pArrayListPassenger,Passenger_newPassenger(pasajeroLeido));
			        i++;
			    }
			}
			while(!feof(pFile));
	}

	fclose(pFile);
	return i;
}
