#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Headers/interface.h"
#include "../Headers/ArrayPassenger.h"
#include "../Headers/pedirDatos.h"
#include "../Headers/tipoPasajero.h"



void ejecutarPrograma(){
	int respuestaMenu;
	int id = ID_VIAJES;
	int seHizoCargaForzada = 0;
	int contadorPasajeros = 0;
	Passenger arrayPassengers [CANT_PASAJEROS] ={};
	eTipoPasajero tiposPasajeros[TAMT] = {{10000,"Clase Business"},
										   {10001,"Clase Economy"},
										   {10002,"Clase Premium Economy"}};

	if(TODO_OK == initPassengers(arrayPassengers,CANT_PASAJEROS)){
		do{
				respuestaMenu = pedirDatosMenu();
				system("cls");
				if( respuestaMenu >=2 && respuestaMenu<=4 && !contadorPasajeros){
					printf("Debe dar de ALTA por lo menos 1 pasajero para utilizar esta opcion \n");
				}else{
					switch(respuestaMenu){
						case 1:
							alta(arrayPassengers,&id,tiposPasajeros,TAMT);
							contadorPasajeros++;
						break;
						case 2:
							modificar(arrayPassengers,tiposPasajeros,TAMT);
						break;
						case 3:
							baja(arrayPassengers,tiposPasajeros,TAMT);
							contadorPasajeros--;
						break;
						case 4:
							listar(arrayPassengers,tiposPasajeros,TAMT);
						break;
						case 5:
							if(!seHizoCargaForzada && (contadorPasajeros = hardcodearPasajeros(arrayPassengers,CANT_PASAJEROS,5,&id))){
								printf("Carga forzada realizada de manera exitosa \n");
								seHizoCargaForzada = 1;
							}else
								printf("Error en la carga forzada o ya se realizo una \n");
						break;
						case 6:
							printf("Saliendo \n");
						break;
					}
				}
				system("pause");
				system("cls");
		}while(respuestaMenu != 6);
	}else
		printf("Error al iniciar el programa \n");
}

void alta(Passenger* list,int* id,eTipoPasajero tiposPasajeros[],int tamT){
	//ALTA
	Passenger pasajeroNuevo;
	int indice;

	if(list && id && tiposPasajeros && tamT>0 ){
		buscarPasajeroLibre(list,CANT_PASAJEROS,&indice);
		if(indice == ERROR){
			printf("Limite de pasajeros alcanzado (MAX: %d) \n",CANT_PASAJEROS);
		}else{
			pedirDatosAlta(&pasajeroNuevo,tiposPasajeros,tamT);
			if(!addPassenger(list,CANT_PASAJEROS,*id,pasajeroNuevo.name,pasajeroNuevo.lastName,
					pasajeroNuevo.price,pasajeroNuevo.typePassenger,pasajeroNuevo.statusFlight,pasajeroNuevo.flycode)){
				printf("Pasajero dado de ALTA exitosamente \n");
				(*id)++;
			}else
				printf("Error en la ALTA del pasajero \n");
		}
	}else
		printf("Error en los parametros del alta \n");

}


void modificar(Passenger* list,eTipoPasajero tiposPasajeros[],int tamT){
	//MODIFICAR
	int respuesta = 0;
	int idBusqueda;
	Passenger pasajero;
	int posicion;

	if(list && tiposPasajeros && tamT >0){

		printPassenger(list,CANT_PASAJEROS,tiposPasajeros,tamT);
		idBusqueda = pedirId();
		posicion = findPassengerById(list,CANT_PASAJEROS,idBusqueda);

		if(ERROR == posicion){
			printf("Error en la ID ingresada \n");
		}else if ('s'== pedirConfirmacion(list[posicion],MODIFICAR,tiposPasajeros,tamT)){
			pasajero = list[posicion];
			do{
				switch(respuesta = pedirMenuModificar()){
					case 1:
						pedirNombre(pasajero.name);
						printf("Nombre modificado de manera correcta \n");
						break;
					case 2:
						pedirApellido(pasajero.lastName);
						printf("Apellido modificado de manera correcta \n");
						break;
					case 3:
						pedirPrecio(&pasajero.price);
						printf("Precio modificado de manera correcta \n");
						break;
					case 4:
						pedirTipoPasajero(&pasajero.typePassenger,tiposPasajeros,tamT);
						printf("Tipo de pasajero modificado de manera correcta \n");
						break;
					case 5:
						pedirCodigoVuelo(pasajero.flycode);
						printf("Codigo de vuelo modificado de manera correcta \n");
						break;
				}
			}while(respuesta != 6);
			if(!modifyPassenger(list,CANT_PASAJEROS,idBusqueda,pasajero.name,pasajero.lastName,pasajero.price,
					pasajero.typePassenger,pasajero.flycode)){
				printf("Pasajero MODIFICADO exitosamente \n");
			}else
				printf("Error en la MODIFICACION del pasajero \n");
		}else
			printf("MODIFICACION cancelada \n");
	}else
		printf("Error en los parametros de modificar \n");
}


void baja (Passenger* list,eTipoPasajero tiposPasajeros[],int tamT){

	if(list && tiposPasajeros && tamT >0){
		printPassenger(list,CANT_PASAJEROS,tiposPasajeros,tamT);
		int idBusqueda = pedirId();
		int posicion = findPassengerById(list,CANT_PASAJEROS,idBusqueda);
		if(ERROR == posicion){
			printf("Error en la ID ingresada \n");
		}else if ('s'== pedirConfirmacion(list[posicion],BAJA,tiposPasajeros,TAMT)){
			if(!removePassenger(list,CANT_PASAJEROS,idBusqueda)){
					printf("Pasajero dado de BAJA de manera exitosa \n");
			}else
				printf("Error en la BAJA del pasajero \n");
		}else
			printf("BAJA cancelada \n");
	}else
		printf("Error en los parametros de baja \n");
}

void listar (Passenger* list,eTipoPasajero tiposPasajeros[],int tamT){
	int respuesta ;
	Passenger arrayPassengersAux [CANT_PASAJEROS];

	if(list && tiposPasajeros && tamT >0){
		//TRABAJO CON UNA COPIA PARA NO DESORDENAR EL VECTOR ORIGINAL
		for(int i=0;i<CANT_PASAJEROS;i++){
			arrayPassengersAux[i] = list[i];
		}
		do{
			switch(respuesta = pedirDatosSubMenu()){
				case 1:
					sortPassengers(arrayPassengersAux,CANT_PASAJEROS,ASC);
					printPassenger(arrayPassengersAux,CANT_PASAJEROS,tiposPasajeros,tamT);
				break;
				case 2:
					calculatePricesPassengers(arrayPassengersAux,CANT_PASAJEROS);
				break;
				case 3:
					sortPassengersByCode(arrayPassengersAux,CANT_PASAJEROS,ASC);
					printPassengerActive(arrayPassengersAux,CANT_PASAJEROS,tiposPasajeros,tamT);
				break;
			}
			system("pause");
			system("cls");
		}while(respuesta != 4);
	}else
		printf("Error en los parametros de logicaSubMenu \n");


}





