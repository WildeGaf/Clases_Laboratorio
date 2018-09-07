#include <stdio.h>
#include <stdlib.h>

int menu(){
    int opcion;
    printf("Menu de la calculadora\n");
    printf("\n1- Ingrese 1 para realizar una suma \n");
    printf("2- Ingrese 2 para realizar una resta \n");
    printf("3- Ingrese 3 para realizar una division \n");
    printf("4- Ingrese 4 para realizar una multiplicacion \n");
    printf("5- Ingrese 5 para realizar el factorial \n");
    printf("6- Ingrese 6 para realizar todas las operaciones \n");
    printf("\nDigite la opcion elegida: ");
    scanf("%d",&opcion);
    return opcion;
}

int suma(int num1, int num2){
    int suma;
    suma = (num1+num2);
    return suma;
}

int resta(int num1, int num2){
    int resta;
    resta = num1-num2;
    return resta;
}

int multiplicacion(int num1,int num2){
    int multi;
    multi = num1*num2;
    return multi;
}

int division(int num1,int num2){
    int div;
    div = num1/num2;
    return div;
}

int factorial(int num){
    int contador,acumuladorUno=0;
    if (num<0){
        return -1;
    }
    else{
        if (num==0 || num==1){
           return 1;
           }
        else{
            for (contador=num-1;contador!=0;contador--){
                acumuladorUno = num * contador + acumuladorUno;
            }
        }
    return acumuladorUno;
    }
}
