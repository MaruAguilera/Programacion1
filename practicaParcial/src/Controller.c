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
    	printf("\nNULL");
        retorno=0;
    }
    fclose(pArchivo);
    return retorno;
}

int controller_count(LinkedList* pArrayList)
{
	printf("\nEN EL CONTROLER COUNT");
	if(pArrayList != NULL){
		printf("\nla lista no es nula");
		ll_count(pArrayList, Ventas_Total_Count);
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
