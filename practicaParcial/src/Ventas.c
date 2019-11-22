#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Ventas.h"

Venta* venta_new()
{
	return (Venta*)malloc(sizeof(Venta));
//    Venta* this;
//    this=malloc(sizeof(Venta));
//    return this;
}
Venta* venta_newConParametros(char* idStr,char* fechaStr,char* tipoFotoStr,char* cantidadStr, char* precioStr,char* cuitStr)
{
	Venta* pVentas=NULL;
	int id = atoi(idStr);
	int cantidad = atoi(cantidadStr);
	int precio = atoi(precioStr);

	pVentas = (Venta*)malloc(sizeof(Venta));

	pVentas->ID_Venta = id;
	strcpy(pVentas->Fecha_Venta, fechaStr);
	strcpy(pVentas->Tipo_Foto, tipoFotoStr);
	pVentas->Cantidad = cantidad;
	pVentas->Precio_Unitario = precio;
	strcpy(pVentas->CUIT_Cliente, cuitStr);

	return pVentas;
//    pVentas=venta_new();

//    if( pVentas==NULL ||
//    Venta_setId(pVentas,id)||
//	Venta_setFecha(pVentas,fecha)||
//	Venta_setTipo_Foto(pVentas,tipo) ||
//	Venta_setCantidad(pVentas,cantidad)||
//	Venta_setPrecio_Unitario(pVentas,precio)||
//    Venta_setCUIT_Cliente(pVentas,cuit))
//    {
//        Employee_delete(pVentas);
//        pVentas=NULL;
//    }



    return pVentas;
}

void Venta_delete(Venta* this)
{
    free(this);
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
        printf("\nSET CANTIDAD: %d, %d", this->Cantidad, Cantidad);
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

int Venta_getCantidad_Foto(Venta* this, int* cantidad)
{
	int retorno=0;
	if(this!=NULL && cantidad!=NULL)
	{
		printf("\nENTRA A CANTIDAD DE FOTOS? %d", this->Cantidad);
		printf("\nVENTA: %s, %s, %d", this->Fecha_Venta, this->Tipo_Foto, this->Cantidad);
		*cantidad = this->Cantidad;
	}
	printf("\nRETORNO: %d", retorno);
	return retorno;
}

int Ventas_Total_Count(void* thisA)
{
    int retorno = 0;
    Venta* venta;
    venta = (Venta*) thisA;

//    printf("\nTOTAL");

    if(thisA != NULL && venta->Cantidad >= 0)
    {
    	retorno = venta->Cantidad;
    }
    else
    {
    	retorno = 0;
    }
//    printf("TOTAL: %d", ((Venta*)thisA)->Cantidad);
//    Venta_getTipo_Foto((Venta*)thisA,NombreThisA);
//    Venta_getCantidad_Foto((Venta*)thisA, &count_foto);
//    printf("\nFOTOS: %d", count_foto);
//
//    if(strcmp(NombreThisA,"4R_10x15")==0)
//    {
//    	count_4R_10x15++;
//
//    }
//    else if(strcmp(NombreThisA,"5R_13x18")==0)
//    {
//    	count_5R_13x18++;
//    }

    return retorno;
}

