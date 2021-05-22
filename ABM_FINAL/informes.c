#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "informes.h"
#include "empleado.h"
#include "sector.h"



int empleadosSector(eEmpleado lista[], int tam, eSector sectores[], int tamSec)
{
    int idSector;
    int contador=0;
    char descripcion[20];

    system("cls");
    printf("      **** INFORME DE EMPLEADOS POR SECTOR **** \n\n");
    mostrarSectores(sectores, tamSec);
    printf("\n\n");
    printf("Ingrese el ID del Sector a informar: ");
    scanf("%d", &idSector);
    cargarDescripcionSector(idSector, sectores, tamSec, descripcion);

    for(int i=0; i<tam; i++)
    {
        if(lista[i].idSector == idSector && lista[i].isEmpty == 0) // si lista esta lleno u ocupado
        {
            contador++;
        }
    }
    if(contador == 0)
    {
        printf("No hay empleados en el sector %s \n\n", descripcion);
    }
    else
    {
        printf("Para el Sector %s hay %d empleado/s \n\n", descripcion, contador);
    }
    printf("\n\n");
    return contador;
}
//*******************************************************************************//
int subMenuInformes()
{
    int opcion;
    system("cls");
    printf("            **** INFORMES **** \n");
    printf("\n");
    printf("1.- Cantidad de Empleados por Sector. \n");
    printf("2.- Actualizacion de Sueldos por Sector. \n");
    printf("3.- Informe sueldos y el Total de Sueldos. \n");
    printf("4.- Salir. \n");
    printf("\n");
    printf("Ingrese Opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

//*******************************************************************************//
void aPonerla(eEmpleado lista[], int tam, eSector sectores[], int tamSec)
{
    float totalSector;
    float total=0;

    system("cls");
    printf("   **** INFORME SUELDOS POR SECTOR Y TOTAL ****\n\n");
    for(int i=0; i<tamSec; i++) // RECORRO EL ARRAY DE SECTORES - ME POSICIONA SOBRE LOS SECTORES
    {
        totalSector = 0; //RESETEO EL ACUMULADOR DE LOS SUELDOS
        printf("Sector: %s\n",sectores[i].descripcion); //CUANDO ARRANCO UN SECTOR NUEVO MUESTO EL NOMBRE DEL SECTOR
        for(int j=0; j<tam; j++) // RECORRO EL ARRAY DE EMPLEADOS ACTIVOS QUE PERTENEZCAN A ESE SECTOR
        {
            if(!lista[j].isEmpty && lista[j].idSector == sectores[i].id) //BUSCO EMPLEADOS NO VACIO - ACTIVOS Y QUE EL SERCTOR DE EMPLEADO SEA IGUAL AL ID DEL SECTOR DONDE ESTOY ARRANCANDO
            {
                totalSector += lista[j].sueldo; //ACUMULO EL SUELDO DEL EMPLEADO
            }
        }
        printf("Total: $%.2f\n\n",totalSector);
        total += totalSector; //ACUMULO EL TOTAL DE LOS SECTORES 1 A 1
    }
    printf("El Total de todos los sueldos de la empresa es: $%.2f\n",total);
    printf("\n\n");
}
//*******************************************************************************//
void totalesComidasPorSector(eAlmuerzo almuerzo[], int tamAlm, eComida comidas[], int tamCom, eEmpleado lista[], int tam, eSector sectores[], int tamSec)
{
    float total;
    int flag = 1;

    for(int i=0; i<tamSec; i++)
    {
        total=0;
        for(int j=0;j<tam;j++)
        {
            if(lista[j].isEmpty == 0 && lista[j].idSector == sectores[i].id)
            {
                for(int k=0; k<tamAlm;k++)
                {
                    if(almuerzo[k].isEmpty == 0 && almuerzo[k].legEmpleado == lista[j].legajo)
                    {
                        for(int l=0;l<tamCom;l++)
                        {
                            if(comidas[l].idComida == almuerzo[k].idComida)
                            {
                                total+= comidas[l].precio;
                                flag=0;
                            }
                        }
                    }
                }
            }
        }
        if(flag==0)
        {
            printf("El sector %s tiene un total de $.2f en Comidas.",sectores[i].descripcion, total);
        }else{
        printf("El sector %s no registra Comidas.",sectores[i].descripcion);
        }
    }
}
