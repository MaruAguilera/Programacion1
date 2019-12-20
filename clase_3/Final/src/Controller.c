#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "utn.h"
#include "bicicleta.h"

int controller_listBicicleta(LinkedList* pArrayList);

int controller_loadFromText(char* path , LinkedList* pArrayList)
{
	//char nombreDeArchivo[20];

//	("Ingrese el nombre del archivo: ");


    int retorno=-1;
    FILE* pArchivo;
    pArchivo=fopen(path,"r");
  //  printf("\nabrio el coso");

    if(pArchivo!=NULL && parser_bicicletaFromText(pArchivo,pArrayList)==0)
    {
    	//printf("\nNO NULL");
        retorno=0;
    }
    fclose(pArchivo);
    return retorno;
}

int controller_listBicicleta(LinkedList* pArrayList)
{
	//	esta asi pq no tiene getter y setter, cambiar
		Node* nAux = pArrayList->pFirstNode;
		bicicleta* bicicleta = nAux->pElement;

//		controller_MAP(pArrayList);

		for(int i=0; i<ll_len(pArrayList); i++){
//			char idTipoAux[20];
//			if(bicicleta->idTipo == 1)
//			{
//				strcpy(idTipoAux, "DESKTOP");
//			}
//			if(bicicleta->idTipo == 2)
//			{
//				strcpy(idTipoAux, "LAPTOP");
//			}
			printf("ID_BIKE: %d\n1.NOMBRE: %s\n2.TIPO: %s\n3.TIEMPO: %d\n4.VELOCIDAD: %f\n\n", bicicleta->ID_BIKE, bicicleta->NOMBRE, bicicleta->TIPO, bicicleta->TIEMPO, bicicleta->VELOCIDAD);

			if(nAux->pNextNode != NULL){
				nAux = nAux->pNextNode;
				bicicleta = nAux->pElement;
			}
		}
		return 1;
}

int controller_velocidadPromedio(LinkedList* pArrayList)
{
	int retorno = -1;
		printf("\nVELOCIDAD PROMEDIO: \n");
		if(pArrayList != NULL)
		{
			if(ll_map(pArrayList, bicicleta_velocidadPromedio) == 0)
			{
				controller_listBicicleta(pArrayList);
				retorno = 0;
			}
		}
	return retorno;
}

int controller_filter(LinkedList* pArrayList)
{
	int retorno=-1;
	printf("\nFILTRO DE COMPUTADORAS BICI: \n");
	if(pArrayList != NULL)
	{
		controller_listBicicleta(ll_filter(pArrayList, bici_BMX));
		retorno=0;
	}
	return retorno;
}



int controller_savePerrosAsText(FILE* pFile , LinkedList* pArrayList) {
    int ret = 0;
    bicicleta* auxComputer;

    int i, len;

    if(pArrayList != NULL && pFile != NULL) {
    	fprintf(pFile,"\n ID,Descripcion,Precio,idTipo,Oferta \n");
    	len = ll_len(pArrayList);

    	for(i = 0; i < len; i++) {
    		auxComputer = (bicicleta*)ll_get(pArrayList, i);



    		fprintf("ID_BIKE: %d\n1.NOMBRE: %s\n2.TIPO: %s\n3.TIEMPO: %d\n4.VELOCIDAD: %f\n\n", auxComputer->ID_BIKE, auxComputer->NOMBRE, auxComputer->TIPO, auxComputer->TIEMPO, auxComputer->VELOCIDAD);
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




