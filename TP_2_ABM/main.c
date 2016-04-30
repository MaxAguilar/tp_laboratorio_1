#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "prototipos.h"
#define TAM 20

int main()
{
    ePersona persona[TAM];
    inicializarPersona(persona,TAM);
    int indiceDesocupado;
    int dniAux;
    char seguir='s';
    int opcion=0;
    int flagAltas=0;

    printf("\n  ----------------------------- ");
    printf("\n  -   BIENVENIDO A TP2_ABM    - ");
    printf("\n  ----------------------------- \n\n");
    system("pause");
    system("cls");

    while(seguir=='s')
    {
        system("cls");
        printf("MENU \n\n");
        printf("****\n\n");
        printf("1- Agregar una persona\n");
        printf("2- Borrar una persona\n");
        printf("3- Imprimir lista ordenada por nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        printf("\nOpcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                indiceDesocupado=buscarDesocupado(persona,TAM);
                if(indiceDesocupado!=-1)
                {
                    agregarPersonas(persona,TAM,indiceDesocupado);
                    persona[indiceDesocupado].estado=1;
                }
                else
                {
                    printf("\nNO HAY ESPACIO DISPONIBLE");
                }
                flagAltas=1;
                break;
                system("pause");
                system("cls");
            case 2:
                if(flagAltas==0)
                    {
                        printf("\nDEBE INGRESAR AL MENOS UNA PERSONA\n");
                        system("pause");
                    }
                else
                    {
                        printf("\nINGRESE DNI DE LA PERSONA QUE DESEA BORRAR: ");
                        scanf("%d",&dniAux);
                        indiceDesocupado=borrarPersona(persona,TAM,dniAux);
                        if(indiceDesocupado!=-1)
                        {
                            persona[indiceDesocupado].estado=-1;
                            persona[indiceDesocupado].dni=-1;
                            persona[indiceDesocupado].edad=-1;
                            printf("\nPERSONA ELIMINADA CON EXITO\n\n");
                        }
                        else
                        {
                            printf("\nNO SE ENCONTRO EL DNI INGRESADO\n");
                        }
                        system("pause");
                    }
                break;
            case 3:
                if(flagAltas==0)
                    {
                        printf("\nDEBE INGRESAR AL MENOS UNA PERSONA\n");
                        system("pause");
                    }
                else
                    {
                        mostrarListaPersonas(persona,TAM);
                        system("pause");
                    }
                break;
            case 4:
                if(flagAltas==0)
                    {
                        printf("\nDEBE INGRESAR AL MENOS UNA PERSONA\n");
                        system("pause");
                    }
                else
                    {
                        graficoDeBarras(persona,TAM);
                        system("pause");
                    }
                break;
            case 5:
                seguir='n';
                printf("\nSESION FINALIZADA\n");
                printf("\n- GRACIAS POR UTILIZAR TP2_ABM -\n\n");
                system("pause");
                break;
            default:
                printf("\nNO INGRESO UNA OPCION VALIDA (1-5)\n\n");
                system("pause");
        }
    }

    return 0;
}
