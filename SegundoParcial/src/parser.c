#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Cachorros.h"
#include "parser.h"


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_PuppyFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	printf("\nEntro al parser");
    int retorno=-1;

    char bufferID_Cacchoro[20];
    char bufferNombre[20];
    char bufferDias[20];
    char bufferRaza[20];
    char bufferReservado[20];
    char bufferGenero [30];
    int count = 0;
    Cachorros* auxiliarPunteroCachorros;

    while(feof(pFile)==0)
    {
        if (fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bufferID_Cacchoro,bufferNombre,bufferDias,bufferRaza,bufferReservado,bufferGenero)==6)
        {


        	auxiliarPunteroCachorros = Cachorros_newConParametros(atoi(bufferID_Cacchoro),bufferNombre,atoi(bufferDias),bufferRaza,bufferReservado,bufferGenero);
            count++;
            //printf("\nFSCANF %s", bufferCantidad);
            {
                ll_add(pArrayListEmployee,auxiliarPunteroCachorros);
                retorno=0;
            }
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

