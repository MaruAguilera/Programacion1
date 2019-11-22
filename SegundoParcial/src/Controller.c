#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "utn.h"
#include "Cachorros.h"

int controller_loadFromText(char* path , LinkedList* pArrayList)
{
    int retorno=-1;
    FILE* pArchivo;
    pArchivo=fopen(path,"r");


    if(pArchivo!=NULL && parser_PuppyFromText(pArchivo,pArrayList)==0)
    {

        retorno=0;
    }
    fclose(pArchivo);
    return retorno;
}


int controller_ListCachorros(LinkedList* pArrayList)
{
    int retorno=-1;
    int i;
    int len=ll_len(pArrayList);
    int idAuxiliar;
    char nombreAux[128];
    int diasAux;
    char razaAux[128];
    char reservadoAux[128];
    char generoAux[128];
    Cachorros*pEmployeeAuxiliar;

    if(pArrayList!=NULL)
        {
            for(i=0;i<len;i++)
                {
                    pEmployeeAuxiliar=(Cachorros*)ll_get(pArrayList,i);
                    if(pEmployeeAuxiliar!=NULL)
                        {
                    		Cachorros_getId(pEmployeeAuxiliar,&idAuxiliar);
                    		Cachorros_getNombre(pEmployeeAuxiliar,&nombreAux);
                    		Cachorros_getDias(pEmployeeAuxiliar,&diasAux);
                    		Cachorros_getRaza(pEmployeeAuxiliar,&razaAux);
                    		Cachorros_getReservado(pEmployeeAuxiliar,&reservadoAux);
                    		Cachorros_getGenero(pEmployeeAuxiliar,&generoAux);

                            printf("\n%d -- %s -- %d-- %s -- %s-- %s \n",idAuxiliar,nombreAux,diasAux,razaAux,reservadoAux,generoAux);
                            retorno=0;
                        }
                }
        }

    return retorno;
}

int controller_filtro(LinkedList* pArrayList){
print("entra?");
	if(pArrayList != NULL){

			ll_filter(pArrayList, em_calcularDiasCachorros);
		}
		return 0;
}

