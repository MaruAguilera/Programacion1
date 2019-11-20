#include "Ventas.h"
#include "utn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Venta* venta_new()
{
    Venta* this;
    this=malloc(sizeof(Venta));
    return this;
}
void Employee_delete(Venta* this)
{
    free(this);
}
Venta* venta_newConParametros(int id,char* fecha,char* tipo,int cantidad, int precio,char cuit)
{
	Venta*pVentas=NULL;
    pVentas=venta_new();

    if( pVentas==NULL ||
    Venta_setId(pVentas,id)||
	Venta_setFecha(pVentas,fecha)||
	Venta_setTipo_Foto(pVentas,tipo) ||
	Venta_setCantidad(pVentas,cantidad)||
	Venta_setPrecio_Unitario(pVentas,precio)||
    Venta_setCUIT_Cliente(pVentas,cuit))
    {
        Employee_delete(pVentas);
        pVentas=NULL;
    }

    return pVentas;
}

int Venta_setId(Venta* this,int id)
{
    int retorno=-1;
    static int proximoId=-1;

    if(this!=NULL && id==-1)
    {
        proximoId++;
        this->ID_Venta=proximoId;
        retorno=0;
    }
    else if(id>proximoId)
    {
        proximoId=id;
        this->ID_Venta=proximoId;
        retorno=0;
    }
    return retorno;
}
int Venta_setFecha(Venta* this,char* fecha)
{
    int retorno=-1;
    if(this!=NULL && !verificarArregloSoloLetras(fecha))
    {
        strcpy(this->Fecha_Venta,fecha);
        retorno=0;
    }
    return retorno;
}

int Venta_setTipo_Foto(Venta* this,char* Tipo_Foto)
{
    int retorno=-1;
    if(this!=NULL && !verificarArregloSoloLetras(Tipo_Foto))
    {
        strcpy(this->Tipo_Foto,Tipo_Foto);
        retorno=0;
    }
    return retorno;
}
int Venta_setCantidad(Venta* this,int Cantidad)
{
    int retorno=-1;
    if(this!=NULL && Cantidad>=0)
    {
        this->Cantidad=Cantidad;
        retorno=0;
    }
    return retorno;
}

int Venta_setPrecio_Unitario(Venta* this,int Precio_Unitario)
{
    int retorno=-1;
    if(this!=NULL && Precio_Unitario>=0)
    {
        this->Precio_Unitario=Precio_Unitario;
        retorno=0;
    }
    return retorno;
}

int Venta_setCUIT_Cliente(Venta* this,char* CUIT_Cliente)
{
    int retorno=-1;
    if(this!=NULL && !verificarArregloSoloLetras(CUIT_Cliente))
    {
        strcpy(this->CUIT_Cliente,CUIT_Cliente);
        retorno=0;
    }
    return retorno;
}
int Venta_getTipo_Foto(Venta* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->Tipo_Foto);
        retorno=0;
    }
    return retorno;
}

int Venta_Count(void* thisA ,void* thisB)
{
    int retorno;
    char NombreThisA[128];
    int count_4R_10x15;
    int count_5R_13x18;

    Venta_getTipo_Foto((Venta*)thisA,NombreThisA);

    if(strcmp(NombreThisA,"4R_10x15")==0)
    {
    	count_4R_10x15++;

    }
    else if(strcmp(NombreThisA,"5R_13x18")==0)
    {
    	count_5R_13x18++;
    }

    return retorno;
}

