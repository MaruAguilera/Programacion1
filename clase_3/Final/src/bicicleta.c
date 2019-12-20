#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "bicicleta.h"

bicicleta* new_bicicleta()
{
	return (bicicleta*)malloc(sizeof(bicicleta));
}

bicicleta* new_bicicletaConParametros(char* idStr, char* nombreStr, char* tipoStr, char* tiempoStr)
{
	//agregar getter y setter se que se agregan gets y set, pero no podia hacer que funcionaran
	bicicleta* pBicicleta=NULL;
	int id = atoi(idStr);
	int tiempo = atoi(tiempoStr); // viene en string por el parceo convierto a int

	pBicicleta = new_bicicleta();

	pBicicleta->ID_BIKE = id;
	strcpy(pBicicleta->NOMBRE, nombreStr);
	strcpy(pBicicleta->TIPO, tipoStr);
	pBicicleta->TIEMPO = tiempo;


	return pBicicleta;
}

int bicicleta_velocidadPromedio(void* this)
{
	int retorno = 0;
	int kilometroRecorridos = 10;

	bicicleta* bicletaVelocidadPromedio;
	bicletaVelocidadPromedio = (bicicleta*) this;

	if(this != NULL)
	{
		float auxVelocidad;

		auxVelocidad = (float)kilometroRecorridos / (float)bicletaVelocidadPromedio->TIEMPO;
		//printf("\nVELOCIDAD PROMEDIO: %f", auxVelocidad);
		bicletaVelocidadPromedio->VELOCIDAD = auxVelocidad;
	}

	return retorno;
}
int bici_BMX(void* this)
{
	int retorno = 0;
	bicicleta* bici;
	bici = (bicicleta*) this;

	if(this != NULL && strcmp(bici->TIPO, "BMX"))
	{
		retorno = 1;
	}

	return retorno;
}

