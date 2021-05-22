
#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED
#include "sector.h"
#include "fecha.h"

typedef struct
{
    int legajo;
    char nombre[20];
    int edad;
    char sexo;
    float sueldo;
    eFecha fechaDeIngreso;
    int idSector;
    int isEmpty; //ESTA VACIO -- 1 si esta Vacio ---- 0 si esta lleno
}eEmpleado;

int menu();
int altaEmpleado(eEmpleado lista[], int tam, int* pId, eSector sectores[], int tamSec);
int modificarDatos(eEmpleado lista[], int tam, eSector sectores[], int tamSec);
int subMenuModificar();
int bajaEmpleado(eEmpleado lista[], int tam, eSector sectores[], int tamSec);
void mostrarEmpleado(eEmpleado unEmpleado, eSector sectores[], int tam);
void mostrarEmpleados(eEmpleado lista[], int tam, eSector sectores[], int tamSec);
int buscarEmpleado(eEmpleado lista[], int tam, int legajo);
int buscarLugar(eEmpleado lista[], int tam);
void inicializarEmpleado(eEmpleado lista[], int tam);
void ordenar(eEmpleado lista[], int tam, eSector sectores[], int tamSec);
void actualizarSueldosPorSector(eEmpleado lista[], int tam, eSector sectores[], int tamSec);
int cargarNombreDelEmpleado(int legajo, eEmpleado lista[], int tam, char nombre[]);
int sectorQueMasCobra(eEmpleado lista[], int tam, eSector sectores[], int tamSec);
#endif // EMPLEADO_H_INCLUDED

