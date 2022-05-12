#include "../Headers/pedirDatos.h"
#include "../Headers/ArrayPassenger.h"
#include "../Headers/tipoPasajero.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int pedirDatosMenu(){
	int respuesta;
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
		printf("5) Carga forzada \n");
		printf("6) Salir \n");
		printf("-------------------------------------------------------------------------------------------------------------------------------"
				"------------------------\n");
		scanf("%d",&respuesta);
		fflush(stdin);

		if(respuesta <1 || respuesta > 6){
			printf("Error en la opcion del menu, vuelva a ingresar \n");
		}
	}while (respuesta <1 || respuesta > 6);

	return respuesta;

}

int pedirMenuModificar(){
	int respuesta;
	printf("\n1) Nombre \n");
	printf("2) Apellido \n");
	printf("3) Precio \n");
	printf("4) Tipo de pasajero \n");
	printf("5) Codigo de vuelo \n");
	printf("6) Salir \n");
	scanf("%d",&respuesta);
	fflush(stdin);
	printf("\n");
	return respuesta;
}

char pedirConfirmacion (Passenger pasajero,int tipo,eTipoPasajero tiposPasajeros[],int tamT){
	char respuesta = 'n';
	if(!pasajero.isEmpty && tiposPasajeros && tamT){
		if(tipo==MODIFICAR){
			printf("Desea modificar el siguiente pasajero ? s-n \n\n");
		}else
			printf("Desea borrar el siguiente pasajero ? s-n \n\n");

		printf("ID\t\tNombre\t\tApellido\t\t    Precio\t\tTipo de Pasajero\t\tCodigo de vuelo\t\tEstado de vuelo\n");
		printf("-------------------------------------------------------------------------------------------------------------------------------"
				"------------------------\n");
		printPassengerData(pasajero,tiposPasajeros,tamT);
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
		printf("Ingrese el nombre del pasajero \n");
		gets(nombre);
		fflush(stdin);
		while(strlen(nombre) >50){
			printf("Ingrese un nombre mas corto \n");
			gets(nombre);
			fflush(stdin);
		}
	}else
		printf("Error en parametro pedirNombre \n");
}

void pedirApellido (char apellido[]){
	if(apellido){
		printf("Ingrese el apellido del pasajero \n");
		gets(apellido);
		fflush(stdin);
		while(strlen(apellido) >50){
			printf("Ingrese un apellido mas corto \n");
			gets(apellido);
			fflush(stdin);
		}
	}else
		printf("Error en parametro pedirApellido \n");
}

void pedirPrecio (float* precio){
	if(precio){
		printf("Ingrese el precio del vuelo \n");
		scanf("%f",precio);
		fflush(stdin);
		while(*precio < 0){
			printf("Error en precio, ingrese un precio positivo \n$: ");
			scanf("%f",precio);
		}
	}else
		printf("Error en parametro pedirPrecio \n");
}


void pedirTipoPasajero (int* pId,eTipoPasajero tiposPasajeros[],int tamT){
	if(pId && tiposPasajeros && tamT){
		mostrarTiposPasajeros(tiposPasajeros,tamT);
		printf("Ingrese el ID del tipo de pasajero \n");
		scanf("%d",pId);
		fflush(stdin);

		while(!validarTipoPasajero (tiposPasajeros,tamT,*pId)){
			printf("Error en la ID del tipo de pasajero.Vuelva a ingresar \n");
			scanf("%d",pId);
			fflush(stdin);
		}
	}else
		printf("Error en los parametros de pedirTipoPasajero \n");
}

void pedirCodigoVuelo(char codigoVuelo[]){
	if(codigoVuelo){
		printf("Ingrese el codigo de vuelo del pasajero \n");
		gets(codigoVuelo);
		fflush(stdin);
		while(strlen(codigoVuelo) >9){
			printf("Ingrese un codigo de vuelo mas corto, hasta 9 caracteres \n");
			gets(codigoVuelo);
			fflush(stdin);
		}
	}else
		printf("Error en parametros de pedirCodigoVuelo \n");
}

void pedirEstadoVuelo(int* estadoVuelo){
	if(estadoVuelo){
		printf("Ingrese el estado del vuelo (1) ACTIVO (0) INACTIVO \n");
		scanf("%d",estadoVuelo);
		fflush(stdin);
		while((*estadoVuelo) != 1 && (*estadoVuelo) != 0){
			printf("Ingrese el estado del vuelo, debe ser (1) ACTIVO (0) INACTIVO \n");
			scanf("%d",estadoVuelo);
			fflush(stdin);
		}
	}else
		printf("Error en los parametros de pedirEstadoVuelo \n");
}

int pedirDatosAlta (Passenger* pasajero,eTipoPasajero tiposPasajeros[],int tamT){
	int todoOk = 0;

	if(pasajero && tiposPasajeros && tamT){

		pedirNombre(pasajero->name);
		pedirApellido(pasajero->lastName);
		pedirPrecio(&pasajero->price);
		pedirCodigoVuelo(pasajero->flycode);
		pedirEstadoVuelo(&pasajero->statusFlight);
		pedirTipoPasajero(&pasajero->typePassenger,tiposPasajeros,tamT);
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

int pedirDatosSubMenu(){
	int respuesta;
	do{
		printf("1) Listado de los pasajeros ordenados alfabeticamente por Apellido y Tipo de pasajero \n");
		printf("2) Total y promedio de los precios de los pasajes, y cuantos pasajeros superan el precio promedio. \n");
		printf("3) Listado de los pasajeros por Codigo de vuelo y estados de vuelos 'ACTIVO'\n");
		printf("4) Salir \n\n");
		scanf("%d",&respuesta);
		fflush(stdin);
		printf("\n");
		if(respuesta <1 || respuesta > 4){
			printf("Error en la opcion del menu, vuelva a ingresar \n");
		}
	}while (respuesta <1 || respuesta > 4);
	return respuesta;
}
