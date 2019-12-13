typedef struct{
	int id;
	char descripcion[200];
	int precio;
	int idTipo;
	char oferta[50];

}Computadora;


int compu_order(void* this, void* thisMasUno);
