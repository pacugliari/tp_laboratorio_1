#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "tipoPasajero.h"
#include "estadoVuelo.h"


int esCadenaValida(char* cadena){
	int todoOk = 1;
	if(cadena){
		char cadenaAux [strlen(cadena)+1];
		strcpy(cadenaAux,cadena);
		strlwr(cadenaAux);
		for(int i=0;i<strlen(cadenaAux);i++){
			if((cadenaAux[i] < 97 || cadenaAux[i] > 122) && cadenaAux[i] != ' ' && cadenaAux[i] != '-'){
				todoOk=0;
				break;
			}
		}

	}
	return todoOk;
}

int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger,int* pId,LinkedList* tiposPasajeros,LinkedList* estadosVuelos)
{
	int datosLeidos,datosCargados=0;
	char buffer [7][50];
    int indiceTipoPasajero;
    int indiceEstadoVuelo;
    eEstadoVuelo* auxEstado;
    eTipoPasajero* auxTipo;
    Passenger* pasajeroNuevo = NULL;
    int mayorId;
    int esPrimero = 1;
    char encabezado[]={"id,name,lastname,price,flycode,typePassenger,statusFlight"};
    char comprobacion[strlen(encabezado)+1];
    fgets(comprobacion,strlen(encabezado)+1,pFile);

    if(!strcmp(comprobacion,"id,name,lastname,price,flycode,typePassenger,statusFlight")){
    	do{
			datosLeidos = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],
					buffer[4],buffer[5],buffer[6]);
			buscarTipoPasajeroPorDescripcion(tiposPasajeros,buffer[5],&indiceTipoPasajero);
			buscarEstadoVueloPorDescripcion(estadosVuelos,buffer[6],&indiceEstadoVuelo);

			if(datosLeidos==7 && esCadenaValida(buffer[1]) && esCadenaValida(buffer[2]) && indiceEstadoVuelo != -1 && indiceTipoPasajero != -1){
				auxEstado = (eEstadoVuelo*) ll_get(estadosVuelos,indiceEstadoVuelo);
				auxTipo = (eTipoPasajero*) ll_get(tiposPasajeros,indiceTipoPasajero);

				pasajeroNuevo = Passenger_newParametros(atoi(buffer[0]),buffer[1],buffer[2],atof(buffer[3]),buffer[4],auxTipo->id,auxEstado->id);
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
    }else{
    	printf("Error esta intentando abrir un archivo binario o error en el encabezado del archivo \n");
    	printf("Formato de encabezado: id,name,lastname,price,flycode,typePassenger,statusFlight \n");
    }

	return datosCargados;
}



int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger,int* pId)
{
	int datosLeidos,datosCargados=0;
	Passenger pasajeroLeido;
	int mayorId=0;
	int esPrimero = 1;
	Passenger* pasajeroNuevo;

	do
	{
		datosLeidos = fread(&pasajeroLeido,sizeof(Passenger),1,pFile);
		pasajeroNuevo = Passenger_newPassenger(pasajeroLeido);
		if(datosLeidos==1 && pasajeroNuevo)
		{
			if(esPrimero || pasajeroLeido.id > mayorId){
				mayorId = pasajeroLeido.id;
				esPrimero = 0;
			}
			ll_add(pArrayListPassenger,pasajeroNuevo);
			datosCargados++;
		}
	}
	while(!feof(pFile));

	if(datosCargados == 0){
    	printf("Error esta intentando abrir un archivo texto o error en el  archivo \n");
    }else{
    	(*pId) = mayorId +1;
    }

	return datosCargados;
}
