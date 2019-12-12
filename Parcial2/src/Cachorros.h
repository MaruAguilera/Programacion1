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
int Cachorros_setId(Cachorro* this,int id);
int Cachorros_getId(Cachorro* this,int* id);
int Cachorros_Nombre(Cachorro* this,char* Nombre);
int Cachorros_setRaza(Cachorro* this,char* Raza);
int Cachorros_setDias(Cachorro* this,int Dias);
int Cachorros_setReservado(Cachorro* this,char* Reservado);
int Cachorros_Genero(Cachorro* this,char* Genero);
int Cachorros_getId(Cachorro* this,int* id);
int Cachorros_getNombre(Cachorro* this,char* nombre);
int Cachorros_getDias(Cachorro* this,int* dias);
int Cachorros_getRaza(Cachorro* this,char* Raza);
int Cachorros_getReservado(Cachorro* this,char* Reservado);
int Cachorros_getGenero(Cachorro* this,char* Genero);







int cachorros_callejeros(void* this);
int cachorros_dias(void* this);
int cachorros_machos(void* this);

#endif /* CACHORROS_H_ */
