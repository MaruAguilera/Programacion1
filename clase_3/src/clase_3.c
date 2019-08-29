#include <stdio.h>
#include <stdlib.h>
#define CONTADOR_ITERA 5

int calculaMaximoMinimo(int contador, int *max, int *min );

int main(void) {
	int calculoMaximo;
	int calculoMinimo;
	int contador;
	int *contador1;
	printf("ALGO %d y contador %d contador %d",contador,&contador,*contador1);
	printf("ingrese un numero");
	scanf("%d",&contador);

	calculaMaximoMinimo(contador,&calculoMaximo, &calculoMinimo);
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

	if(contador>0 && *min != NULL && *max !=NULL){

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


		retorno =0;
		}
	}

	return retorno;
}












