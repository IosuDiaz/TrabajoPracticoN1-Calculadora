#include <stdio.h>
#include <stdlib.h>

int mostrarMenu(int opcionElegida)
{
    printf("\nPara ingresar el primer operando, ingrese 1. ");
    printf("\nPara ingresar el segundo operando, ingrese 2. ");
    printf("\nPara calcular las operaciones, ingrese 3. ");
    printf("\nPara mostrar los resultados, ingrese 4. ");
    printf("\nPara salir, ingrese 5. ");
    printf("\n\nIngrese numero: ");
    scanf("\n %d",&opcionElegida);
    system("cls");
    return opcionElegida;
}

float pedirNumero(float operando, int opcionElegida)
{
    if(opcionElegida==1)
    {
        printf("\nIngrese el primer operando. A=");
        scanf("%f",&operando);
        system("cls");
    }
    else
    {
        if(opcionElegida==2)
        {
            printf("\nIngrese el segundo operando. B=");
            scanf("%f",&operando);
            system("cls");
        }
    }
    return operando;
}

float sumarOperandos(float primerOperando, float segundoOperando)
{
    float suma;

    suma=primerOperando+segundoOperando;

    return suma;
}

float restarOperandos(float primerOperando, float segundoOperando)
{
    float resta;

    resta=primerOperando-segundoOperando;

    return resta;
}

float dividirOperadores(float primerOperando, float segundoOperando)
{
    float division;

    if(!segundoOperando)
    {
        division=0;
    }
    else
    {
        division=primerOperando/segundoOperando;
    }

    return division;
}
float multiplicarOperadores(float primerOperando, float segundoOperando)
{
    float multiplicacion;

    multiplicacion=primerOperando*segundoOperando;

    return multiplicacion;
}

int verificarDecimal(float operando)
{
    int operandoEntero;
    int verificacionFactorial=1;

    operandoEntero=operando;

    if(operando-operandoEntero>0)
    {
        verificacionFactorial=0;
    }

    return verificacionFactorial;
}

int factorizarOperando(float operando)
{
    int factorizacionOperando=1;
    int verificacionFactorial;

    verificacionFactorial= verificarDecimal(operando);

    if(operando<0 || verificacionFactorial==0)
    {
        factorizacionOperando=0;
    }
    else
    {

        if(operando==0)
        {
            factorizacionOperando=1;
        }

            for(int i = 1;i<=operando;i++)
            {
                factorizacionOperando *= i;
            }

    }

    return factorizacionOperando;
}

void mostrarOperaciones(float primerOperando, float segundoOperando, float sumaResuelta, float restaResuelta, float divisionResuelta, float multiplicacionResuelta, int factorizacionPrimerOperandoResuelta, int factorizacionSegundoOperandoResuelta)
{
    printf("Teniendo en cuenta que A=%.2f y que B=%.2f\n\n",primerOperando,segundoOperando);

    //mostrar resultados
    printf("El resultado de A+B es: %.2f \n",sumaResuelta);
    printf("El resultado de A-B es: %.2f \n",restaResuelta);

    //validacion division
    if(!divisionResuelta)
    {
        printf("El resultado de A/B es: Infinito\n");
    }
    else
    {
        printf("El resultado de A/B es: %.2f \n",divisionResuelta);
    }

    printf("El resultado de A*B es: %.2f \n",multiplicacionResuelta);

    //validacion factorial
    if(!factorizacionPrimerOperandoResuelta && !factorizacionSegundoOperandoResuelta)
    {
        printf("El factorial de A no es posible de calcular y El factorial de B tampoco\n");
    }
    else
    {
        if(factorizacionSegundoOperandoResuelta!=0 && !factorizacionPrimerOperandoResuelta)
        {
            printf("El factorial de A no es posible de calcular y El factorial de B es: %d \n\n",factorizacionSegundoOperandoResuelta);
        }
        else
        {
            if(factorizacionPrimerOperandoResuelta!=0 && !factorizacionSegundoOperandoResuelta)
            {
                printf("El factorial de A es: %d y El factorial de B no es posible de calcular. \n\n",factorizacionPrimerOperandoResuelta);
            }
            else
            {
                printf("El factorial de A es: %d y El factorial de B es: %d \n\n",factorizacionPrimerOperandoResuelta,factorizacionSegundoOperandoResuelta);
            }
        }
    }
}

