#ifndef CALCULADORA_H_INCLUDED
#define CALCULADORA_H_INCLUDED

/**
* @brief Se imprime una lista de opciones, en la cual el usuario debe seleccionar una.
* @return Devuelve un valor correspondido a la opcion seleccionada.
*/
int menu();

/**
* @brief Suma dos valores enteros.
* @param num1 El primer valor, para realizar la operacion.
* @param num2 El segundo valor, para realizar la operacion.
* @return Devuelve el resultado de la suma de los operadores ingresados.
*/
int suma(int,int);

/**
* @brief Resta dos valores enteros.
* @param num1 El primer valor, para realizar la operacion.
* @param num2 El segundo valor, para realizar la operacion.
* @return Devuelve el resultado de la resta de los operadores ingresados.
*/
int resta(int,int);

/**
* @brief Divide dos valores enteros y si no es posible da mensaje de error.
* @param num1 El primer valor, para realizar la operacion.
* @param num2 El segundo valor, para realizar la operacion el cual debe ser distinto de 0.
* @return Devuelve el resultado de la division de los operadores ingresados.
*/
int division(int,int);

/**
* @brief Multiplica dos valores enteros.
* @param num1 El primer valor, para realizar la operacion.
* @param num2 El segundo valor, para realizar la operacion.
* @return Devuelve el resultado de la multiplicacion de los operadores ingresados.
*/
int multiplicacion(int,int);

/**
* @brief Realiza el factorial de un numero ingresado, en caso de que sea un numero negativo, da un mensaje de error.
* @param num El numero al cual se desea realizar el factorial.
* @return Devuelve el resultado del factorial del numero ingresado.
*/
int factorial(int);

#endif // FUNCIONES_H_INCLUDED
