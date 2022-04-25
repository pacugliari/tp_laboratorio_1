#include "../Headers/pedirDatos.h"
#include "../Headers/ArrayPassenger.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pedirDatosMenu(){
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
	}while (respuesta <1 || respuesta > 5);

	return respuesta;

}

void pedirDatosPasajero(Passenger* pasajero,int tipo){
	char cadenaAux [100];//51
	float precio;
	int estadoVuelo;
	int tipoPasajero;

	//PARA ALTA
	printf("Ingrese el nombre del pasajero \n");
	gets(cadenaAux);
	fflush(stdin);
	while(strlen(cadenaAux) >50){
		printf("Ingrese un nombre mas corto \n");
		gets(cadenaAux);
		fflush(stdin);
	}
	strcpy(pasajero->name,cadenaAux);

	printf("Ingrese el apellido del pasajero \n");
	gets(cadenaAux);
	fflush(stdin);
	while(strlen(cadenaAux) >50){
		printf("Ingrese un apellido mas corto \n");
		gets(cadenaAux);
		fflush(stdin);
	}
	strcpy(pasajero->lastName,cadenaAux);

	printf("Ingrese el precio del vuelo \n");
	scanf("%f",&precio);
	fflush(stdin);
	while(precio < 0){
		printf("Error en precio, ingrese un precio positivo \n");
		scanf("%f",&precio);
	}
	pasajero->price = precio;

	printf("Ingrese el codigo de vuelo del pasajero \n");
	gets(cadenaAux);
	fflush(stdin);
	while(strlen(cadenaAux) >9){
		printf("Ingrese un codigo de vuelo mas corto, hasta 9 caracteres \n");
		gets(cadenaAux);
		fflush(stdin);
	}
	strcpy(pasajero->flycode,cadenaAux);

	if(tipo){
		printf("Ingrese el estado del vuelo \n");
		scanf("%d",&estadoVuelo);
		while(estadoVuelo != 1 && estadoVuelo != 0){
			printf("Ingrese el estado del vuelo, debe ser 1(ACTIVO) o 0 (INACTIVO) \n");
			scanf("%d",&estadoVuelo);
		}
		pasajero->statusFlight = estadoVuelo;
	}


	printf("Ingrese el tipo de pasajero \n");
	scanf("%d",&tipoPasajero);
	while(tipoPasajero < 0){
		printf("El tipo de pasajero debe ser mayor o igual a cero \n");
		scanf("%d",&tipoPasajero);
	}
	pasajero->typePassenger = tipoPasajero;


}

int pedirId(){
	int id;
	printf("Ingrese el ID \n");
	fflush(stdin);
	scanf(" %d",&id);
	fflush(stdin);
	return id;
}

int pedirDatosSubMenu(){
	int respuesta;
	do{
		printf("1) Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero \n");
		printf("2) Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio. \n");
		printf("3) Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’\n");
		scanf("%d",&respuesta);
		fflush(stdin);

		if(respuesta <1 || respuesta > 3){
			printf("Error en la opcion del menu, vuelva a ingresar \n");
		}
	}while (respuesta <1 || respuesta > 3);
	return respuesta;

}
