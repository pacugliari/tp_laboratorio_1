/*
 * main.c
 *
 *  Created on: 1 abr. 2022
 *      Author: PACugliari
 */


#include <stdio.h>
#include <stdlib.h>
#include "../Headers/menu.h"
#include "../Headers/calculos.h"

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);//AGREGADO PARA EVITAR BUG CONSOLA ECLIPSE
	float kilometrosIngresados=0;
	float precioAerolineas=0;
	float precioLatam=0;
	float preciosCalculados [9];
	char opcionVuelos;
	int esCorrectoCalculo=0;//1-SI, 0-NO
	int respuestaMenu;

	do{
		respuestaMenu = mostrarMenu();
		switch(respuestaMenu){
		case 1:
			kilometrosIngresados = obtenerKilometros();
		break;
		case 2:
			opcionVuelos=mostrarOpcionesVuelos();
			calcularPrecios (opcionVuelos,&precioLatam,&precioAerolineas);
		break;
		case 3:
			esCorrectoCalculo = calcularCostos(precioAerolineas,precioLatam,kilometrosIngresados,preciosCalculados);
		break;
		case 4:
			mostrarResultados(preciosCalculados,kilometrosIngresados,precioAerolineas,precioLatam,esCorrectoCalculo);
			reiniciarValores(&precioAerolineas,&precioLatam,&kilometrosIngresados,&esCorrectoCalculo);
		break;
		case 5:
			cargaForzada(&precioAerolineas,&precioLatam,&kilometrosIngresados);
			esCorrectoCalculo = calcularCostos(precioAerolineas,precioLatam,kilometrosIngresados,preciosCalculados);
			mostrarResultados(preciosCalculados,kilometrosIngresados,precioAerolineas,precioLatam,esCorrectoCalculo);
			reiniciarValores(&precioAerolineas,&precioLatam,&kilometrosIngresados,&esCorrectoCalculo);
		break;
		case 6:
			mostrarMensajeFinPrograma();
		break;
		default:
			mostrarMensajeErrorMenu();
		break;
		system("cls");
		}
	}while(respuestaMenu != 6);

	return 0;
}
