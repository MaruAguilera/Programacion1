/*
 ============================================================================
 Name        : segundoParcialRecu.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "ControllerComputer.h"
#include "Computer.h"
#include "parser.h"
#include "utn.h"

int main(void) {

	LinkedList* listaComputadoras= ll_newLinkedList();

	int opcion=0;

	do
	{
		utn_getIntConSigno("\nSeleccione opcion:  ","Opcion invalida",1,sizeof(int),1,11,1,&opcion);

		switch(opcion)
		{
			case 1:
				if (controller_loadFromText("/home/alumno/Documentos/datos_Fin.csv",listaComputadoras)==0)
				{
					printf("el archivo se abrio!!!!");
				}

				//controller_loadFromText("/home/alumno/Documentos/Marisa/segundoParcialRecu/datos_Fin.csv",listaComputadoras);
				break;
			/**case 2: controller_listCachorros(listaCachorros);
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
				*/
		}

	} while(opcion == 6);
}




