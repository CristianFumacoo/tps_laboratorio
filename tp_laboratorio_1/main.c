#include <stdio.h>
#include <stdlib.h>

#include "calcu.h"

int main()
{
    int opcion;
    char respuesta = 's';
    int primerNumero = 0;
    int segundoNumero = 0;
    int resultadoSuma;
    int resultadoResta;
    int resultadoMulti;
    float resultadoDivi;
    int factorialNumUno;
    int factotialNumDos;

    do
    {
        printf("1.Ingresar primer numero. \n");
        printf("2.Ingresar segundo numero\n");
        printf("3.Hacer operaciones.\n");
        printf("4.Mostrar resultados.\n");
        printf("5.Salir.\n\n");
        printf("Primer numero: %d", primerNumero);
        printf("\nSegundo numero: %d\n\n", segundoNumero);
        printf("Ingrese una opcion: ");


        scanf("%d", &opcion);
        system("cls");

        switch(opcion)
        {
            case 1:
                primerNumero = ingresarPrimerNumero();
                printf("\nNumero ingresado correctamente.\n");
                break;
            case 2:
                segundoNumero = ingresarSegundoNumero();
                printf("\nNumero ingresado correctamente.\n");
                break;
            case 3:
                resultadoSuma = sumarNumeros(primerNumero,segundoNumero);

                resultadoResta = restarNumeros(primerNumero,segundoNumero);

                resultadoMulti = multiplicarNumeros(primerNumero,segundoNumero);

                resultadoDivi = dividirNumeros(primerNumero,segundoNumero);

                factorialNumUno = factorialNumeros(primerNumero);

                factotialNumDos = factorialNumeros(segundoNumero);

                printf("\nResultados se hicieron correctamente.\n");
                break;

            case 4:
                printf("El resultado de la suma es: %d\n", resultadoSuma);

                printf("El resultado de la resta es: %d\n", resultadoResta);

                printf("El resultado de la multiplicacion es: %d\n", resultadoMulti);

                printf("El resultado de la division es: %f\n", resultadoDivi);

                printf("El factorial del primer numero es: %d\n", factorialNumUno);

                printf("El factorial del segundo numero es: %d\n", factotialNumDos);


                break;

            case 5:
                respuesta = 'n';
                printf("Hasta luego!\n");
                break;


        }

        system("pause");
        system("cls");

    }while(respuesta == 's');



}
