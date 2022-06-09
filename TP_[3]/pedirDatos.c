#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Controller.h"
#include "Passenger.h"
#include "pedirDatos.h"

int pedirMenuModificar(){
	int respuesta;
	printf("\n1) Nombre \n");
	printf("2) Apellido \n");
	printf("3) Precio \n");
	printf("4) Tipo de pasajero \n");
	printf("5) Codigo de vuelo \n");
	printf("6) Estado de vuelo \n");
	printf("7) Salir \n");
	scanf("%d",&respuesta);
	fflush(stdin);
	printf("\n");
	return respuesta;
}

char pedirConfirmacion (Passenger pasajero,int tipo,LinkedList* listaTiposPasajeros,LinkedList* listaEstadosVuelos){
	char respuesta = 'n';
	if(listaTiposPasajeros && listaEstadosVuelos){
		if(tipo==MODIFICAR){
			printf("Desea modificar el siguiente pasajero ? s-n \n\n");
		}else
			printf("Desea borrar el siguiente pasajero ? s-n \n\n");

		printf("ID\t\tNombre\t\tApellido\t\t    Precio\t\tTipo de Pasajero\t\tCodigo de vuelo\t\tEstado de vuelo\n");
		printf("-------------------------------------------------------------------------------------------------------------------------------"
				"------------------------\n");
		printPassengerData(pasajero,listaTiposPasajeros,listaEstadosVuelos);
		printf("-------------------------------------------------------------------------------------------------------------------------------"
				"------------------------\n");
		fflush(stdin);
		scanf("%c",&respuesta);
		respuesta = tolower(respuesta);
		fflush(stdin);
	}
	return respuesta;

}

void pedirNombre(char nombre[]){
	if(nombre){
		printf("Ingrese el nombre del pasajero: ");
		gets(nombre);
		fflush(stdin);
		while(strlen(nombre) >50  || strlen(nombre)<=1){
			printf("Ingrese un nombre mas corto/largo: ");
			gets(nombre);
			fflush(stdin);
		}
	}else
		printf("Error en parametro pedirNombre \n");
}

void pedirApellido (char apellido[]){
	if(apellido){
		printf("Ingrese el apellido del pasajero: ");
		gets(apellido);
		fflush(stdin);
		while(strlen(apellido) >50 || strlen(apellido)<=1){
			printf("Ingrese un apellido mas corto/largo: ");
			gets(apellido);
			fflush(stdin);
		}
	}else
		printf("Error en parametro pedirApellido \n");
}

void pedirPrecio (float* precio){
	if(precio){
		printf("Ingrese el precio del vuelo $: ");
		scanf("%f",precio);
		fflush(stdin);
		while(*precio < 0){
			printf("Error en precio, ingrese un precio positivo $: ");
			scanf("%f",precio);
		}
	}else
		printf("Error en parametro pedirPrecio \n");
}



void pedirCodigoVuelo(char codigoVuelo[]){
	if(codigoVuelo){
		printf("Ingrese el codigo de vuelo del pasajero: ");
		gets(codigoVuelo);
		fflush(stdin);
		while(strlen(codigoVuelo) >7 || strlen(codigoVuelo) <= 0){
			printf("Ingrese un codigo de vuelo mas corto/largo, hasta 7 caracteres: ");
			gets(codigoVuelo);
			fflush(stdin);
		}
	}else
		printf("Error en parametros de pedirCodigoVuelo \n");
}



int pedirDatosAlta (Passenger* pasajero,LinkedList* listaTiposPasajeros,LinkedList* listaEstadosVuelos){
	int todoOk = 0;

	if(pasajero && listaTiposPasajeros && listaEstadosVuelos){

		pedirNombre(pasajero->nombre);
		pedirApellido(pasajero->apellido);
		pedirPrecio(&pasajero->precio);
		pedirCodigoVuelo(pasajero->codigoVuelo);
		pedirTipoPasajero(listaTiposPasajeros,&pasajero->idTipoPasajero);
		pedirEstadoVuelo(listaEstadosVuelos,&pasajero->idEstadoVuelo);
		todoOk = 1;
	}
	return todoOk;


}

int pedirId(){
	int id;
	printf("Ingrese el ID \n");
	fflush(stdin);
	scanf(" %d",&id);
	fflush(stdin);
	return id;
}

