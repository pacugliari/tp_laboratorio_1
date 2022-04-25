#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Headers/interface.h"
#include "../Headers/ArrayPassenger.h"
#include "../Headers/pedirDatos.h"

#define CANT_PASAJEROS 2000

void ejecutarMenu(Passenger* ,int* );
void logicaSubMenu(Passenger* );
void mostrarPrecios(float* );

void ejecutarPrograma(){

	Passenger arrayPassengers [CANT_PASAJEROS] ={};
	int cantidadPasajerosCargados = 0;

	if(!initPassengers(arrayPassengers,CANT_PASAJEROS)){
		/*
			//HARDCODEO DATOS DE PRUEBA
			addPassenger(arrayPassengers,CANT_PASAJEROS,posicionVacia(arrayPassengers,CANT_PASAJEROS),"Pablo","Cugliari",100,1,1,"PA1006");
			addPassenger(arrayPassengers,CANT_PASAJEROS,posicionVacia(arrayPassengers,CANT_PASAJEROS),"Beto","Cugliari",200,2,0,"PA1006");
			addPassenger(arrayPassengers,CANT_PASAJEROS,posicionVacia(arrayPassengers,CANT_PASAJEROS),"Mirta","Mena",300,3,1,"PA1004");
			addPassenger(arrayPassengers,CANT_PASAJEROS,posicionVacia(arrayPassengers,CANT_PASAJEROS),"Antonio","Mena",400,4,0,"PA1003");
			addPassenger(arrayPassengers,CANT_PASAJEROS,posicionVacia(arrayPassengers,CANT_PASAJEROS),"Donna","Benfenati",500,5,1,"PA1002");
			addPassenger(arrayPassengers,CANT_PASAJEROS,posicionVacia(arrayPassengers,CANT_PASAJEROS),"Gian","Benfenati",600,6,0,"PA1001");
			cantidadPasajerosCargados = 6;
			//FIN HARDCODEO DATOS*/

			ejecutarMenu(arrayPassengers,&cantidadPasajerosCargados);

	}else{
		printf("Error al iniciar el programa \n");
	}
}

void ejecutarMenu(Passenger* arrayPassengers,int* cantidadPasajerosCargados){
	int respuestaMenu;
	int idBusqueda;
	int unaPosicionVacia;
	Passenger pasajero;

	do{
		respuestaMenu = pedirDatosMenu();
		if(respuestaMenu != 1 && respuestaMenu!= 5 && !*cantidadPasajerosCargados){
			printf("Debe dar de ALTA por lo menos 1 pasajero para utilizar esta opcion \n");
		}else{
			switch(respuestaMenu){
				case 1:
					//ALTA
					pedirDatosPasajero(&pasajero,ALTA);
					unaPosicionVacia = posicionVacia(arrayPassengers,CANT_PASAJEROS);

					if(!addPassenger(arrayPassengers,CANT_PASAJEROS,unaPosicionVacia,pasajero.name,pasajero.lastName,
							pasajero.price,pasajero.typePassenger,pasajero.statusFlight,pasajero.flycode)){

						printf("Pasajero dado de ALTA exitosamente \n");
						(*cantidadPasajerosCargados)++;
					}else
						printf("Error en la ALTA del pasajero \n");

				break;
				case 2:
					//MODIFICAR
					idBusqueda = pedirId();
					pedirDatosPasajero(&pasajero,MODIFICAR);

					if(!modifyPassenger(arrayPassengers,CANT_PASAJEROS,idBusqueda,pasajero.name,pasajero.lastName,pasajero.price,
							pasajero.typePassenger,pasajero.flycode)){
						printf("Pasajero MODIFICADO exitosamente \n");
					}else
						printf("Error en la MODIFICACION del pasajero \n");

				break;
				case 3:
					//BAJA
					idBusqueda = pedirId();
					if(!removePassenger(arrayPassengers,CANT_PASAJEROS,idBusqueda)){
							printf("Pasajero dado de BAJA de manera exitosa \n");
							(*cantidadPasajerosCargados)--;
					}else
						printf("Error en la BAJA del pasajero \n");
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
			if(calculatePricesPassengers(arrayPassengersAux,CANT_PASAJEROS,preciosCalculados)){
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
	printf("Total de los pasajes: %.2f \n",resultados[0]);
	printf("Promedio de los pasajes: %.2f \n",resultados[1]);
	printf("Cantidad de pasajeros que superan el precio promedio: %d \n",(int)resultados[2]);
}



