#include <stdio_ext.h>
#include <stdio.h>
#include <stdlib.h>

#include "utn.h"

struct datosPersonales{
	char nombre[20];
	char apellido[20];
	char calle[20];
	int numero;
	int isEmpy;
};
int pedirDatos(struct datosPersonales persona[]);


int main(void) {
	int opcion;
    struct datosPersonales persona[3];
do {
    printf("\n Introduce algunas de las siguientes opciones: \n");
    printf(" 1. Alta");
    printf(" 2. baja");
    printf(" 3. modifica");
    printf(" 4. listar");
    printf(" 5. ordenar");
    printf(" 6. salir");
    printf(" opcion:\n");

    while(scanf("%d",&opcion)==0 ||(opcion<1 ||opcion>6))
    	{
        printf("ERROR!!, Ingrese opcion entre 1 y 6");
        }
    switch (opcion) {
		case 1:
				pedirDatos(persona);
				printf("Alta");
			break;
		case 2:
				printf("baja");
			break;
		case 3:
				printf("modifica");
			break;
		case 4:
				printf("listar");
			break;
		case 5:
				printf("ordena");
			break;
	}


} while (opcion != 6);
printf("saliste del manu");
}
int pedirDatos( struct datosPersonales persona[])
{

    int i;

    for(i=0;i<3;i++){

        getStringLetras("INgrese un nombre",persona[i].nombre);
        printf("\nIngrese apellido ");
        getStringLetras("ingrese un apellido",persona[i].apellido);
        printf("\nIngrese calle ");
        getStringLetras("ingrese una calle",persona[i].calle);
        printf("\nIngrese numero ");
        scanf("%d", &persona[i].numero);
        __fpurge(stdin);
    };
   return 0;
};


