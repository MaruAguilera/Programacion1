#include <stdio_ext.h>
#include <stdio.h>
#include <stdlib.h>

#include "utn.h"

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
