#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"


int cargarNumero(int *pnumero)
{
    int auxiliar;
    while(scanf("%d",&auxiliar)==0)
        {
            printf("\n error ingrese numero\n");
            fflush(stdin);
            if(scanf("%d",&auxiliar)==1)
                {
                    *pnumero=auxiliar;
                    break;
                }
        }
        return auxiliar;
}



int sumarDosnumeros(int *pnumeroUno,int *pnumeroDos,int *psuma)
{
	int suma;
    int operador1;
    int operador2;
    operador1=*pnumeroUno;
    operador2=*pnumeroDos;
    suma=operador1+operador2;
    *psuma=suma;
    return 0;
}

int restarDosnumeros(int *pnumeroUno,int *pnumeroDos,int *presta)
{
	int resta;
    int operador1;
    int operador2;
    operador1=*pnumeroUno;
    operador2=*pnumeroDos;
    resta=operador1-operador2;
    *presta=resta;
    return 0;
}

int multiplicarDosnumeros(int *pnumeroUno,int *pnumeroDos,int *pmultiplicar)
{
	int multiplicar;
    int operador1;
    int operador2;
    operador1=*pnumeroUno;
    operador2=*pnumeroDos;
    multiplicar=operador1*operador2;
    *pmultiplicar= multiplicar;
    return 0;
}

int dividirDosnumeros(int *pnumeroUno,int *pnumeroDos,float *pdivision)
{
   float division;
   int operador1;
   int operador2;
   operador1=*pnumeroUno;
   operador2=*pnumeroDos;
   int retorno;
   if(operador2==0)
    {
        retorno=-1;
    }
   else
    {	retorno=0;
    	division=operador1/operador2;
    	*pdivision=division;
    }
    return retorno;
}
int obtenerFactorialdeunNumero(int *pnumero,int *pfactorialNumero)
{
	int auxiliar;
    int i;
    int acumulador=1;
    auxiliar=*pnumero;
            for(i=1;i<=auxiliar;i++)
                {
                   acumulador=acumulador*i;
                }
                *pfactorialNumero=acumulador;

    return 0;
}



