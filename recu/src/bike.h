typedef struct{
	int ID_BIKE;
	char NOMBRE[200];
	char TIPO [200] ;
	int TIEMPO;
	int VEL_PROMEDIO;
}Participante;
int participante_setId(Participante* this,int id);
int paricipante_Setnombre(Participante* this,char* nombre);
int participante_setTiempo(Participante* this,int tiempo);
int Computadora_setVelProm(Participante* this,int vel_promedio);
int participante_setTipoBici(Participante* this,char* tipo);
int participante_getTipoBici(Participante* this,char* TipoBici);
int participante_getVelPromedio(Participante* this,int* vel_prom);
int participante_getTiempo(Participante* this,int* tiempo);
int participante_getNombre(Participante* this,char* nombre);
int participante_getId(Participante* this,int* id);
