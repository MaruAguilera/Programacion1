
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "Cachorros.h"
//#include "Controlador.h"

int main(void) {

//printf("INICIO\n");
LinkedList* listaCachorros=ll_newLinkedList();
//printf("LOAD FROM TEXT\n");
//controller_loadFromText("/home/marisa/data.csv",listaVentas);
//printf("\nANTES DE COTROLLER COUNT\n");
//controller_count(listaVentas);

//return 0;

int opcion;
char archivo [20];

	do {
		utn_getIntConSigno("\n\n1) Alta \n2) Modificar \n3) Baja \n4) Listar \n5) Ordenar \n6) Salir\n","\nError",1,sizeof(int),1,11,1,&opcion);

	switch (opcion) {
		case 1:
			printf("Ingrese el archivo a subir");
			//scanf("%s",&archivo);

			controller_loadFromText("/home/alumno/Marisa/cachorros.csv",listaCachorros);
			break;
		case 2:
			controller_ListCachorros(listaCachorros);
			break;
		case 3:
			controller_filtro(listaCachorros);
		default:
			break;
	}




	} while (opcion!=6);
}
