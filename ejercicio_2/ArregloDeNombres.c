#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void MostrarPersonas(char *p[]);
void BuscaNombrePorId(char *p[], int num);
int BuscaNombrePorPalabra(char *p[]);
int main()
{
    int opcion = 0, id = 0;
    char *p[5], buff[50];
    for (int i = 0; i < 5; i++)
    {
        printf("\nIngrese un nombre: ");
        gets(buff);
        p[i] = (char *)malloc(sizeof(char) * (strlen(buff) + 1));
        strcpy(p[i], buff);
    }
    printf("Para elegir buscar por nombre seleccione 1, para elegir buscar por coincidencia sleccione 2: ");
    scanf("%d", &opcion);

    if (opcion == 1)
    {
        printf("\nSeleccione un id");
        scanf("%d", &id);
        BuscaNombrePorId(p, 20);
    }
    else
    {
        getchar();
        int f = BuscaNombrePorPalabra(p);
        if (f != -1)
        {
            printf("\nEl nombre buscado por palabra es:  %s", p[f]);
        }
        else
        {
            printf("No se encontro coincidencias");
        }
    }

    MostrarPersonas(p);

    return 0;
}
void MostrarPersonas(char *p[])
{
    for (int i = 0; i < 5; i++)
    {
        puts(p[i]);
    }
}
int BuscaNombrePorPalabra(char *p[])
{
    char aux[50];
    printf("Ingrese el nombre que decea buscar: ");
    gets(aux);
    for (int i = 0; i < 5; i++)
    {
        if (strstr(p[i], aux) != NULL)
        {
            return i;
        }
    }
    return -1;
}

void BuscaNombrePorId(char *p[], int num)
{
    if (p[num] != NULL)
    {
        printf("El nombre solicitao es: ");
        puts(p[num]);
    }
    else
    {
        printf("Nombre invalido");
    }
}