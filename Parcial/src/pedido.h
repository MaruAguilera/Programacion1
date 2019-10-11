#define TEXT_SIZE 50
typedef struct
{
    int idPedido;
    int isEmpty;
    int idCliente;

    //-----------------
    char tipoPlastico[TEXT_SIZE];
    char estado[TEXT_SIZE];
    int kgTotales;


}Pedido;

int pedido_buscarEmpty(Pedido arrayPedido[], int size, int* posicion);
