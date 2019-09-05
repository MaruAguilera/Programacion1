#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>


#define PRUEBA_MINIMO 4
#define PRUEBA_MAXIMO 4
int menorEnElArray(int *pArray, int limite, int *minimo);
int mayorEnElArray(int *pArray, int limite, int *maximo);

int main (void)
{
	int minimoR;
	int maximoR;
	int array[PRUEBA_MINIMO] = {12,4,3,7};
	int array2[PRUEBA_MAXIMO]= {12,54,23,7};
	menorEnElArray(array,PRUEBA_MINIMO ,&minimoR );
	mayorEnElArray(array2,PRUEBA_MAXIMO ,&maximoR );
	printf("minimo %d",minimoR);
	printf("maximo %d",maximoR);



}
int menorEnElArray(int *pArray, int limite, int *minimo){

	int menor;
	int i;
	for(i=0;i<limite;i++)
	{
		if(pArray[i]<menor || i==0)
		{
			menor=pArray[i];
			*minimo=pArray[i];
		}
	}
	return 0;
}

int mayorEnElArray(int *pArray, int limite, int *maximo){

	int mayor;
	int i;
	for(i=0;i<limite;i++)
	{
		if(pArray[i]>mayor || i==0)
		{
			mayor=pArray[i];
			*maximo=pArray[i];
		}
	}
	return 0;
}
