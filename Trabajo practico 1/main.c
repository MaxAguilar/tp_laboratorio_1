#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "prototipos.h"

int main()
{
    char seguir='s';
    int opcion=0, flagA=0, flagB=0, auxFac;
    float A=0,B=0, resultado;
    double resultadoF;

    printf("\n  ------------------------------------- ");
    printf("\n  -   BIENVENIDO A TP1_CALCULADORA    - ");
    printf("\n  ------------------------------------- \n\n");
    system("pause");
    system("cls");

    while(seguir=='s')
    {
        system("cls");
        printf("\nMENU \n\n");
        printf("1- Ingresar 1er operando (A=%.2f) \n", A);
        printf("2- Ingresar 2do operando (B=%.2f) \n\n",B);
        printf("3- Calcular la suma \n");
        printf("4- Calcular la resta \n");
        printf("5- Calcular la division \n");
        printf("6- Calcular la multiplicacion \n");
        printf("7- Calcular el factorial (A) \n");
        printf("8- Calcular todas las operaciones\n\n");
        printf("9- Salir\n");

        printf("\nOpcion: ");
        scanf("%d",&opcion);

        while(opcion<1||opcion>9)
        {
            printf("ingrese una opcion valida (1-9)");
            printf("\nOpcion: ");
            scanf("%d",&opcion);
        }

        switch(opcion)
        {
            case 1:
                printf("\npor favor ingrese el valor de A: ");
                scanf("%f",&A);
                flagA=1;
                auxFac=A;
                break;

            case 2:
                printf("\npor favor ingrese el valor de B: ");
                scanf("%f",&B);
                flagB=1;
                break;

            case 3:
                if(flagA==0||flagB==0)
                    {
                        printf("\nNecesita ingresar al menos una vez los valores de A y B \n\n");
                    }
                    else
                    {
                        resultado=realizarSuma(A,B);
                        printf("\nla suma es igual a: %.2f \n\n", resultado);
                    }
                system("pause");

                break;

            case 4:
                if(flagA==0||flagB==0)
                    {
                        printf("\nNecesita ingresar al menos una vez los valores de A y B \n\n");
                    }
                    else
                    {
                        resultado=realizarResta(A,B);
                        printf("\nla resta es: %.2f \n\n ", resultado);
                    }
                system("pause");

                break;

            case 5:
                if(flagA==0||flagB==0)
                    {
                        printf("\nNecesita ingresar al menos una vez los valores de A y B \n\n");
                    }
                    else
                    {
                        if(B==0)
                        {
                            printf("\nNo se puede dividir entre cero...\n\n");
                        }
                        else
                        {
                            resultado=(float)realizarDivision(A,B);
                            printf("\nla division es: %.2f \n\n", resultado);
                        }
                    }
                system("pause");

                break;

            case 6:
                if(flagA==0||flagB==0)
                    {
                        printf("\nNecesita ingresar al menos una vez los valores de A y B \n\n");
                    }
                    else
                    {
                        resultado=realizarMultiplicacion(A,B);
                        printf("\nla multiplicacion es: %.2f \n\n", resultado);
                    }
                system("pause");

                break;

            case 7:
                 if(flagA==0)
                    {
                        printf("\nNecesita ingresar al menos una vez el valor de A \n\n");
                    }
                    else
                    {
                        if(A<0||A-auxFac!=0)
                        {
                            printf("\nNo se puede obtener factorial de numeros negativos o numeros con coma...\n\n");
                        }
                        else
                        {
                            resultadoF=realizarFactorial(A);
                            printf("\nEl factorial de A es: %.0lf\n\n", resultadoF);
                        }
                    }
                system("pause");

                break;

            case 8:
                if(flagA==0||flagB==0)
                    {
                        printf("\nNecesita ingresar al menos una vez los valores de A y B \n\n");
                    }
                    else
                    {

                        resultado=realizarSuma(A,B);
                        printf("\nLa suma es: %.2f \n ", resultado);
                        resultado=realizarResta(A,B);
                        printf("\nLa resta es: %.2f \n ", resultado);
                        if(B==0)
                        {
                            printf("\nNo se puede dividir entre cero...\n");
                        }
                        else
                        {
                            resultado=(float)realizarDivision(A,B);
                            printf("\nLa division es: %.2f \n ", resultado);
                        }
                        resultado=realizarMultiplicacion(A,B);
                        printf("\nLa multiplicacion es: %.2f \n ", resultado);
                        if(A<0||A-auxFac!=0)
                        {
                            printf("\nNo se puede obtener factorial de numeros negativos o numeros con coma...\n ");
                        }
                        else
                        {
                            resultadoF=realizarFactorial(A);
                            printf("\nEl factorial de A es: %.0lf \n\n ", resultadoF);
                        }
                    }
                    system("pause");

                    break;

            case 9:
                seguir ='n';
                printf("\nSesion Finalizada\n");
                printf("\n- GRACIAS POR UTILIZAR TP1_CALCULADORA -\n\n");

                break;
        }

    }

    return 0;

}
