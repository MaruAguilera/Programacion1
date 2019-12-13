#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "utn.h"
#include "Computer.h"

int controller_loadFromText(char* path , LinkedList* pArrayList)
{
    int retorno=-1;
    FILE* pArchivo;
    pArchivo=fopen(path,"r");
    printf("\nabrio el coso");

    if(pArchivo!=NULL && parser_CompuFromText(pArchivo,pArrayList)==0)
    {
    	printf("\nNO NULL");
        retorno=0;
    }
    fclose(pArchivo);
    return retorno;
}



int controller_order(LinkedList* pArrayList)
{
	printf("\nLISTA DE COMPUTADORAS ORDENADAS POR IDTIPO \n");
	if(pArrayList != NULL)
	{
		if(ll_sort(pArrayList, compu_order, 1) == 0)
		{
			controller_imprimerCompu(pArrayList);
		}
	}

	return	0;
}


int controller_imprimerCompu(LinkedList* pArrayList)
{
    int retorno=-1;
    int i;
    int len=ll_len(pArrayList);
    int idAuxiliar;
    char descripcionAux[128];
    int precioAux;
    int idTipoAux;
    char ofertaAux[128];

    Computadora*pEmployeeAuxiliar;

    if(pArrayList!=NULL)
        {
            for(i=0;i<len;i++)
                {
                    pEmployeeAuxiliar=(Computadora*)ll_get(pArrayList,i);
                    if(pEmployeeAuxiliar!=NULL)
                        {
                    		Computadora_getId(pEmployeeAuxiliar,&idAuxiliar);
                    		Computadora_getDescripcion(pEmployeeAuxiliar,&descripcionAux);
                    		Computadora_getPrecio(pEmployeeAuxiliar,&precioAux);
                    		Computadora_getIdTipo(pEmployeeAuxiliar,&idTipoAux);
                    		//Computadora_getOferta(pEmployeeAuxiliar,&ofertaAux);

                    		if (idTipoAux==1) {

								char idTipoAux="DESKTOP";
							}else{
								char idTipoAux="LAPTOP";
							}


                            printf("\n%d -- %s -- %d-- %d -- \n",idAuxiliar,descripcionAux,precioAux,idTipoAux);
                            retorno=0;
                        }
                }
        }

    return retorno;
}

int controller_listCompus(LinkedList* pArrayList)
{
	printf("\nLISTA DEsktop DIAS\n");
	if(pArrayList != NULL)
	{
		controller_listCachorros(ll_filter(pArrayList, em_calculartipoId));
	}
	return 0;
}


