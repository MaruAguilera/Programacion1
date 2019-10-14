

#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"

int main(void) {

	int n1;
	int n2;
	int opcion;
	int suma;
	int resta;
	int multiplicacion;
	float division;
    int factorialNumerouno;
    int factorialNumerodos;
	//Imprimir las opciones

    do {
        printf("\n Introduce algunas de las siguientes opciones: \n");
        printf(" 1. Ingresar primer operando A=  %d\n",n1);
        printf(" 2. Ingresar segundo operando B= %d \n",n2);
        printf(" 3. Calcular todas las operaciones \n");
        printf(" 4. Informar resultados \n");
        printf(" 5. Salir\n");
        printf(" opcion:\n");

	    while(scanf("%d",&opcion)==0 ||(opcion<1 ||opcion>5))
	    	{
            printf("ERROR!!, Ingrese opcion entre 1 y 5");
            }
	    switch ((int)opcion) {
            case 1:
            	printf("Ingrese primer operando:\n");
            	n1=cargarNumero(&n1);
            break;
            case 2:
            	printf("Ingrese segundo operando:\n");
            	n2=cargarNumero(&n2);
            break;
            case 3:
            	sumarDosnumeros(&n1,&n2,&suma);
                restarDosnumeros(&n1,&n2,&resta);
                multiplicarDosnumeros(&n1,&n2,&multiplicacion);
                dividirDosnumeros(&n1,&n2,&division);
                obtenerFactorialdeunNumero(&n1,&factorialNumerouno);
                obtenerFactorialdeunNumero(&n2,&factorialNumerodos);
            break;
            case 4:
            printf("\n La suma de %d+%d es: %d\n",n1,n2,suma);
            printf(" La resta de %d-%d es: %d\n ",n1,n2,resta);
            printf(" La multiplicacion de %d*%d es: %d\n ",n1,n2,multiplicacion);
            if(dividirDosnumeros(&n1,&n2,&division)==0){
                                    printf("La division de %d/%d es: %f\n",n1,n2,division);
            					}
                            else{
                                    printf("ERROR!!,no se puede dividir por cero \n");
                                }
            printf(" El factorial de %d es: %d\n",n1,factorialNumerouno);
            printf(" El factorial de %d es: %d\n",n2,factorialNumerodos);
		}


	} while (opcion!= 5);
    printf("Saliste de la calculadora");

    return 0;
}




