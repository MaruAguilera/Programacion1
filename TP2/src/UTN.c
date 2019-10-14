#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int utn_getInt(  int* pInt, char* msg,
                    char msgErr[],int min, int max,
                    int reintentos)

{
    int retorno=-1;
    int buffer;
    if( pInt != NULL &&  msg != NULL && msgErr != NULL &&
         min <= max && reintentos >= 0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            if( getInt(&buffer) == 0 &&
                buffer >= min && buffer <= max)
            {
                retorno = 0;
                *pInt = buffer;
                break;
            }
            else
            {
                printf("%s",msgErr);
            }
        }while(reintentos >= 0);
    }
    return retorno;
}



int getInt(int* pBuffer)
{
    char bufferString [4096];
    int retorno = -1;


   // if(getString(bufferString,4096) == 0 && verificarArregloSoloNumeros(bufferString)==0)
    //{
      //  *pBuffer = atoi(bufferString);
        //retorno = 0;
    //}

    return retorno;
}

