int getInt(char mensaje[]);
int utn_getFloat(char* msg, char* msgError, int minSize, int maxSize, int min, int max, int reintentos, float* input);
int isValidFloatNumber(char* stringRecibido);
int utn_getString(char* msg, char* msgError, int min, int max, int reintentos, char* resultado);
int isValidName(char* stringRecibido);
int getString(char* msg, char* msgError, int min, int max, int* reintentos, char* resultado);
int utn_getIntConSigno(char* msg, char* msgError, int minSize, int maxSize, int min, int max, int reintentos, int* input);
int isValidSignedNumber(char* stringRecibido);
int utn_getIntSinSigno(  char* msg,char* msgError,int minSize,int maxSize,int min,int max,int reintentos,int* input);
int isValidNumber(char* stringRecibido);
int isValidChar(char charRecibido);