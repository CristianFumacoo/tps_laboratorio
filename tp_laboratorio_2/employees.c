#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employees.h"

void initEmployees(eEmployee empleados[], int cant)
{
    for(int i=0; i<cant; i++)
    {
        empleados[i].salary = 0;
        empleados[i].sector = 0;
        strcpy(empleados[i].name, " ");
        strcpy(empleados[i].lastName, " ");
        empleados[i].isEmpty = 0;
    }
}

void hardcoreEmployees(eEmployee empleados[],int cant)
{
    int arraySalarios[3] = {15500,45000,78000};
    int arraySectores[3] = {12,21,45};
    char arrayNombres[3][51] = {"Cristian","Matias","Noelia"};
    char arrayApellidos[3][51] = {"Fumacoo","Gustavo","Anabel"};
    int arrayIsEmpty[3] = {1,1,1};
    int arrayId[3] = {1,2,3};

    for(int i=0;i<3;i++)
    {
        empleados[i].salary = arraySalarios[i];
        empleados[i].sector = arraySectores[i];
        empleados[i].isEmpty = arrayIsEmpty[i];
        empleados[i].id = arrayId[i];
        strcpy(empleados[i].name,arrayNombres[i]);
        strcpy(empleados[i].lastName,arrayApellidos[i]);
    }
}




int addEmployees(eEmployee empleado[],int cant,int idEmpleado)
{
    int flag = -1;
    for(int i=0; i<cant; i++)
    {
        if(empleado[i].isEmpty == 0)
        {

            printf("Ingrese el nombre del empleado: ");
            fflush(stdin);
            scanf("%[^\n]", &empleado[i].name);

            printf("Ingrese el apellido del empleado: ");
            fflush(stdin);
            scanf("%[^\n]", &empleado[i].lastName);

            printf("Ingrese el salario del empleado: ");
            scanf("%f", &empleado[i].salary);

            printf("Ingrese el sector del empleado: ");
            scanf("%d", &empleado[i].sector);

            empleado[i].isEmpty = 1;
            empleado[i].id = idEmpleado;
            flag = 0;
            break;
        }
    }

    return flag;
}

void printEmployees(eEmployee empleados[],int cant)
{
    printf("IDS --- NOMBRES --- APELLIDOS --- SECTORES --- SALARIOS\n");
    for(int i=0; i<cant; i++)
    {
        if(empleados[i].isEmpty != 0)
        {
            printf("%d %10s %11s %11d %15.f\n",empleados[i].id,empleados[i].name,empleados[i].lastName,empleados[i].sector,empleados[i].salary);
        }
    }
}

void modifyEmployees(eEmployee empleados[],int cant)
{
    int opc;
    int idModify;
    eEmployee modifyEmployee;

    printf("LISTA DE EMPLEADOS\n");
    printEmployees(empleados,cant);

    printf("\ningrese el id del empleado a modificar: ");
    scanf("%d",&idModify);

    for(int i=0; i<cant; i++)
    {
        if(empleados[i].id == idModify)
        {
            modifyEmployee = empleados[i];
            break;
        }
    }

    do
    {
        printf("\n¿Que desea modificar?\n");
        printf("1.Nombre.\n");
        printf("2.Apellido.\n");
        printf("3.Sector.\n");
        printf("4.Salario\n");
        printf("5.Salir.\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opc);

        switch(opc)
        {
        case 1:
            printf("Ingrese nuevo nombre: ");
            fflush(stdin);
            scanf("%[^\n]", &modifyEmployee.name);
            system("cls");
            break;
        case 2:
            printf("Ingrese nuevo apellido: ");
            fflush(stdin);
            scanf("%[^\n]", &modifyEmployee.lastName);
            system("cls");
            break;
        case 3:
            printf("Ingrese nuevo sector: ");
            scanf("%d", &modifyEmployee.sector);
            system("cls");
            break;
        case 4:
            printf("Ingrese nuevo salario: ");
            scanf("%f", &modifyEmployee.salary);
            system("cls");
            break;
        }
    }
    while(opc != 5);

    for(int i=0; i<cant; i++)
    {
        if(empleados[i].id == idModify)
        {
            empleados[i] = modifyEmployee;
            break;

        }
    }


}

void deleteEmployees(eEmployee empleado[],int cant)
{
    int indexId;

    printf("LISTA DE EMPLEADOS.");
    printEmployees(empleado,cant);

    printf("\nIngrese el id del empleado que quiere borrar: ");
    scanf("%d", &indexId);

    for(int i=0;i<cant;i++)
    {
        if(empleado[i].id == indexId)
        {
            empleado[i].isEmpty = 0;
        }
    }
}

void orderEmployees(eEmployee empleado[],int cant)
{
    eEmployee employee;

    int orderColum;

    printf("Como desea mostrarlos.\n");
    printf("1.Alfabeticamente por apellido.\n");
    printf("2.Por sector. \n");
    scanf("%d", &orderColum);

    for (int i = 0; i < cant-1; i++)
    {
        for (int j = i; j < cant; j++)
        {
            if(empleado[i].isEmpty == 1 && empleado[j].isEmpty == 1)
            {
                switch(orderColum)
                {
                    case 1:
                        if (strcmp(empleado[i].lastName, empleado[j].lastName)>0)
                        {
                            employee = empleado[j];
                            empleado[j] = empleado[i];
                            empleado[i] = employee;
                        }
                        break;

                    case 2:
                        if (empleado[i].sector > empleado[j].sector)
                        {
                            employee = empleado[i];
                            empleado[i] = empleado[j];
                            empleado[j] = employee;
                        }
                        break;
                }
            }
        }
    }
        printEmployees(empleado,cant);
        calculoSalario(empleado,cant);
}

void calculoSalario(eEmployee empleados[],int cant)
{
    float suma;
    float promedio;
    int contadorMayor = 0;
    int contadorEmpleados = 0;


    for(int i=0;i<cant;i++)
    {
        if (empleados[i].isEmpty == 1)
        {
            suma += empleados[i].salary;
            contadorEmpleados++;
        }
    }

    promedio = suma / contadorEmpleados;

    for(int i=0;i<cant;i++)
    {
        if(empleados[i].isEmpty == 1)
        {
            if(empleados[i].salary > promedio)
            {
                contadorMayor++;
            }
        }
    }

    printf("\nEl promedio de los salarios es: %8.f\n",promedio);
    printf("La cantidad de empleados que superan el salario promedio son: %d\n",contadorMayor);
}



