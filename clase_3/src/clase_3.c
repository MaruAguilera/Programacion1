#include <stdio.h>
#include <stdlib.h>
#define CONTADOR_ITERA 5;

int calculaMaximoMinimo(int contador, int *max, int *min );

int main(void) {
	int calculoMaximo;
	int calculoMinimo;


	calculaMaximoMinimo(CONTADOR_ITERA,&calculoMaximo, &calculoMinimo);
	printf("el maximo es %d",calculoMaximo);
	printf("el minimo es %d",calculoMinimo);

	return 0;
}



int calculaMaximoMinimo(int contador, int *max, int *min )
{
	int minimo;
	int maximo;
	int i;
	int num;
	int retorno = -1;

	if(contador>0 && *min != NULL && *min !=NULL){

	for(i=0; i<contador;i++)
	{
		printf("ingrese un numero");
		scanf("%d",&num);
		if (i==0||num>maximo  ){
			maximo=num;
		}if(i==0||num<minimo  ){
			minimo = num;
		}

		*min=minimo;
		*max=maximo;


		return retorno;
	}
	}

	return retorno;
}












