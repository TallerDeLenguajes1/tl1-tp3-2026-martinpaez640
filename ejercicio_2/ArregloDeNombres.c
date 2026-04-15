#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void MostrarPersonas(char *p[]);
void BuscarNombre(char *p[], int num);
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
     BuscarNombre( p,  20);
    return 0;
}
void MostrarPersonas(char *p[])
{
    for (int i = 0; i < 5; i++)
    {
        puts(p[i]);
    }
}

void BuscarNombre(char *p[], int num)
{
    if (p[num]!=NULL)
    {
        printf("El nombre solicitao es: ");
        puts(p[num]);
    }else
    {
        printf("Nombre invalido");
    }
    
}