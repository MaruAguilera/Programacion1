#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "pedido.h"
#include "utn.h"
#define NUMERO_CLIENTES 100
#define NUMERO_PEDIDO 1000
#define RECICLA_MIL 1000
#define RECICLA_CIEN 100
//recibe la id de cliente y calcula las diferentes informes


int cliente_conMasPedidos_pendiente(Cliente arrayClientes[], int size, Pedido arrayPedidos[], int sizePedidos)
{
    int retorno=-1;
    int i;
    int pendientes;
    int pendienteMaximo=0;
    int clienteConMayorPedido;
    if(arrayClientes!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(arrayClientes[i].isEmpty==1){continue;}

            else{

            	pendientes = contadorDePendientes(arrayPedidos,sizePedidos, arrayClientes[i].idCliente);
            	if(pendientes>pendienteMaximo || i==0 ){
            	    pendienteMaximo=pendientes;
            	    clienteConMayorPedido=arrayClientes[i].idCliente;

            	}
            	                        }
        }
    	printf("\nEl mas pedidos pendientes  %d  con id %d",pendienteMaximo,clienteConMayorPedido);

        retorno=0;
    }
    return retorno;
}


int cliente_conMasPedidos_completados(Cliente arrayClientes[], int size, Pedido arrayPedidos[], int sizePedidos)
{
    int retorno=-1;
    int i;
    int completados;
    int completadoMaximo=0;
    int clienteConMayorPedido;
    if(arrayClientes!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(arrayClientes[i].isEmpty==1){continue;}

            else{

            	completados = contadorDeCompletados(arrayPedidos,sizePedidos, arrayClientes[i].idCliente);
            	if(completados>completadoMaximo || i==0 ){
            		completadoMaximo=completados;
            	    clienteConMayorPedido=arrayClientes[i].idCliente;

            	}
            	                        }
        }
    	printf("\nEl mas pedidos completados  %d  con id %d",completadoMaximo,clienteConMayorPedido);

        retorno=0;
    }
    return retorno;
}
int cliente_conMasPedidos(Cliente arrayClientes[], int size, Pedido arrayPedidos[], int sizePedidos)
{
    int retorno=-1;
    int i;
    int totales;
    int totalesMaximo=0;
    int clienteContotalesMaximo;
    if(arrayClientes!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(arrayClientes[i].isEmpty==1){continue;}

            else{

            	totales = contadorDePedidos(arrayPedidos,sizePedidos, arrayClientes[i].idCliente);
            	if(totales>totalesMaximo || i==0 ){
            		totalesMaximo=totales;
            		clienteContotalesMaximo=arrayClientes[i].idCliente;

            	}
            	                        }
        }
    	printf("\nEl mas pedidos %d  con id %d",totalesMaximo,clienteContotalesMaximo);

        retorno=0;
    }
    return retorno;
}

int cliente_conMasKg(Cliente arrayClientes[], int size, Pedido arrayPedidos[], int sizePedidos)
{
    int retorno=-1;
    int i;
    int kg;
    int kgMaximo=0;
    int clienteConkgMaximo;
    if(arrayClientes!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(arrayClientes[i].isEmpty==1){continue;}

            else{

            	kg = contadorDeKgReciclados(arrayPedidos,sizePedidos, arrayClientes[i].idCliente);
            	if(kg>kgMaximo || i==0 ){
            		kgMaximo=kg;
            		clienteConkgMaximo=arrayClientes[i].idCliente;

            	}
            	                        }
        }
    	printf("\nlos kg maximos son %d  con id %d",kgMaximo,clienteConkgMaximo);

        retorno=0;
    }
    return retorno;
}

int cliente_conMenosKg(Cliente arrayClientes[], int size, Pedido arrayPedidos[], int sizePedidos)
{
    int retorno=-1;
    int i;
    int kg;
    int kgMinimo=0;
    int clienteConkgMinimo;
    if(arrayClientes!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(arrayClientes[i].isEmpty==1){continue;}

            else{

            	kg = contadorDeKgReciclados(arrayPedidos,sizePedidos, arrayClientes[i].idCliente);
            	if(kg<kgMinimo || i==0 ){
            		kgMinimo=kg;
            		clienteConkgMinimo=arrayClientes[i].idCliente;

            	}
            	                        }
        }
    	printf("\nlos kg minimos son %d  con id %d",kgMinimo,clienteConkgMinimo);

        retorno=0;
    }
    return retorno;
}

int cliente_conMasDe1000kg(Cliente arrayClientes[], int size, Pedido arrayPedidos[], int sizePedidos)
{
    int retorno=-1;
    int i;
    int kg;
    int kgMayorMIl=0;
    int clienteConkgMayorMil;
    if(arrayClientes!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(arrayClientes[i].isEmpty==1){continue;}

            else{

            	kg = contadorDeKgReciclados(arrayPedidos,sizePedidos, arrayClientes[i].idCliente);
            	if(kg> RECICLA_MIL|| i==0 ){
            		kgMayorMIl=kg;
            		clienteConkgMayorMil=arrayClientes[i].idCliente;

            	}
            	                        }
        }
    	printf("\nKg mayor a 1000 %d  con id %d",kgMayorMIl,clienteConkgMayorMil);

        retorno=0;
    }
    return retorno;
}
int cliente_conMenosDe100kg(Cliente arrayClientes[], int size, Pedido arrayPedidos[], int sizePedidos)
{
    int retorno=-1;
    int i;
    int kg;
    int kgMenorCien=0;
    int clienteConkgMenorCien;
    if(arrayClientes!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(arrayClientes[i].isEmpty==1){continue;}

            else{

            	kg = contadorDeKgReciclados(arrayPedidos,sizePedidos, arrayClientes[i].idCliente);
            	if(kg<RECICLA_CIEN|| i==0 ){
            		kgMenorCien=kg;
            		clienteConkgMenorCien=arrayClientes[i].idCliente;

            	}
            	                        }
        }
    	printf("\nKg menor a 100 %d  con id %d",kgMenorCien,clienteConkgMenorCien);

        retorno=0;
    }
    return retorno;
}

