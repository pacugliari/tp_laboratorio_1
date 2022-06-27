/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/Pagina.h"


int menu();
void ejecutarPruebas();

int main(void)
{
	//PROYECTO INICIALMENTE CREADO EN CODEBLOCKS Y LUEGO PASADO A ECLIPSE
	setvbuf(stdout, NULL, _IONBF, 0);//AGREGADO PARA EVITAR BUG CONSOLA ECLIPSE
    int respuesta;
    do{
        switch(respuesta=menu()){
            case 1:
                ejecutarPruebas();
            break;
            case 2:
                ejecutarFunciones();
            break;
            case 3:
                printf("Saliendo...\n");
            break;
        }
        system("pause");
        system("cls");
    }while(respuesta!=3);


    return 0;
}

int menu(){
    int respuesta;

	printf("\t\t\t\t\t\t***Trabajo Practico numero 4***\n");
	printf("\t\t\t\t\t\t  Programacion I- Laboratorio I\n");
	printf("\t\t\t\t\t  Tecnicatura Superior en Programacion UTN-FRA \n");
	printf("Alumno: Pablo Cugliari | Division: 1A \n");
	printf("-------------------------------------------------------------------------------------------------------------------\n");
    printf("Menu: \n");
    printf("\t1. Ejecutar pruebas unitarias.\n");
    printf("\t2. Ejecutar todas las funciones del LinkedList.\n");
    printf("\t3. Salir \n\n");
	printf("--------------------------------------------------------------------------------------------------------------------\n");
	printf("Ingrese opcion: ");

    scanf("%d",&respuesta);
    fflush(stdin);


    return respuesta;

}

void ejecutarPruebas(){
     startTesting(1);  // ll_newLinkedList USADO
     startTesting(2);  // ll_len USADO
     startTesting(3);  // getNode - test_getNode USADO
     startTesting(4);  // addNode - test_addNode USADO
     startTesting(5);  // ll_add USADO
     startTesting(6);  // ll_get USADO
     startTesting(7);  // ll_set USADO
     startTesting(8);  // ll_remove USADO
     startTesting(9);  // ll_clear USADO
     startTesting(10); // ll_deleteLinkedList USADO
     startTesting(11); // ll_indexOf USADO
     startTesting(12); // ll_isEmpty USADO
     startTesting(13); // ll_push USADO
     startTesting(14); // ll_pop USADO
     startTesting(15); // ll_contains USADO
     startTesting(16); // ll_containsAll USADA
     startTesting(17); // ll_subList USADO
     startTesting(18); // ll_clone USADO
     startTesting(19); // ll_sort USADO

}













