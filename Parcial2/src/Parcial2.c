/*
 ============================================================================
 Name        : Parcial2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "Cachorros.h"
#include "Controller.h"

int main(void) {

	int opcionMenu;
	int salir = 0;
	LinkedList* listaCachorros = ll_newLinkedList();
	LinkedList* listaPerrosFiltrados = ll_newLinkedList();
	do
	{
		menu(&opcionMenu);
		switch(opcionMenu)
		{
			case 1: controller_loadFromText("/home/marisa/nuevoRepo/Programacion1/Parcial2/src/data.csv",listaCachorros);
				break;
			case 2: controller_listCachorros(listaCachorros);
				break;
			case 3:
				listaPerrosFiltrados = ll_filter(listaCachorros,cachorros_dias);
				                    printf("Calculando\n");

				                    if(listaPerrosFiltrados != NULL) {
										if(controller_saveAsText("/home/marisa/nuevoRepo/Programacion1/Parcial2/src/menosDe45Dias.csv",listaPerrosFiltrados) == 0) {
											printf("\nArchivo generado correctamente\n");
										} else {
											printf("Error generando archivo\n");
										}
				                    }

				//controller_listCachorrosCallejeros(listaCachorros);
				break;
			case 4: controller_listCachorrosDias(listaCachorros);
				break;
			case 5: controller_listCachorrosMachos(listaCachorros);
				break;
			case 6: salir = 1;
				break;
		}
	} while(salir != 1);
}

void menu(int* opcionMenu)
{
	int opcionUsuario;
	printf("\n");
	printf("1. CARGARA ARCHIVO\n");
	printf("2. LISTAR CACHORROS\n");
	printf("3. GERERAR LISTA DE CALLEJEROS\n");
	printf("4. FILTRAR MENORES DE 45 DIAS\n");
	printf("5. FILTRAR MACHOS\n");
	printf("6. SALIR\n");
	printf("**ELIGE UNA OPCION PARA CONTINUAR**");
	scanf("%d", &opcionUsuario);
	*opcionMenu = opcionUsuario;
}
