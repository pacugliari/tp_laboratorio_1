/*
 * main.c
 *
 *  Created on: 18 abr. 2022
 *      Author: PACugliari
 */

#include "../Headers/ArrayPassenger.h"

#define ASC 1
#define DESC 0

int mostrarMenu(){
	int respuesta;

	do{
		printf("1) ALTA \n");
		printf("2) MODIFICAR \n");
		printf("3) BAJA \n");
		printf("4) INFORMAR \n");
		printf("5) SALIR \n");
		scanf("%d",&respuesta);
		fflush(stdin);

		if(respuesta <1 || respuesta > 5){
			printf("Error en la opcion del menu, vuelva a ingresar \n");
		}
	}while (respuesta <1 || respuesta > 100);

	return respuesta;

}


int main(){
	setvbuf(stdout, NULL, _IONBF, 0);//AGREGADO PARA EVITAR BUG CONSOLA ECLIPSE

	Passenger arrayPassengers [CANT_PASAJEROS] ={};
	int cantidadPasajerosCargados = 0;

	Passenger pasajeroActual;

	initPassengers(arrayPassengers,CANT_PASAJEROS);

	int respuestaMenu;
	int idBusqueda;

	addPassenger(arrayPassengers,CANT_PASAJEROS,posicionVacia(arrayPassengers,CANT_PASAJEROS),"Pablo","Cugliari",100,1,"PA1001");
	addPassenger(arrayPassengers,CANT_PASAJEROS,posicionVacia(arrayPassengers,CANT_PASAJEROS),"Beto","Cugliari",100,2,"PA1001");
	addPassenger(arrayPassengers,CANT_PASAJEROS,posicionVacia(arrayPassengers,CANT_PASAJEROS),"Mirta","Mena",100,5,"PA1001");
	addPassenger(arrayPassengers,CANT_PASAJEROS,posicionVacia(arrayPassengers,CANT_PASAJEROS),"Antonio","Mena",100,1,"PA1001");
	addPassenger(arrayPassengers,CANT_PASAJEROS,posicionVacia(arrayPassengers,CANT_PASAJEROS),"Donna","Benfenati",100,10,"PA1001");
	addPassenger(arrayPassengers,CANT_PASAJEROS,posicionVacia(arrayPassengers,CANT_PASAJEROS),"Gian","Benfenati",100,4,"PA1001");
	cantidadPasajerosCargados = 6;
		do{
			respuestaMenu = mostrarMenu();
			switch(respuestaMenu){
				case 1:
					//ALTA

					if(!addPassenger(arrayPassengers,CANT_PASAJEROS,posicionVacia(arrayPassengers,CANT_PASAJEROS),"Pablo","Cugliari",100,1,"PA1001"))
						cantidadPasajerosCargados++;
				break;
				case 2:
					//MODIFICAR
				break;
				case 3:
					//BAJA
					printf("Ingrese el ID a Remover \n");
					fflush(stdin);
					scanf(" %d",&idBusqueda);
					fflush(stdin);
					printf("%d",idBusqueda);
					if(-1 != findPassengerById(arrayPassengers,CANT_PASAJEROS,idBusqueda)){
						removePassenger(arrayPassengers,CANT_PASAJEROS,idBusqueda);
					}
				break;
				case 4:
					//INFORMAR
					for(int i=0;i<CANT_PASAJEROS;i++){
						pasajeroActual = arrayPassengers[i];
						if(!pasajeroActual.isEmpty)
							printf("ID: %d Nombre: %s Apellido: %s Precio: %.2f TipoPasajero: %d Codigo de vuelo: %s Flag: %d \n",pasajeroActual.id,
								pasajeroActual.name,pasajeroActual.lastName,pasajeroActual.price,pasajeroActual.typePassenger,
								pasajeroActual.flycode,pasajeroActual.isEmpty);
					}
				break;
				case 5:
					printf("Saliendo \n");
				break;
				case 6:
					printf("%d",sortPassengers(arrayPassengers,CANT_PASAJEROS,ASC));
				break;
				case 7:
					sortPassengers(arrayPassengers,CANT_PASAJEROS,DESC);
				break;
			}
		}while(respuestaMenu != 5);


	return 0;
}
