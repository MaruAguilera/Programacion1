#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "eComputer.h"

int main(void) {
	int opcionMenu;
		int salir = 0;
		LinkedList* listaComputer = ll_newLinkedList();
		LinkedList* listaComputerFiltrados = ll_newLinkedList();
		do
		{
			menu(&opcionMenu);
			switch(opcionMenu)
			{
				case 1:
					if(controller_loadFromText("/home/marisa/Desktop/Recuperatorio/src/data.csv",listaComputer)==0)
					{
						printf("\n Se abrio el archivo y se ordeno por idTipo\n");
					}else{
						printf("\nERROR\n");
					}


					break;
				case 2: //TIENE EL MAP ADENTRO
					if(controller_listComputer(listaComputer)==0){
						printf("\n se listaron correctamente");
					}else{
						printf("\n Error!");
					}
					break;
//				ESTO SOLO SI ME PIDEN ORDENAR Y LISTAR, PERO ESTE METODO ESTA EN EL
					//LOADFORMTEXT
					//case 3:
//					if(controller_orderComputer(listaComputer)==0){
//						printf("\n se ordeno correctamente");
//					}else{
//						printf("\n EROOR!");
//					}
//
//					break;
				case 4:
					controller_filterDesktop(listaComputer);
					break;
				case 5:

					listaComputerFiltrados = ll_filter(listaComputer,computer_desktop);
						printf("Calculando\n");

					if(listaComputerFiltrados != NULL) {
						if(controller_saveAsText("/home/marisa/Desktop/Recuperatorio/src/filtro.csv",listaComputerFiltrados) == 0) {
							printf("\nArchivo generado correctamente\n");
						} else {
							printf("Error generando archivo\n");
						}
					}
					break;
				case 6:
					printf("saliste");
					break;
			}
		} while(opcionMenu != 6);
}

void menu(int* opcionMenu)
{
	int opcionUsuario;
	printf("\n");
	printf("1. CARGARA ARCsHIVO\n");
	printf("2. LISTAR COMPUTADORAS\n");
	//printf("3. ORDENAR POR ID TIPO\n");
	//printf("4. MAP\n");
	printf("4. SOLO DESKTOP\n");
	printf("5. GUARDAR FILTRADOS\n");
	printf("6. SALIR\n");
	printf("**ELIGE UNA OPCION PARA CONTINUAR**");
	utn_getIntConSigno("\nSeleccione opcion: ","Opcion invalida",1,sizeof(int),1,11,1,&opcionUsuario);
	*opcionMenu = opcionUsuario;
}
