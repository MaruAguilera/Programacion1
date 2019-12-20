#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "bicicleta.h"
//#include "parser.h"


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return intc
 *
 */
int parser_bicicletaFromText(FILE* pFile , LinkedList* pArrayListBicicleta)
{
	//printf("\nEntro al parser");
    int retorno=-1;

    char bufferID_BIKE[20];
    char bufferNOMBRE[20];
    char bufferTIPO[20];
    char bufferTIEMPO[20];

    int count = 0;
    bicicleta* auxiliarPunteroBicicleta;

    while(feof(pFile)==0)
    {
        if (fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferID_BIKE,bufferNOMBRE,bufferTIPO,bufferTIEMPO)==4)
        {
        	if(count > 0) {
        		auxiliarPunteroBicicleta = new_bicicletaConParametros(bufferID_BIKE, bufferNOMBRE, bufferTIPO, bufferTIEMPO);
        		ll_add(pArrayListBicicleta,auxiliarPunteroBicicleta);
        		retorno=0;
        	}
            count++;
        }
    }
    return retorno;
}
