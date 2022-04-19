/*
 * main.c
 *
 *  Created on: 18 abr. 2022
 *      Author: PACugliari
 */

#include "../Headers/interface.h"


int main(){
	setvbuf(stdout, NULL, _IONBF, 0);//AGREGADO PARA EVITAR BUG CONSOLA ECLIPSE

	ejecutarPrograma();

	return 0;
}
