#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Ventas.h"
//#include "parser.h"


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	printf("\nEntro al parser");
    int retorno=-1;

    char bufferID_Venta[20];
    char bufferFecha_Venta[20];
    char bufferTipo_Foto[20];
    char bufferCantidad[20];
    char bufferPrecio_Unitario[20];
    char bufferCUIT_Cliente [30];
    int count = 0;
    Venta* auxiliarPunteroEmployee;

    while(feof(pFile)==0)
    {
        if (fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bufferID_Venta,bufferFecha_Venta,bufferTipo_Foto,bufferCantidad,bufferPrecio_Unitario,bufferCUIT_Cliente)==6)
        {


            auxiliarPunteroEmployee = venta_newConParametros(atoi(bufferID_Venta),bufferFecha_Venta,bufferTipo_Foto,atoi(bufferCantidad),atoi(bufferPrecio_Unitario),atoi(bufferCUIT_Cliente));
            count++;
            //printf("\nFSCANF %s", bufferCantidad);
            {
                ll_add(pArrayListEmployee,auxiliarPunteroEmployee);
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

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayList)
{

    int retorno=-1;
    Venta*pVentas;
    if(pArrayList!=NULL && pFile!=NULL)
    {
        do
        {
        	pVentas=venta_new();
            if(pVentas!=NULL)
            {
                fread(pVentas,sizeof(Venta	),1,pFile);
                ll_add(pArrayList,pVentas);
                retorno=0;
            }

    }while(!feof(pFile));
    }
    return retorno;
}
