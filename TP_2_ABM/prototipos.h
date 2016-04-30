#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

typedef struct{

    char nombre[50];
    int edad;
    int estado;
    int dni;

}ePersona;

void inicializarPersona(ePersona lista[], int cantidad);
void agregarPersonas(ePersona lista[], int cantidad, int indice);
int borrarPersona(ePersona lista[], int cantidad, int numDni);
void mostrarListaPersonas(ePersona lista[], int cantidad);
int buscarDesocupado(ePersona lista[], int cantidad);
void graficoDeBarras (ePersona lista[], int cantidad);
#endif // PROTOTIPOS_H_INCLUDED
