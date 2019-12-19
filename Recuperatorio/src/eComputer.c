#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "eComputer.h"

eComputer* new_eComputer()
{
	return (eComputer*)malloc(sizeof(eComputer));
}

eComputer* new_eComputerConParametros(char* idStr, char* descripcionStr, char* precioStr, char* idTipoStr)
{
	eComputer* pCompu=NULL;
	int id = atoi(idStr); // viene en string por el parceo convierto a int
	int precio = atoi(precioStr);
	int idTipo = atoi(idTipoStr);

	pCompu = new_eComputer();

	if(pCompu==NULL ||
    Computadora_setId(pCompu,id)||
	//Computadora_setOferta(pCompu,ofertaStr)||
	Computadora_descripcion(pCompu,descripcionStr)||
	Computadora_setPrecio(pCompu,precio) ||
	Computadora_setIdTipo(pCompu,idTipo))


    {
		free(pCompu);
        pCompu=NULL;
    }


	//pEcomputer->ID = id;
//	strcpy(pCompu->Descripcion, descripcionStr);
//	pCompu->precio = precio;
//	pCompu->idTipo = idTipo;
	//strcpy(pCompu->oferta, ofertaStr);

	return pCompu;
}

int computer_order_idTipo(void* this, void* thisMasUno)
{
	int retorno = 0;
	eComputer* orderIdTipo;
	eComputer* orderIdTipoMasUno;
	orderIdTipo = (eComputer*) this;
	orderIdTipoMasUno = (eComputer*) thisMasUno;

	if(this != NULL && thisMasUno != NULL && (orderIdTipo->idTipo > orderIdTipoMasUno->idTipo))
	{
		retorno = 1;
	}

	return retorno;
}

int computer_oferta(void* this)
{
	int retorno = 0;
	eComputer* coputadoraOferta;
	coputadoraOferta = (eComputer*) this;

	if(this != NULL)
	{
		if(coputadoraOferta->idTipo == 2)
		{
			strcpy(coputadoraOferta->oferta, "SIN DATOS");
			retorno = 1;
		}
		if(coputadoraOferta->idTipo == 1 && coputadoraOferta->precio > 20000)
		{
			strcpy(coputadoraOferta->oferta, "50% DESCUENTO");
			retorno = 1;
		}
	}

	return retorno;
}

int computer_desktop(void* this)
{
	int retorno = 0;
	eComputer* desktop;
	desktop = (eComputer*) this;

	if(this != NULL && (desktop->idTipo == 1))
	{
		retorno = 1;
	}

	return retorno;
}
int Computadora_setId(eComputer* this,int id)
{
    int retorno=-1;
    static int proximoId=-1;

    if(this!=NULL && id==-1)
    {
        proximoId++;
        this->ID=proximoId;
        retorno=0;
    }
    else if(id>proximoId)
    {
        proximoId=id;
        this->ID=proximoId;
        retorno=0;
    }


    return retorno;
}
int Computadora_descripcion(eComputer* this,char* descripcion)
{
    int retorno=-1;
    if(this!=NULL && !verificarArregloSoloLetras(descripcion))
    {
        strcpy(this->Descripcion,descripcion);
        retorno=0;
    }
    return retorno;
}

int Computadora_setPrecio(eComputer* this,int precio)
{
    int retorno=-1;
    if(this!=NULL && precio>=0)
    {
        this->precio=precio;
        retorno=0;
    }
    return retorno;
}

int Computadora_setIdTipo(eComputer* this,int idTipo)
{
    int retorno=-1;
    if(this!=NULL && idTipo>=0)
    {
        this->idTipo=idTipo;
        retorno=0;
    }
    return retorno;
}



int Computadora_setOferta(eComputer* this,char* oferta)
{
    int retorno=-1;
    if(this!=NULL && !verificarArregloSoloLetras(oferta))
    {
        strcpy(this->oferta,oferta);
        retorno=0;
    }
    printf("%d",retorno);
    return retorno;
}
int Computadora_getId(eComputer* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->ID;
        retorno=0;
    }
    return retorno;
}

int Computadora_getDescripcion(eComputer* this,char* descripcion)
{
    int retorno=-1;
    if(this!=NULL && descripcion!=NULL)
    {
        strcpy(descripcion,this->Descripcion);
        retorno=0;
    }
    return retorno;
}

int Computadora_getPrecio(eComputer* this,int* precio)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *precio=this->precio;
        retorno=0;
    }
    return retorno;
}

int Computadora_getIdTipo(eComputer* this,int* idTipo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *idTipo=this->idTipo;
        retorno=0;
    }
    return retorno;
}

int Computadora_getOferta(eComputer* this,char* oferta)
{
    int retorno=-1;
    if(this!=NULL && oferta!=NULL)
    {
        strcpy(oferta,this->oferta);
        retorno=0;
    }
    return retorno;
}
