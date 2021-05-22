
#ifndef ALMUERZO_H_INCLUDED
#define ALMUERZO_H_INCLUDED
#include "empleado.h"
#include "sector.h"
#include "comida.h"
#include "fecha.h"




typedef struct{
    int id; //Primary Key de almuerzo
    int legEmpleado; //Primary Key de empleado
    int idComida; //Primary Key de comida
    eFecha fecha;
    int isEmpty;
}eAlmuerzo;

#endif // ALMUERZO_H_INCLUDED

void inicializarAlmuerzos(eAlmuerzo almuerzos[], int tamAlm);
void totalGastoAlmuerzo(eAlmuerzo almuerzo[], int tamAlm, eComida comidas[], int tamCom, eEmpleado lista[], int tam, eSector sectores[], int tamSec);
int buscarLibreAlmuerzo(eAlmuerzo almuerzos[], int tam); //DEVUELVE EL INDICE DEL PRIMER ALMUERZO VACIO Y SI NO HAY NINGUNO DEVUELVE MENOS UNO
int altaAlmuerzo(eAlmuerzo almuerzos[], int tamAlm, eEmpleado lista[], int tam, eSector sectores[], int tamSec, eComida comidas[], int tamCom, int* pIdAlmuerzo);
//SE FIJA SI HAY LUGAR / MUESTRA LOS EMPLEADOS Y PIDE LEGAJO / MUESTRA LAS COMIDAS Y PIDE EL ID DE LA COMIDA / PIDE LA FECHA / COPIA EL AUX ALMUERZO EN LA POSICION LIBRE DE ALMUERZO
void mostrarUnAlmuerzo(eAlmuerzo unAlmuerzo, eComida comidas[], int tamCom,eEmpleado lista[], int tam);
int mostrarAlmuerzos(eAlmuerzo almuerzos[], int tamAlm, eComida comidas[], int tamCom, eEmpleado lista[], int tam);
int hardcodearAlmuerzos(eAlmuerzo almuerzos[], int tam, int cant, int* pId);
void mostrarAlmuerzosEmpleado(eEmpleado lista[],int tam, eAlmuerzo almuerzo[], int tamAlm, eComida comidas[], int tamCom, eSector sectores[], int tamSec);

