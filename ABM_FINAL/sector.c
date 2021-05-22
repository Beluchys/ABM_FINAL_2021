#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sector.h"
#include "almuerzo.h"



void mostrarSectores(eSector sectores[], int tamSec)
{
    printf("     **** LISTA DE SECTORES ****   \n\n");
    printf(" ID      DESCRIPCION SECTOR\n\n");
    for(int i=0 ; i < tamSec ; i++)
    {
        mostrarSector(sectores[i]);
    }
    printf("\n\n");
}
//*************************************************************//
void mostrarSector(eSector unSector)
{
    printf(" %d           %10s\n", unSector.id, unSector.descripcion);

}
//**************************************************************//
int cargarDescripcionSector(int id, eSector sectores[], int tam, char descripcion[])
{
    int todoOk = 0;
    if(id >= 500 && id <=504 && sectores != NULL && tam > 0 && descripcion != NULL)
    {
        for(int i=0 ; i<tam ; i++)
        {
            if(sectores[i].id == id)
            {
                strcpy(descripcion, sectores[i].descripcion);
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;
}

//**************************************************************//


