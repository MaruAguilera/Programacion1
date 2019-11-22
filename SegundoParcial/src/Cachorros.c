#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Cachorros.h"

Cachorros* cachorro_new()
{
	return (Cachorros*)malloc(sizeof(Cachorros));
	Cachorros* this;
    this=malloc(sizeof(Cachorros));
    return this;
}

void Employee_delete(Cachorros* this)
{
    free(this);
}

Cachorros* Cachorros_newConParametros(int id,char* nombre,int dias,char* raza, char* reservado,char* genero)
{
	Cachorros*pCachorro=NULL;
    pCachorro=cachorro_new();

    if( pCachorro==NULL ||
    Cachorros_setId(pCachorro,id)||
	Cachorros_Nombre(pCachorro,nombre)||
	Cachorros_setDias(pCachorro,dias) ||
	Cachorros_setRaza(pCachorro,raza)||
	Cachorros_setReservado(pCachorro,reservado)||
	Cachorros_Genero(pCachorro,genero))
    {
        Employee_delete(pCachorro);
        pCachorro=NULL;
    }

    return pCachorro;
}

int Cachorros_setId(Cachorros* this,int id)
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
int Cachorros_Nombre(Cachorros* this,char* Nombre)
{
    int retorno=-1;
    if(this!=NULL && !verificarArregloSoloLetras(Nombre))
    {
        strcpy(this->Nombre,Nombre);
        retorno=0;
    }
    return retorno;
}

int Cachorros_setRaza(Cachorros* this,char* Raza)
{
    int retorno=-1;
    if(this!=NULL && !verificarArregloSoloLetras(Raza))
    {
        strcpy(this->Raza,Raza);
        retorno=0;
    }
    return retorno;
}
int Cachorros_setDias(Cachorros* this,int Dias)
{
    int retorno=-1;
    if(this!=NULL && Dias>=0)
    {
        this->Dias=Dias;
        retorno=0;
    }
    return retorno;
}



int Cachorros_setReservado(Cachorros* this,char* Reservado)
{
    int retorno=-1;
    if(this!=NULL && !verificarArregloSoloLetras(Reservado))
    {
        strcpy(this->Reservado,Reservado);
        retorno=0;
    }
    return retorno;
}

int Cachorros_Genero(Cachorros* this,char* Genero)
{
    int retorno=-1;
    if(this!=NULL && !verificarArregloSoloLetras(Genero))
    {
        strcpy(this->Nombre,Genero);
        retorno=0;
    }
    return retorno;
}

int Cachorros_getId(Cachorros* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->ID_Cachorro;
        retorno=0;
    }
    return retorno;
}

int Cachorros_getNombre(Cachorros* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->Nombre);
        retorno=0;
    }
    return retorno;
}

int Cachorros_getDias(Cachorros* this,int* dias)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *dias=this->Dias;
        retorno=0;
    }
    return retorno;
}

int Cachorros_getRaza(Cachorros* this,char* Raza)
{
    int retorno=-1;
    if(this!=NULL && Raza!=NULL)
    {
        strcpy(Raza,this->Raza);
        retorno=0;
    }
    return retorno;
}
int Cachorros_getReservado(Cachorros* this,char* Reservado)
{
    int retorno=-1;
    if(this!=NULL && Reservado!=NULL)
    {
        strcpy(Reservado,this->Reservado);
        retorno=0;
    }
    return retorno;
}

int Cachorros_getGenero(Cachorros* this,char* Genero)
{
    int retorno=-1;
    if(this!=NULL && Genero!=NULL)
    {
        strcpy(Genero,this->Genero);
        retorno=0;
    }
    return retorno;
}

int em_calcularDiasCachorros(void* this)
 {
	int retorno=-1;
	int dias;

	// recibo elemento empleado como void.
	Cachorros_getDias(this, &dias);
	if (dias < 45)
	{
		retorno = 0;
	}
	else{
		retorno =1;
	}
	return retorno;
}

