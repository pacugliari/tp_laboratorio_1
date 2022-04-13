/*
 * calculos.c
 *
 *  Created on: 6 abr. 2022
 *      Author: PACugliari
 */


#include "../Headers/calculos.h"

#define BITCOIN 4606954.55
#define KILOMETROS_FORZADOS 7090
#define PRECIO_LATAM_FORZADO 159339
#define PRECIO_AERO_FORZADO 162965

float calcularBitCoin(float unPrecio){
	return unPrecio/BITCOIN;
}

float calcularUnitario(float unPrecio,float kilometros){
	return unPrecio/kilometros;
}


int calcularCostos(float precioAerolineas,float precioLatam,float kilometrosIngresados,float* preciosCalculados){
	int retorno=0;
	if(precioAerolineas && precioLatam && kilometrosIngresados){
		//AEROLINEAS
		preciosCalculados [0] = precioAerolineas * (0.9);
		preciosCalculados [1] = precioAerolineas * (1.25);
		preciosCalculados [2] = calcularBitCoin(precioAerolineas);
		preciosCalculados [3] = calcularUnitario(precioAerolineas,kilometrosIngresados);

		//LATAM
		preciosCalculados [4] = precioLatam * (0.9);
		preciosCalculados [5] = precioLatam * (1.25);
		preciosCalculados [6] = calcularBitCoin(precioLatam);
		preciosCalculados [7] = calcularUnitario(precioLatam,kilometrosIngresados);

		//DIFERENCIA DE PRECIO
		if(precioAerolineas > precioLatam){
			preciosCalculados [8] = precioAerolineas - precioLatam;
		}else{
			preciosCalculados [8] = precioLatam - precioAerolineas;
		}

		if(kilometrosIngresados != KILOMETROS_FORZADOS ){
			printf("Se calcularon todos los costos \n\n");
		}
		retorno = 1; //CALCULO EXITOSO
	}else{
		if(!precioAerolineas){
			printf("No se ingreso el precio de Aerolineas \n");
		}
		if(!precioLatam){
			printf("No se ingreso el precio de Latam \n");
		}

		if(!kilometrosIngresados){
			printf("No se ingreso los kilometros \n");
		}
		printf("\n");
		retorno = 0;
	}
	return retorno;
}


void cargaForzada(float* precioAerolineas,float* precioLatam,float* kilometrosIngresados){
	*precioAerolineas = PRECIO_AERO_FORZADO;
	*precioLatam = PRECIO_LATAM_FORZADO;
	*kilometrosIngresados = KILOMETROS_FORZADOS;

	printf("Se realizo una carga forzada \n\n");


}

void reiniciarValores (float* precioAerolineas,float* precioLatam,float* kilometrosIngresados,int* esCorrecto){
	if(*esCorrecto){
		*precioAerolineas = *precioLatam = *kilometrosIngresados =*esCorrecto = 0;
	}
}

