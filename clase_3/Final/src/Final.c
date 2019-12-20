#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "bicicleta.h"

int main(void) {
	int opcionMenu;
	int Submenu;
		int salir = 0;
		LinkedList* listaBicicleta = ll_newLinkedList();
		LinkedList* listaBiciFiltrados = ll_newLinkedList();
		do
		{
			menu(&opcionMenu);
			switch(opcionMenu)
			{
				case 1:
					if(controller_loadFromText("/home/alumno/Descargas/Marisa/bicicletas_v3.csv",listaBicicleta)==0){
						printf("se abrio el archivo");
					}else{
						printf("error!");
					}
					break;
				case 2: controller_listBicicleta(listaBicicleta);
					break;

				case 3:
					if(controller_velocidadPromedio(listaBicicleta)==0){
						printf("se calculo la velocidad");
					}else{
						printf("error");
					}
					break;
				case 4:
					printf("\nELIJA QUE BICI FILTRAR\n, \n1) BMX \n2) PASEO \n3)MTB \n4)PLAYERA");
					int Submenu;

					do {
						scanf("%d", &Submenu);
						switch (Submenu) {
							case 1:

								listaBiciFiltrados = ll_filter(listaBiciFiltrados,bici_BMX);
							printf("Calculando\n");

								if(listaBiciFiltrados != NULL) {
									if(controller_saveAsText("/home/alumno/Descargas/Marisa/filtroAMX.csv",listaBiciFiltrados) == 0) {
										printf("\nArchivo generado correctamente\n");
									} else {
										printf("Error generando archivo\n");
									}
								}
							break;

						}

					} while (Submenu !=4);




					break;
//				case 4: controller_MAP(listaComputer);
//					break;
//				case 5: controller_filterDesktop(listaComputer);
//					break;
//				case 7: controller_MAP(listaCachorros);
//					break;
				case 8: salir = 1;
					break;
			}
		} while(salir != 1);
}

void menu(int* opcionMenu)
{
	int opcionUsuario;
	printf("\n");
	printf("1. CARGARA ARCHIVO\n");
	printf("2. LISTAR BICICLETAS\n");
	printf("3. VELOCIDAD PROMEDIO\n");
	printf("4. MAP\n");
	printf("5. SOLO DESKTOP\n");
	printf("8. SALIR\n");
	printf("**ELIGE UNA OPCION PARA CONTINUAR**");
	scanf("%d", &opcionUsuario);
	*opcionMenu = opcionUsuario;
}
