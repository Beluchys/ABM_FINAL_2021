#ifndef SECTOR_H_INCLUDED
#define SECTOR_H_INCLUDED
#include "empleado.h"
#include "comida.h"
#include "almuerzo.h"

typedef struct
{
    int id;
    char descripcion[20];
} eSector;

void mostrarSectores(eSector sectores[], int tamSec);
void mostrarSector(eSector unSector);
int cargarDescripcionSector(int id, eSector sectores[], int tam, char descripcion[]);
#endif // SECTOR_H_INCLUDED



