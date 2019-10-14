/*
 ============================================================================
 Name        : TP1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

int main(void) {

	float n1;
	float n2;
	float respuesta;
	float opcion;
	//Imprimir las opciones

    printf("\n introduce algunas de las siguientes opciones: \n");
    printf("\n 1. ingresar primer operando A= %f  \n",n1);
    printf("\n 2. ingresar segundo operando B= %f \n",n2);
    printf("\n 3. calcular todas las operaciones \n");
    printf("\n 4. informar resultados \n");
    printf("\n 5. salir\n");
    printf("\n opcion:\n");

    do {
		float opcion;

	    while(scanf("%f",&opcion)==0 ||(opcion<1 ||opcion>5) || getInt()==0){

            {
            __fpurge(stdin);
            printf("\n error, ingrese opcion entre 1 y 5\n");
            }

	    }
	    float auxiliar;
	    switch ((int)opcion) {
			case 1:
                printf("\n ingrese primer operando:\n");
                while(scanf("%f",&auxiliar)==0)
                       {
                           printf("\n error ingrese numero\n");
                           __fpurge(stdin);
                           if(scanf("%f",&auxiliar)==1)
                               {
                                   n1=auxiliar;

                                   break;
                               }
                       }	    printf("numero %d",n1);
				break;
			default:
				break;
		}


	} while (opcion== 5);
}


float getInt(float *pnumero)
{
    float auxiliar;
    while(scanf("%f",&auxiliar)==0)
        {
            printf("\n error ingrese numero\n");
            __fpurge(stdin);
            if(scanf("%f",&auxiliar)==1)
                {
                    *pnumero=auxiliar;
                    break;
                }
        }
        return auxiliar;
}
