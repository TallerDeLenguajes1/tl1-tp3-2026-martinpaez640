#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Producto
{
    int ProductoID;       // Numerado en ciclo iterativo
    int Cantidad;         // entre 1 y 10
    char *TipoProducto;   // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
} Producto;
typedef struct Cliente
{
    int ClienteID;               // Numerado en el ciclo iterativo
    char *NombreCliente;         // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos;         // El tamaño de este arreglo depende de la variable                  //  “CantidadProductosAPedir”
} Cliente;
float costoTotal(Producto p);
int main()
{

    char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"}, buff[50];

    int cant = 0;
    printf("Ingrese la cantidad de Cliente: ");
    scanf("%d", &cant);
    Cliente *clientes = (Cliente *)malloc(sizeof(Cliente) * (size_t)cant);
    for (int i = 0; i < cant; i++)
    {
        clientes[i].ClienteID = i;
        getchar();
        printf("Ingresar nombre del cliente: ");
        gets(buff);
        clientes[i].NombreCliente = (char *)malloc(strlen(buff) + 1);
        strcpy(clientes[i].NombreCliente, buff);
        clientes[i].CantidadProductosAPedir = 1 + rand() % 5;
        clientes[i].Productos = (Producto *)malloc(sizeof(Producto) * (size_t)clientes[i].CantidadProductosAPedir);
        for (int d = 0; d < clientes[i].CantidadProductosAPedir; d++)
        {
            clientes[i].Productos[d].ProductoID = d;
            clientes[i].Productos[d].Cantidad = 1 + rand() % 10;
            clientes[i].Productos[d].TipoProducto = TiposProductos[0 + rand() % 4];
            clientes[i].Productos[d].PrecioUnitario = (float)(10 + rand() % 91);
            printf("\nLa cantidad total es: %f", costoTotal(clientes[i].Productos[d]));
        }
    }

    return 0;
}
float costoTotal(Producto p)
{
    return (float)p.Cantidad * p.PrecioUnitario;
}