#include "perro.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "utn.h"

Perro* perro_new() {
	return (Perro*)malloc(sizeof(Perro));
}

Perro* perro_newParametros(char* idStr,char* nombreStr,char* diasStr, char* razaStr, char* reservadoStr, char* sexoStr) {
	Perro* aux;
	aux = perro_new();
	printf("newParam1\nId:%s\nNombre: %s\nDias: %s\nRaza: %s\nReservado: %s\nSexo: %s\n\n", idStr, nombreStr, diasStr, razaStr, reservadoStr, sexoStr);
	if(aux != NULL) {
    int setId = perro_setIdStr(aux, idStr);
    int setNombre = perro_setNombre(aux, nombreStr);
    int setDias = perro_setDiasStr(aux, diasStr);
    int setRaza = perro_setRaza(aux, razaStr);
    int setReservado = perro_setReservado(aux, reservadoStr);
    int setSexo = perro_setSexo(aux, sexoStr);

    if (setId != 0) {
      printf("Problema al cargar id\n");
      return NULL;
    }

    if (setNombre != 0) {
      printf("Problema al cargar nombre\n");
      return NULL;
    }

    if (setDias != 0) {
      printf("Problema al cargar dias\n");
      return NULL;
    }

    if (setRaza != 0) {
      printf("Problema al cargar raza\n");
      return NULL;
    }

    if (setReservado != 0) {
      printf("Problema al cargar id\n");
      return NULL;
    }

    if (setSexo != 0) {
      printf("Problema al cargar id\n");
      return NULL;
    }
	}

	return aux;
}

int perro_delete(Perro* this) {
	int ret = -1;
	if(this != NULL) {
		free(this);
		ret = 0;
	}
	return ret;
}

int perro_setIdStr(Perro* this,char* idStr) {
    int ret = -1;
    int auxId;
    if(this != NULL && idStr != NULL) {
        if(isValidNumber(idStr) == 0) {
            auxId = atoi(idStr);
            if(perro_setId(this, auxId) == 0) {
                ret = 0;
            }
        }
    }
    return ret;
}

int perro_setId(Perro* this,int id) {
    int ret = -1;
    if(this != NULL && id >= 0) {
      this->id = id;
      ret = 0;
    }
    return ret;
}

int perro_getId(Perro* this,int* id) {
    int ret = -1;
    if(this != NULL && id != NULL) {
      *id = this->id;
      ret = 0;
    }
    return ret;
}

int perro_setNombre(Perro* this,char* nombre) {
    int ret = -1;
    if(this != NULL && isValidName(nombre) == 0) {
      strncpy(this->nombre,nombre,sizeof(this->nombre));
      ret = 0;
    }
    return ret;
}

int perro_getNombre(Perro* this,char* nombre) {
    int ret = -1;
    if(this != NULL && nombre != NULL) {
      strcpy(nombre,this->nombre);
      ret = 0;
    }
    return ret;
}

int perro_setDiasStr(Perro* this,char* diasStr) {
    int ret = -1;
    int auxDias;
    if(this != NULL && diasStr != NULL) {
      if(isValidNumber(diasStr) == 0) {
        auxDias = atoi(diasStr);
        if(perro_setDias(this, auxDias) == 0) {
        	perro_setDias(this, auxDias);
          ret = 0;
        }
      }
    }
    return ret;
}

int perro_setDias(Perro* this,int dias) {
    int ret = -1;
    if(this != NULL && dias > 0) {
      this->dias = dias;
      ret = 0;
    } else {
    printf("error");
    }
    return ret;
}

int perro_getDias(Perro* this,int* dias) {
  int ret = -1;
  if(this != NULL && dias != NULL) {
    *dias = this->dias;
    ret = 0;
  }
  return ret;
}

int perro_setRaza(Perro* this,char* raza) {
    int ret = -1;
    if(this != NULL && isValidName(raza) == 0) {
      strncpy(this->raza,raza,sizeof(this->raza));
      ret = 0;
    }
    return ret;
}

int perro_getRaza(Perro* this,char* raza) {
    int ret = -1;
    if(this != NULL && raza != NULL) {
      strcpy(raza,this->raza);
      ret = 0;
    }
    return ret;
}

int perro_setReservado(Perro* this,char* reservado) {
    int ret = -1;
    if(this != NULL && isValidName(reservado) == 0) {
      strncpy(this->reservado,reservado,sizeof(this->reservado));
      ret = 0;
    }
    return ret;
}

int perro_getReservado(Perro* this,char* reservado) {
    int ret = -1;
    if(this != NULL && reservado != NULL) {
      strcpy(reservado,this->reservado);
      ret = 0;
    }
    return ret;
}

int perro_setSexo(Perro* this,char* sexo) {
    int ret = -1;
    if(this != NULL && isValidName(sexo) == 0) {
      strncpy(this->sexo,sexo,sizeof(this->sexo));
      ret = 0;
    }
    return ret;
}

int perro_getSexo(Perro* this,char* sexo) {
    int ret = -1;
    if(this != NULL && sexo != NULL) {
      strcpy(sexo,this->sexo);
      ret = 0;
    }
    return ret;
}

int filtrarMenores45Dias(void* perro) {
	int returnAux = -1;
	int dias;
	if(perro != NULL) {
		perro_getDias(perro, &dias);
		if(dias < 45) {
			returnAux = 0;
		}
	}
	return returnAux;
}

int filtrarMachos(void* perro) {
	int returnAux = -1;
	char sexo[64];
	if(perro != NULL) {
		perro_getSexo(perro, sexo);
		if(strcmp(sexo, "H")) {
			returnAux = 0;
		}
	}
	return returnAux;
}

int filtrarRazas(void* perro) {
	int returnAux = -1;
	char raza[64];
	if(perro != NULL) {
		perro_getRaza(perro, raza);
		if(strcmp(raza, "Callejero")) {
			returnAux = 0;
		}
	}
	return returnAux;
}
