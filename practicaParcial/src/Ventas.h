typedef struct
{
    int ID_Venta;
    char Fecha_Venta[20];
    char Tipo_Foto[20];
    int Cantidad;
    int Precio_Unitario;
    char CUIT_Cliente [30];
}Venta;

Venta* venta_new();
Venta* venta_newConParametros(char* id,char* fecha,char* tipo,char* cantidad, char* precio,char* cuit);
void Venta_delete(Venta* this);

int Venta_setId(Venta* this,int id);

int Venta_setFecha(Venta* this,char* fecha);

int Venta_setTipo_Foto(Venta* this,char* Tipo_Foto);

int Venta_setCantidad(Venta* this,int Cantidad);

int Venta_setPrecio_Unitario(Venta* this,int Precio_Unitario);

int Venta_setCUIT_Cliente(Venta* this,char* CUIT_Cliente);

int Ventas_Total_Count(void* thisA);
int Venta_getCantidad_Foto(Venta* this, int* cantidad);

