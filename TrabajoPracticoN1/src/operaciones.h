#ifndef TP1_H_INCLUDED
#define TP1_H_INCLUDED


/**
la funcion sumarDosnumeros() recibe como argumento tres int con *pnumeroUno, *pnumeroDos,*psuma como punteros
y calcula la suma.
*/
int sumarDosnumeros(int *pnumeroUno,int *pnumeroDos,int *psuma);

/**
la funcion restarDosnumeros() recibe como argumento tres int con *pnumeroUno, *pnumeroDos,*presta como punteros
y calcula la resta.
*/
int restarDosnumeros(int *pnumeroUno,int *pnumeroDos,int *presta);

/**
la funcion multiplicarDosnumeros() recibe como argumento tres int con *pnumeroUno, *pnumeroDos,*pmultiplicar como punteros
y calcula la multiplicacion.
*/
int multiplicarDosnumeros(int *pnumeroUno,int *pnumeroDos,int *pmultiplicar);

/**
la funcion dividirDosnumeros() recibe como argumento tres int con *pnumeroUno, *pnumeroDos,*pdivision como punteros
y si *pnumeroDos no es cero calcula la division y retorna 0 caso contrario retorna -1
*/
int dividirDosnumeros(int *pnumeroUno,int *pnumeroDos,float *pdivision);

/**
la funcion obtenerFactorialdeunNumero recibe como argumento un int con *pnumero y un int *pfactorialNumero como punteros
y calcula el factorial siempre y cuando p*numero sea entero positivo en ese caso retorna 0 sino -1
*/
int obtenerFactorialdeunNumero(int *pnumero,int *pfactorialNumero);

/**
la funcion cargarNumero() tiene como argumento un int con *pnumero como puntero y recibe los datos que el usuario ingresa
y verifica que sea realmente un numero, luego retorna ese valor
*/
int cargarNumero(int *pnumero);


#endif
