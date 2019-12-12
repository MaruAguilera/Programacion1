#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "utn.h"
#include "Cachorros.h"

int controller_loadFromText(char* path , LinkedList* pArrayList)
{
	//char nombreDeArchivo[20];

//	("Ingrese el nombre del archivo: ");


    int retorno=-1;
    FILE* pArchivo;
    pArchivo=fopen(path,"r");
  //  printf("\nabrio el coso");

    if(pArchivo!=NULL && parser_EmployeeFromText(pArchivo,pArrayList)==0)
    {
    	//printf("\nNO NULL");
        retorno=0;
    }
    fclose(pArchivo);
    return retorno;
}

int controller_listCachorros(LinkedList* pArrayList)
{
//	printf("\nCONTROLLER LISTA DE CACHORROS") esta asi pq no tiene getter y setter, cambiar
	Node* nAux = pArrayList->pFirstNode;
	Cachorro* cachorro = nAux->pElement;

	for(int i=0; i<ll_len(pArrayList); i++){
		printf("ID: %d\n1.Nombre: %s\n2.Dias: %d\n3.Raza: %s\n4.Reservado: %s\n5.Genero: %s\n\n", cachorro->ID_Cachorro, cachorro->Nombre, cachorro->Dias, cachorro->Raza, cachorro->Reservado, cachorro->Genero);

		if(nAux->pNextNode != NULL){
			nAux = nAux->pNextNode;
			cachorro = nAux->pElement;
		}
	}
	return 1;
}

int controller_listCachorrosDias(LinkedList* pArrayList)
{
	printf("\nLISTA DE CACHORROS MENOS A 45 DIAS\n");
	if(pArrayList != NULL)
	{
		controller_listCachorros(ll_filter(pArrayList, cachorros_dias));
	}
	return 0;
}

int controller_listCachorrosMachos(LinkedList* pArrayList)
{
	printf("\nLISTA DE CACHORROS MACHOS: \n");
	if(pArrayList != NULL)
	{
		controller_generarArchivoInformes("/home/marisa/nuevoRepo/Programacion1/Parcial2/src/machos.csv" ,(ll_filter(pArrayList, cachorros_machos)));
	}
	return 0;
}

int controller_listCachorrosCallejeros(LinkedList* pArrayList)
{
	printf("\nLISTA DE CACHORROS CALLEJEROS: \n");
	if(pArrayList != NULL)
	{
		controller_listCachorros(ll_filter(pArrayList, cachorros_callejeros));
	}
	return 0;
}

int controller_generarArchivoInformes(char* path, LinkedList* pArrayList)
{
	int len;
	int i;
	int id;
	char nombre[20];
	int dias;
	char raza[20];
	char reservado[5];
	char genero[5];
	Cachorro* auxCachorro;

	FILE *pFile;
	pFile = fopen(path, "w");
	if(pFile == NULL)
	{
		printf("el archivo no existe");
		exit(1);
	}
	else
	{
		fprintf(pFile,"ID_Cachorro,Nombre,Dias,Raza,Reservado,Genero\n");
		len = ll_len(pArrayList);
		for(i = 0; i < len; i++){
			auxCachorro = (Cachorro*)ll_get(pArrayList, i);
			id = auxCachorro->ID_Cachorro;
			strcpy(nombre, auxCachorro->Nombre);
			dias = auxCachorro->Dias;
			strcpy(raza, auxCachorro->Raza);
			strcpy(reservado, auxCachorro->Reservado);
			strcpy(genero, auxCachorro->Genero);
			fprintf(pFile, "%d,%s,%d,%s,%s,%s\n", id, nombre, dias, raza, reservado, genero);
		}
		fclose(pFile);
	}
	return 0;
}

int controller_savePerrosAsText(FILE* pFile , LinkedList* pListaPerros) {
    int ret = 0;
	Cachorro* auxPerro;
    int auxId;
    char auxNombre[4096];
    int auxDias;
    char auxRaza[4096];
	char auxReservado[4096];
	char auxSexo[4096];
    int i, len;

    if(pListaPerros != NULL && pFile != NULL) {
    	fprintf(pFile,"id,nombre,dias,raza,reservado,sexo\n");
    	len = ll_len(pListaPerros);

    	for(i = 0; i < len; i++) {
    		auxPerro = (Cachorro*)ll_get(pListaPerros, i);
    		Cachorros_getId(auxPerro, &auxId);
    		Cachorros_getNombre(auxPerro, auxNombre);
    		Cachorros_getDias(auxPerro, &auxDias);
    		Cachorros_getRaza(auxPerro, auxRaza);
    		Cachorros_getReservado(auxPerro, auxReservado);
    		Cachorros_Genero(auxPerro, auxSexo);


    		fprintf(pFile,"%d,%s,%d,%s,%s,%s\n", auxId, auxNombre, auxDias, auxRaza, auxReservado, auxSexo);
    		ret++;
    	}
	fclose(pFile);
    }
    return ret;
}



int controller_count(LinkedList* pArrayList)
{
	printf("\nEN EL CONTROLER COUNT");
	int cantidadDeFotosTotales = 0;
	if(pArrayList != NULL){
		printf("\nla lista no es nula");
//		cantidadDeFotosTotales = ll_count(pArrayList, Ventas_Total_Count);
		printf("\nTOALES: %d", cantidadDeFotosTotales);
	}
	return 0;
}
int controller_saveAsText(char* fileName,LinkedList* listaPerros) {
	FILE*pArchivo;
	int retorno = -1;

	    if(fileName != NULL && listaPerros != NULL) {
	        pArchivo=fopen(fileName,"w");
	        if(pArchivo != NULL && controller_savePerrosAsText(pArchivo,listaPerros)) {
	            //fclose(pArchivo);
	            printf("\nGuardado exitoso en Texto");
	            retorno = 0;
	        } else {
	            printf("\nNo se pudo abrir el archivo");
	        }
	    }
	    return retorno;
}
