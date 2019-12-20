#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "bike.h"
#include "parser.h"


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return intc
 *
 */
int parser_eComputerFromText(FILE* pFile , LinkedList* pArrayListeComputer)
{
	//printf("\nEntro al parser");
    int retorno=-1;

    char bufferID_Computer[20];
    char bufferDescription[20];
    char bufferPrecio[20];
    char bufferIdTipo[20];

    int count = 0;
    Participante* auxiliarPunteroEcomputer;

    while(feof(pFile)==0)
    {
        if (fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferID_Computer,bufferDescription,bufferPrecio,bufferIdTipo)==4)
        {
        	if(count > 0) {
        		auxiliarPunteroEcomputer = new_participanteConParametros(bufferID_Computer, bufferDescription, bufferPrecio, bufferIdTipo);
        		ll_add(pArrayListeComputer,auxiliarPunteroEcomputer);
        		retorno=0;
        	}
            count++;
        }
    }
    return retorno;
}
