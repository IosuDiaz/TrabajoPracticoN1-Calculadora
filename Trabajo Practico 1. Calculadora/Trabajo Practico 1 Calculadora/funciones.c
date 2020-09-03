#include <stdio.h>
#include <stdlib.h>
int pedirDatos(int A, int B)
{
    //A = PRIMER OPERANDO
    //B = SEGUNDO OPERANDO
    //Pido primer operando (A=x)
    printf("\nIngrese el primer operando. A=");
    scanf("%d",&A);
    printf("\nIngrese el segundo operando. B=");
    scanf("%d",&B);
    return A,B;
}
int sumarOperandos(int primerOperando, int segundoOperando)
{
    int suma;
    suma=primerOperando+segundoOperando;
    return suma;
}

int restarOperandos(int primerOperando, int segundoOperando)
{
    int resta;
    resta=primerOperando-segundoOperando;
    return resta;
}

float dividirOperadores(int primerOperando, int segundoOperando)
{
    float division;
    division=(float)primerOperando/segundoOperando;
    return division;
}
int multiplicarOperadores(int primerOperando, int segundoOperando)
{
    int multiplicacion;
    multiplicacion=primerOperando*segundoOperando;
    return multiplicacion;
}

int factorizarPrimerOperando(int primerOperando)
{
    int factorizacionPrimerOperando=1;

    if(primerOperando<0)
    {
        printf("ERROR. El factoreo de un numero negativo no existe.");
    }
    else {

        for(int i = 1;i<=primerOperando;i++)
        {
            factorizacionPrimerOperando *= i;
        }
    }

    return factorizacionPrimerOperando;
}
int factorizarSegundoOperando(int segundoOperando)
{
    int factorizacionSegundoOperando=1;

    if(segundoOperando<0)
    {
        printf("ERROR. El factoreo de un numero negativo no existe.");
    }
    else
    {
        for(int i=1;i<=segundoOperando;i++)
        {
            factorizacionSegundoOperando *= i;
        }
    }
    return factorizacionSegundoOperando;
}

void calcularYMostrarOperaciones(int primerOperando, int segundoOperando)
{
    int sumaResuelta;
    int restaResuelta;
    float divisionResuelta;
    int multiplicacionResuelta;
    int factorizacionPrimerOperandoResuelta;
    int factorizacionSegundoOperandoResuelta;

    sumaResuelta=sumarOperandos(primerOperando,segundoOperando);
    restaResuelta=restarOperandos(primerOperando,segundoOperando);
    divisionResuelta=dividirOperadores(primerOperando,segundoOperando);
    multiplicacionResuelta=multiplicarOperadores(primerOperando,segundoOperando);
    factorizacionPrimerOperandoResuelta=factorizarPrimerOperando(primerOperando);
    factorizacionSegundoOperandoResuelta=factorizarSegundoOperando(segundoOperando);

    printf("El resultado de A+B es: %d \n",sumaResuelta);
    printf("El resultado de A-B es: %d \n",restaResuelta);
    printf("El resultado de A/B es: %f \n",divisionResuelta);
    printf("El resultado de A*B es: %d \n",multiplicacionResuelta);
    printf("El factorial de A es: %d y El factorial de B es: %d",factorizacionPrimerOperandoResuelta,factorizacionSegundoOperandoResuelta);
    return 0;
}
