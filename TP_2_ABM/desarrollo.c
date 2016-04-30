#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "prototipos.h"

/** \brief recibe una estructura y su tamañano, e inicializa todas sus variables;
 *
 * \param ePersona Lista[] -nombre de la estructura;
 * \param cantidad -tamaño de la estructura;
 * \return void
 *
 */

void inicializarPersona(ePersona lista[],int cantidad)
{
    int i;
    for(i=0; i<cantidad; i++)
    {
        lista[i].estado=-1;
        lista[i].edad=-1;
        lista[i].dni=-1;
    }
}





/** \brief recibe una estructura y su tamaño, y devuelve la primera posicion libre que encuentre;
 *
 * \param ePersona Lista[] -nombre de la estructura;
 * \param cantidad -tamaño de la estructura;
 * \return devuelve un entero que corresponde a la posicion libre encontrada.
 *
 */

int buscarDesocupado(ePersona lista[],int cantidad)
{
    int indice=-1;
    int i;
    for(i=0; i<cantidad; i++)
    {
        if(lista[i].estado==-1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}






/** \brief recibe la estructura, su tamaño, y la posicion libre donde se van a guardar los datos(nombre,edad,dni);
 *
 * \param ePersona Lista[] -nombre de la estructura;
 * \param cantidad -tamaño de la estructura;
 * \param indice -posicion libre;
 * \return void
 *
 */

void agregarPersonas(ePersona lista[],int cantidad,int indice)
{
    printf("\nIngrese nombre: ");
    fflush(stdin);
    gets(lista[indice].nombre);

    printf("Ingrese edad: ");
    fflush(stdin);
    scanf("%d", &lista[indice].edad);
    while(lista[indice].edad<1||lista[indice].edad>100)
        {
            printf("EDAD NO VALIDA, POR FAVOR REINGRESE (1-99)\n");
            fflush(stdin);
            scanf("%d",&lista[indice].edad);
        }

    printf("Ingrese dni: ");
    fflush(stdin);
    scanf("%d", &lista[indice].dni);

    printf("\nDatos guardados con exito...\n");
    system("pause");
}







/** \brief recibe la estructura, su tamaño, y el dni de la persona que desea borrar, busca a la persona y de ser encontrada, devuelve su ubicacion para ser borrada.
 *
 * \param ePersona Lista[] -nombre de la estructura;
 * \param cantidad -tamaño de la estructura;
 * \param numDni -dni de la persona que desea borrar;
 * \return devuelve la ubicacion;
 *
 */

int borrarPersona(ePersona lista[],int cantidad,int numDni)
{
    int indice=-1;
    int i;
    for(i=0; i<cantidad; i++)
    {
        if(lista[i].dni==numDni)
        {
            indice=i;
        }
    }
    return indice;
}





/** \brief recibe una estructura y su tamaño, la ordena, y la muestra por pantalla;
 *
 * \param ePersona Lista[] -nombre de la estructura;
 * \param cantidad -tamaño de la estructura;
 * \return void
 *
 */

void mostrarListaPersonas(ePersona lista[],int cantidad)
{
    int comparar;
    int i;
    int j;
    for(i=0; i<cantidad-1; i++)
    {
        for(j=i+1; j<cantidad; j++)
        {
            if(lista[j].estado==-1)
            {
                continue;
            }
            ePersona personaAux;
            comparar=stricmp(lista[i].nombre,lista[j].nombre);
            if(comparar==1)
            {
                personaAux=lista[i];
                lista[i]=lista[j];
                lista[j]=personaAux;
            }
        }
    }
    for(i=0;i<cantidad;i++)
    {
        if(lista[i].estado!=-1)
        {
        printf("Nombre: %s, Edad: %d, Dni: %d",lista[i].nombre,lista[i].edad,lista[i].dni);
        printf("\n");
        }
    }
}





/** \brief recibe una estructura y su tamaño, divide las edades en 3 grupos, y los muestra por pantalla;
 *
 * \param
 * \param
 * \return void;
 *
 */

void graficoDeBarras (ePersona lista[], int cantidad)
{
    int i,hasta18=0,de19a35=0,mayorDe35=0,flag=0,mayor;

    for(i=0;i<cantidad;i++)
        {
            if(lista[i].edad>0&&lista[i].edad<=18)
                {
                    hasta18++;
                }
            if(lista[i].edad>=19&&lista[i].edad<=35)
                {
                    de19a35++;
                }
            if(lista[i].edad>35)
                {
                    mayorDe35++;
                }
        }

    if(hasta18>=de19a35&&hasta18>=mayorDe35)
    {
        mayor=hasta18;
    }
    else
    {
        if(de19a35>=hasta18&&de19a35>= mayorDe35)
        {
            mayor=de19a35;
        }
        else
        {
            mayor=mayorDe35;
        }
    }

    for(i=mayor;i>0;i--)
    {
        if(i<10)
        {
            printf("%02d|",i);
        }
        else
        {
            printf("%02d|",i);
        }

        if(i<= hasta18)
        {
            printf("*");
        }

        if(i<= de19a35)
        {
            flag=1;
            printf("\t*");
        }

        if(i<= mayorDe35)
        {
            if(flag==0)
                printf("\t\t*");
            if(flag==1)
                printf("\t*");
        }
        printf("\n\n");
    }
    printf("--+-----------------");
    printf("\n  |<18\t19-35\t>35");
    printf("\n   %d\t%d\t%d", hasta18, de19a35, mayorDe35);
}
