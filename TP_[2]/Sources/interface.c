#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Headers/interface.h"
#include "../Headers/ArrayPassenger.h"
#include "../Headers/pedirDatos.h"

void ejecutarMenu(Passenger* );
void logicaSubMenu(Passenger* );
void mostrarPrecios(float* );
void hardcodeoDatos(Passenger* ,int* ,int* ,int );
void alta(Passenger* ,int* cantdadPasajeros,int* );
void modificar(Passenger*);
void baja(Passenger*,int* );

void ejecutarPrograma(){

	Passenger arrayPassengers [CANT_PASAJEROS] ={};

	if(TODO_OK == initPassengers(arrayPassengers,CANT_PASAJEROS)){

			ejecutarMenu(arrayPassengers);

	}else{
		printf("Error al iniciar el programa \n");
	}
}


void ejecutarMenu(Passenger* arrayPassengers){
	int respuestaMenu;
	int id = -1;
	int cantidadPasajerosCargados = 0;

	//hardcodeoDatos(arrayPassengers,&id,&cantidadPasajerosCargados,6);

	do{
		respuestaMenu = pedirDatosMenu();
		if(respuestaMenu != 1 && respuestaMenu!= 5 && !cantidadPasajerosCargados){
			printf("Debe dar de ALTA por lo menos 1 pasajero para utilizar esta opcion \n");
		}else{
			switch(respuestaMenu){
				case 1:
					alta(arrayPassengers,&cantidadPasajerosCargados,&id);
				break;
				case 2:
					modificar(arrayPassengers);
				break;
				case 3:
					baja(arrayPassengers,&cantidadPasajerosCargados);
				break;
				case 4:
					logicaSubMenu(arrayPassengers);
				break;
				case 5:
					printf("Saliendo \n");
				break;
			}
		}
	}while(respuestaMenu != 5);
}

void hardcodeoDatos(Passenger* list,int* id,int* cantidad,int cantidadDatos){
	int estado = 0;
	char str [100];
	for(int i=0; i<cantidadDatos;i++){
		if(ERROR != addPassenger(list,CANT_PASAJEROS,*id,itoa(i,str,10),itoa(i,str,10),i,i,estado,itoa(i,str,10))){
			(*id)++;
			(*cantidad)++;
			estado = !estado;
		}
	}
}

void alta(Passenger* list,int* cantidadPasajeros,int* id){
	//ALTA
	Passenger pasajero;
	if(*cantidadPasajeros == CANT_PASAJEROS){
		printf("Limite de pasajeros alcanzado (MAX: %d) \n",CANT_PASAJEROS);
	}else{
		pedirDatosPasajero(&pasajero,ALTA);
		if(!addPassenger(list,CANT_PASAJEROS,*id,pasajero.name,pasajero.lastName,
				pasajero.price,pasajero.typePassenger,pasajero.statusFlight,pasajero.flycode)){

			printf("Pasajero dado de ALTA exitosamente \n");
			(*cantidadPasajeros)++;
			(*id)++;
		}else
			printf("Error en la ALTA del pasajero \n");
	}

}

void modificar(Passenger* list){
	//MODIFICAR
	int idBusqueda = pedirId();
	Passenger pasajero;
	int posicion = findPassengerById(list,CANT_PASAJEROS,idBusqueda);
	if(ERROR == posicion){
		printf("Error en la ID ingresada \n");
	}else if ('s'== pedirConfirmacion(list[posicion],MODIFICAR)){
		pedirDatosPasajero(&pasajero,MODIFICAR);
		if(!modifyPassenger(list,CANT_PASAJEROS,idBusqueda,pasajero.name,pasajero.lastName,pasajero.price,
				pasajero.typePassenger,pasajero.flycode)){
			printf("Pasajero MODIFICADO exitosamente \n");
		}else
			printf("Error en la MODIFICACION del pasajero \n");
	}
}


void baja (Passenger* list,int* cantidadPasajeros){
	//BAJA
	int idBusqueda = pedirId();
	int posicion = findPassengerById(list,CANT_PASAJEROS,idBusqueda);
	if(ERROR == posicion){
		printf("Error en la ID ingresada \n");
	}else if ('s'== pedirConfirmacion(list[posicion],BAJA)){
		if(!removePassenger(list,CANT_PASAJEROS,idBusqueda)){
				printf("Pasajero dado de BAJA de manera exitosa \n");
				(*cantidadPasajeros)--;
		}else
			printf("Error en la BAJA del pasajero \n");
	}
}

void logicaSubMenu(Passenger* list){
	int respuesta  = pedirDatosSubMenu();
	float preciosCalculados[3];//0-TOTAL,1-PROMEDIO,2-CONTADOR QUE SUPERAN EL PROMEDIO
	Passenger arrayPassengersAux [CANT_PASAJEROS];

	//TRABAJO CON UNA COPIA PARA NO DESORDENAR EL VECTOR ORIGINAL
	for(int i=0;i<CANT_PASAJEROS;i++){
		arrayPassengersAux[i] = list[i];
	}

	switch(respuesta){
		case 1:
			sortPassengers(arrayPassengersAux,CANT_PASAJEROS,ASC);
			printPassenger(arrayPassengersAux,CANT_PASAJEROS);
		break;
		case 2:
			if(ERROR != calculatePricesPassengers(arrayPassengersAux,CANT_PASAJEROS,preciosCalculados)){
				mostrarPrecios(preciosCalculados);
			}
		break;
		case 3:
			sortPassengersByCode(arrayPassengersAux,CANT_PASAJEROS,ASC);
			printPassengerActive(arrayPassengersAux,CANT_PASAJEROS);
		break;
	}

}

void mostrarPrecios(float* resultados){
	if(resultados){
		printf("Total de los pasajes: %.2f \n",resultados[0]);
		printf("Promedio de los pasajes: %.2f \n",resultados[1]);
		printf("Cantidad de pasajeros que superan el precio promedio: %d \n",(int)resultados[2]);
	}else
		printf("Error al mostrar los precios \n");
}



