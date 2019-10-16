#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "pedido.h"


int pedido_Inicializar(Pedido arrayPedido[], int size)                                    //cambiar fantasma
{
    int retorno=-1;
    if(arrayPedido!= NULL && size>0)
    {
        for(;size>0;size--)
        {
        	arrayPedido[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

int pedido_alta(Pedido arrayPedido[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(arrayPedido!=NULL && size>0 && contadorID!=NULL)
    {
        if(pedido_buscarEmpty(arrayPedido,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            arrayPedido[posicion].idPedido=*contadorID;
            arrayPedido[posicion].isEmpty=0;
            strcpy(arrayPedido[posicion].estado,"Pendiente");

            utn_getIntConSigno("\nIngrese el id de cliente ","\nError, id no valido",1,20,0,10,1,&arrayPedido[posicion].idCliente);
            utn_getIntConSigno("\nIngrese la cantidad de kg ","\nError, kg no valido",1,20,0,10,1,&arrayPedido[posicion].kgTotales);

            printf("\nidCliente %d", arrayPedido[posicion].idCliente);
            printf("\nkg Totales %d", arrayPedido[posicion].kgTotales);
            printf("\nESTADO %s", arrayPedido[posicion].estado);

            retorno=0;
        }
    }

    return retorno;
}

int pedido_buscarEmpty(Pedido arrayPedidos[], int size, int* posicion)
{
    int retorno=-1;
    int i;
    if(arrayPedidos!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(arrayPedidos[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
int pedido_listar(Pedido arrayPedidos[], int size)
{
    int retorno=-1;
    int i;
    if(arrayPedidos!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(arrayPedidos[i].isEmpty==1){continue;}

            else{
                printf("\nidCliente %d", arrayPedidos[i].idCliente);
                printf("\nkg Totales %d", arrayPedidos[i].kgTotales);
                printf("\nESTADO %s", arrayPedidos[i].estado);

            }

        }
        retorno=0;
    }
    return retorno;
}

int pedido_modificar(Pedido arrayPedidos[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    char opcion;
    if(arrayPedidos!=NULL && sizeArray>0)
    {
        utn_getIntSinSigno("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
        if(pedido_buscarID(arrayPedidos,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {



            printf("\nidCliente %d", arrayPedidos[posicion].idCliente);
            printf("\nkg Totales %d", arrayPedidos[posicion].kgTotales);
            printf("\nESTADO %s", arrayPedidos[posicion].estado);

           printf("\n#####################################################\n");



                if(utn_getChar("\nSeleccione la cantidad de kg: \nA:Direccion \nB:Localidad \nC:Salir ","\nError ",'A','B',1,&opcion)==-1)
                {
                	printf("Letra Invalida");
                }
                else{
            		utn_getIntSinSigno("\n\nIngrese el tipo de plastico y la cantidad de su residuo","\nError, numero invalido",1,sizeof(int),1,8,1,&opcion);


				/*	switch(opcion)
					{
						case 'A':
							utn_getString("\nIngrese la nueva direccion","\nError, nombre no valido",1,TEXT_SIZE,5,&arrayClientes[posicion].direccion);
							break;
						case 'B':
							utn_getString("\nIngrese la nueva localidad ","\nError, apellido no valido",1,TEXT_SIZE,1,&arrayClientes[posicion].localidad);
							break;

						default:
							printf("Saliste del menu");

				*/

					}
					retorno=0;
              }

        }

    }

    int pedido_buscarID(Pedido arrayPedidos[], int size, int valorBuscado, int* posicion)
    {
        int retorno=-1;
        int i;
        if(arrayPedidos!= NULL && size>=0)
        {
            for(i=0;i<size;i++)
            {
                if(arrayPedidos[i].isEmpty==1)
                    continue;
                else if(arrayPedidos[i].idPedido==valorBuscado)
                {
                    retorno=0;
                    *posicion=i;
                    break;
                }
            }
        }
        return retorno;
    }
