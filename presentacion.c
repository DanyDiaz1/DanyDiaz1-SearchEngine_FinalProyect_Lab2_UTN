#include "presentacion.h"


void computadoraPresentacion() {

setColor(GREEN);

printf("\t\t\t               ,---------------------------,\n");
printf("\t\t\t              |  /---------------------\  |\n");
printf("\t\t\t              | |                       | |\n");
printf("\t\t\t              | |     MOTOR DE          | |\n");
printf("\t\t\t              | |      BUSQUEDA         | |\n");
printf("\t\t\t              | |       TP - FINAL      | |\n");
printf("\t\t\t              | |         UTN           | |\n");
printf("\t\t\t              |  \_____________________/  |\n");
printf("\t\t\t              |___________________________|\n");
printf("\t\t\t            ,---\_____     []     _______/------,\n");
printf("\t\t\t          /         /______________\           /|\n");
printf("\t\t\t        /___________________________________ /  | ___\n");
printf("\t\t\t       |                                   |   |    )\n");
printf("\t\t\t        |  _ _ _                 [-------]  |   |   (\n");
printf("\t\t\t        |  o o o                 [-------]  |  /    _)_\n");
printf("\t\t\t        |__________________________________ |/     /  /\n");
printf("\t\t\t    /-------------------------------------/|      ( )/\n");
printf("\t\t\t  /-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/ /\n");
printf("\t\t\t/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/ /\n");
printf("\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~   \n");
printf("\n");

setColor(CYAN);
}

void arrowHere(int realPosition, int arrowPosition)
{
    if(realPosition == arrowPosition)
    {
        setColor(GREEN);
        printf(" ---->> ");
    }
    else
    {
        printf("       ");
    }
}
