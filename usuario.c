#include "usuario.h"

nodoP* crearNodoPalabras(char* palabra,nodoT* ocurrencias)
{

    nodoP* nuevo = (nodoP*)malloc(sizeof(nodoP));
    strcpy(nuevo->palabra, palabra);
    nuevo->ocurrencias = ocurrencias;
    nuevo->sig = NULL;

    return nuevo;
}

void insertarPalabraAlFinal(nodoP** listaDePalabras, char* palabra, nodoT* ocurrencias)
{
    nodoP* nuevo = crearNodoPalabras(palabra, ocurrencias);
    nodoP* aux;

    if(*listaDePalabras == NULL)
    {
        *listaDePalabras = nuevo;
    }
    else
    {
        aux = *listaDePalabras;

        while(aux->sig != NULL)
        {
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}

void mostrarListaDePalabras(nodoP* listaDePalabras)
{

    nodoT* aux;

    while(listaDePalabras)
    {
        aux = listaDePalabras->ocurrencias;
        printf("%s\n", listaDePalabras->palabra);
        mostrarListaDeOcurrencias(aux);
        listaDePalabras = listaDePalabras->sig;
    }
}

void mostrarNodosCoincidentesDosID(nodoT* ocurrencias, int ID1, int ID2)
{
    while(ocurrencias)
    {
        if(ocurrencias->idDOC == ID1 || ocurrencias->idDOC == ID2)
        {
            mostrarUnaOcurrencia(ocurrencias);
        }
        ocurrencias = ocurrencias->sig;
    }
}

nodoT* BuscarNodosCoincidentesUnID(nodoT* ocurrencias,int ID)
{
    while(ocurrencias)
    {
        if(ocurrencias->idDOC == ID)
        {
            return ocurrencias;
        }
        ocurrencias = ocurrencias->sig;
    }
    return ocurrencias;
}

void mostrarNodosCoincidentesUnID(nodoT* ocurrencias, int ID1)
{

    while(ocurrencias)
    {

        if(ocurrencias->idDOC == ID1)
        {

            mostrarUnaOcurrencia(ocurrencias);
        }

        ocurrencias = ocurrencias->sig;
    }
}

int buscarCoincidenciaID(nodoT* ocurrencias, int ID)
{
    while(ocurrencias && ocurrencias->idDOC != ID)
    {
        ocurrencias = ocurrencias->sig;
    }

    if(ocurrencias)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void buscarEnDosDoc(nodoA* motor, char* palabra, int ID1, int ID2)
{

    //Variables locales
    int enc1, enc2;

    if(motor)
    {

        if(strcmpi(motor->palabra, palabra) == 0)
        {
            enc1 = buscarCoincidenciaID(motor->ocurrencias, ID1); //motor.c
            enc2 = buscarCoincidenciaID(motor->ocurrencias, ID2);

            if(enc1 && enc2)
            {
                mostrarNodosCoincidentesDosID(motor->ocurrencias, ID1, ID2);

            }
            else if(enc1 == 1 && enc2 == 0)
            {

                setColor(RED);printf("\n[!]");
                setColor(CYAN);printf(" Se encontro la palabra en documento");
                setColor(GREEN);printf(" %d ", ID1);
                setColor(CYAN);printf("pero no en el");
                setColor(GREEN);printf(" %i \n", ID2);

            }
            else if(enc1 == 0 && enc2 == 1)
            {

                setColor(RED);printf("\n[!]");
                setColor(CYAN);printf(" Se encontro la palabra en documento");
                setColor(GREEN);printf(" %d ", ID2);
                setColor(CYAN);printf("pero no en el");
                setColor(GREEN);printf(" %i \n", ID1);

            }
            else
            {

                setColor(RED);
                printf("\n[!]");
                setColor(CYAN);
                printf(" No se encontro la palabra en ninguno de los documentos que indico\n");
            }

        }
        else
        {

            if(strcmpi(motor->palabra, palabra) > 0)
            {

                buscarEnDosDoc(motor->izq, palabra, ID1, ID2);

            }
            else if(strcmpi(motor->palabra, palabra) < 0)
            {

                buscarEnDosDoc(motor->der, palabra, ID1, ID2);
            }
        }
    }
    else
    {
        setColor(CYAN);printf("\nLa palabra %s no se encuentra en el motor\n",palabra);
    }
}

void buscarVariosTerminosEnUnDoc(nodoA* motor, char* palabra, int ID)
{
    nodoT* aux;

    if(motor)
    {
        if(strcmpi(motor->palabra, palabra) == 0)
        {
            aux = BuscarNodosCoincidentesUnID(motor->ocurrencias, ID);

            if(aux)
            {
                setColor(CYAN);printf("----------------------------------------------------------------------------------------------------\n");
                setColor(RED);printf("\n- [");
                setColor(CYAN);printf("PALABRA");
                setColor(RED);printf("]: ");
                setColor(GREEN);printf("%s\n\n", palabra);
                setColor(CYAN);
                mostrarNodosCoincidentesUnID(motor->ocurrencias, ID);
            }
            else
            {
                printf("[!] No se encuentra la palabra: \"%s\" en el documento %i\n", palabra, ID);
            }
        }
        else
        {
            if(strcmpi(motor->palabra, palabra) > 0)
            {
                buscarVariosTerminosEnUnDoc(motor->izq, palabra, ID);
            }
            else if(strcmpi(motor->palabra, palabra) < 0)
            {
                buscarVariosTerminosEnUnDoc(motor->der, palabra, ID);
            }
        }
    }
    else
    {
        printf("[!] No se encuentra la palabra: \"%s\" en el motor\n", palabra);
    }
}

void palabraMasFrecuentePorDoc(nodoA* motor, int ID, int comparar)
{

    int frec;
    //printf("%i\n",comparar);

    if(motor)
    {

        frec = retornarMaximaFrecuencia(motor->ocurrencias, ID);
        //printf("%i\n ",frec);

        if(frec > comparar)
        {
            comparar = frec;
            //printf("Test %i\n\n",comparar);
            system("cls");
            printf("\n----------------------------------------------------------------------------------------------------\n");
            setColor(RED);printf("[!]");
            setColor(CYAN);printf(" La palabra mas repetida es:");
            setColor(GREEN);printf(" %s \n", motor->palabra);
        }

        palabraMasFrecuentePorDoc(motor->izq, ID, comparar);
        palabraMasFrecuentePorDoc(motor->der, ID, comparar);
    }
    //printf("%i",comparar);
}

int retornarMaximaFrecuencia(nodoT* ocurrencias, int ID)
{
    int frec = 0;

    while(ocurrencias && ocurrencias->idDOC == ID)
    {
        //printf("%i == %i\n",ID,ocurrencias->idDOC);
        frec++;
        ocurrencias = ocurrencias->sig;
    }

    return frec;
}
