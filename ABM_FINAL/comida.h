#ifndef COMIDA_H_INCLUDED
#define COMIDA_H_INCLUDED

typedef struct{
    int idComida; //Primary Key de comida
    char descripcion[20];
    float precio;
}eComida;


#endif // COMIDA_H_INCLUDED

int mostrarComidas(eComida comidas[], int tamCom);
void mostrarUnaComida(eComida unaComida);
int buscarComida(eComida comidas[], int tamCom, int idComida);
int cargarDescripcionComida(int idComida, eComida comidas[], int tamCom, char descripcion[]);
