#ifndef CACHORROS_H_
#define CACHORROS_H_

typedef struct{
	int ID_Cachorro;
	char Nombre[20];
	int Dias;
	char Raza[20];
	char Reservado[5];
	char Genero[5];
}Cachorro;

Cachorro* new_cachorro();
Cachorro* new_cachorroConParametros(char* id, char* nombre, char* dias, char* raza, char* reservado, char* genero);

int cachorros_callejeros(void* this);
int cachorros_dias(void* this);
int cachorros_machos(void* this);

#endif /* CACHORROS_H_ */
