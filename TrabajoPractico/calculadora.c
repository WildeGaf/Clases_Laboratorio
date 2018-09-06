/**
* @brief Se imprime una lista de opciones, en la cual el usuario debe seleccionar una.
* @return Devuelve un valor correspondido a la opcion seleccionada.
*/

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

/**
* @brief Suma dos valores enteros.
* @param num1 El primer valor, para realizar la operacion.
* @param num2 El segundo valor, para realizar la operacion.
* @return Devuelve el resultado de la suma de los operadores ingresados.
*/

int suma(num1,num2){
    int suma;
    suma = (num1+num2);
    return suma;
}

/**
* @brief Resta dos valores enteros.
* @param num1 El primer valor, para realizar la operacion.
* @param num2 El segundo valor, para realizar la operacion.
* @return Devuelve el resultado de la resta de los operadores ingresados.
*/

int resta(num1,num2){
    int resta;
    resta = num1-num2;
    return resta;
}
/**
* @brief Multiplica dos valores enteros.
* @param num1 El primer valor, para realizar la operacion.
* @param num2 El segundo valor, para realizar la operacion.
* @return Devuelve el resultado de la multiplicacion de los operadores ingresados.
*/
int multiplicacion(num1,num2){
    int multi;
    multi = num1*num2;
    return multi;
}
/**
* @brief Divide dos valores enteros y si no es posible da mensaje de error.
* @param num1 El primer valor, para realizar la operacion.
* @param num2 El segundo valor, para realizar la operacion el cual debe ser distinto de 0.
* @return Devuelve el resultado de la division de los operadores ingresados.
*/
int division(num1,num2){
    int div;
    div = num1/num2;
    return div;
}
/**
* @brief Realiza el factorial de un numero ingresado.
* @param num El numero al cual se desea realizar el factorial.
* @return Devuelve el factorial del numero ingresado.
*/
int factorial(num){
    int contador,acumuladorUno=0;
    if (num<0){
        return -1;
    }
    else{
        if (num==0 || num==1){
           return 1;
           }
        else{
            contador = num - 1;
            for (contador;contador!=0;contador--){
                acumuladorUno = num * contador + acumuladorUno;
            }
        }
    return acumuladorUno;
    }
}
