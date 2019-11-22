#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Cachorros.h"

Cachorro* venta_new()
{
	return (Cachorro*)malloc(sizeof(Cachorro));
}

Cachorro* new_cachorroConParametros(char* idStr, char* nombreStr, char* diasStr, char* razaStr, char* reservadoStr, char* generoStr)
{
	Cachorro* pCachorro=NULL;
	int id = atoi(idStr);
	int dias = atoi(diasStr);

	pCachorro = (Cachorro*)malloc(sizeof(Cachorro));

	pCachorro->ID_Cachorro = id;
	strcpy(pCachorro->Nombre, nombreStr);
	pCachorro->Dias = dias;
	strcpy(pCachorro->Raza, razaStr);
	strcpy(pCachorro->Reservado, reservadoStr);
	strcpy(pCachorro->Genero, generoStr);

	return pCachorro;
}

int cachorros_dias(void* this)
{
	int retorno = 0;
	Cachorro* cachorro;
	cachorro = (Cachorro*) this;

	if(this != NULL && (cachorro->Dias < 45))
	{
		retorno = 1;
	}
	return retorno;
}

int cachorros_machos(void* this)
{
	int retorno = 0;
	Cachorro* macho;
	macho = (Cachorro*) this;

	if(this != NULL && (strcmp(macho->Genero, "M") != 0))
	{
		retorno = 1;
	}
	return retorno;
}

int cachorros_callejeros(void* this)
{
	int retorno = 0;
	Cachorro* callejero;
	callejero = (Cachorro*) this;

	if(this != NULL && (strcmp(callejero->Raza, "Callejero") == 0))
	{
		retorno = 1;
	}

	return retorno;
}

