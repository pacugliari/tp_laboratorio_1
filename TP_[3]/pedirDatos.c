#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "pedirDatos.h"
#include "Passenger.h"

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

void printPassengerData (Passenger p,eTipoPasajero tiposPasajeros[],int tamT,eEstadoVuelo estadosVuelos[],int tamE){
	char descripcionTipoPasajero [30];
	char descripcionEstado [30];
	if(tiposPasajeros && tamT >0 && estadosVuelos && tamE > 0){
		cargarDescripcionTipoPasajero(tiposPasajeros,tamT,p.idTipoPasajero,descripcionTipoPasajero);
		cargarDescripcionEstadoVuelo(estadosVuelos,tamE,p.idEstadoVuelo,descripcionEstado);
		printf("%04d\t\t%-16s%-24s$%10.2f\t\t%-30s\t%-10s\t\t%-s\n",p.id,
									p.nombre,p.apellido,p.precio,descripcionTipoPasajero,
									p.codigoVuelo,descripcionEstado);
	}else
		printf("Error en los parametros de printPassengerData \n");
}

char pedirConfirmacion (Passenger pasajero,int tipo,eTipoPasajero tiposPasajeros[],int tamT,eEstadoVuelo estadosVuelos[],int tamE){
	char respuesta = 'n';
	if(!pasajero.isEmpty && tiposPasajeros && tamT>0 && estadosVuelos && tamE > 0){
		if(tipo==MODIFICAR){
			printf("Desea modificar el siguiente pasajero ? s-n \n\n");
		}else
			printf("Desea borrar el siguiente pasajero ? s-n \n\n");

		printf("ID\t\tNombre\t\tApellido\t\t    Precio\t\tTipo de Pasajero\t\tCodigo de vuelo\t\tEstado de vuelo\n");
		printf("-------------------------------------------------------------------------------------------------------------------------------"
				"------------------------\n");
		printPassengerData(pasajero,tiposPasajeros,tamT,estadosVuelos,tamE);
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



int pedirDatosAlta (Passenger* pasajero,eTipoPasajero tiposPasajeros[],int tamT,eEstadoVuelo estadosV[],int tamE){
	int todoOk = 0;

	if(pasajero && tiposPasajeros && tamT>0 && estadosV && tamE > 0){

		pedirNombre(pasajero->nombre);
		pedirApellido(pasajero->apellido);
		pedirPrecio(&pasajero->precio);
		pedirCodigoVuelo(pasajero->codigoVuelo);
		pedirTipoPasajero(tiposPasajeros,tamT,&pasajero->idTipoPasajero);
		pedirEstadoVuelo(estadosV,tamE,&pasajero->idEstadoVuelo);
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

