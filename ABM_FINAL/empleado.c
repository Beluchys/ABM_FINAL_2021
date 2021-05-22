#include "empleado.h"
#include "sector.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int menu()
{
    int opcion;
    system("cls");
    printf("            Gestion de Empleados \n");
    printf("\n");
    printf("1.- Alta Empleado. \n");
    printf("2.- Modificar Empleado. \n");
    printf("3.- Baja Empleado. \n");
    printf("4.- Lista de Empleados. \n");
    printf("5.- Ordenar Empleados. \n");
    printf("6.- Mostrar Sectores. \n");
    printf("7.- Informes. \n");
    printf("8.- Mostrar Comidas. \n");
    printf("9.- Alta Almuerzos. \n");
    printf("10.- Mostrar Almuerzos. \n");
    printf("11.- Sector que mas cobra. \n");
    printf("12.- Mostrar almuerzos por empleado. \n");
    printf("13.- Total gasto almuerzo por empleado. \n");
    printf("14.- Salir. \n");
    printf("\n");
    printf("Ingrese Opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
//********************************************************************************//

int altaEmpleado(eEmpleado lista[], int tam, int* pId, eSector sectores[], int tamSec)
{
    system("cls");
    printf("    *** Alta Empleado ***   \n\n");
    printf("Legajo: %d \n", *pId);
    int indice;
    int todoOk = 0; //false
    eEmpleado nuevoEmpleado;

    if(lista !=NULL && tam > 0 && pId != NULL)
    {
        indice = buscarLugar(lista, tam);
        if(indice == -1)
        {
            printf("No hay lugar en el Sistema. \n");
        }
        else
        {
            nuevoEmpleado.legajo = *pId;

            printf("Ingrese Nombre del Empleado: ");
            fflush(stdin);
            gets(nuevoEmpleado.nombre);

            printf("Ingrese Edad del Empleado: ");
            scanf("%d", &nuevoEmpleado.edad);

            printf("Ingrese el Sexo del empleado: ");
            fflush(stdin);
            scanf("%c", &nuevoEmpleado.sexo);

            printf("Ingrese el sueldo del Empleado: ");
            scanf("%f", &nuevoEmpleado.sueldo);

            printf("Ingrese fecha de ingreso dd/mm/aaaa: ");
            scanf("%d/%d/%d", &nuevoEmpleado.fechaDeIngreso.dia,
                  &nuevoEmpleado.fechaDeIngreso.mes,
                  &nuevoEmpleado.fechaDeIngreso.anio);
            printf("\n");

            mostrarSectores(sectores, tamSec);
            printf("Ingrese Sector: ");
            scanf("%d", &nuevoEmpleado.idSector);



            nuevoEmpleado.isEmpty = 0;
            lista[indice] = nuevoEmpleado;

            *pId = (*pId)+1; //ACTUALIZAMOS EL PROXIMO ID
            todoOk=1;
        }
    }
    return todoOk;
}

//************************************************************************************//

int modificarDatos(eEmpleado lista[], int tam, eSector sectores[], int tamSec)
{
    int todoOk = 0;
    int indice;
    int legajo;
    char confirma;

    system("cls");
    printf("    **** MODIFICAR EMPLEADO **** \n\n");
    mostrarEmpleados(lista, tam, sectores, tamSec);
    printf("\n\n Ingrese Legajo: ");
    scanf("%d", &legajo);

    indice = buscarEmpleado(lista, tam, legajo);

    printf("\n\n\n      ****  EMPLEADO ENCONTRADO  ****\n\n");
    printf(" Legajo           Nombre  Edad    Sexo     Sueldo    Fecha de Ingreso\n");
    mostrarEmpleado(lista[indice], sectores, tamSec);

    do
    {

        switch(subMenuModificar())
        {
        case 1:
            printf("Ingrese el nuevo Nombre: ");
            fflush(stdin);
            gets(lista[indice].nombre);
            todoOk = 1;
            printf("\n");
            mostrarEmpleado(lista[indice], sectores, tamSec);

            break;
        case 2:
            printf("Ingrese la nueva Edad: ");
            scanf("%d", &lista[indice].edad);
            todoOk = 1;
            printf("\n");
            mostrarEmpleado(lista[indice], sectores, tamSec);
            break;
        case 3:
            printf("Ingrese la nuevo sexo: ");
            scanf("%c", &lista[indice].sexo);
            todoOk = 1;
            printf("\n");
            mostrarEmpleado(lista[indice], sectores, tamSec);
            break;
        case 4:
            printf("Ingrese el nuevo sueldo: ");
            scanf("%f", &lista[indice].sueldo);
            todoOk = 1;
            printf("\n");
            mostrarEmpleado(lista[indice], sectores, tamSec);
            break;
        case 5:
            printf("Ingrese la nueva fecha de ingreso dd/mm/aaaa: ");
            scanf("%d/%d/%d", &lista[indice].fechaDeIngreso.dia,
                  &lista[indice].fechaDeIngreso.mes,
                  &lista[indice].fechaDeIngreso.anio);
            todoOk = 1;
            printf("\n");
            mostrarEmpleado(lista[indice], sectores, tamSec);
            break;
        case 6:
            printf("Desea Salir?");
            scanf("%c", &confirma);

            break;
        default:
            printf("Opcion incorrecta.");
        }

        system("pause");
    }
    while(confirma=='s');

    return todoOk;
}

//***************************************************************************//
int subMenuModificar()
{
    int opcion;
    printf("\n\n QUE DESEA MODIFICAR DEL EMPLEADO?\n\n ");
    printf("1.- Nombre del Empleado. \n");
    printf("2.- Edad. \n");
    printf("3.- Sexo. \n");
    printf("4.- Sueldo. \n");
    printf("5.- Fecha de Ingreso. \n");
    printf("6.- Nada - Salir. \n");
    printf("\n");
    printf("Ingrese Opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

//*************************************************************************//


int bajaEmpleado(eEmpleado lista[], int tam, eSector sectores[], int tamSec)
{
    int todoOk = 0;
    int indice;
    int legajo;
    char confirma;


    system("cls");
    printf("    **** BAJA EMPLEADO **** \n\n");

    mostrarEmpleados(lista, tam, sectores, tamSec);
    printf("\n\n Ingrese Legajo: ");
    scanf("%d", &legajo);


    indice = buscarEmpleado(lista, tam, legajo);

    if(indice == -1)
    {
        printf("El empleado que desea buscar NO EXISTE EN EL SISTEMA.\n\n");
    }
    else
    {
        mostrarEmpleado(lista[indice], sectores, tamSec);
        printf("Confirma la baja? \n");
        fflush(stdin);
        scanf("%c", &confirma);
        if(confirma == 's')
        {
            lista[indice].isEmpty = 1;
            todoOk = 1;
            printf("Se realizo la baja de forma CORRECTA.\n");
        }
        else
        {
            printf("Baja cancelada por el Usuario.\n");
        }
    }
    return todoOk;
}

//******************************************************************************//

void mostrarEmpleado(eEmpleado unEmpleado, eSector sectores[], int tam)
{
    char descripcion[20];

    if(cargarDescripcionSector(unEmpleado.idSector, sectores, tam, descripcion))
    {
    printf("   %d      %10s    %d      %c     %9.2f     %02d/%02d/%d       %s \n",
           unEmpleado.legajo,
           unEmpleado.nombre,
           unEmpleado.edad,
           unEmpleado.sexo,
           unEmpleado.sueldo,
           unEmpleado.fechaDeIngreso.dia,
           unEmpleado.fechaDeIngreso.mes,
           unEmpleado.fechaDeIngreso.anio,
           descripcion
          );
    }else{
    printf("Hubo un problema con la descripcion del Sector");
    }
}

//******************************************************************************//

void mostrarEmpleados(eEmpleado lista[], int tam, eSector sectores[], int tamSec)
{
    int flag = 1;

    printf("                       ****LISTA DE EMPLEADOS****       \n");
    printf("\n");
    printf(" Legajo           Nombre  Edad    Sexo     Sueldo    Fecha de Ingreso   Sector\n");
    for(int i=0 ; i < tam ; i++)
    {
        if( !lista[i].isEmpty  )  //SI NO ESTA VACIA ENTRA ---
        {
            mostrarEmpleado(lista[i], sectores, tamSec);
            flag=0;
        }
    }
    if(flag ==1)
    {
        printf("No hay empleados para Mostrar. \n");
    }
    printf("\n");
}

//******************************************************************************//
int buscarEmpleado(eEmpleado lista[], int tam, int legajo)
{
    int indice = -1;
    if(lista != NULL && tam > 0)
    {
        for(int i=0 ; i<tam ; i++)
        {
            if(!lista[i].isEmpty && lista[i].legajo == legajo)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

//******************************************************************************//
int buscarLugar(eEmpleado lista[], int tam)
{
    int indice = -1;
    if(lista != NULL && tam > 0)
    {
        for(int i=0 ; i<tam ; i++)
        {
            if(lista[i].isEmpty)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}
//******************************************************************************//
void actualizarSueldosPorSector(eEmpleado lista[], int tam, eSector sectores[], int tamSec)
{
    int idSector;
    int porcentaje;
    float sueldo;
    float nuevoSueldo;
    char descripcion[20];

    system("cls");
    printf("       **** ACTUALIZAR SUELDOS POR SECTOR **** \n\n");
    mostrarSectores(sectores, tamSec);
    printf("\n\n");
    printf("Ingrese el ID del Sector a informar: ");
    scanf("%d", &idSector);
    cargarDescripcionSector(idSector, sectores, tamSec, descripcion);

    printf("Ingrese el porcentaje de aumento: ");
    scanf("%d", &porcentaje);

    for(int i=0; i<tam; i++)
    {
        if(lista[i].idSector == idSector && lista[i].isEmpty == 0) // si lista esta lleno u ocupado
        {
           sueldo = lista[i].sueldo;
           nuevoSueldo = sueldo + sueldo * porcentaje/100;
           lista[i].sueldo = nuevoSueldo;
        }
    }
    printf("\n\n El sueldo nuevo del sector %s esta actualizado.", descripcion);
    printf("\n\n");

}
//***************************************************************************//
void ordenar(eEmpleado lista[], int tam, eSector sectores[], int tamSec) //ORDEN POR SEXO DESCENDENTE Y POR LEGAJO ASCENDENTE
{
    eEmpleado auxEmpleado;

    for(int i=0 ; i<tam-1 ; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(lista[i].sexo < lista[j].sexo)
            {
                auxEmpleado = lista[i];
                lista[i] = lista[j];
                lista[j] = auxEmpleado;
            }
            else if(lista[i].sexo == lista[j].sexo && lista[j].legajo > lista[i].legajo)
            {
                auxEmpleado = lista[i];
                lista[i] = lista[j];
                lista[j] = auxEmpleado;
            }
        }
    }
}

//**********************************************************************//
void inicializarEmpleado(eEmpleado lista[], int tam)
{
    for(int i=0 ; i < tam ; i++)
    {
        lista[i].isEmpty = 1;
    }
}
//**********************************************************************//

int cargarNombreDelEmpleado(int legajo, eEmpleado lista[], int tam, char nombre[])
{
    int retorno=0;
    if(legajo>=20000 && legajo<=29000 && lista!=NULL && tam>0 && nombre!=NULL)
    {
        for(int i=0; i<tam; i++)
        {
            if(lista[i].legajo==legajo && !lista[i].isEmpty)
            {
                strcpy(nombre, lista[i].nombre);
                retorno=1;
                break;
            }
        }
    }
    return retorno;
}
//**********************************************************************//

int sectorQueMasCobra(eEmpleado lista[], int tam, eSector sectores[], int tamSec)
{
    int retorno=-1;
    float totales[tamSec];
    float auxFloat;
    int idSector;
    int mayor;

    printf("\n\n");
    for(int i=0; i<tamSec; i++)//RECORRO EL ARRAY DE SECTORES
    {
        auxFloat=0; // RESETEO EL FLOAT
        idSector=sectores[i].id; // PARA VER EL ID DEL SECTOR

        for(int j=0; j<tam; j++)
        {
            if(lista[j].isEmpty == 0 && lista[j].idSector == idSector) //BUSCO DENTRO SI ES EMPLEADO ACTIVO
            {
                auxFloat += lista[j].sueldo; // TOTALIZAMOS TODOS LOS SUELDOS DE LOS EMPLEADOS DE ESE SECTOR
            }
        }
        totales[i] = auxFloat; // GUARDO EL TOTAL DE CADA SECTOR EN UNA POSICIÓN DEL ARRAY
    }

    // BUSCAMOS EL MAYOR DE TODOS LOS ARRAYS
    mayor = totales[0];

    for(int i=1; i < tamSec; i++)
    {
        if(totales[i] > mayor)
        {
            mayor = totales[i];
        }
    }

    printf("Los sectores que mas cobran son: \n");
    for(int i=0; i<tamSec; i++)
    {
        if(totales[i] == mayor)
        {
            printf(" - %s ", sectores[i].descripcion);
            retorno = 1;
        }
    }
    printf("\n\n");
    return retorno;
}
//**********************************************************************//
