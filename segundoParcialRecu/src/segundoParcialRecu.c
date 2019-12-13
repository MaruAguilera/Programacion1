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
	LinkedList* listaFiltrados = ll_newLinkedList();

	int opcion=0;

	do

	{
		printf("/****************************************************\
		        	    	  \nMenu:\
		        	    	  \n1. Cargar Archivo\
		        	    	  \n2. lista ordenada\
		        	    	  \n\n3.imprime \
		        	    	  \n4. llmap\
		        	    	  \n5. ´filter\
		        	    	  \n6. Salir\
		        	    	  \n*****************************************************/");
		utn_getIntConSigno("\nSeleccione opcion:  ","Opcion invalida",1,sizeof(int),1,11,1,&opcion);

		switch(opcion)
		{
			case 1:
				controller_loadFromText("datos_Fin.csv",listaComputadoras);


				//controller_loadFromText("/home/alumno/Documentos/Marisa/segundoParcialRecu/datos_Fin.csv",listaComputadoras);
				break;
			case 2:
				controller_order(listaComputadoras);

				break;
			case 3:
				 controller_imprimerCompu(listaComputadoras);
				break;
			case 4:
				controller_listCompus(listaComputadoras);
				break;
			case 5:
				listaFiltrados = ll_filter(listaComputadoras,em_calculartipoId);
				                    printf("Calculando\n");

				                    if(listaFiltrados != NULL) {
										if(controller_saveAsText("listaFiltrados.ods",listaFiltrados) == 0) {
											printf("\nArchivo generado correctamente\n");
										} else {
											printf("Error generando archivo\n");
										}
				                    }

				break;

		}

	} while(opcion != 6);
}




