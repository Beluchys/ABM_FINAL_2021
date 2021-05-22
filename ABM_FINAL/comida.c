#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "comida.h"

int mostrarComidas(eComida comidas[], int tamCom)
{
    system("cls");
    printf("          **** LISTA DE COMIDAS ****\n\n");
    printf(" ID COMIDAS       DESCRIPCION              PRECIO\n\n");
    for(int i=0; i<tamCom ; i++)
    {
        mostrarUnaComida(comidas[i]);
        printf("\n");
    }
    printf("\n\n");
    return 0;
}
void mostrarUnaComida(eComida unaComida)
{

        printf("   %d      %15s            %9.2f", unaComida.idComida, unaComida.descripcion, unaComida.precio);
}

int buscarComida(eComida comidas[], int tamCom, int idComida)
{
    int indice = -1;
    if(comidas != NULL && tamCom > 0)
    {
        for(int i=0 ; i<tamCom ; i++)
        {
            if(comidas[i].idComida == idComida)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}
int cargarDescripcionComida(int idComida, eComida comidas[], int tamCom, char descripcion[])
{
    int todoOk = 0;
    if(idComida >= 1001 && idComida <=1005 && comidas != NULL && tamCom > 0 && descripcion != NULL)
    {
        for(int i=0 ; i<tamCom ; i++)
        {
            if(comidas[i].idComida == idComida)
            {
                strcpy(descripcion, comidas[i].descripcion);
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;
}
