#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Computer.h"
#include "parser.h"


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_CompuFromText(FILE* pFile , LinkedList* pArrayList)
{
	printf("\nEntro al parser");
    int retorno=-1;

    char bufferID[20];
    char bufferDescripcion[20];
    char bufferprecio[20];
    char bufferIdTipo[20];
    char bufferOferta[20];

    int count = 0;
    Computadora* auxiliarPunteroComputadora;

    while(feof(pFile)==0)
    {
        if (fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferID,bufferDescripcion,bufferprecio,bufferIdTipo)==5)
        {


        	auxiliarPunteroComputadora = Computadora_newConParametros(atoi(bufferID),bufferDescripcion,atoi(bufferprecio),atoi(bufferIdTipo));
            count++;

            {
            	 //printf("llego hasta aca");
                ll_add(pArrayList,auxiliarPunteroComputadora);
                retorno=0;

            }

        }

    }
    printf("%d",retorno);
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

