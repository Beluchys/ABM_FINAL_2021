#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "almuerzo.h"
#include "comida.h"


void inicializarAlmuerzos(eAlmuerzo almuerzos[], int tamAlm)
{
    for(int i=0; i<tamAlm; i++)
    {
        almuerzos[i].isEmpty = 1;
    }
}
//*****************************************************************************//
int buscarLibreAlmuerzo(eAlmuerzo almuerzos[], int tam)
{
    int indice=-1;
    if(almuerzos != NULL && tam > 0)
    {
        for(int i=0 ; i < tam ; i++)
        {
            if(almuerzos[i].isEmpty)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}
//*****************************************************************************//
int altaAlmuerzo(eAlmuerzo almuerzos[], int tamAlm, eEmpleado lista[], int tam, eSector sectores[], int tamSec, eComida comidas[], int tamCom, int* pIdAlmuerzo)
{
    int indice;
    int todoOk = 0; //false
    int legajo;
    int idComida;

    system("cls");
    printf("    *** ALTA ALMUERZO ***   \n\n");
    printf("Id Almuerzo: %d \n", *pIdAlmuerzo);

    eAlmuerzo nuevoAlmuerzo;

    if(lista !=NULL && tam > 0 && pIdAlmuerzo != NULL)
    {
        indice = buscarLibreAlmuerzo(almuerzos, tamAlm);
        if(indice == -1)
        {
            printf("No hay lugar para cargar nuevos almuerzos. \n");
        }
        else
        {
            nuevoAlmuerzo.id = *pIdAlmuerzo;

            mostrarEmpleados(lista, tam, sectores, tamSec);

            printf("Ingrese Legajo del Empleado: ");
            scanf("%d", &legajo);

            while (buscarEmpleado(lista,tam,legajo) == -1)
            {
                printf("No es un empleado valido. Reingrese Legajo: ");
                scanf("%d", &legajo);
            }

            nuevoAlmuerzo.legEmpleado = legajo;

            mostrarComidas(comidas, tamCom);

            printf("Ingrese ID comida: ");
            scanf("%d", &idComida);

            while(buscarComida(comidas, tamCom, idComida) == -1)
            {
                printf("Comida no valida. Reingrese el ID Comida: ");
                scanf("%d", &idComida);
            }

            nuevoAlmuerzo.idComida = idComida;

            printf("Ingrese fecha dd/mm/aaaa: ");
            scanf("%d/%d/%d", &nuevoAlmuerzo.fecha.dia,
                  &nuevoAlmuerzo.fecha.mes,
                  &nuevoAlmuerzo.fecha.anio);
            printf("\n");

            nuevoAlmuerzo.isEmpty = 0;
            almuerzos[indice] = nuevoAlmuerzo;

            *pIdAlmuerzo = (*pIdAlmuerzo) + 1; //ACTUALIZAMOS EL PROXIMO ID
            todoOk=1;
        }
    }
    return todoOk;

}
//*****************************************************************************//
void mostrarUnAlmuerzo(eAlmuerzo unAlmuerzo, eComida comidas[], int tamCom, eEmpleado lista[], int tam)
{
    char descricpcion[20];
    char nombre[20];
    if(cargarDescripcionComida(unAlmuerzo.idComida,comidas,tamCom,descricpcion)&&
       cargarNombreDelEmpleado(unAlmuerzo.legEmpleado,lista,tam,nombre))
    {
        printf("%5d    %5d    %10s    %10s   %02d/%02d/%4d\n",unAlmuerzo.id,
                                                    unAlmuerzo.legEmpleado,
                                                    nombre,
                                                    descricpcion,
                                                    unAlmuerzo.fecha.dia,
                                                    unAlmuerzo.fecha.mes,
                                                    unAlmuerzo.fecha.anio);
    }
    else
    {
        printf("Hubo un problema al cargar la descripcion de la comida\n");
    }
}
//*****************************************************************************//
int mostrarAlmuerzos(eAlmuerzo almuerzos[], int tamAlm, eComida comidas[], int tamCom, eEmpleado lista[], int tam)
{
    int retorno=-1;
    int flag=0;
    if(almuerzos!=NULL && tamAlm>0)
    {
        retorno=0;
        printf("      LISTA DE ALMUERZOS\n");
        printf(" ID     Legajo     Empleado      Comida        Fecha\n");
        for(int i=0; i<tamAlm; i++)
        {
            if(!almuerzos[i].isEmpty)
            {
                mostrarUnAlmuerzo(almuerzos[i],comidas,tamCom,lista,tam);
                flag=1;
            }
        }
        if(!flag)
        {
            printf("No hay almuerzos cargados.\n");
        }
    }
    return retorno;
}
//*****************************************************************************//
void mostrarAlmuerzosEmpleado(eEmpleado lista[],int tam, eAlmuerzo almuerzo[], int tamAlm, eComida comidas[], int tamCom, eSector sectores[], int tamSec)
{
    int legajo;
    int flag = 0;

    system("cls");
    mostrarEmpleados(lista, tam,sectores,tamSec);
    printf("                     **** ALMUERZOS POR EMPLEADO **** \n\n");
    printf("Ingrese Legajo: ");
    scanf("%d", &legajo);

    while(buscarEmpleado(lista, tam, legajo) == -1)
    {

        printf("El empleado que desea buscar NO EXISTE EN EL SISTEMA.\n\n");
        printf("Ingrese Legajo nuevamente: ");
        scanf("%d", &legajo);
    }
        printf("\n                     **** LISTA DE ALMUERZO **** \n");
        printf(" ID     Legajo     Empleado      Comida        Fecha\n");
        for(int i=0; i<tamAlm; i++)
        {
            if(almuerzo[i].legEmpleado == legajo && !almuerzo[i].isEmpty)
            {
                mostrarUnAlmuerzo(almuerzo[i],comidas,tamCom,lista,tam);
                flag=1;

            }
        }
        if(!flag)
        {
            printf("No hay almuerzos cargados.\n\n");
        }
        printf("\n\n");
}
//*******************************************************************************//
void totalGastoAlmuerzo(eAlmuerzo almuerzo[], int tamAlm, eComida comidas[], int tamCom, eEmpleado lista[], int tam, eSector sectores[], int tamSec)
{
    int legajo;

    int flag = 0;
    float total=0;

    system("cls");
    mostrarEmpleados(lista, tam,sectores,tamSec);
    printf("                     **** TOTAL ALMUERZOS POR EMPLEADO **** \n\n");
    printf("Ingrese Legajo: ");
    scanf("%d", &legajo);

    while(buscarEmpleado(lista, tam, legajo) == -1)
    {

        printf("El empleado que desea buscar NO EXISTE EN EL SISTEMA.\n\n");
        printf("Ingrese Legajo nuevamente: ");
        scanf("%d", &legajo);
    }
        printf("\n                     **** LISTA DE ALMUERZO **** \n");
        printf(" ID     Legajo     Empleado      Comida        Fecha\n");
        for(int i=0; i<tamAlm; i++)
        {
            if(almuerzo[i].legEmpleado == legajo && !almuerzo[i].isEmpty)
            {
                for(int j=0; j< tamCom ;j++)
                {
                    if(comidas[j].idComida == almuerzo[i].idComida)
                    {
                        total += comidas[j].precio;
                        mostrarUnAlmuerzo(almuerzo[i],comidas,tamCom,lista,tam);
                        flag=1;
                    }
                }
            }
        }
        if(!flag)
        {
            printf("\nEl empleado %d no registra almuerzo.\n\n", legajo);
        }else
        {

            printf("\nTotal a pagar $%.2f\n",total);
        }
        printf("\n\n");
}
