/*
 ============================================================================
 Name        : TP2.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
//#include "utn.h"
//#include "funcionesEmpleados.h"
#define CANTIDAD_EMPLEADOS 1000

int main(void) {
	printf("safa");
	int opcion;
	int contadorEmpleados;
//	struct Empleado empleados[CANTIDAD_EMPLEADOS];
//	inicializarEmpleados(empleados,CANTIDAD_EMPLEADOS);

	printf("Bienvenido");
    do
    {

        switch(opcion)
        {
            case 1: //Alta
//                altaEmpleados(empleados,CANTIDAD_EMPLEADOS,&contadorEmpleados);
                break;

            case 2: //Modificar
                //fantasma_modificar(arrayFantasma,QTY_TIPO);
                break;

            case 3: //Baja
                //fantasma_baja(arrayFantasma,QTY_TIPO);
                break;

            case 4://Listar
                //fantasma_listar(arrayFantasma,QTY_TIPO);
                break;

            case 5://Salir
                break;

        }
    }
    while(opcion!=6);
    return 0;
}




