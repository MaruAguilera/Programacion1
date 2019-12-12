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
