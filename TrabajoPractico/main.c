#include <stdio.h>
#include <stdlib.h>
#include "calculadora.h"
int main()
{
    int opcionElegida,primerOperador,segundoOperador,resultadoSuma,resultadoResta,resultadoMulti,factorialUno,factorialDos,resultadoDiv;
    char respuesta;
    do{
        system("cls");
        printf ("Ingrese el primer operador: ");
        scanf("%d",&primerOperador);
        printf ("Ingrese el segundo operador: ");
        scanf("%d",&segundoOperador);
        system("cls");
        opcionElegida = menu();
        printf("\nEl primer operador es: %d ",primerOperador);
        printf("\nEl segundo operador es: %d \n",segundoOperador);
        switch (opcionElegida){
        case 1:
            resultadoSuma = suma(primerOperador,segundoOperador);
            printf("\n1- La suma entre los dos operadores es de: %d \n",resultadoSuma);
            break;
        case 2:
            resultadoResta = resta(primerOperador,segundoOperador);
            printf("\n2- La resta entre los dos operadores es de: %d \n",resultadoResta);
            break;
        case 3:
            if (segundoOperador==0){
                printf("\n3- No se puede dividir por 0 \n");
            }
            else{
            resultadoDiv = division(primerOperador,segundoOperador);
            printf("\n3- La division entre los dos operadores es de: %d \n",resultadoDiv);
            }
            break;
        case 4:
            resultadoMulti = multiplicacion(primerOperador,segundoOperador);
            printf("\n4- La multiplicacion entre los dos operadores es de: %d \n ",resultadoMulti);
            break;
        case 5:
            factorialUno = factorial(primerOperador);
            factorialDos = factorial(segundoOperador);
            if (factorialUno == -1 || factorialDos == -1) {
                if (factorialUno == -1 && factorialDos == -1){
                   printf("\n5- El primer operador es negativo al igual que el segundo, no possen factorial \n");
                }
                else if (factorialUno == -1 && factorialDos != -1){
                    printf("\n5- El primer operador es negativo, no posee factorial, el del segundo operador es: %d \n",factorialDos);
                    }
                else{
                    printf("\n5- El factorial del primer operador es %d, el segundo opererador es negativo, no posee factorial \n",factorialUno);
                }
            }
            else {
                printf("\n5- El factorial del primer operador es: %d y del segundo es: %d \n",factorialUno,factorialDos);
            }
            break;
        case 6:
            factorialUno = factorial(primerOperador);
            factorialDos = factorial(segundoOperador);
            resultadoSuma = suma(primerOperador,segundoOperador);
            resultadoResta = resta(primerOperador,segundoOperador);
            printf("\n1- La suma entre los dos operadores es de: %d ",resultadoSuma);
            printf("\n2- La resta entre los dos operadores es de: %d ",resultadoResta);
            if (segundoOperador==0){
                printf("\n3- No se puede dividir por 0");
            }
            else{
                resultadoDiv = division(primerOperador,segundoOperador);
                printf("\n3- La division entre los dos operadores es de: %d ",resultadoDiv);
            }
            resultadoMulti = multiplicacion(primerOperador,segundoOperador);
            printf("\n4- La multiplicacion entre los dos operadores es de: %d ",resultadoMulti);
            factorialUno = factorial(primerOperador);
            factorialDos = factorial(segundoOperador);
            if (factorialUno == -1 || factorialDos == -1) {
                if (factorialUno == -1 && factorialDos == -1){
                   printf("\n5- El primer operador es negativo al igual que el segundo, no possen factorial \n");
                }
                else if (factorialUno == -1 && factorialDos != -1){
                    printf("\n5- El primer operador es negativo, no posee factorial, el del segundo operador es: %d \n",factorialDos);
                    }
                else{
                    printf("\n5- El factorial del primer operador es %d, el segundo opererador es negativo, no posee factorial \n",factorialUno);
                }
            }
            else {
                printf("\n5- El factorial del primer operador es: %d y del segundo es: %d \n",factorialUno,factorialDos);
            }
        break;
        default:
            system("cls");
            printf("No ingreso un numero valido\n");
        }
    printf("\nPresione una tecla para realizar otra operacion o N para terminar: ");
    fflush(stdin);
    scanf("%c",&respuesta);
    }while(respuesta!=110 && respuesta!=78);
    system("cls");
    printf("Ha salido del programa \n");

    return 0;
}


