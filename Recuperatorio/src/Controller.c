#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "utn.h"
#include "eComputer.h"

int controller_listComputer(LinkedList* pArrayList);
int controller_MAP(LinkedList* pArrayList);
int controller_savePerrosAsText(FILE* pFile , LinkedList* pArrayList);

int controller_loadFromText(char* path , LinkedList* pArrayList)
{


    int retorno=-1;
    FILE* pArchivo;
    pArchivo=fopen(path,"r");
    //printf("\nabrio el coso");

    if(pArchivo!=NULL && parser_eComputerFromText(pArchivo,pArrayList)==0)
    {
    	controller_orderComputer(pArrayList); //ORDENA DIRECTAMENTE AL ABRIR EL ARCHIVO
    	//printf("\nNO NULL");
        retorno=0;
    }
    fclose(pArchivo);
    return retorno;
}

int controller_listComputer(LinkedList* pArrayList)
{
	Node* nAux = pArrayList->pFirstNode;
	eComputer* computer = nAux->pElement;
	int auxID;
	char auxDes[800];
	int auxPrecio;
	char idTipoAux[20];
	int AuxTipo;
	char auxOf [800];
	controller_MAP(pArrayList); //AL IMPRIMIR SE AGREGA DIRECTAMENTE OFERTA
		for(int i=0; i<ll_len(pArrayList); i++)
		{
			Computadora_getId(computer, &auxID);
			Computadora_getDescripcion(computer, auxDes);
			Computadora_getPrecio(computer, &auxPrecio);
			Computadora_getOferta(computer, auxOf);
			Computadora_getIdTipo(computer, &AuxTipo);

			if(AuxTipo == 1)
			{
				strcpy(idTipoAux, "DESKTOP");
			}
			if(AuxTipo == 2)
			{
				strcpy(idTipoAux, "LAPTOP");
			}



			printf("ID: %d\n1.Descripcion: %s\n2.Precio: %d\n3.idTipo: %s\n4.Oferta: %s\n\n",auxID, auxDes, auxPrecio, idTipoAux, auxOf);

			if(nAux->pNextNode != NULL){
				nAux = nAux->pNextNode;
				computer = nAux->pElement;
			}
		}
		return 0;
}

int controller_orderComputer(LinkedList* pArrayList)
{
	int retorno=-1;
	//printf("\nLISTA DE COMPUTADORAS ORDENADAS POR ID TIPO: \n");
	if(pArrayList != NULL)
	{
		if(ll_sort(pArrayList, computer_order_idTipo, 1) == 0)
		{
			retorno=0;
			//controller_listComputer(pArrayList); SI LA FUNCION LO AMERITA, IMPRIMO
		}
	}

	return	retorno;
}

int controller_MAP(LinkedList* pArrayList)
{
	int retorno=-1;

	if(pArrayList != NULL)
	{
		if(ll_map(pArrayList, computer_oferta) == 0)
		{
			retorno=0;
			//controller_listComputer(pArrayList); USAR SI TENGO Q IMPRIMIR MAP A PARTE
		}
	}
	return retorno;
}

int controller_filterDesktop(LinkedList* pArrayList)
{
	int retorno=-1;
	printf("\nFILTRO DE COMPUTADORAS DESKTOP: \n");
	if(pArrayList != NULL)
	{
		controller_listComputer(ll_filter(pArrayList, computer_desktop));
		retorno=0;
	}
	return retorno;
}

int controller_savePerrosAsText(FILE* pFile , LinkedList* pArrayList) {
    int ret = 0;
	eComputer* auxComputer;
    int auxId;
    char auxDescripcion[4096];
    int auxPrecio;
    int auxIdTipo;
    char auxOferta[4096];
    int i, len;

    if(pArrayList != NULL && pFile != NULL) {
    	fprintf(pFile,"\n ID,Descripcion,Precio,idTipo,Oferta \n");
    	len = ll_len(pArrayList);

    	for(i = 0; i < len; i++) {
    		auxComputer = (eComputer*)ll_get(pArrayList, i);
    		Computadora_getId(auxComputer, &auxId);
    		Computadora_getDescripcion(auxComputer, auxDescripcion);
    		Computadora_getPrecio(auxComputer, &auxPrecio);
    		Computadora_getIdTipo(auxComputer, &auxIdTipo);
    		Computadora_getOferta(auxComputer, auxOferta);


    		fprintf(pFile,"%d,%s,%d,%d,%s\n", auxId, auxDescripcion, auxPrecio, auxIdTipo, auxOferta);
    		ret++;
    	}
	fclose(pFile);
    }
    return ret;
}


int controller_saveAsText(char* fileName,LinkedList* pArrayList) {
	FILE*pArchivo;
	int retorno = -1;

	    if(fileName != NULL && pArrayList != NULL) {
	        pArchivo=fopen(fileName,"w");
	        if(pArchivo != NULL && controller_savePerrosAsText(pArchivo,pArrayList)) {
	            //fclose(pArchivo);
	            printf("\nGuardado exitoso en Texto");
	            retorno = 0;
	        } else {
	            printf("\nNo se pudo abrir el archivo");
	        }
	    }
	    return retorno;
}
