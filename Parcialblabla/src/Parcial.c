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
#define NUMERO_CLIENTES 100
#define NUMERO_PEDIDO 1000
int main(void) {
	int opcion;
	int contadorIdClientes;
	int contadorIdPedidos;
	Cliente arrayClientes[NUMERO_CLIENTES];
	Pedido arrayPedidos[NUMERO_PEDIDO];
	cliente_Inicializar(arrayClientes,NUMERO_CLIENTES);
	pedido_Inicializar(arrayPedidos,NUMERO_PEDIDO);

	do {
		utn_getIntSinSigno("\n\n1) Alta \n2) Modificar \n3) Baja \n4) Crear Pedido \n5)Procesar Residuos \n6)Imprimir Clientes \n7)Imprimir pedidos pendientes \n8)Imprimir pedidos procesados \n","\nError, numero invalido",1,sizeof(int),1,8,1,&opcion);
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
				if(cliente_modificar(arrayClientes,NUMERO_CLIENTES)==0){
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

				break;
		}

	} while (opcion!=8);



}
