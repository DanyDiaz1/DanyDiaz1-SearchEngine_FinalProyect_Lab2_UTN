#ifndef DICCIONARIO_H_INCLUDED
#define DICCIONARIO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colors.h"

#define diccionario "diccionario.dat"
#define MAX_WORD 20
#define CANT_DOCS 5

typedef struct {

    char palabra[MAX_WORD];
    int idDOC;
    int pos; //incrementa palabra por palabra, y no letra por letra

} termino;

termino cargarUnTermino(char* palabra, int idDoc, int pos);
void mostrarUnaPalabra(termino palabra);
void mostrarTodasLasPalabrasCargadas(termino* arregloDePalabras, int cantPalabras);
int contarPalabrasDocs();
void guardarPalabrasDelDocumento(termino* arregloDePalabras, int* validos);
void cargarPalabrasAlDiccionario(termino* arregloDeTerminos, int validos);
void recorrerDiccionario();

#endif // DICCIONARIO_H_INCLUDED
