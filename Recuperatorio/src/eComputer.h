#ifndef ECOMPUTER_H_
#define ECOMPUTER_H_

typedef struct{
	int ID;
	char Descripcion[20];
	int precio;
	int idTipo;
	char oferta[20];
}eComputer;

eComputer* new_eComputer();
eComputer* new_eComputerConParametros(char* id, char* descripcion, char* precio, char* idTipo);
int Computadora_setOferta(eComputer* this,char* oferta);
int Computadora_setIdTipo(eComputer* this,int idTipo);
int Computadora_setPrecio(eComputer* this,int precio);
int Computadora_descripcion(eComputer* this,char* descripcion);
int Computadora_setId(eComputer* this,int id);


int computer_order_idTipo(void* this, void* thisMasUno);
int computer_oferta(void* this);
int computer_desktop(void* this);

#endif /* ECOMPUTER_H_ */
