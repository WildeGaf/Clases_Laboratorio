#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validacionesinput.h"
#include "juegos.h"
#include "cliente.h"


/**\brief Para indicar que todas las posiciones del array JUEGOS estan vacias, esta funcion pone la bandera isEmpty de la estructura en 1 (TRUE).
* \param Juegos arrayJuegos [] Es el array de tipo de dato estructura a ser inicializado.
*\param int longitudArray Es la cantidad de elementos del array.
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/

 int initJuegos(Juegos arrayJuegos [], int longitudArray)
 {
     int i, retorno = -1;

     if (arrayJuegos!= NULL && longitudArray > 0)
     {
         for (i=0; i< longitudArray; i++)
         {
             arrayJuegos[i].isEmpty = 1;
         }
             retorno=0;
     }
     return retorno;
 }

/**\brief Busca el primer lugar vacio en un array estructura, previamente cargado con el valor 1.
* \param Juegos arrayJuegos [] Es el array de tipo de dato estructura en donde se busca el dato.
*\param int longitudArray Es la cantidad de elementos del array de enteros.
* \return Devuelve el subindice vacio en el array (i) o -1 en caso de no haber lugar vacio.
*
*/

 int utn_buscarLugarVacioJuegos (Juegos arrayJuegos [],int longitudArray)
 {
     int i, retorno=-1;

     if (arrayJuegos!= NULL && longitudArray > 0)
     {
         for (i=0; i< longitudArray ; i++)
         {
             if (arrayJuegos[i].isEmpty == 1)
             {
                 retorno= i;
                 break;
             }
         }
     }
         return retorno;
 }

/** \brief Agrega, en un array de JUEGOS existente, los valores recibidos como par�metro en la primer posici�n libre encontrada.
* \param Juegos arrayJuegos [] Array de  JUEGOS donde se cargan los datos ingresados
* \param int longitudArray longitud del array de JUEGOS.
* \param int codigoJuego codigo de juego pasado por referencia desde el main, generado automaticamente por contador.
* \param char descripcion[] descripcion del juego pasado por referencia desde el main
* \param float importe del juego pasado por referencia desde el main
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*/

 int addJuegos (Juegos arrayJuegos [], int longitudArray, int codigoJuego , char descripcion[], float importe)
 {
       int i;
       int retorno=-1;

     if (arrayJuegos!= NULL && longitudArray > 0)
     {
        i= utn_buscarLugarVacioJuegos(arrayJuegos, longitudArray); // BUSCA EL 1 Q ES EL LUGAR VACIO...

        if (i != -1) // o sea si no hay error en la funcion anterior
        {
            arrayJuegos[i].isEmpty= 0;
            arrayJuegos[i].codigoJuego = codigoJuego;
            strcpy (arrayJuegos[i].descripcionJuego, descripcion);
            arrayJuegos[i].importeJuego=importe;

            retorno= 0;
        }
     }
         return retorno;
 }

 /** \brief find JUEGO by Id. Returns the index position in array.
 * \param Juegos arrayJuegos [] array de JUEGOS en el cual se va a buscar el id.
 * \param int longitudArray tama�o del array de JUEGOS.
 * \param int codigoJuego el id de JUEGO a buscar.
 * \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 *
 */
 int findJuegoById(Juegos arrayJuegos [], int longitudArray, int codigoJuego)
 {
     int i;
     int retorno=-1;

     if (arrayJuegos!= NULL && longitudArray > 0)
     {
         for (i=0; i< longitudArray ; i++)
         {
             if (arrayJuegos[i].isEmpty==0 && arrayJuegos[i].codigoJuego == codigoJuego)
             {
                 retorno= i;
                 break;
             }
         }
     }
         return retorno;
 }

/** \brief Remove a JUEGO by Id (put isEmpty Flag in 1)
* \param Juegos arrayJuegos [] Array de JUEGOS donde se va a buscar el que se desea eliminar.
* \param int longitudArray tama�o del array de JUEGOS.
* \param int codigoJuego el id de JUEGO a buscar.
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
*
*/
 int removeJuegos (Juegos arrayJuegos [], int longitudArray, int codigoJuego)
 {
     int i;
     int retorno=-1;

     if (arrayJuegos!= NULL && longitudArray > 0)
     {
         for (i=0; i< longitudArray ; i++)
         {
             if (arrayJuegos[i].isEmpty==0 && arrayJuegos[i].codigoJuego == codigoJuego)
             {
                 arrayJuegos[i].isEmpty=1;
                 retorno= 0;
             }
         }
     }
         return retorno;
 }

 /** \brief Ordena el array juegos en las posiciones guardadas por importe y descripcion en orden ascendente.
 * \param Juegos arrayJuegos [] Array de JUEGOS que se va a ordenar.
 * \param int longitudArray tama�o del array de JUEGOS.
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
 int sortJuegos (Juegos arrayJuegos [], int longitudArray)
 {
     int i, j, retorno=-1;
     Juegos auxArrayJuegos;

     if (arrayJuegos!= NULL && longitudArray > 0)
     {
         for(i=0; i<longitudArray-1; i++)
         {
             if (arrayJuegos[i].isEmpty==0) // PARA QUE LEA SOLO LOS QUE ESTAN GUARDADOS !
             {
                 for(j=i+1; j<longitudArray; j++)
                {
                     if (arrayJuegos[j].isEmpty==0) // PARA QUE LEA SOLO LOS QUE ESTAN GUARDADOS !
                     {
                        if (arrayJuegos[i].importeJuego > arrayJuegos[j].importeJuego)
                        {
                            auxArrayJuegos = arrayJuegos[i];
                            arrayJuegos[i] = arrayJuegos[j];
                            arrayJuegos[j] = auxArrayJuegos;
                            retorno=0;
                        }
                        else
                        {
                            if (arrayJuegos[i].isEmpty==0 && arrayJuegos[i].importeJuego == arrayJuegos[j].importeJuego)
                            {
                                if (strcmp(arrayJuegos[i].descripcionJuego,arrayJuegos[j].descripcionJuego) >0) // PIDE ORDENAMIENTO POR APELLIDO Y SECTOR VER SI SE PONE UN Y ACA O HAY OTRA FORMA
                                {
                                    auxArrayJuegos = arrayJuegos[i];
                                    arrayJuegos[i] = arrayJuegos[j];
                                    arrayJuegos[j] = auxArrayJuegos;
                                    retorno=0;
                                }
                            }
                         }
                    }
                }
             }
         }
     }
    return retorno;
}

/** \brief IMPRIME EL CONTENIDO DEL ARRAY DE JUEGOS.
* \param Juegos arrayJuegos [] Array de JUEGOS que se va a ordenar.
* \param int longitudArray tama�o del array de JUEGOS.
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok.
*
*/
 int printJuegos(Juegos arrayJuegos [], int longitudArray)
 {
     int i;
     int retorno=-1;

     if (arrayJuegos!= NULL && longitudArray > 0)
     {
          for (i=0; i< longitudArray ; i++)
         {
             if (arrayJuegos[i].isEmpty==0) // SOLAMENTE VA A MOSTRAS LOS VECTORES GUARDADOS, SINO HAY DATOS MUESTRA BASURA..
             {
                 printf("\nIMPORTE JUEGO:%0.2f\t DESCRIPCION:%s\t CODIGO JUEGO:%d\n", arrayJuegos[i].importeJuego, arrayJuegos[i].descripcionJuego, arrayJuegos[i].codigoJuego);
             }
         }
         retorno=0;
     }
     return retorno;
 }

//SECTOR ALQUILERES ************************************************************************************************************************************

/**\brief Para indicar que todas las posiciones del array employee estan vacias, esta funcion pone la bandera isEmpty de la estructura en 1 (TRUE).
 * \param Alquileres arrayAlquileres []  Es el array de tipo de dato estructura a ser inicializado.
 *\param int longitudArray Es la cantidad de elementos del array.
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */

 int initAlquileres (Alquileres arrayAlquileres [] , int longitudArray)
 {
     int i, retorno = -1;

     if (arrayAlquileres!= NULL && longitudArray > 0)
     {
         for (i=0; i< longitudArray; i++)
         {
             arrayAlquileres[i].isEmpty = 1;
         }
             retorno=0;
     }
     return retorno;
 }

 /**\brief Busca el primer lugar vacio en un array estructura, previamente cargado con el valor 1.
 * \param Alquileres arrayAlquileres [] Es el array de tipo de dato estructura en donde se busca el dato.
 *\param int longitudArray Es la cantidad de elementos del array de enteros.
 * \return Devuelve el subindice vacio en el array (i) o -1 en caso de no haber lugar vacio. // OJO ACA USO EL -1 PARA INDICAR LUGAR VACIO
 *
 */

 int utn_buscarLugarVacioAlquileres(Alquileres arrayAlquileres [], int longitudArray)
 {
     int i, retorno=-1;

     if (arrayAlquileres!= NULL && longitudArray > 0)
     {
         for (i=0; i< longitudArray ; i++)
         {
             if ( arrayAlquileres[i].isEmpty == 1)
             {
                 retorno= i;
                 break;
             }
         }
     }
         return retorno;
 }

/** \brief Agrega en un array de ALQUILERES existente, los valores recibidos como par�metro, en la primer posici�n libre encontrada.
 * \param Alquileres arrayAlquileres [] Array de  ALQUILERES donde se cargan los datos ingresador
 * \param int longitudArray longitud del array de ALQUILERES.
 * \param int contadorAlquileres Codigo de alquiler generado automaticamente por un contador, pasado por referencia.
 * \param int auxCodigoJuegoAlquileres Codigo de JUEGO generado automaticamente por un contador, pasado por referencia.
 * \param int auxCodigoClienteAlquileres Codigo de CLIENTE generado automaticamente por un contador, pasado por referencia.
 * \param int auxDiaFecha, int auxMesFecha, int auxAnioFecha FECHA DE ALQUILER, PASADA COMO ESTRUCTURA ANIDADA.
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 */

int addAlquileres (Alquileres arrayAlquileres [],int longitudArray, int contadorAlquileres, int auxCodigoJuegoAlquileres,
                   int auxCodigoClienteAlquileres, int auxDiaFecha, int auxMesFecha, int auxAnioFecha)
 {
    int i;
    int retorno=-1;

     if (arrayAlquileres!= NULL && longitudArray > 0)
     {
        i= utn_buscarLugarVacioAlquileres(arrayAlquileres, longitudArray); // BUSCA EL 1 Q ES EL LUGAR VACIO...

        if (i != -1) // o sea si no hay error en la funcion anterior
        {
            arrayAlquileres[i].isEmpty=0;
            arrayAlquileres[i].codigoAlquileres = contadorAlquileres;
            arrayAlquileres[i].codigoJuegoAlquileres = auxCodigoJuegoAlquileres;
            arrayAlquileres[i].codigoClienteAlquileres = auxCodigoClienteAlquileres;
            arrayAlquileres[i].fecha.dia=auxDiaFecha;
            arrayAlquileres[i].fecha.mes=auxMesFecha;
            arrayAlquileres[i].fecha.anio=auxAnioFecha;

            retorno= 0;
        }
     }
         return retorno;
 }

/** \brief EVALUA SI EL CODIGO DE JUEGO INGRESADO EXISTE EN EL SISTEMA
* \param Juegos arrayJuegos [] array de JUEGOS en el cual se va a buscar el id.
* \param int longitudArray tama�o del array de JUEGOS.
* \param int codigoJuego CODIGO DE JUEGO A SER CHEQUEADO, PASADO POR REFERENCIA.
* \return Return 0 if ok index position or (-1) if [Invalid length or NULL pointer received or employee not found]
*
*/
 int checkCodigoJuegos (Juegos arrayJuegos [], int longitudArray, int codigoJuego)
 {
     int i;
     int retorno=-1;

     if (arrayJuegos!= NULL && longitudArray > 0)
     {
         for (i=0; i< longitudArray ; i++)
         {
             if (arrayJuegos[i].isEmpty != 1)
             {
                if (arrayJuegos[i].codigoJuego == codigoJuego)
                {
                    retorno= 0;
                    break;
                }
             }
         }
     }
         return retorno;
 }

/** \brief IMPRIME EL TOTAL DE LOS IMPORTES Y EL PROMEDIO DE LOS JUEGOS QUE FUERON ALQUILADOS.
* \param Alquileres arrayAlquileres [] ARRAY ALQUILERES DONDE SE VA A BUSCAR EL CODIGO DE LOS JUEGOS ALQUILADOS.
* \param int longitudArrayAlquileres Longitud del array de ALQUILERES.
* \param Juegos arrayJuegos []] ARRAY JUEGOS DONDE SE VA A BUSCAR EL CODIGO DE ALQUILER Y SE IMPRIME SU INFORMACION.
* \param int longitudArrayJuegos Longitud del array de JUEGOS.
* \return void.
*
*/
void printPromedioImporteTotales(Alquileres arrayAlquileres [], int longitudArrayAlquileres, Juegos arrayJuegos [], int longitudArrayJuegos)
{
    int i,j, contadorImportes=0;
    float importePromedio, acumuladorImportes=0;

    if (arrayAlquileres!= NULL && longitudArrayAlquileres > 0 && arrayJuegos!= NULL && longitudArrayJuegos > 0)
    {
        for (i=0; i< longitudArrayAlquileres ; i++) // PARA CALCULAR PROMEDIOS Y TOTAL DE SALARIOS.
        {
            if (arrayAlquileres[i].isEmpty ==0)
            {
                for (j=0; j< longitudArrayJuegos ; j++) // PARA CALCULAR PROMEDIOS Y TOTAL DE SALARIOS.
                {
                    if (arrayJuegos[j].isEmpty ==0)
                    {
                        if (arrayAlquileres[i].codigoJuegoAlquileres==arrayJuegos[j].codigoJuego)
                        {
                            acumuladorImportes= acumuladorImportes + arrayJuegos[j].importeJuego;
                            contadorImportes++;
                            importePromedio= acumuladorImportes / contadorImportes;

                            printf("\n CODIGO: %d ***JUEGOS ALQUILADOS: %s ***IMPORTE: %0.2f  \n", arrayJuegos[j].codigoJuego, arrayJuegos[j].descripcionJuego, arrayJuegos[j].importeJuego);
                        }

                    }
                }
            }

        }
    }

        printf( "\n El total de los IMPORTES DE LOS JUEGOS ALQUILADOS es: %0.2f \n El promedio de los IMPORTES DE LOS JUEGOS ALQUILADOS es: %0.2f  \n",acumuladorImportes, importePromedio );

}

/** \brief IMPRIME EL TOTAL DE LOS IMPORTES Y EL PROMEDIO DE LOS JUEGOS QUE FUERON ALQUILADOS.
* \param Alquileres arrayAlquileres [] ARRAY ALQUILERES DONDE SE VA A BUSCAR EL CODIGO DE LOS JUEGOS ALQUILADOS.
* \param int longitudArrayAlquileres Longitud del array de ALQUILERES.
* \param Juegos arrayJuegos []] ARRAY JUEGOS DONDE SE VA A BUSCAR EL CODIGO DE ALQUILER Y SE IMPRIME SU INFORMACION.
* \param int longitudArrayJuegos Longitud del array de JUEGOS.
* \return PROMEDIO DE JUEGOS ALQUILADOS Y -1 SINO CUMPLE LA PRIMERA CONDICION DEL IF.
*
*/
float promedioJuegosAlquilados(Alquileres arrayAlquileres [], int longitudArrayAlquileres, Juegos arrayJuegos [], int longitudArrayJuegos)
{
    int i,j, contadorImportes=0;
    float importePromedio, acumuladorImportes=0, retorno=-1;

    if (arrayAlquileres!= NULL && longitudArrayAlquileres > 0 && arrayJuegos!= NULL && longitudArrayJuegos > 0)
    {
        for (i=0; i< longitudArrayAlquileres ; i++) // PARA CALCULAR PROMEDIOS Y TOTAL DE SALARIOS.
        {
            if (arrayAlquileres[i].isEmpty ==0)
            {
                for (j=0; j< longitudArrayJuegos ; j++) // PARA CALCULAR PROMEDIOS Y TOTAL DE SALARIOS.
                {
                    if (arrayJuegos[j].isEmpty ==0)
                    {
                        if (arrayAlquileres[i].codigoJuegoAlquileres==arrayJuegos[j].codigoJuego)
                        {
                            acumuladorImportes= acumuladorImportes + arrayJuegos[j].importeJuego;
                            contadorImportes++;
                            importePromedio= acumuladorImportes / contadorImportes;

                        }

                    }
                }
            }

        }
        retorno= importePromedio;
    }
    return retorno;
}

/** \brief IMPRIME LA CANTIDAD DE JUEGOS DEL ARRAY DE JUEGOS QUE SON INFERIORES AL PROMEDIO DE LOS JUEGOS TOTALES ALQUILADOS.
* \param Alquileres arrayAlquileres [] ARRAY ALQUILERES PARA BUSCAR EL PROMEDIO DE LOS JUEGOS ALQUILADOS.
* \param int longitudArrayAlquileres Longitud del array de ALQUILERES.
* \param Juegos arrayJuegos []] ARRAY JUEGOS DONDE SE VA A BUSCAR LA CANTIDAD DE JUEGOS MENOR AL PROMEDIO.
* \param int longitudArrayJuegos Longitud del array de JUEGOS.
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok.
*
*/
void printCantidadJuegosMinPromedio(Alquileres arrayAlquileres [], int longitudArrayAlquileres, Juegos arrayJuegos [], int longitudArrayJuegos)
{
    int i, contadorImportesMin=0;
    float importePromedio;

    importePromedio= promedioJuegosAlquilados(arrayAlquileres, longitudArrayAlquileres, arrayJuegos, longitudArrayJuegos);

    if (arrayAlquileres!= NULL && longitudArrayAlquileres > 0 && arrayJuegos!= NULL && longitudArrayJuegos > 0)
    {
        for (i=0; i< longitudArrayJuegos ; i++) // PARA CALCULAR LA CANT CON IMPORTES INFERIOR AL PROMEDIO
        {
            if ((arrayJuegos[i].isEmpty ==0) && (arrayJuegos[i].importeJuego < importePromedio))
            {
                    contadorImportesMin ++;
                    printf( "\n JUEGO: %s \n CODIGO DE JUEGO: %d \n IMPORTE: %0.2f \n", arrayJuegos[i].descripcionJuego, arrayJuegos[i].codigoJuego, arrayJuegos[i].importeJuego );
            }
        }

        printf( "\n La cantidad de TODOS LOS JUEGOS DISPONIBLES PARA ALQUILAR \n que NO SUPERAN el IMPORTE promedio DE LOS JUEGOS ALQUILADOS son: %d \n", contadorImportesMin);

    }

}

/** \brief Ordena el array juegos en las posiciones guardadas por importe y descripcion en orden ascendente.
 * \param Juegos arrayJuegos [] Array de JUEGOS que se va a ordenar.
 * \param int longitudArray tama�o del array de JUEGOS.
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
 int sortJuegosMasEficiente (Juegos arrayJuegos [], int longitudArray)
 {
     int i, j, retorno=-1;
     int flagNoEstaOrdenado = 1;

     Juegos auxArrayJuegos;

     if (arrayJuegos!= NULL && longitudArray > 0)
     {
         while (flagNoEstaOrdenado==1)
        {
            flagNoEstaOrdenado = 0;

             for(i=0; i<longitudArray-1; i++)
             {
                 if (arrayJuegos[i].isEmpty==0) // PARA QUE LEA SOLO LOS QUE ESTAN GUARDADOS !
                 {
                     for(j=i+1; j<longitudArray; j++)
                    {
                         if (arrayJuegos[j].isEmpty==0) // PARA QUE LEA SOLO LOS QUE ESTAN GUARDADOS !
                         {
                            if (arrayJuegos[i].importeJuego < arrayJuegos[j].importeJuego)
                            {
                                auxArrayJuegos = arrayJuegos[i];
                                arrayJuegos[i] = arrayJuegos[j];
                                arrayJuegos[j] = auxArrayJuegos;
                                flagNoEstaOrdenado = 1;
                                retorno=0;
                            }
                            else
                            {
                                if (arrayJuegos[i].importeJuego == arrayJuegos[j].importeJuego)
                                {
                                    if (strcmp(arrayJuegos[i].descripcionJuego,arrayJuegos[j].descripcionJuego) >0) // PIDE ORDENAMIENTO POR APELLIDO Y SECTOR VER SI SE PONE UN Y ACA O HAY OTRA FORMA
                                    {
                                        auxArrayJuegos = arrayJuegos[i];
                                        arrayJuegos[i] = arrayJuegos[j];
                                        arrayJuegos[j] = auxArrayJuegos;
                                        flagNoEstaOrdenado = 1;
                                        retorno=0;
                                    }
                                }
                             }
                        }
                    }
                 }
             }
         }
    }
        return retorno;
}

/** \brief IMPRIME EL CONTENIDO DEL ARRAY DE JUEGOS.
* \param Juegos arrayJuegos [] Array de JUEGOS que se va a ordenar.
* \param int longitudArray tama�o del array de JUEGOS.
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok.
*
*/
 int printAlquileres(Alquileres arrayAlquileres [], int longitudArray)
 {
     int i;
     int retorno=-1;

     if (arrayAlquileres!= NULL && longitudArray > 0)
     {
          for (i=0; i< longitudArray ; i++)
         {
             if (arrayAlquileres[i].isEmpty != 1) // SOLAMENTE VA A MOSTRAS LOS VECTORES GUARDADOS, SINO HAY DATOS MUESTRA BASURA..
             {
                 printf("\nCODIGO ALQUILERES: %d\t CODIGO CLIENTE:%d\t CODIGO JUEGO:%d FECHA:%d %d %d\n", arrayAlquileres[i].codigoAlquileres, arrayAlquileres[i].codigoClienteAlquileres,
                         arrayAlquileres[i].codigoJuegoAlquileres, arrayAlquileres[i].fecha.dia, arrayAlquileres[i].fecha.mes, arrayAlquileres[i].fecha.anio );
             }
         }
         retorno=0;
     }
     return retorno;
 }

/** \brief EVALUA SI EL CODIGO DE JUEGO INGRESADO EXISTE EN EL ARRAY ALQUILERES
* \param Alquileres arrayAlquileres [] array de ALQUILERES en el cual se va a buscar el id.
* \param int longitudArray tama�o del array de ALQUILERES.
* \param int codigoJuego CODIGO DE JUEGO A SER CHEQUEADO, PASADO POR REFERENCIA.
* \return Return 0 if ok index position or (-1) if [Invalid length or NULL pointer received or employee not found]
*
*/
 int checkCodigoAlquileres (Alquileres arrayAlquileres [], int longitudArray, int codigoJuego)
 {
     int i;
     int retorno=-1;

     if (arrayAlquileres!= NULL && longitudArray > 0)
     {
         for (i=0; i< longitudArray ; i++)
         {
             if (arrayAlquileres[i].isEmpty != 1)
             {
                if (arrayAlquileres[i].codigoJuegoAlquileres == codigoJuego)
                {
                    retorno= 0;
                    break;
                }
             }
         }
     }
         return retorno;
 }



 // FUNCIONES GENERALES

/** \brief DESPLIEGA EL MENU JUEGOS Y REALIZA TODAS LAS OPERANCIONES DE DICHO MENU
* \param Alquileres arrayAlquileres [] array de ALQUILERES en el cual se va a buscar el id.
* \param int CANT_JUEGOS tama�o del array de JUEGOS.
* \param int contadorAltasJuegos CONTADOR PASADO DESDE EL MAIN PARA INDICAR SI SE REALIZO UN ALTA O NO.
* \param int IMPORTE_JUEGOS CONSTANTE DEFINIDA EN EL MAIN, IMPORTE MAXIMO DE LOS JUEGOS A INGRESAR.
* \return contadorAltasJuegos CONTADOR PARA INDICAR SI SE REALIZO UN ALTA O NO
*
*/

int menuJuegos (Juegos arrayJuegos[], int CANT_JUEGOS, int contadorAltasJuegos, int IMPORTE_JUEGOS, int contadorJuego)
{
    int respuesta, opcionesDosJuegos;
    int auxIndexJuegos, index;
    char auxDescripcionJuego[51];
    int auxCodigoJuego=0;
    int opcionesJuegos, verificarIdJuegos;
    float auxImporteJuego;

    do
    {
        utn_getNumeroAvanzada(&opcionesJuegos, "\n\n------JUEGOS------\n\n 1. ALTAS \n 2. MODIFICAR  \n 3. BAJA  \n 4. LISTAR. \n 5. Salir.\n \n Seleccione una opcion: "," \n Seleccione una opcion valida.", 1, 5,3);

        switch (opcionesJuegos)
        {

            case 1: // ALTAS JUEGOS

            do
            {
                contadorJuego++; //GENERA EL CODIGO DE JUEGO AUTOINCREMENTAL
                auxCodigoJuego=contadorJuego;


                if (utn_getCadenaDeCaracteresAvanzada(auxDescripcionJuego, "\n Ingrese el nombre del juego: ", "El nombre ingresado no es valido, debe estar compuesto solo por letras....\n", 3 ) != 1)
                break;

                if (utn_getNumeroConDecimalesAvanzada(&auxImporteJuego, "\n Ingrese importe del juego: ", "El importe ingresado no es valido, debe ser numerico, mayor a cero...\n ", 1 ,IMPORTE_JUEGOS, 3 ) != 1)
                break;

                addJuegos(arrayJuegos ,CANT_JUEGOS, auxCodigoJuego, auxDescripcionJuego, auxImporteJuego);

                contadorAltasJuegos ++;

                if (utn_getNumeroAvanzada(&respuesta, " \n DESEA CONTINUAR INGRESANDO DATOS: 1 (SI) -  2 (NO):", "No ingreso un dato valido, reintente por favor", 1, 2, 3) != 1)
                break;

            }  while (respuesta != 2);

            break; // BREAK CASE 1 ALTAS JUEGOS

            case 2: // MODIFICACION JUEGOS

                if (contadorAltasJuegos > 0) // PARA INGRESAR UNICAMENTE SI HAY UN ALTA
                {
                    utn_getNumeroAvanzada(& auxIndexJuegos, " \n Ingrese el ID del Juego que desea modificar: ", "El ID ingresado debe ser numerico", 0, 1000, 3);

                    index=findJuegoById (arrayJuegos, CANT_JUEGOS, auxIndexJuegos);

                    if (index==-1)
                    {
                        printf("\n ****NO SE ENCUENTRA ESE ID..****\n \n ");
                        break;
                    }

                    do
                    {
                        utn_getNumeroAvanzada(&opcionesDosJuegos, "\n 1. Modificar DESCRIPCION \n 2. Modificar IMPORTE \n 3. Salir. \n \n Seleccione una opcion: "," \n Seleccione una opcion valida.", 1, 5,3);

                        switch (opcionesDosJuegos)
                        {
                            case 1:

                            utn_getCadenaDeCaracteresAvanzada( arrayJuegos[index].descripcionJuego, "\n Ingrese NOMBRE O DESCRIPCION DEL JUEGO: ", "El nombre ingresado no es valido, debe estar compuesto solo por letras....\n", 3 );
                            printf( "\n *****El nombre o descripcion fue modificado con exito. ****\n \n ");
                            break;

                            case 2:

                            utn_getNumeroConDecimalesAvanzada(& arrayJuegos[index].importeJuego, "\n Ingrese nuevo importe: ", "El importe ingresado no es valido, debe estar compuesto solo por numeros....\n ", 1 , IMPORTE_JUEGOS, 3  );
                            printf( "\n *****El importe fue modificado con exito. ****\n \n ");
                            break;
                        }
                    } while (opcionesDosJuegos != 3); // JUEGOS CASE 2

                }
                else
                {
                    printf("\n ****Primero debe dar de alta un JUEGO..****\n \n ");
                    break;
                }

            break; // BREAK CASE 2 ALTAS JUEGOS


            case 3: // MENU BAJAS JUEGOS

                if (contadorAltasJuegos > 0) // PARA INGRESAR UNICAMENTE SI HAY UN ALTA
                {
                    utn_getNumeroAvanzada(& auxIndexJuegos, " \n Ingrese el ID del JUEGO que desea dar de baja: ", "El ID ingresado debe ser numerico", 0, 1000, 3);

                    verificarIdJuegos= removeJuegos (arrayJuegos, CANT_JUEGOS, auxIndexJuegos);

                    if (verificarIdJuegos==0)
                    {
                        printf( "\n *****El JUEGO fue removido con exito. ****\n \n ");
                        contadorAltasJuegos --;
                    }
                    else
                    {
                        printf("\n ****NO SE ENCUENTRA ESE ID..****\n \n");
                        break;
                    }

                }
                else
                {
                    printf("\n ****Primero debe dar de alta un JUEGO..****\n \n ");
                    break;
                }

            break; // BREAK CASE 3 BAJA JUEGOS


            case 4: //MENU INFORMAR JUEGOS

                if (contadorAltasJuegos > 0) // PARA INGRESAR UNICAMENTE SI HAY UN ALTA
                {
                    sortJuegos(arrayJuegos, CANT_JUEGOS);

                    printJuegos (arrayJuegos, CANT_JUEGOS);
                }
                else
                {
                    printf("\n ****Primero debe dar de alta un JUEGO..****\n \n ");
                }

            break; // BREAK CASE 4 JUEGOS

        } // FIN SWITCH OPCIONES JUEGOS

      }while (opcionesJuegos!= 5); // WHILE OPCIONES MENU JUEGOS


    return contadorAltasJuegos;
}




/** \brief DESPLIEGA EL MENU ALQUILERES Y REALIZA TODAS LAS OPERANCIONES DE DICHO MENU
* \return contadorAltasJuegos CONTADOR PARA INDICAR SI SE REALIZO UN ALTA O NO
*
*/
int menuAlquileres (Alquileres arrayAlquileres [],int CANT_ALQUILERES ,Juegos arrayJuegos[], int CANT_JUEGOS, Clientes arrayClientes [], int CANT_CLIENTES)
{
    int opcionesAlquileres, contadorAlquileres=0, auxCodigoJuegoAlquileres, auxCodigoClienteAlquileres, auxDiaFecha, auxMesFecha, auxAnioFecha;

     do
    {   // OJOOOO AGREGUE MENU INFORMAR ACA!!!
        utn_getNumeroAvanzada(&opcionesAlquileres, "\n\n------ALQUILERES------\n\n 1. ALTAS \n 2. INFORMAR \n 3. Salir.\n \n Seleccione una opcion: "," \n Seleccione una opcion valida.", 1, 3,3);

        switch (opcionesAlquileres)
        {
            case 1: // ALTAS ALQUILERES

            do
            {
                contadorAlquileres ++; //GENERA EL CODIGO DE ALQUILER AUTOINCREMENTAL

                if (utn_getNumeroAvanzadaSinMax(& auxCodigoJuegoAlquileres, "\n Ingrese el codigo del juego: ", "El codigo ingresado no es valido, debe estar dentro del rango valido y compuesto solo por numeros....\n",1, 3 ) != 1)
                break; // HAY QUE VOLVER A HACER EL CONTADOR CUANDO LO PASE A FUNCIONES..IGUAL EL DE ABAJO

                if (checkCodigoJuegos(arrayJuegos, CANT_JUEGOS,auxCodigoJuegoAlquileres)!=0) // BUSCA SI EXISTE EN JUEGOS EL CODIGO A BUSCAR.
                {
                    printf("\n ****NO EXISTE ESE CODIGO DE JUEGO, POR FAVOR INTENTE NUEVAMENTE O INGRESE UN JUEGO..****\n \n ");
                    break;
                }

                if (utn_getNumeroAvanzadaSinMax(& auxCodigoClienteAlquileres, "\n Ingrese el codigo del cliente: ", "El codigo ingresado no es valido, debe estar entro del rango valido y compuesto solo por numeros....\n",1, 3 ) != 1)
                break;

                if (checkCodigoClientes(arrayClientes, CANT_CLIENTES,auxCodigoClienteAlquileres)!=0) // BUSCA SI EXISTE EN CLIENTES EL CODIGO A BUSCAR.
                {
                    printf("\n ****NO EXISTE ESE CODIGO DE CLIENTE, POR FAVOR INTENTE NUEVAMENTE O INGRESE UN CLIENTE..****\n \n ");
                    break;
                }

                if (utn_getNumeroAvanzada(& auxDiaFecha, "\n Ingrese el dia del alquiler: ", "El dia ingresado no es valido, debe estar compuesto solo por numeros (hasta 31 dias)....\n",1, 31,3 ) != 1)
                break;

                if (utn_getNumeroAvanzada(& auxMesFecha, "\n Ingrese el mes del alquiler: ", "El mes ingresado no es valido, debe estar compuesto solo por numeros (hasta 12 meses)....\n",1,12, 3 ) != 1)
                break;

                if (utn_getNumeroAvanzada(& auxAnioFecha, "\n Ingrese el anio del alquiler: ", "El anio ingresado no es valido, debe estar compuesto solo por numeros y dentro del rango valido....\n", 2000, 2200, 3 ) != 1)
                break;

                addAlquileres (arrayAlquileres ,CANT_ALQUILERES, contadorAlquileres, auxCodigoJuegoAlquileres, auxCodigoClienteAlquileres,auxDiaFecha, auxMesFecha, auxAnioFecha);

                if (utn_getNumeroAvanzada(&respuesta, " \n DESEA CONTINUAR INGRESANDO DATOS: 1 (SI) -  2 (NO):", "No ingreso un dato valido, reintente por favor", 1, 2, 3) != 1)
                break;

            } while (respuesta != 2);

            break; // BREAK CASE 1 ALQUILERES

            case 2: // MENU INFORMAR ALQUILERES

                printAlquileres(arrayAlquileres, CANT_ALQUILERES);


            break; // BREAK INFORMAR ALQUILERES
        }

    }while(opcionesAlquileres!=3);


}

