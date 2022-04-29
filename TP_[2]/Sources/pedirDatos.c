#include "../Headers/pedirDatos.h"
#include "../Headers/ArrayPassenger.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int pedirDatosMenu(){
	int respuesta;
/*
Trabajo Práctico número 2
Programación I – Laboratorio I.
Tecnicatura Superior en Programación.
UTN-FRA
 * */
	do{
		printf("\t\t\t\t\t\t***Trabajo Practico numero 2***\n");
		printf("\t\t\t\t\t\t  Programacion I- Laboratorio I\n");
		printf("\t\t\t\t\t  Tecnicatura Superior en Programacion UTN-FRA \n");
		printf("Alumno: Pablo Cugliari | Division: 1A \n");
		printf("-------------------------------------------------------------------------------------------------------------------------------"
				"------------------------\n");
		printf("1) Alta \n");
		printf("2) Modificar \n");
		printf("3) Baja \n");
		printf("4) Informar \n");
		printf("5) Salir \n");
		printf("-------------------------------------------------------------------------------------------------------------------------------"
				"------------------------\n");
		scanf("%d",&respuesta);
		fflush(stdin);

		if(respuesta <1 || respuesta > 5){
			printf("Error en la opcion del menu, vuelva a ingresar \n");
		}
	}while (respuesta <1 || respuesta > 5);

	return respuesta;

}

char pedirConfirmacion (Passenger pasajero,int tipo){
	char respuesta = 'n';
	if(!pasajero.isEmpty){
		if(tipo==MODIFICAR){
			printf("Desea modificar el siguiente pasajero ? s-n \n\n");
		}else
			printf("Desea borrar el siguiente pasajero ? s-n \n\n");

		printf("ID\t\tNombre\t\tApellido\t\t    Precio\t\tTipo de Pasajero\t\tCodigo de vuelo\t\tEstado de vuelo\n");
		printf("-------------------------------------------------------------------------------------------------------------------------------"
				"------------------------\n");
		printPassengerData(pasajero);
		printf("-------------------------------------------------------------------------------------------------------------------------------"
				"------------------------\n");
		fflush(stdin);
		scanf("%c",&respuesta);
		respuesta = tolower(respuesta);
		fflush(stdin);
	}
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

	if(tipo==ALTA){
		printf("Ingrese el estado del vuelo \n");
		scanf("%d",&estadoVuelo);
		fflush(stdin);
		while(estadoVuelo != 1 && estadoVuelo != 0){
			printf("Ingrese el estado del vuelo, debe ser 1(ACTIVO) o 0 (INACTIVO) \n");
			scanf("%d",&estadoVuelo);
			fflush(stdin);
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
		printf("1) Listado de los pasajeros ordenados alfabeticamente por Apellido y Tipo de pasajero \n");
		printf("2) Total y promedio de los precios de los pasajes, y cuantos pasajeros superan el precio promedio. \n");
		printf("3) Listado de los pasajeros por Codigo de vuelo y estados de vuelos 'ACTIVO'\n");
		scanf("%d",&respuesta);
		fflush(stdin);

		if(respuesta <1 || respuesta > 3){
			printf("Error en la opcion del menu, vuelva a ingresar \n");
		}
	}while (respuesta <1 || respuesta > 3);
	return respuesta;

}
