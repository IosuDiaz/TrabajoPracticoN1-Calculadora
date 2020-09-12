#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    //A = PRIMER OPERANDO
    //B = SEGUNDO OPERANDO
    float a;
    float b;
    int respuestaMenu;
    float sumaResuelta;
    float restaResuelta;
    float divisionResuelta;
    float multiplicacionResuelta;
    int factorizacionPrimerOperandoResuelta;
    int factorizacionSegundoOperandoResuelta;
    int flagUno;
    int flagDos;
    int flagTres;

    a=0;
    b=0;
    flagUno=0;
    flagDos=0;
    flagTres=0;

    do
    {

        printf("\n  -----------------------");
        printf("\n|                        |");
        printf("\n|    A=%.2f   B=%.2f     |",a,b);
        printf("\n|                        |");
        printf("\n  -----------------------");

        respuestaMenu = mostrarMenu(respuestaMenu);

        switch (respuestaMenu)
        {
            case 1:
                //Pido primer operando (A=x)
                a = pedirNumero(a, respuestaMenu);
                flagUno=1;
                break;
            case 2:
                if(!flagUno)
                {
                    printf("Tiene que ingresar el operando 1\n");
                    system("pause");
                    system("cls");
                }
                else
                {
                //Pido SEGUNDO operando (B=y)
                b = pedirNumero(b, respuestaMenu);
                flagDos=1;
                }
                break;
            case 3:
                if(!flagUno || !flagDos)
                {
                    printf("Para calcular primero tiene que ingresar los operandos\n");
                    system("pause");
                    system("cls");
                }
                else
                {
                sumaResuelta=sumarOperandos(a,b);
                restaResuelta=restarOperandos(a,b);
                divisionResuelta=dividirOperadores(a,b);
                multiplicacionResuelta=multiplicarOperadores(a,b);
                factorizacionPrimerOperandoResuelta=factorizarOperando(a);
                factorizacionSegundoOperandoResuelta=factorizarOperando(b);
                flagTres=1;
                }
                break;
            case 4:
                if(!flagTres)
                {
                    printf("No se puede calcular antes de mostrar\n");
                    system("pause");
                    system("cls");
                }
                else
                {
                    mostrarOperaciones(a,b,sumaResuelta,restaResuelta,divisionResuelta,multiplicacionResuelta,factorizacionPrimerOperandoResuelta,factorizacionSegundoOperandoResuelta);
                    flagUno=0;
                    flagDos=0;
                    flagTres=0;

                    //system("pause");

                    a=0;
                    b=0;
                }
                break;
            case 5:
                //Mensaje de salida
                printf("Apagando...\n\n\n\n\n");
                break;
            default:
                {
                    //Validacion menu
                    printf("ERROR. La opcion ingresada no coincide con las disponibles.\n\n");
                }
        }

    }while(respuestaMenu != 5);
}
