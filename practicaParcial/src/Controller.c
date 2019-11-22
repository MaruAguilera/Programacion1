#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "utn.h"
#include "Ventas.h"

int controller_loadFromText(char* path , LinkedList* pArrayList)
{   printf("entro al coso");
    int retorno=-1;
    FILE* pArchivo;
    pArchivo=fopen(path,"r");
    printf("\nabrio el coso");

    if(pArchivo!=NULL && parser_EmployeeFromText(pArchivo,pArrayList)==0)
    {
    	printf("\nNO NULL");
        retorno=0;
    }
    fclose(pArchivo);
    return retorno;
}

int controller_listVentas(LinkedList* pArrayList)
{
	printf("\nCONTROLLER LISTA DE VENTAS");
	Node* nAux = pArrayList->pFirstNode;
	Venta* venta = nAux->pElement;

	for(int i=0; i<ll_len(pArrayList); i++){
		printf("ID: %d\n1.Fecha: %s\n2.Foto: %s\n3.Cantidad: %d\n4.Precio: %d\n\n", venta->ID_Venta, venta->Fecha_Venta, venta->Tipo_Foto, venta->Cantidad, venta->Precio_Unitario);

		if(nAux->pNextNode != NULL){
			nAux = nAux->pNextNode;
			venta = nAux->pElement;
		}
	}
	return 1;
}

int controller_count(LinkedList* pArrayList)
{
	printf("\nEN EL CONTROLER COUNT");
//	Node* nAux = pArrayList->pFirstNode;
//	Venta* venta = nAux->pElement;

//	for(int i=0; i<ll_len(pArrayList); i++){
//
//	}
	int cantidadDeFotosTotales = 0;
	if(pArrayList != NULL){
		printf("\nla lista no es nula");
		cantidadDeFotosTotales = ll_count(pArrayList, Ventas_Total_Count);
		printf("\nTOALES: %d", cantidadDeFotosTotales);
	}
	return 0;
}

int controller_filtro(LinkedList* pArrayList){

	if(pArrayList != NULL){
			printf("\nla lista no es nula");
			ll_filter(pArrayList, em_calcularDiasCachorros);
		}
		return 0;
}
