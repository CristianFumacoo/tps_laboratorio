#include <stdio.h>
#include "calcu.h"

int ingresarPrimerNumero()
{
    int num;

    printf("Ingrese el numero: ");
    scanf("%d",&num);

    return num;
}
int ingresarSegundoNumero()
{
    int num;

    printf("Ingrese el numero: ");
    scanf("%d",&num);

    return num;
}

int sumarNumeros(int numeroUno, int numeroDos)
{
    int resultado;
        resultado = numeroUno + numeroDos;

    return resultado;
}
int restarNumeros(int numeroUno, int numeroDos)
{
    int resultado;
        resultado = numeroUno - numeroDos;

    return resultado;
}

int multiplicarNumeros(int numeroUno, int numeroDos)
{
    int resultado;
        resultado = numeroUno * numeroDos;

    return resultado;
}

float dividirNumeros(float numeroUno, float numeroDos)
{
    float resultado;

        if(numeroUno == 0 && numeroDos == 0)
        {
            printf("No se puede realizar esta operacion\n");
            return 0;
        }
        if(numeroDos == 0)
        {
            printf("No se puede dividir por 0");
            return 0;
        }

        resultado = numeroUno / numeroDos;

    return resultado;
}

int factorialNumeros(int num)
{
    int resultado = 1;

    if(num > 0)
    {
        for(int i = 1; i <= num; i++)
        {
            resultado *= i;
        }
    }
    else
    {
        printf("\nNo se puede sacar factorial de numeros negativos.");
        return 0;
    }
    return resultado;
}

