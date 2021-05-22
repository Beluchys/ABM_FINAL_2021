#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"
#include "sector.h"
#include "informes.h"
#include "comida.h"
#include "almuerzo.h"
#include "datawarehouse.h"


#define TAM 10
#define TAMSEC 5
#define TAMCOM 5
#define TAMALM 30

int main()
{

    char seguir = 's';
    char submenu;
    int nextId = 20000;
    int nextIdAlmuerzo = 50000;
    eAlmuerzo almuerzos[TAMALM];
    eEmpleado nomina [TAM];
    eSector sectores[TAMSEC] =
    {
        {500, "Sistemas"},
        {501, "RRHH"},
        {502, "Cobranzas"},
        {503, "Legales"},
        {504, "Ventas"}
    };
    eComida comidas[TAMCOM] =
    {
        {1001, "Milanesa", 100},
        {1002, "Fideos", 120},
        {1003, "Churrasco", 140},
        {1004, "Ensalada", 160},
        {1005, "Pescado", 110}
    };

    inicializarEmpleado(nomina, TAM);
    inicializarAlmuerzos(almuerzos,TAMALM);
    hardcodearEmpleados(nomina, TAM, 10, &nextId);
 //   hardcodearAlmuerzos(almuerzos, TAM, 10, &nextIdAlmuerzo);

    do
    {
        switch(menu())
        {
        case 1:
            if (altaEmpleado(nomina, TAM, &nextId, sectores, TAMSEC))
            {
                printf("Alta Exitosa.\n");
            }
            else
            {
                printf("Hubo un problema al dar de alta.\n");
            }
            break;
        case 2:
            if (modificarDatos(nomina, TAM, sectores, TAMSEC))
            {
                printf("\n Modificacion Exitosa.\n");
            }
            else
            {
                printf("\n Hubo un problema en la modificacion.\n");
            }
            break;
        case 3:
            if (bajaEmpleado(nomina, TAM, sectores, TAMSEC))
            {
                printf("\n Baja Exitosa.\n");
            }
            else
            {
                printf("\n Hubo un problema al dar la baja.\n");
            }
            break;

        case 4:
            mostrarEmpleados(nomina, TAM, sectores, TAMSEC);
            break;
        case 5:
            ordenar(nomina, TAM, sectores, TAMSEC);
            break;
        case 6:
            mostrarSectores(sectores, TAMSEC);
            break;
        case 7:
            submenu = subMenuInformes();
            switch(submenu)
            {
            case 1:
                empleadosSector(nomina, TAM, sectores, TAMSEC);
                break;
            case 2:
                actualizarSueldosPorSector(nomina, TAM, sectores, TAMSEC);
                break;
            case 3:
                aPonerla(nomina, TAM, sectores,TAMSEC);
                break;
            case 4:
                main();
                break;
            }
            break;
        case 8:
            mostrarComidas(comidas, TAMCOM);
            break;
        case 9:
            if (altaAlmuerzo(almuerzos, TAMALM, nomina, TAM, sectores,TAMSEC,comidas,TAMCOM, &nextIdAlmuerzo))
            {
                printf("Alta Almuerzo Exitosa.\n");
            }
            else
            {
                printf("Hubo un problema al dar de alta.\n");
            }
            break;
        case 10:
            system("cls");
            mostrarAlmuerzos(almuerzos,TAMALM,comidas,TAMCOM,nomina,TAM);
            break;
        case 11:
            sectorQueMasCobra(nomina,TAM,sectores,TAMSEC);
            break;
            case 12:
            mostrarAlmuerzosEmpleado(nomina,TAM,almuerzos,TAMALM,comidas,TAMCOM,sectores,TAMSEC);
            break;
            case 13:
                totalGastoAlmuerzo(almuerzos,TAMALM,comidas,TAMCOM,nomina,TAM,sectores,TAMSEC);
                break;
                case 14:
                    totalesComidasPorSector(almuerzos,TAMALM,comidas,TAMCOM,nomina,TAM,sectores,TAMSEC);
        case 15:
            seguir='n';
            break;
        default:
            printf("Opcion invalidad.\n\n");

        }
        system("pause");

    }
    while(seguir=='s');

    return 0;
}
