#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "utn.h"
#include "bike.h"



int controller_loadFromText(char* path , LinkedList* pArrayList)
{


    int retorno=-1;
    FILE* pArchivo;
    pArchivo=fopen(path,"r");
    //printf("\nabrio el coso");

    if(pArchivo!=NULL && parser_eComputerFromText(pArchivo,pArrayList)==0)
    {
    	//controller_orderComputer(pArrayList); //ORDENA DIRECTAMENTE AL ABRIR EL ARCHIVO
    	//printf("\nNO NULL");
        retorno=0;
    }
    fclose(pArchivo);
    return retorno;
}

int controller_listComputer(LinkedList* pArrayList)
{
	Node* nAux = pArrayList->pFirstNode;
	Participante* participante = nAux->pElement;
	int auxID;
	char auxNom[800];
	int auxTiempo;
	char AuxTipo[20];
	int auxVel;
	//controller_MAP(pArrayList); //AL IMPRIMIR SE AGREGA DIRECTAMENTE OFERTA
		for(int i=0; i<ll_len(pArrayList); i++)
		{
			participante_getId(participante, &auxID);
			participante_getNombre(participante, auxNom);
			participante_getTiempo(participante, &auxTiempo);
			participante_getTipoBici(participante, AuxTipo);
			participante_getVelPromedio(participante,&auxVel);

//			if(AuxTipo == 1)
//			{
//				strcpy(idTipoAux, "DESKTOP");
//			}
//			if(AuxTipo == 2)
//			{
//				strcpy(idTipoAux, "LAPTOP");
//			}



			printf("ID: %d\n1.NOMBRE: %s\n2.TIEMPO: %d\n3.TipoBIKE: %s \n4.VELOCIDAD: %s\n\n",auxID, auxNom, auxTiempo, AuxTipo, auxVel);

			if(nAux->pNextNode != NULL){
				nAux = nAux->pNextNode;
				participante = nAux->pElement;
			}
		}
		return 0;
}
