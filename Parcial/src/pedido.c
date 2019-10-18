#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "pedido.h"
#include "cliente.h"


int pedido_Inicializar(Pedido arrayPedido[], int size)
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

            utn_getIntSinSigno("\nIngrese el id de cliente ","\nError",1,20,0,10,1,&arrayPedido[posicion].idCliente);
            utn_getIntSinSigno("\nIngrese la cantidad de kg ","\nError, kg no valido",1,20,0,10,1,&arrayPedido[posicion].kgTotales);

            printf("\nID PEDIDO%d: ID EMPRESA: %d  KG TOTALES: %d  Estado: %s ", arrayPedido[posicion].idPedido, arrayPedido[posicion].idCliente, arrayPedido[posicion].kgTotales,arrayPedido[posicion].estado);

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
    	printf("\nID Pedido \tKg Totales \tEstado");
        for(i=0;i<size;i++)
        {
            if(arrayPedidos[i].isEmpty==1){continue;}

            else{
                printf("\n %d \t\t %d \t\t %s", arrayPedidos[i].idPedido, arrayPedidos[i].kgTotales, arrayPedidos[i].estado);
            }
        }
        printf("\n#####################################################\n");
        retorno=0;
    }
    return retorno;
}

int pedido_ingresarkg(Pedido arrayPedidos[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    int hdpe;
    int ldpe;
    int pp;
    int sumaKg;
    if(arrayPedidos!=NULL && sizeArray>0)
    {
        utn_getIntSinSigno("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
        if(pedido_buscarID(arrayPedidos,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
			utn_getIntSinSigno("\n\nIngrese el los kg de HDPE","\nError, numero invalido",1,sizeof(int),1,8,1,&hdpe);
			utn_getIntSinSigno("\n\nIngrese el los kg de LDPE","\nError, numero invalido",1,sizeof(int),1,8,1,&ldpe);
			utn_getIntSinSigno("\n\nIngrese el los kg de PP","\nError, numero invalido",1,sizeof(int),1,8,1,&pp);
			sumaKg= hdpe + ldpe +pp;
			if(sumaKg>arrayPedidos[posicion].kgTotales){
			   printf("excede el kg total, vuelva a intentar");
			}else{
			   arrayPedidos[posicion].tipo_plastico.HDPE = hdpe;
			   arrayPedidos[posicion].tipo_plastico.LDPE = ldpe;
			   arrayPedidos[posicion].tipo_plastico.PP = pp;
			   strcpy(arrayPedidos[posicion].estado, "Completado");
			   retorno=0;
			}
        }
    }
    return retorno;
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

int contadorDePendientes(Pedido arrayPedidos[], int size, int idCliente)
{
	int i;
	int TotalPendientes = 0;
	if(arrayPedidos!= NULL && size > 0)
	{
		for(i=0;i < size; i++)
		{
			if(arrayPedidos[i].isEmpty==1) continue;
			{
			   if(arrayPedidos[i].idCliente == idCliente && strcmp(arrayPedidos[i].estado,"Pendiente") == 0)
			   {
				   TotalPendientes++;
			   }
			}
		}
	}
	return TotalPendientes;
}
int contadorDeCompletados(Pedido arrayPedidos[], int size, int idCliente)
{
	int i;
	int TotalCompletados = 0;
	if(arrayPedidos!= NULL && size > 0)
	{
		for(i=0;i < size; i++)
		{
			if(arrayPedidos[i].isEmpty==1) continue;
			{
			   if(arrayPedidos[i].idCliente == idCliente && strcmp(arrayPedidos[i].estado,"Completado") == 0)
			   {
				   TotalCompletados++;
			   }
			}
		}
	}
	return TotalCompletados;
}

int contadorDePedidos(Pedido arrayPedidos[], int size, int idCliente)
{
	int i;
	int Total = 0;
	if(arrayPedidos!= NULL && size > 0)
	{
		for(i=0;i < size; i++)
		{
			if(arrayPedidos[i].isEmpty==1) continue;
			{
			   if(arrayPedidos[i].idCliente == idCliente && arrayPedidos[i].idPedido!=0)
			   {
				   Total++;
			   }
			}
		}
	}
	return Total;
}


int pedidos_pendientes(Pedido arrayPedidos[], int sizePedidos, Cliente arrayClientes[], int sizeClientes) {
	int retorno = -1;
	int i;
	int j;

	printf("\nCuit \tDireccion \tKg a Recolectar");
	for(i=0;i < sizePedidos; i++) {
		if(strcmp(arrayPedidos[i].estado, "Pendiente") == 0){
			for(j=0;j < sizeClientes; j++){
				if(arrayClientes[j].idCliente == arrayPedidos[i].idCliente){
					printf("\n%d \t\t %s \t\t %d",arrayClientes[j].cuit, arrayClientes[j].direccion, arrayPedidos[i].kgTotales);
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}

int pedidos_procesados(Pedido arrayPedidos[], int sizePedidos, Cliente arrayClientes[], int sizeClientes) {
	int retorno = -1;
	int i;
	int j;

	printf("\nCuit \tDireccion \tKg de HDPE \tKg de LDPE \tKg de PP");
	for(i=0;i < sizePedidos; i++) {
		if(strcmp(arrayPedidos[i].estado, "Completado") == 0){
			for(j=0;j < sizeClientes; j++){
				if(arrayClientes[j].idCliente == arrayPedidos[i].idCliente){
					printf("\n%d \t\t %s \t\t %d \t\t %d \t\t %d ",arrayClientes[j].cuit, arrayClientes[j].direccion, arrayPedidos[i].tipo_plastico.HDPE, arrayPedidos[i].tipo_plastico.LDPE, arrayPedidos[i].tipo_plastico.PP);
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}

int contadorDeKgReciclados(Pedido arrayPedidos[], int size, int idCliente)
{
	int i;
	int kgReciclados = 0;
	int totalPlastico;
	if(arrayPedidos!= NULL && size > 0)
	{
		for(i=0;i < size; i++)
		{
			if(arrayPedidos[i].isEmpty==1) continue;
			{
			   if(arrayPedidos[i].idCliente == idCliente )
			   {
				   totalPlastico = arrayPedidos[i].tipo_plastico.HDPE + arrayPedidos[i].tipo_plastico.LDPE + arrayPedidos[i].tipo_plastico.PP;
				   kgReciclados = kgReciclados + totalPlastico;
			   }
			}
		}
	}
	return kgReciclados;
}
