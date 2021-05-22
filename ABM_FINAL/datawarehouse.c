#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include  "datawarehouse.h"

static char nombres[10][20]=
{
    "Donato",
    "Maria",
    "Gisela",
    "Belen",
    "Emanuel",
    "Maximo",
    "Romina",
    "Carola",
    "Mariano",
    "Andres",
};

static char sexos[10]= {'m','f','f','f','m','m','f','f','m','m'};

static int edades[10]= {50,49,30,25,29,26,36,23,43,39};

static float sueldos[10]= {29000,85000,67000,53000,83000,20000,74000,60000,37000,46000};

// static char localidades[10][20]= {"Lanus","Avellaneda","Gerli","Escalada","Tigre","Caba","Caba","Lanus","Gerli","Avellaneda"};

static eFecha fechas[10]= {{12,5,2015},{1,12,2016},{7,9,2017},{9,6,2010},{5,12,2000},{9,3,2010},{1,10,2011},{12,9,2012},{9,8,2013},{25,6,2000}};

static int idSectores[10]= {500,504,500,502,501,501,503,500,503,504};

int hardcodearEmpleados(eEmpleado lista[],int tam, int cant, int* pLegajo)
{
    int totalEmpleados = 0;
    if(lista != NULL && tam > 0 && cant >=0 && cant <= tam && pLegajo != NULL)
    {
        for(int i=0 ; i < cant ; i++)
        {
            lista[i].legajo = *pLegajo;
            (*pLegajo)++;
            strcpy(lista[i].nombre, nombres[i]);
            lista[i].sexo = sexos[i];
            lista[i].edad = edades[i];
            lista[i].fechaDeIngreso = fechas[i];
            lista[i].idSector = idSectores[i];
            lista[i].isEmpty = 0;
            lista[i].sueldo = sueldos[i];
            totalEmpleados++;

        }
    }
    return totalEmpleados;
}

static int legEmpleados[20]= {20000,20000,20001,20002,20005,20003,20001,20007,20005,20006,20004,20009,20007,20005,20000,20001,20002,20005,20007,20003};

static int idComidasA[20]= {1001,1002,1002,1003,1002,1002,1001,1004,1003,1002,1001,1002,1001,1003,1004,1001,1001,1003,1002,1004};

static eFecha fechas2[30] =
{
    {2,3,2021},
    {21,5,2021},
    {10,4,2021},
    {2,3,2021},
    {21,11,2021},
    {10,8,2021},
    {2,3,2021},
    {21,5,2021},
    {10,8,2021},
    {10,8,2021},
    {7,3,2021},
    {21,5,2021},
    {10,12,2021},
    {12,5,2017},
    {23,1,2021},
    {12,3,2001},
    {21,5,2014},
    {10,12,2003},
    {22,2,2013},
    {23,1,2011},
    {26,3,2021},
    {2,3,2021},
    {21,5,2021},
    {10,8,2021},
    {7,3,2021},
    {21,5,2021},
    {10,12,2021},
    {12,5,2017},
    {23,1,2021},
    {12,3,2001}
};
int hardcodearAlmuerzos(eAlmuerzo almuerzos[], int tam, int cant, int* pId)
{
    int retorno=0;
    if(almuerzos!=NULL && tam>0 && cant>=0 && cant<=tam && pId!=NULL)
    {
        for(int i=0; i<cant; i++)
        {
            almuerzos[i].id=*pId;
            (*pId)++;
            almuerzos[i].idComida=idComidasA[i];
            almuerzos[i].legEmpleado=legEmpleados[i];
            almuerzos[i].fecha=fechas2[i];
            almuerzos[i].isEmpty = 0;
        }
    }
    return retorno;
}


