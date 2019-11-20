#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "utn.h"
//#include "Controller.h"

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
