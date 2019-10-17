#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "cliente.h"
#include "pedido.h"

int cliente_Inicializar(Cliente arrayClientes[], int size)
{
    int retorno=-1;
    if(arrayClientes!= NULL && size>0)
    {
        for(;size>0;size--)
        {
        	arrayClientes[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

int cliente_buscarEmpty(Cliente arrayCliente[], int size, int* posicion)
{
    int retorno=-1;
    int i;
    if(arrayCliente!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(arrayCliente[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
int cliente_alta(Cliente arrayClientes[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(arrayClientes!=NULL && size>0 && contadorID!=NULL)
    {
        if(cliente_buscarEmpty(arrayClientes,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            arrayClientes[posicion].idCliente=*contadorID;
            arrayClientes[posicion].isEmpty=0;
            utn_getString("\nIngrese el nombre el Cliente ","\nError, nombre no valido",1,TEXT_SIZE,5,&arrayClientes[posicion].nombreEmpresa);
            utn_getString("\nIngrese la direccion","\nError, direccion no valida",1,TEXT_SIZE,1,&arrayClientes[posicion].direccion);
            utn_getString("\nIngrese la localidad","\nError, localidad no valida",1,TEXT_SIZE,1,&arrayClientes[posicion].localidad);
            utn_getIntConSigno("\nIngrese el CUIT ","\nError, CUIT no valido",1,20,0,10,1,&arrayClientes[posicion].cuit);

            printf("\nID \tNombre Empresa \tDireccion \tLocalidad \tCUIT");
            printf("\n%d, \t%s \t\t%s \t\t%s \t\t%d", arrayClientes[posicion].idCliente, arrayClientes[posicion].nombreEmpresa, arrayClientes[posicion].direccion, arrayClientes[posicion].localidad, arrayClientes[posicion].cuit);
            retorno=0;
        }
    }

    return retorno;
}


int cliente_buscarID(Cliente arrayCliente[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(arrayCliente!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(arrayCliente[i].isEmpty==1)
                continue;
            else if(arrayCliente[i].idCliente==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

int cliente_modificar(Cliente arrayClientes[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    char opcion;
    if(arrayClientes!=NULL && sizeArray>0)
    {
        utn_getIntSinSigno("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
        if(cliente_buscarID(arrayClientes,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
        	printf("\nPosicion \tID \tNombre \tDireccion \tLocalidad \tCUIT");
        	printf("\n%d, \t\t%d, \t%s \t%s \t%s \t%d", posicion, arrayClientes[posicion].idCliente, arrayClientes[posicion].nombreEmpresa, arrayClientes[posicion].direccion, arrayClientes[posicion].localidad, arrayClientes[posicion].cuit);
        	printf("\n#####################################################\n");

			if(utn_getChar("\nSeleccione que desea Modificar: \nA:Direccion \nB:Localidad \nC:Salir ","\nError ",'A','B',1,&opcion)==-1)
			{
				printf("Letra Invalida");
			}
			else{


				switch(opcion)
				{
					case 'A':
						utn_getString("\nIngrese la nueva direccion","\nError, nombre no valido",1,TEXT_SIZE,5,&arrayClientes[posicion].direccion);
						break;
					case 'B':
						utn_getString("\nIngrese la nueva localidad ","\nError, apellido no valido",1,TEXT_SIZE,1,&arrayClientes[posicion].localidad);
						break;

					default:
						printf("Saliste del menu");

				}
				retorno=0;
		  }

        }

    }
    return retorno;
}

int cliente_baja(Cliente arrayClientes[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    if(arrayClientes!=NULL && sizeArray>0)
    {
        utn_getIntSinSigno("\nID a BORRAR: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
        if(cliente_buscarID(arrayClientes,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
        	arrayClientes[posicion].isEmpty=1;
        	arrayClientes[posicion].idCliente=0;
            strcpy(arrayClientes[posicion].nombreEmpresa,"");
            strcpy(arrayClientes[posicion].direccion,"");
            strcpy(arrayClientes[posicion].localidad,"");
            arrayClientes[posicion].cuit=0;



            retorno=0;
        }
    }
    return retorno;
}

int cliente_listar(Cliente arrayClientes[], int size)
{
    int retorno=-1;
    int i;
    if(arrayClientes!=NULL && size>=0)
    {
    	printf("\nID \tNombre \tDireccion \tLocalidad \tCUIT");
        for(i=0;i<size;i++)
        {
            if(arrayClientes[i].isEmpty==1){continue;}

            else{
            	printf("\n%d \t%s \t%s \t%s \t%d",arrayClientes[i].idCliente, arrayClientes[i].nombreEmpresa, arrayClientes[i].direccion, arrayClientes[i].localidad, arrayClientes[i].cuit);
            }

        }
        retorno=0;
    }
    return retorno;
}

int cliente_listar_pendiente(Cliente arrayClientes[], int size, Pedido arrayPedidos[], int sizePedidos)
{
    int retorno=-1;
    int i;
    int pendientes;
    if(arrayClientes!=NULL && size>=0)
    {
    	printf("\nID \tNombre \tDireccion \tLocalidad \tCUIT \tPendientes");
        for(i=0;i<size;i++)
        {
            if(arrayClientes[i].isEmpty==1){continue;}

            else{
            	pendientes = contadorDePendientes(arrayPedidos,sizePedidos, arrayClientes[i].idCliente);
            	printf("\n%d \t%s \t%s \t\t%s \t%d \t%d",arrayClientes[i].idCliente, arrayClientes[i].nombreEmpresa, arrayClientes[i].direccion, arrayClientes[i].localidad, arrayClientes[i].cuit,pendientes);
            }
        }
        retorno=0;
    }
    return retorno;
}




