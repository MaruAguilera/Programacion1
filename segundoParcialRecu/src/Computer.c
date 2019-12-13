#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Computer.h"


Computadora* computadora_new()
{
	return (Computadora*)malloc(sizeof(Computadora));
	Computadora* this;
    this=malloc(sizeof(Computadora));
    return this;
}

void Computadora_delete(Computadora* this)
{
    free(this);
}

Computadora* Computadora_newConParametros(int id,char* descripcion,int precio,int idTipo, char* oferta)
{
	Computadora*pCompu=NULL;
    pCompu=computadora_new();

    if(pCompu==NULL ||
    Computadora_setId(pCompu,id)||
	Computadora_descripcion(pCompu,descripcion)||
	Computadora_setPrecio(pCompu,precio) ||
	Computadora_setIdTipo(pCompu,idTipo)||
	Computadora_setOferta(pCompu,oferta))

    {
    	Computadora_delete(pCompu);
        pCompu=NULL;
    }

    return pCompu;
}

int Computadora_setId(Computadora* this,int id)
{
    int retorno=-1;
    static int proximoId=-1;

    if(this!=NULL && id==-1)
    {
        proximoId++;
        this->id=proximoId;
        retorno=0;
    }
    else if(id>proximoId)
    {
        proximoId=id;
        this->id=proximoId;
        retorno=0;
    }
    return retorno;
}
int Computadora_descripcion(Computadora* this,char* descripcion)
{
    int retorno=-1;
    if(this!=NULL && !verificarArregloSoloLetras(descripcion))
    {
        strcpy(this->descripcion,descripcion);
        retorno=0;
    }
    return retorno;
}

int Computadora_setPrecio(Computadora* this,int precio)
{
    int retorno=-1;
    if(this!=NULL && precio>=0)
    {
        this->precio=precio;
        retorno=0;
    }
    return retorno;
}

int Computadora_setIdTipo(Computadora* this,int idTipo)
{
    int retorno=-1;
    if(this!=NULL && idTipo>=0)
    {
        this->idTipo=idTipo;
        retorno=0;
    }
    return retorno;
}



int Computadora_setOferta(Computadora* this,char* oferta)
{
    int retorno=-1;
    if(this!=NULL && !verificarArregloSoloLetras(oferta))
    {
        strcpy(this->oferta,oferta);
        retorno=0;
    }
    return retorno;
}


int Computadora_getId(Computadora* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int Computadora_getDescripcion(Computadora* this,char* descripcion)
{
    int retorno=-1;
    if(this!=NULL && descripcion!=NULL)
    {
        strcpy(descripcion,this->descripcion);
        retorno=0;
    }
    return retorno;
}

int Computadora_getPrecio(Computadora* this,int* precio)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *precio=this->precio;
        retorno=0;
    }
    return retorno;
}

int Computadora_getIdTipo(Computadora* this,int* idTipo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *idTipo=this->idTipo;
        retorno=0;
    }
    return retorno;
}

int Computadora_getOferta(Computadora* this,char* oferta)
{
    int retorno=-1;
    if(this!=NULL && oferta!=NULL)
    {
        strcpy(oferta,this->oferta);
        retorno=0;
    }
    return retorno;
}

int compu_order(void* this, void* thisMasUno)
{
	int retorno = 0;
	Computadora* order;
	Computadora* orderMasUno;
	order = (Computadora*) this;
	orderMasUno = (Computadora*) thisMasUno;

	if(this != NULL && thisMasUno != NULL && (order->idTipo > orderMasUno->idTipo))
	{
		retorno = 1;
	}

	return retorno;
}

int em_calculartipoId(void* this)
 {
	int retorno=-1;
	int idTipo;

	// recibo elemento empleado como void.
	Computadora_getIdTipo(this, &idTipo);
	if (idTipo==1)
	{
		retorno = 0;
	}
	else{
		retorno =1;
	}
	return retorno;
}

