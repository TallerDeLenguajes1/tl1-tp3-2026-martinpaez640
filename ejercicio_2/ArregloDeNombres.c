#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void MostrarPersonas(char *p[]);
int main()
{
    char *p[5], buff[50];
    for (int i = 0; i < 5; i++)
    {
        printf("\nIngrese un numbre: ");
        gets(buff);
        p[i] = (char *)malloc(sizeof(char) * (strlen(buff) + 1));
        strcpy(p[i], buff);
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
int BuscarNombre(char *p[])
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