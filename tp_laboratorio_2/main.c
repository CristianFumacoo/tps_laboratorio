#include <stdio.h>
#include <stdlib.h>
#include "employees.h"

#define TAM 10

int main()
{
    int opc;
    int idEmpleado = 5;
    int respuesta;
    eEmployee empleados[TAM];
    initEmployees(empleados,TAM);
    hardcoreEmployees(empleados,TAM);

    do
    {
        opc = menu();

        switch(opc)
        {
            case 1:
                respuesta = addEmployees(empleados,TAM,idEmpleado);
                if(respuesta != -1)
                {
                    idEmpleado++;
                    printf("Empleado cargado correctamente.\n");
                }
                else
                {
                    printf("No se pudo cargar.");
                }

                system("pause");
                system("cls");
                break;
            case 2:
                system("cls");
                modifyEmployees(empleados,TAM);
                printf("El empleado se modifico correctamente.\n");
                system("pause");
                system("cls");
                break;
            case 3:
                system("cls");
                deleteEmployees(empleados,TAM);
                printf("El empleado fue borrado correctamente.\n");
                    system("pause");
                    system("cls");
                break;
            case 4:
                //printEmployees(empleados,TAM);
                orderEmployees(empleados,TAM);
                    system("pause");
                    system("cls");
                break;
        }

    }while(opc != 6);
}
