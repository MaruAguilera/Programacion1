/*
 ============================================================================
 Name        : TP_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"



int main(void) {
	int	 numeroUno;
	int numeroDos;
	int resultadoSuma;
	//float resultadoResta;
	//float resultadoDivision;
	//float resultadoMultiplicacion;
	//float resultadoFactorial;


	printf("Este programa  suma, resta, multiplica, divide y calcula el facorial dos numeros que usted ingrese");
	printf("Ingrese el primer numero y presione ENTER/n");
	scanf("%d",&numeroUno);
	printf("Ingrese el segundo numero y presione ENTER/n");
	scanf("%d",&numeroDos);

	sumarDosNumeros(numeroUno,numeroDos,&resultadoSuma);
	printf("El resultado de A+B es: %d",resultadoSuma);


}



