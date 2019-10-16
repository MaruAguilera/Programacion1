#define TEXT_SIZE 50

typedef struct
{
	int HDPE;
	int LDPE;
	int PP;
	int otros;
}tipoPlastico;


typedef struct
{
    int idPedido;
    int isEmpty;
    int idCliente;

    //-----------------    struct tipoPlastico;

    tipoPlastico tipo_plastico;
    char estado[TEXT_SIZE];
    int kgTotales;


}Pedido;

int pedido_buscarEmpty(Pedido arrayPedido[], int size, int* posicion);
int contadorDePendientes(Pedido arrayPedidos[],int size, int idCliente);
