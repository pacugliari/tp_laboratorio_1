#include "../inc/Empleado.h"
#include "../inc/Pagina.h"
#include "../inc/LinkedList.h"
#include <stdio.h>
#include <stdlib.h>


void ejecutarFunciones(){
    int pagina = 1;
    LinkedList* listaArch = cargarArchivoEmpleados();//dentro se hace ll_newLinkedList
    if(listaArch){
        pagina1(&pagina,listaArch);
        pagina2(&pagina,listaArch);
        pagina3(&pagina,listaArch);
        system("cls");
        printf("FIN DE LA EJECUCION DE FUNCIONES \n");
        destroy_ListaEmpleados(listaArch);
        ll_deleteLinkedList(listaArch);//ll_deleteLinkedList
    }

}

int mostrarLista(LinkedList* lista){
    int todoOk = 0;
    int tam;
    eEmpleado* empleado;

    if(lista){
        tam = ll_len(lista);//ll_len
        for(int i=0;i<tam;i++){
            printf("Indice: %d\t",i);
            empleado = ll_get(lista,i);//ll_get
            mostrarEmpleado(empleado);
        }
        todoOk = 1;
    }
    return todoOk;
}

int compararListas(LinkedList* original,LinkedList* clonada){
    int todoOk = 0;
    eEmpleado* empleado;
    if(original && clonada){
        if(ll_containsAll(original,clonada)){//ll_containsAll
            printf("La lista clonada tiene todos los elementos de la sub-lista  \n");
        }else{
            printf("La lista clonada no tiene todos los elementos de la sub-lista  \n");
            printf("Busco los elementos que no esta en la lista clonada \n\n");
            for(int i=0;i<ll_len(clonada);i++){//ll_len
                empleado = ll_get(clonada,i);//ll_get
                if(!ll_contains(original,empleado)){//ll_contains
                    mostrarEmpleado(empleado);
                }
            }
        }
        todoOk = 1;
    }
    return todoOk;
}


void pagina1(int* pagina,LinkedList* lista){
     eEmpleado* empleado;
     Node* nodo;
     int tamanio ;
     LinkedList* lista1 = ll_clone(lista);//ll_clone

    /*
    CARGO DE UN ARCHIVO DE PRUEBA DE EMPLEADOS EN UNA LISTA USANDO ADD, Y NEW, LUEGO RECORRO LA LISTA USANDO EMPTY,POP Y LIBERANDO LA MEMORIA
    CON DELETE
    */
    system("cls");
    printf("-------------------------------------------------------------  \n");
    printf("PAGINA ACTUAL: %d \n",(*pagina));
    printf("-------------------------------------------------------------  \n");
    printf("Funciones usadas: \n");
    printf("\t-test_addNode\n");
    printf("\t-test_getNode\n");
    printf("\t-ll_remove\n");
    printf("\t-ll_newLinkedList\n");
    printf("\t-ll_pop\n");
    printf("\t-ll_clone\n");
    printf("\t-ll_add\n");
    printf("\t-ll_isEmpty\n");
    printf("\t-ll_len\n");
    printf("\t-ll_deleteLinkedList\n");
    printf("-------------------------------------------------------------  \n");
    printf("OBTENGO UN NODO Y LO VUELVO AGREGAR USANDO GET/ADD NODE \n");
    printf("-------------------------------------------------------------  \n");
    nodo = (Node*) test_getNode(lista1,0);//test_getNode
    empleado = nodo->pElement;
    mostrarEmpleado(empleado);
    ll_remove(lista1,0);//ll_remove
    empleadoSetNombre(empleado,"test_getNode");
    empleadoSetApellido(empleado,"test_addNode");
    mostrarEmpleado(empleado);
    nodo->pElement = empleado;
    test_addNode(lista1,ll_len(lista1),empleado);//test_addNode
    printf("-------------------------------------------------------------  \n");
    tamanio = ll_len(lista1);//ll_len
    printf("Cantidad de empleados: %d \n",tamanio);

    mostrarEncabezadoEmpleado();
    while(!ll_isEmpty(lista1)){//ll_isEmpty
        empleado = ll_pop(lista1,0);//ll_pop
        mostrarEmpleado(empleado);
    }
    printf("-------------------------------------------------------------  \n");
    tamanio = ll_len(lista1);//ll_len
    printf("Como recorri la lista haciendo POP queda el tamanio en cero \n");
    printf("Cantidad de empleados: %d \n",tamanio);
    ll_deleteLinkedList(lista1);//ll_deleteLinkedList
    printf("-------------------------------------------------------------  \n");
    printf("Presione alguna tecla para pasar a la siguiente pagina \n");
    system("pause");
    system("cls");
    (*pagina)++;
    //-------------------------------------
}



void pagina2(int* pagina,LinkedList* lista){
    LinkedList* lista1 = ll_clone(lista);//ll_clone
    LinkedList* lista3 = ll_subList(lista1,10,20);//ll_subList
    LinkedList* lista2 = ll_clone(lista3);//ll_clone

    printf("------------------------------------------------------------------------  \n");
    printf("PAGINA ACTUAL: %d \n",(*pagina));
    printf("------------------------------------------------------------------------  \n");
    printf("Funciones usadas: \n");
    printf("\t-ll_newLinkedList\n");
    printf("\t-ll_clone\n");
    printf("\t-ll_add\n");
    printf("\t-ll_subList\n");
    printf("\t-ll_len\n");
    printf("\t-ll_get\n");
    printf("\t-ll_sort\n");
    printf("\t-ll_deleteLinkedList\n");

    printf("------------------------------------------------------------------------  \n");
    printf("LISTA ORIGINAL \n");
    printf("------------------------------------------------------------------------  \n");
    mostrarLista(lista1);

    printf("------------------------------------------------------------------------  \n");
    printf("LISTA3: CLONADA DE ORIGINAL DESDE INDICE 10 HASTA 20 \n");
    printf("------------------------------------------------------------------------  \n");
    mostrarLista(lista3);

    printf("------------------------------------------------------------------------  \n");
    printf("LISTA2: CLONADA DE LISTA3 \n");
    printf("------------------------------------------------------------------------  \n");
    mostrarLista(lista2);

    printf("------------------------------------------------------------------------  \n");
    printf("LISTA2: ORDENADA POR ID MANERA ASCENDENTE\n");
    printf("------------------------------------------------------------------------  \n");
    ll_sort(lista2,empleadoComparaLegajo,1);
    mostrarLista(lista2);


    printf("------------------------------------------------------------------------  \n");
    printf("Presione alguna tecla para pasar a la siguiente pagina \n");
    system("pause");
    system("cls");
    (*pagina)++;
    ll_deleteLinkedList(lista1);//ll_deleteLinkedList
    ll_deleteLinkedList(lista2);//ll_deleteLinkedList
    ll_deleteLinkedList(lista3);//ll_deleteLinkedList
    //-------------------------------------

}




void pagina3(int* pagina,LinkedList* lista){
    LinkedList* lista1 = ll_clone(lista);//ll_clone
    LinkedList* lista2 = ll_subList(lista1,0,10);//ll_subList
    int indice1;
    int indice2;
    eEmpleado* empleado1;
    eEmpleado* empleado2;

    printf("------------------------------------------------------------------------  \n");
    printf("PAGINA ACTUAL: %d \n",(*pagina));
    printf("------------------------------------------------------------------------  \n");
    printf("Funciones usadas: \n");
    printf("\t-ll_newLinkedList\n");
    printf("\t-ll_get\n");
    printf("\t-ll_add\n");
    printf("\t-ll_indexOf\n");
    printf("\t-ll_len\n");
    printf("\t-ll_set\n");
    printf("\t-ll_remove\n");
    printf("\t-ll_push\n");
    printf("\t-ll_clone\n");
    printf("\t-ll_containsAll\n");
    printf("\t-ll_contains\n");
    printf("\t-ll_isEmpty\n");
    printf("\t-ll_clear\n");
    printf("\t-ll_deleteLinkedList\n");
    printf("------------------------------------------------------------------------  \n");
    printf("MUESTRO EMPLEADO DEL INDICE 5 Y 6\n");
    printf("------------------------------------------------------------------------  \n");
    empleado1 = ll_get(lista2,5);//ll_get
    empleado2 = ll_get(lista2,6);//ll_get
    indice1 =ll_indexOf(lista2,empleado1);//ll_indexOf
    indice2 =ll_indexOf(lista2,empleado2);//ll_indexOf
    printf("Indice: %d\t",indice1);
    mostrarEmpleado(empleado1);
    printf("Indice: %d\t",indice2);
    mostrarEmpleado(empleado2);
    printf("------------------------------------------------------------------------  \n");
    printf("SET EMPLEADO 6,REMOVE + PUSH EMPLEADO 5\n");
    printf("------------------------------------------------------------------------  \n");
    empleadoSetNombre(empleado2,"'SETEADO'");
    empleadoSetApellido(empleado2,"'SETEADO'");
    ll_set(lista2,indice2,empleado2);//ll_set
    printf("Indice: %d\t",indice2);
    mostrarEmpleado(empleado2);
    ll_remove(lista2,indice1);//ll_remove
    empleadoSetNombre(empleado1,"'PUSHEADO'");
    empleadoSetApellido(empleado1,"'PUSHEADO'");
    ll_push(lista2,ll_len(lista2),empleado1);//ll_push Y ll_len
    printf("------------------------------------------------------------------------  \n");
    printf("SUBLISTA CON SET+REMOVE+PUSH\n");
    printf("------------------------------------------------------------------------  \n");
    mostrarLista(lista2);

    printf("------------------------------------------------------------------------  \n");
    printf("CLONE DE SUBLISTA+ COMPARACION LISTA CLONADA\n");
    printf("------------------------------------------------------------------------  \n");
    LinkedList* lista3 = ll_clone(lista2);//ll_clone
    compararListas(lista2,lista3);

    printf("------------------------------------------------------------------------  \n");
    printf("BORRO ELEMENTO DE SUBLISTA,BUSCO FALTANTES\n");
    printf("------------------------------------------------------------------------  \n");
    ll_pop(lista2,0);//ll_pop
    ll_pop(lista2,8);//ll_pop
    compararListas(lista2,lista3);

    printf("------------------------------------------------------------------------  \n");
    printf("CLEAR DE SUBLISTA: ");
    ll_clear(lista2);//ll_clear
    if(ll_isEmpty(lista2)){//ll_isEmpty
        printf("La lista se vacio \n");
    }else
        printf("La lista se encuentra con datos \n");

    printf("------------------------------------------------------------------------  \n");
    printf("Presione alguna tecla para pasar a la siguiente pagina \n");
    system("pause");
    system("cls");
    ll_deleteLinkedList(lista1);//ll_deleteLinkedList
    ll_deleteLinkedList(lista2);//ll_deleteLinkedList
    ll_deleteLinkedList(lista3);//ll_deleteLinkedList
    //-------------------------------------

}
