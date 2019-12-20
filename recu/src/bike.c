#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "bike.h"

int participante_setId(Participante* this,int id)
{
	int retorno=-1;
	static int proximoId=-1;

	if(this!=NULL && id==-1)
	{
		proximoId++;
		this->ID_BIKE=proximoId;
		retorno=0;
	}
	else if(id>proximoId)
	{
		proximoId=id;
		this->ID_BIKE=proximoId;
		retorno=0;
	}


	return retorno;
}
int paricipante_Setnombre(Participante* this,char* nombre)
{
	int retorno=-1;
	if(this!=NULL && !verificarArregloSoloLetras(nombre))
	{
		strcpy(this->NOMBRE,nombre);
		retorno=0;
	}
	return retorno;
}

int participante_setTiempo(Participante* this,int tiempo)
{
	int retorno=-1;
	if(this!=NULL && tiempo>=0)
	{
		this->TIEMPO=tiempo;
		retorno=0;
	}
	return retorno;
}

int Computadora_setVelProm(Participante* this,int vel_promedio)
{
	int retorno=-1;
	if(this!=NULL && vel_promedio>=0)
	{
		this->VEL_PROMEDIO=vel_promedio;
		retorno=0;
	}

	return retorno;
}



int participante_setTipoBici(Participante* this,char* tipo)
{
	int retorno=-1;
	if(this!=NULL && !verificarArregloSoloLetras(tipo))
	{
		strcpy(this->TIPO,tipo);
		retorno=0;
	}
	printf("tipobici %d",retorno);
	return retorno;
}

int participante_getId(Participante* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->ID_BIKE;
        retorno=0;
    }
    return retorno;
}

int participante_getNombre(Participante* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->NOMBRE);
        retorno=0;
    }
    return retorno;
}

int participante_getTiempo(Participante* this,int* tiempo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *tiempo=this->TIEMPO;
        retorno=0;
    }
    return retorno;
}

int participante_getVelPromedio(Participante* this,int* vel_prom)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *vel_prom=this->VEL_PROMEDIO;
        retorno=0;
    }
    return retorno;
}

int participante_getTipoBici(Participante* this,char* TipoBici)
{
    int retorno=-1;
    if(this!=NULL && TipoBici!=NULL)
    {
        strcpy(TipoBici,this->TIPO);
        retorno=0;
    }
    return retorno;
}



Participante* new_participante()
{
	return (Participante*)malloc(sizeof(Participante));
}

Participante* new_participanteConParametros(char* idStr, char* descripcionStr, char* precioStr, char* idTipoStr)
{
	Participante* pParticipante=NULL;
	int id = atoi(idStr); // viene en string por el parceo convierto a int
	int tiempo = atoi(precioStr);
	//int vel_prom = atoi(idTipoStr);

	pParticipante = new_participante();

	if(pParticipante==NULL ||
	participante_setId(pParticipante,idStr) ||
	paricipante_Setnombre(pParticipante,descripcionStr)||
	participante_setTiempo(pParticipante,tiempo)||
	participante_setTipoBici(pParticipante,idTipoStr))

    {
		free(pParticipante);
		pParticipante=NULL;
    }


//	pParticipante->ID_BIKE = id;
//	strcpy(pParticipante->NOMBRE, descripcionStr);
//	pParticipante->TIEMPO = tiempo;
//	//pParticipante-> = idTipo;
//	strcpy(pParticipante->TIPO, idTipoStr);
	return pParticipante;
}




