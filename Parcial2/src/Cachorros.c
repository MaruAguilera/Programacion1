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
	//agregar getter y setter
	Cachorro* pCachorro=NULL;
	int id = atoi(idStr); // viene en string por el parceo convierto a int
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
int Cachorros_setId(Cachorro* this,int id)
{
    int retorno=-1;
    static int proximoId=-1;

    if(this!=NULL && id==-1)
    {
        proximoId++;
        this->ID_Cachorro=proximoId;
        retorno=0;
    }
    else if(id>proximoId)
    {
        proximoId=id;
        this->ID_Cachorro=proximoId;
        retorno=0;
    }
    return retorno;
}
int Cachorros_Nombre(Cachorro* this,char* Nombre)
{
    int retorno=-1;
    if(this!=NULL && !verificarArregloSoloLetras(Nombre))
    {
        strcpy(this->Nombre,Nombre);
        retorno=0;
    }
    return retorno;
}

int Cachorros_setRaza(Cachorro* this,char* Raza)
{
    int retorno=-1;
    if(this!=NULL && !verificarArregloSoloLetras(Raza))
    {
        strcpy(this->Raza,Raza);
        retorno=0;
    }
    return retorno;
}
int Cachorros_setDias(Cachorro* this,int Dias)
{
    int retorno=-1;
    if(this!=NULL && Dias>=0)
    {
        this->Dias=Dias;
        retorno=0;
    }
    return retorno;
}



int Cachorros_setReservado(Cachorro* this,char* Reservado)
{
    int retorno=-1;
    if(this!=NULL && !verificarArregloSoloLetras(Reservado))
    {
        strcpy(this->Reservado,Reservado);
        retorno=0;
    }
    return retorno;
}

int Cachorros_Genero(Cachorro* this,char* Genero)
{
    int retorno=-1;
    if(this!=NULL && !verificarArregloSoloLetras(Genero))
    {
        strcpy(this->Nombre,Genero);
        retorno=0;
    }
    return retorno;
}

int Cachorros_getId(Cachorro* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->ID_Cachorro;
        retorno=0;
    }
    return retorno;
}

int Cachorros_getNombre(Cachorro* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->Nombre);
        retorno=0;
    }
    return retorno;
}

int Cachorros_getDias(Cachorro* this,int* dias)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *dias=this->Dias;
        retorno=0;
    }
    return retorno;
}

int Cachorros_getRaza(Cachorro* this,char* Raza)
{
    int retorno=-1;
    if(this!=NULL && Raza!=NULL)
    {
        strcpy(Raza,this->Raza);
        retorno=0;
    }
    return retorno;
}
int Cachorros_getReservado(Cachorro* this,char* Reservado)
{
    int retorno=-1;
    if(this!=NULL && Reservado!=NULL)
    {
        strcpy(Reservado,this->Reservado);
        retorno=0;
    }
    return retorno;
}

int Cachorros_getGenero(Cachorro* this,char* Genero)
{
    int retorno=-1;
    if(this!=NULL && Genero!=NULL)
    {
        strcpy(Genero,this->Genero);
        retorno=0;
    }
    return retorno;
}
