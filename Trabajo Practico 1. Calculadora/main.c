#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    //A = PRIMER OPERANDO
    //B = SEGUNDO OPERANDO
    int a;
    int b;
    int respuestaMenu;

    do
    {
        printf(" -------------------\n");
        printf("|                   |\n");
        printf("|    A=%d   B=%d      |\n",a,b);
        printf("|                   |\n");
        printf(" -------------------\n");
        respuestaMenu = mostrarMenu(respuestaMenu);

        switch (respuestaMenu)
        {
            case 1:
                //Pido primer operando (A=x)
                a = pedirNumero(a, respuestaMenu);
                break;
            case 2:
                //Pido SEGUNDO operando (B=y)
                b = pedirNumero(b, respuestaMenu);
                break;
            case 3:
            case 4:
                system("cls");
                calcularYMostrarOperaciones(a,b,respuestaMenu);
                break;
            case 5:
                printf("Apagando...\n\n\n\n\n");
                break;
            default:
                {
                    printf("ERROR. La opcion ingresada no coincide con las disponibles.\n\n");
                }
        }

    }while(respuestaMenu != 5);
}









