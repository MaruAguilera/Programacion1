/*
 ============================================================================
 Name        : Parcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "pedido.h"
#include "utn.h"
#include "informes.h"
#define NUMERO_CLIENTES 100
#define NUMERO_PEDIDO 1000

int cliente_listar_pedido(Cliente arrayClientes[], int size, Pedido arrayPedidos[], int sizePedidos);
int pedidos_pendientes(Pedido arrayPedidos[], int sizePedidos, Cliente arrayClientes[], int sizeClientes);
int pedidos_procesados(Pedido arrayPedidos[], int sizePedidos, Cliente arrayClientes[], int sizeClientes);

int main(void) {

	int opcion;
	int contadorIdClientes=0;
	int contadorIdPedidos=0;
	Cliente arrayClientes[NUMERO_CLIENTES];
	Pedido arrayPedidos[NUMERO_PEDIDO];
	cliente_Inicializar(arrayClientes,NUMERO_CLIENTES);
	pedido_Inicializar(arrayPedidos,NUMERO_PEDIDO);

	do {
		utn_getIntSinSigno("\n\n1) Alta \n2) Modificar \n3) Baja \n4) Crear Pedido \n5)Procesar Residuos \n6)Imprimir Clientes \n7)Imprimir pedidos pendientes \n8)Imprimir pedidos procesados \n9)Informes \n","\nError, numero invalido",1,sizeof(int),1,10,1,&opcion);
		switch (opcion) {
			case 1:
				if(cliente_alta(arrayClientes,NUMERO_CLIENTES,&contadorIdClientes)==0)
				{
					printf("\nSe cargo el cliente exitosamente");
				}else{
					printf("\nEl cliente no se cargo, intente nuevamente");
				}


				break;
			case 2:
				if(cliente_modificar(arrayClientes,NUMERO_CLIENTES)==0)
				{
					printf("\nSe modifico el Cliente");
				}else{
					printf("\nNo se pudo modificar el cliente, intete nuevamente");
				}
				break;
			case 3:
				if(cliente_baja(arrayClientes, NUMERO_CLIENTES)==0 )
				{
					printf("\nEl cliente se dio de baja");
				}else{
					printf("\nEl cliente no se pudo dar de baja, intente nuevamente");
				}
				break;
			case 4:
				cliente_listar(arrayClientes, NUMERO_CLIENTES);
				if(pedido_alta(arrayPedidos,NUMERO_PEDIDO,&contadorIdPedidos)==0){
					printf("\nEL pedido fue procesado");
				}else{
					printf("error");
				}
				break;
			case 5:
				pedido_listar(arrayPedidos, NUMERO_PEDIDO);
				if(pedido_ingresarkg(arrayPedidos,  NUMERO_PEDIDO)==0){
					printf("El proceso fue exitoso!");
				}else{
					printf("Error, no se pudo procesar pedido");
				}
				break;
			case 6:
				cliente_listar_pendiente(arrayClientes, NUMERO_CLIENTES, arrayPedidos, NUMERO_PEDIDO);
				break;
			case 7:
				if(pedidos_pendientes(arrayPedidos, NUMERO_PEDIDO, arrayClientes, NUMERO_CLIENTES)==0){
					printf("\n");
				}else{
					printf("\nError, no se pudieron obtener los pedidos");
				}
				break;
			case 8:
				if(pedidos_procesados(arrayPedidos, NUMERO_PEDIDO, arrayClientes, NUMERO_CLIENTES) ==0){
					printf("\n");
				}else{
					printf("\nError, no se pudieron obtener los pedidos");
				}
				break;
			case 9:
				printf("\nINFORMES");

				cliente_conMasPedidos_pendiente(arrayClientes, NUMERO_CLIENTES, arrayPedidos, NUMERO_PEDIDO);
				cliente_conMasPedidos_completados(arrayClientes, NUMERO_CLIENTES, arrayPedidos, NUMERO_PEDIDO);
				cliente_conMasPedidos(arrayClientes, NUMERO_CLIENTES, arrayPedidos, NUMERO_PEDIDO);
				cliente_conMasKg(arrayClientes, NUMERO_CLIENTES, arrayPedidos, NUMERO_PEDIDO);
				cliente_conMenosKg(arrayClientes, NUMERO_CLIENTES, arrayPedidos, NUMERO_PEDIDO);
				cliente_conMasDe1000kg(arrayClientes, NUMERO_CLIENTES, arrayPedidos, NUMERO_PEDIDO);
				cliente_conMenosDe100kg(arrayClientes, NUMERO_CLIENTES, arrayPedidos, NUMERO_PEDIDO);

				break;
		}

	} while (opcion!=10);



}
