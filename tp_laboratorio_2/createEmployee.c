#include <stdio.h>
#include <stdlib.h>
#include "createEmployee.h"

void createName(eEmployee empleado[],int cant,int accion)
{
    if(accion == ALTA)
    {
        for(int i=id; i<cant; i++)
        {
            printf("Ingrese el nombre del empleado: ");
            fflush(stdin);
            scanf("%[^\n]", &empleado[i].name);
            break;
        }
}

void createLastname(eEmployee empleado[],int cant)
{
    for(int i=0; i<cant; i++)
    {
        printf("Ingrese el apellido del empleado: ");
        fflush(stdin);
        scanf("%[^\n]", &empleado[i].lastName);
        break;
    }
}

void createSalary(eEmployee empleado[],int cant)
{
    for(int i=0; i<cant; i++)
    {
        printf("Ingrese el salario del empleado: ");
        scanf("%f", &empleado[i].salary);
        break;
    }
}

void createSector(eEmployee empleado[],int cant)
{
    for(int i=0; i<cant; i++)
    {
        printf("Ingrese el sector del empleado: ");
        scanf("%d", &empleado[i].sector);
        break;
    }
}
