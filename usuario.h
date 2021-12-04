#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "diccionario.h"
#include "motor.h"
#include "colors.h"



nodoP* crearNodoPalabras(char* palabra, nodoT* ocurrencias);
void mostrarListaDePalabras(nodoP* listaDePalabras);
void mostrarNodosCoincidentesDosID(nodoT* ocurrencias, int ID1, int ID2);
nodoT* BuscarNodosCoincidentesUnID(nodoT* ocurrencias, int ID);
void mostrarNodosCoincidentesUnID(nodoT* ocurrencias, int ID1);
int buscarCoincidenciaID(nodoT* ocurrencias, int ID);
void buscarEnDosDoc(nodoA* motor,char* palabra, int ID1, int ID2);
void buscarVariosTerminosEnUnDoc(nodoA* motor, char* palabra, int ID);
void palabraMasFrecuentePorDoc(nodoA* motor, int ID, int comparar);
int retornarMaximaFrecuencia(nodoT* ocurrencias, int ID);

#endif // USUARIO_H_INCLUDED
