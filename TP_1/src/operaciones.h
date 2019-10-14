/*
 * operaciones.h
 *
 *  Created on: Sep 3, 2019
 *      Author: marisa
 */


int sumarDosNumeros(int numeroUno,int numeroDos, int *resultadoSuma)
{
		int suma;
		suma= numeroUno + numeroDos;

		*resultadoSuma= suma;

		return 0;
}

int restarDosNumeros(int numeroUno, int numeroDos, int *resultadoResta ){

	int resta;

	resta= numeroUno - numeroDos;

	*resultadoResta = resta;

	return 0;
}

int dividirDosNumeros(int numeroUno, int numeroDos, int *resultadoDivisor){
	//falta validar si se sidive por cero, pense en un while q sea numeroDos !=0
	int division;

	division= numeroUno/numeroDos;

	*resultadoDivisor = division;

	return 0;
}
