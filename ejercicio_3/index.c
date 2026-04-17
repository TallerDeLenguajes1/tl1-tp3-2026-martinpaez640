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
void mostrar(Cliente *p, float total);
void liberar(Cliente *p, int cant);
int main()
{
    char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"}, buff[50];

    int cant = 0;
    float total = 0;
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
            clientes[i].Productos[d].TipoProducto = TiposProductos[0 + rand() % 5];
            clientes[i].Productos[d].PrecioUnitario = (float)(10 + rand() % 91);
            total += costoTotal(clientes[i].Productos[d]);
        }
        mostrar(&clientes[i], total);
        total = 0;
    }
    liberar(clientes, cant);
    return 0;
}
void liberar(Cliente *p, int cant)
{
    for (int i = 0; i < cant; i++)
    {
        free(p[i].Productos);
    }
    free(p);
}
void mostrar(Cliente *p, float total)
{
    printf("\nId del cliente %d", p->ClienteID);
    printf("\nNombre del cliente: ");
    puts(p->NombreCliente);
    printf("\nCantidad de productos el cliente: %d", p->CantidadProductosAPedir);
    for (int i = 0; i < p->CantidadProductosAPedir; i++)
    {
        printf("\nProducto ID %d", p->Productos[i].ProductoID);
        printf("\nCantidad de productos: %d", p->Productos[i].Cantidad);
        printf("\nPrecio unitario del producto: %f", p->Productos[i].PrecioUnitario);
        printf("\nNombre del producto: ");
        puts(p->Productos[i].TipoProducto);
    }
    printf("Total a pagar del cliente: %f", total);
}
float costoTotal(Producto p)
{
    return (float)p.Cantidad * p.PrecioUnitario;
}