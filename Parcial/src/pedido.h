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
int pedido_Inicializar(Pedido arrayPedido[], int size);
int pedido_alta(Pedido arrayPedido[], int size, int* contadorID);
int pedido_buscarEmpty(Pedido arrayPedidos[], int size, int* posicion);
int pedido_listar(Pedido arrayPedidos[], int size);
int pedido_ingresarkg(Pedido arrayPedidos[], int sizeArray);
int pedido_buscarID(Pedido arrayPedidos[], int size, int valorBuscado, int* posicion);
int pedido_buscarEmpty(Pedido arrayPedido[], int size, int* posicion);
int contadorDePendientes(Pedido arrayPedidos[],int size, int idCliente);
int contadorDeCompletados(Pedido arrayPedidos[], int size, int idCliente);
