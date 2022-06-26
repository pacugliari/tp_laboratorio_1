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
			system("cls");
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
		printf("Ingrese el nombre del pasajero: ");
		gets(nombre);
		fflush(stdin);
		strlwr(nombre);
		nombre[0]=toupper(nombre[0]);
		while((strlen(nombre) >50  || strlen(nombre)<=1) || !esValidoNombreOApellido(nombre)){
			printf("Error en nombre,ingrese un nombre valido: ");
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
		strlwr(apellido);
		apellido[0]=toupper(apellido[0]);
		while((strlen(apellido) >50 || strlen(apellido)<=1) || !esValidoNombreOApellido(apellido)){
			printf("Error en apellido,ingrese un apellido valido: ");
			gets(apellido);
			fflush(stdin);
		}
	}else
		printf("Error en parametro pedirApellido \n");
}

int esCodigoVueloValido(char* cadena){

	int todoOk = 0;
	int tam = strlen(cadena);
	if(cadena && tam>0){
		todoOk=1;
		char cadenaAux[tam+1];
		strcpy(cadenaAux,cadena);
		strlwr(cadenaAux);
		for(int i=0;i<tam;i++){
			if((cadenaAux[i] < '0' || cadenaAux[i] > '9') && (cadenaAux[i] < 'a' || cadenaAux[i] > 'z')){
				todoOk = 0;
				break;
			}
		}
	}
	return todoOk;
}

int esPrecioValido (char *cadena) {
	int longitud = strlen(cadena);
	int i;
	int haEncontradoElPunto = 0;
	int todoOk = 0;
	if(cadena && longitud > 0){
		todoOk = 1;
		for (i = 0; i < longitud; i++) {
			if (cadena[i] == '.') {
				if (haEncontradoElPunto) {
					todoOk=  0;
				} else {
					haEncontradoElPunto = 1;
				}
			}
			if (!isdigit(cadena[i]) && cadena[i] != '.')
				todoOk=  0;
		}
			if(!todoOk){
				printf("Solo se permite digitos 0-9 o '.' para el precio \n");
			}
	}
	return todoOk;
}

void pedirPrecio (float* precio){
	if(precio){
		char precioAux[10];
		printf("Ingrese el precio del vuelo $: ");
		gets(precioAux);
		fflush(stdin);
		while((atof(precioAux) < 0 || atof (precioAux)> 1000000) || !esPrecioValido(precioAux)){
			printf("Error en precio, ingrese un precio valido $: ");
			gets(precioAux);
		}
		*precio = atof(precioAux);
	}else
		printf("Error en parametro pedirPrecio \n");
}


void pedirTipoPasajero (int* pId,eTipoPasajero tiposPasajeros[],int tamT){
	if(pId && tiposPasajeros && tamT){
		mostrarTiposPasajeros(tiposPasajeros,tamT);
		printf("Ingrese el ID del tipo de pasajero: ");
		scanf("%d",pId);
		fflush(stdin);

		while(!validarTipoPasajero (tiposPasajeros,tamT,*pId)){
			printf("Error en la ID del tipo de pasajero,vuelva a ingresar: ");
			scanf("%d",pId);
			fflush(stdin);
		}
	}else
		printf("Error en los parametros de pedirTipoPasajero \n");
}

void pedirCodigoVuelo(char codigoVuelo[]){
	if(codigoVuelo){
		printf("Ingrese el codigo de vuelo del pasajero: ");
		gets(codigoVuelo);
		fflush(stdin);
		strupr(codigoVuelo);
		while(strlen(codigoVuelo) >9 || !esCodigoVueloValido(codigoVuelo)){
			printf("Error en codigo de vuelo,ingrese un codigo de vuelo valido: ");
			gets(codigoVuelo);
			fflush(stdin);
		}
	}else
		printf("Error en parametros de pedirCodigoVuelo \n");
}

void pedirEstadoVuelo(int* estadoVuelo){
	if(estadoVuelo){
		printf("Ingrese el estado del vuelo (1) ACTIVO (2) INACTIVO: ");
		scanf("%d",estadoVuelo);
		fflush(stdin);
		while((*estadoVuelo) != 1 && (*estadoVuelo) != 2){
			printf("Error en estado de vuelo,ingrese un estado del vuelo valido: ");
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
		pedirTipoPasajero(&pasajero->typePassenger,tiposPasajeros,tamT);
		pedirEstadoVuelo(&pasajero->statusFlight);
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
	char respuesta;
	do{
		printf("A) Listado de los pasajeros ordenados alfabeticamente por Apellido y Tipo de pasajero \n");
		printf("B) Total y promedio de los precios de los pasajes, y cuantos pasajeros superan el precio promedio. \n");
		printf("C) Listado de los pasajeros por Codigo de vuelo y estados de vuelos 'ACTIVO'\n");
		printf("D) Salir \n\n");
		fflush(stdin);
		scanf("%c",&respuesta);
		fflush(stdin);
		respuesta = toupper(respuesta);
		printf("\n");
		if(respuesta < 'A' && respuesta > 'D'){
			printf("Error en la opcion del menu, vuelva a ingresar \n");
		}
	}while (respuesta <'A' || respuesta > 'D');
	return respuesta;
}

int esValidoNombreOApellido (char* cadena){
	int todoOk = 1;

	if(cadena){
		char cadenaAux[strlen(cadena)+1];
		strcpy(cadenaAux,cadena);
		strlwr(cadenaAux);
		for(int i=0;i<strlen(cadenaAux);i++){
			if((cadenaAux [i] < 97 || cadenaAux [i] > 122) && (cadenaAux[i] != ' ')){
				printf("Solo se permite digitos a-z o A-Z para nombre/apellido \n");
				todoOk = 0;
				break;
			}
		}
	}
	return todoOk;
}
