
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "Ventas.h"
#include "Controller.h"

int main(void) {

printf("INICIO\n");
LinkedList* listaVentas=ll_newLinkedList();
printf("LOAD FROM TEXT\n");
controller_loadFromText("/home/marisa/data.csv",listaVentas);
printf("\nANTES DE COTROLLER COUNT\n");
controller_count(listaVentas);

//return 0;
}


