#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Computer.h"
#include "parser.h"

int parser_eComputerFromText(FILE* pFile , LinkedList* pArrayListeComputer)
{
	printf("\nEntro al parser");
    int retorno=-1;

    char bufferID_Computer[20];
    char bufferDescription[20];
    char bufferPrecio[20];
    char bufferIdTipo[20];
    char bufferOferta[20];
    int count = 0;
    Computadora* auxiliarPunteroEcomputer;

    while(feof(pFile)==0)
    {
        if (fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bufferID_Computer,bufferDescription,bufferPrecio,bufferIdTipo,bufferOferta)==5)
        {
        	if(count > 0) {
        		auxiliarPunteroEcomputer = Computadora_newConParametros(bufferID_Computer, bufferDescription, bufferPrecio, bufferIdTipo, bufferOferta);
        		ll_add(pArrayListeComputer,auxiliarPunteroEcomputer);
        		retorno=0;
        	}
            count++;
        }
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

//int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayList)
//{
//
//    int retorno=-1;
//    Venta*pVentas;
//    if(pArrayList!=NULL && pFile!=NULL)
//    {
//        do
//        {
//        	pVentas=venta_new();
//            if(pVentas!=NULL)
//            {
//                fread(pVentas,sizeof(Venta	),1,pFile);
//                ll_add(pArrayList,pVentas);
//                retorno=0;
//            }
//
//    }while(!feof(pFile));
//    }
//    return retorno;

