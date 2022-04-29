#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Headers/interface.h"
#include "../Headers/ArrayPassenger.h"
#include "../Headers/pedirDatos.h"

///PROTOTIPOS DE FUNCIONES ENCAPSULADAS USADAS DENTRO DE LA FUNCION ejecutarMenu();

/// @fn void ejecutarMenu(Passenger*)
/// @brief contiene la logica y muestra las opciones del menu ALTA-MODIFICACION-BAJA-INFORMAR-SALIR
///
/// @param Passenger*, puntero al vector de Passengers
void ejecutarMenu(Passenger* );

/// @fn void logicaSubMenu(Passenger*)
/// @brief contiene la logica y muestra las opciones del submenu de INFORMAR
///
/// @param Passenger*, recibe el vector de pasajeros para realizar una copia del mismo y no modificar el original
void logicaSubMenu(Passenger* );

/// @fn void mostrarPrecios(float*)
/// @brief mustra los precios calculados de la opcion 3 del submenu de INFORMAR
///
/// @param float*, vector de flotantes donde se encuentran los 3 resultados, total de los pasajes, promedio y cantidad de pasajeros que superan
/// dicho promedio
void mostrarPrecios(float* );

/// @fn void hardcodeoDatos(Passenger*, int*, int*, int)
/// @brief funcion de prueba para inicializar el vector de pasajeros y facilitar la prueba del programa
///
/// @param Passenger*, puntero a vector de Passengers
/// @param int* , puntero a entero de la id
/// @param int*, puntero a entero con la cantidad de pasajeros cargados actualmente en el sistema
/// @param int ,entero que es el tamanio maximo del vector de pasajeros
void hardcodeoDatos(Passenger* ,int* ,int* ,int );

/// @fn void alta(Passenger*, int*, int*)
/// @brief funcion para dar el alta de un pasajero , validando que no se supere el maximo de pasajeros
/// pide los datos al usuario utilizando la funcion pedirDatosPasajero(), da el alta en el vector de pasajeros utilizando
/// la funcion addPassenger() y actualiza el valor de id y cantidad de pasajeros del sistema
///
/// @param Passenger*, puntero a vector de pasajeros
/// @param cantdadPasajeros int*, puntero a entero que lleva la cuenta de la cantidad de pasajeros para poder actualizarlo
/// @param int*, puntero a entero de la id para poder actualizar la misma
void alta(Passenger* ,int* cantdadPasajeros,int* );

/// @fn void modificar(Passenger*)
/// @brief funcion que realiza la modificacion de un pasajero, validando la id ingresada por el usuario, muestra
/// el pasajero correspondiente a la id ingresada por el usuario pidiendo una confirmacion, si la confirmacion es valida
/// se piden los datos nuevos de modificacion y en caso correcto se realiza la modificacion del pasajero con ayuda de la funcion
/// modifyPassenger()
///
/// @param Passenger*, puntero a vector de pasajeros
void modificar(Passenger*);

/// @fn void baja(Passenger*, int*)
/// @brief funcion que realiza la baja de un pasajero validando la id ingresada por el usuario, antes de realizar la baja del sistema
/// muestra el pasajero correspondiente a la id ingresada pidiendo confirmacion de borrado, si la confirmacion es valida se realiza la misma y
/// se actualiza el contador de pasajeros del sistema
///
/// @param Passenger* , puntero a vector de pasajeros
/// @param int*, puntero a entero de la cantidad de pasajeros del sistema
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

	hardcodeoDatos(arrayPassengers,&id,&cantidadPasajerosCargados,6);

	do{
		respuestaMenu = pedirDatosMenu();
		system("cls");
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
		system("pause");
		system("cls");
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



