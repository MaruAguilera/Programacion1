#define TEXT_SIZE 50
typedef struct
{
    int idCliente;
    int isEmpty;
    //-----------------
    char nombreEmpresa[TEXT_SIZE];
    char direccion [TEXT_SIZE];
    char localidad [TEXT_SIZE];
    int cuit;



}Cliente;

int cliente_Inicializar(Cliente arrayClientes[], int size);
int cliente_buscarEmpty(Cliente arrayCliente[], int size, int* posicion);
int cliente_alta(Cliente arrayClientes[], int size, int* contadorID);
int cliente_buscarID(Cliente arrayCliente[], int size, int valorBuscado, int* posicion);
