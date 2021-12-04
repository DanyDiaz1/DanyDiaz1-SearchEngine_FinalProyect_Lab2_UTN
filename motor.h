#ifndef MOTOR_H_INCLUDED
#define MOTOR_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "diccionario.h"
#include <alg.h>
#include "colors.h"

typedef struct nodoT {

    int idDOC;
    int pos;
    struct nodoT* sig;

} nodoT;

typedef struct nodoA{

    char palabra[20];
    int frecuencia; //Representa la cantidad de nodos de la lista
    nodoT* ocurrencias; //Ordenada por idDOC, luego por pos
    struct nodoA* der;
    struct nodoA* izq;

} nodoA;

typedef struct nodoP
{

    char palabra[MAX_WORD];
    nodoT* ocurrencias;
    struct nodoP* sig;

} nodoP;

typedef struct
{
    int IDDoc;
    int pos;

}palabra;

//PROTOTIPADO
nodoA* crearNodoArbol(char* palabra);
nodoT* crearNodoOcurrencia(termino palabra);
void insertarNodoArbol(nodoA** motor, termino palabra);
void insertarNodoOcurrencia(nodoT** ocurrencia, termino palabra);
void cargarMotor(nodoA** motor);
void mostrarUnNodo(nodoA* dato);
void mostrarMotor(nodoA* motor);
void mostrarListaDeOcurrencias(nodoT* ocurrencias);
void mostrarUnaOcurrencia(nodoT* nodoOcurrencia);

nodoA* busquedaUnica(nodoA* motor, char* palabra);
int cantPalabrasFrase(char* frase);
void insertarPalabraAlFinal(nodoP** listaDePalabras, char* palabra, nodoT* ocurrencias); //usuario.c
int verificarExistencias(nodoA* motor, char* frase);
void cargarPalabrasDeLaFrase(nodoA* motor, nodoP** listaPalabras, char* frase);
int cantTotalDeRepeticiones(nodoP* listaPalabras);
void cargarUbicaciones(nodoP* listaPalabras,palabra* ubicaciones);
void mostrarUbicaciones(palabra* ubicaciones,int validos);
void cargarUbicacionesEncontradas(palabra* fraseEncontrada,int i, int idDoc,int pos);
void BuscarFrase(nodoP* listaPalabras, int cantPalabras);
int Levenshtein(char *s1, char *s2);
nodoA* sugerirPalabra(nodoA* motor, char* palabra);

#endif // MOTOR_H_INCLUDED
