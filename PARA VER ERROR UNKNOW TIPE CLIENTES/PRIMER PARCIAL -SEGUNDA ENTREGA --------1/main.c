#include <stdio.h>
#include <stdlib.h>
#include "validacionesinput.h"
#include "juegos.h"
#include "cliente.h"
#define CANT_CLIENTES 100 // CANTIDAD DE CLIENTES
#define CANT_JUEGOS 20 // CANTIDAD DE JUEGOS
#define CANT_ALQUILERES (CANT_CLIENTES * CANT_JUEGOS) // CANTIDAD DE ALQUILERES POSIBLES
#define IMPORTE_JUEGOS 10000 //VALOR MAXIMO DE LOS JUEGOS INGRESADOS


int main()
{
    int respuesta, opciones;
    int contadorAltasJuegos=0, contadorJuego =0, auxIndexJuegos, contadorAltasClientes=0;
    /*char auxApellidoCliente[51], auxNombreCliente[51], auxDomicilio[51], auxTelefono[21];
    int opcionesClientes, contadorClientes=0, auxCodigoCliente, opcionesDosClientes, auxIndexClientes, verificarIdJuegos, verificarIdClientes;*/
    int  contadorAlquileres=0; //opcionesAlquileres,auxCodigoJuegoAlquileres, auxCodigoClienteAlquileres, auxDiaFecha, auxMesFecha, auxAnioFecha;
    int opcionesInformes, i, j, k, auxIndexClientes, verificarIdJuegos, verificarIdClientes;
    //float auxImporteJuego;
    //int contadorJuegosAlquilados=0, minimo, maximo, contadorJuegosMin=0, auxCodMinimo, auxCodMaximo ;



    Juegos arrayJuegos[CANT_JUEGOS];
    Clientes arrayClientes [CANT_CLIENTES];
    Alquileres arrayAlquileres [CANT_ALQUILERES];


//*********************************************INICIO DEL PROGRAMA********************************************************************************************************************************

    initJuegos(arrayJuegos , CANT_JUEGOS); // INICIALIZACION DE LOS 3 ARRAYS UTILIZADOS.
    initClientes(arrayClientes , CANT_CLIENTES);
    initAlquileres (arrayAlquileres , CANT_ALQUILERES);


       /* // HARCODEO PARA PRUEBAS

        addJuegos(arrayJuegos ,CANT_JUEGOS, 1, "TA TE TI", 600);
        addJuegos(arrayJuegos ,CANT_JUEGOS, 2, "JUEGO DE LA OCA", 2500);
        addJuegos(arrayJuegos ,CANT_JUEGOS, 3, "CASITA ROBADA", 800);
        addJuegos(arrayJuegos ,CANT_JUEGOS, 4, "AJEDREZ", 3000);
        addJuegos(arrayJuegos ,CANT_JUEGOS, 5, "TRUCO", 20);
        contadorAltasJuegos ++;// OJo sacarlo despues

        addClientes (arrayClientes ,CANT_CLIENTES, 10, "GONZALES", "JUAN", "CUCU 2030", "15-4030-2050" );
        addClientes (arrayClientes ,CANT_CLIENTES, 20, "EDUARDO", "ANGEL", "MALABIA 50", "15-2020-3020" );
        addClientes (arrayClientes ,CANT_CLIENTES, 30, "ROCCHIO", "JOSE", "COCO 88", "15-7878-2040" );
        addClientes (arrayClientes ,CANT_CLIENTES, 40, "GANDOLFI", "CARLOS", "CABRED 234", "15-3050-4030" );
        addClientes (arrayClientes ,CANT_CLIENTES, 50, "MUSSOLLINI", "ALBERTO", "FOFO 54", "15-8050-2030" );
        contadorAltasClientes++;
                                                        // JA- CCLIENTE
        addAlquileres (arrayAlquileres ,CANT_ALQUILERES, 100, 1, 20, 20, 05, 2010);
        addAlquileres (arrayAlquileres ,CANT_ALQUILERES, 200, 2, 20, 15, 04, 2008);
        addAlquileres (arrayAlquileres ,CANT_ALQUILERES, 300, 3, 30, 10, 04, 2016);
        addAlquileres (arrayAlquileres ,CANT_ALQUILERES, 400, 3, 40, 5, 05, 2018);
        addAlquileres (arrayAlquileres ,CANT_ALQUILERES, 500, 4, 50, 10, 04, 2016);
        contadorAlquileres ++;*/

    do
    {
        system("cls");
        utn_getNumeroAvanzada(&opciones, "\n ------MENU PRINCIPAL------\n\n 1. JUEGOS \n 2. CLIENTES  \n 3. ALQUILERES \n 4. INFORMES \n 5. Salir. \n \n Seleccione una opcion: "," \n Seleccione una opcion valida.", 1, 5,3);

        switch (opciones)
        {
            case 1: // MENU PRINCIPAL: JUEGOS-----

                contadorAltasJuegos=menuJuegos(arrayJuegos, CANT_JUEGOS, contadorAltasJuegos, IMPORTE_JUEGOS, contadorJuego); //DENTRO DE ESTA FUNCION SE REALIZA LA LOGICA DEL CASO JUEGOS.


            break; // BREAK CASE 1 MENU PRINCIPAL


//******************************************************************************************************************************************************************************************************

            case 2: // MENU PRINCIPAL: CLIENTES--------

                contadorAltasClientes= menuClientes(arrayClientes, CANT_CLIENTES, contadorAltasClientes);


            break; // BREAK CASE 2 MENU PRINCIPAL CLIENTES

//*****************************************************************************************************************************************************************************************************

            case 3: // MENU PRINCIPAL: ALQUILERES-----

                contadorAlquileres=menuAlquileres(arrayAlquileres, CANT_ALQUILERES, arrayJuegos, CANT_JUEGOS, arrayClientes, CANT_CLIENTES);


            break; // BREAK CASE 3 MENU PRINCIPAL ALQUILERES

//*****************************************************************************************************************************************************************************************************

            case 4: //***************MENU INFORMES***********************************************************

                if (contadorAltasClientes > 0 && contadorAltasJuegos > 0) // PARA INGRESAR UNICAMENTE SI HAY POR LO MENOS UN ALTA DE CLIENTE  JUEGO
                {
                    do
                    {
                        printf("\n ------MENU INFORMES------\n");
                        printf("\n 1.PROMEDIO Y TOTAL DE LOS IMPORTES DE LOS JUEGOS ALQUILADOS  \n 2. CANTIDAD DE JUEGOS CUYO IMPORTE NO SUPERA AL PROMEDIO DE LOS JUEGOS ALQUILADOS");
                        printf("\n 3. CLIENTES QUE ALQUILARON UN DETERMINADO JUEGO \n 4. TODOS LOS JUEGOS QUE FUERON ALQUILADOS POR UN CLIENTE");
                        printf("\n 5.JUEGOS MENOS ALQUILADOS \n 6. CLIENTES CON MAS ALQUILERES ");
                        printf("\n 7. JUEGOS ALQUILADOS EN DETERMINADA FECHA \n 8. CLIENTES QUE REALIZARON AL MENOS UN ALQUILER EN DETERMINADA FECHA");
                        printf("\n 9. JUEGOS ORDENADOS POR IMPORTE DESCENDENTE \n 10 ORDENADOS POR APELLIDO ASCENDENTE \n 11. SALIR");

                        utn_getNumeroAvanzada(& opcionesInformes, " \n \n Seleccione una opcion: "," \n Seleccione una opcion valida.", 1, 11,3);
    //OJO MODIFICAR EL MAXIMO DE GET NUMERO DE ACUERDO A LAS OPCIONES,,,
                        switch (opcionesInformes)
                        {
                            case 1: //CASO 1 INFORMES

                                printPromedioImporteTotales(arrayAlquileres, CANT_ALQUILERES, arrayJuegos, CANT_JUEGOS);
                                system ("pause");
                            break; // BREAK CASO 1 INFORMES

                            case 2: //CASO 2 INFORMES

                                printCantidadJuegosMinPromedio(arrayAlquileres, CANT_ALQUILERES, arrayJuegos, CANT_JUEGOS);
                                system ("pause");
                            break;// BREAK CASO 2 INFORMES

                            case 3: //CASO 3 INFORMES *****3. CLIENTES QUE ALQUILARON UN DETERMINADO JUEGO

                                utn_getNumeroAvanzada(& auxIndexJuegos, " \n Ingrese el ID del JUEGO AL CUAL INFORMAR: ", "El ID ingresado debe ser numerico", 0, 1000, 3);

                                verificarIdJuegos=checkCodigoJuegos(arrayJuegos, CANT_JUEGOS, auxIndexJuegos);

                                if (verificarIdJuegos ==-1)
                                {
                                    printf( " ******NO SE ESCUENTRA ESE ID DE JUEGO****\n");
                                    system ("pause");
                                    break;
                                }


                                for (i=0; i< CANT_JUEGOS ; i++)
                                {
                                    if (arrayJuegos[i].isEmpty==0)
                                    {
                                        for(j=0; j<CANT_ALQUILERES; j++)
                                        {
                                            if (arrayAlquileres[j].isEmpty==0)
                                            {
                                                if (arrayJuegos[i].codigoJuego == auxIndexJuegos && arrayAlquileres[j].codigoJuegoAlquileres == auxIndexJuegos)
                                                {
                                                    for (k=0; k< CANT_CLIENTES; k++)
                                                    {
                                                        if (arrayClientes[k].isEmpty==0)
                                                        {
                                                            if (arrayAlquileres[j].codigoClienteAlquileres == arrayClientes[k].codigoCliente)
                                                            {
                                                                printf("\n APELLIDO:%s\n NOMBRE:%s \n DOMICILIO:%s \n TELEFONO:%s \n JUEGO ALQUILADO: %s \n"
                                                                        ,arrayClientes[k].apellido, arrayClientes[k].nombre, arrayClientes[k].domicilio
                                                                        , arrayClientes[k].telefono,arrayJuegos[i].descripcionJuego);
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }



                            system ("pause");
                            break;// BREAK CASO 3 INFORMES

                            case 4: //INICIO CASE 4  ***** 4. TODOS LOS JUEGOS QUE FUERON ALQUILADOS POR UN CLIENTE

                                utn_getNumeroAvanzada(& auxIndexClientes, " \n Ingrese el ID del CLIENTE A INFORMAR: ", "El ID ingresado debe ser numerico", 0, 1000, 3);

                                verificarIdClientes=checkCodigoClientes(arrayClientes, CANT_CLIENTES, auxIndexClientes);

                                if (verificarIdClientes ==-1)
                                {
                                    printf( " ******NO SE ESCUENTRA ESE ID DE CLIENTES****\n");
                                    system ("pause");
                                    break;
                                }

                                for (i=0; i< CANT_CLIENTES; i++)
                                {
                                    if (arrayClientes[i].isEmpty==0)
                                    {
                                        for(j=0; j<CANT_ALQUILERES; j++)
                                        {
                                            if (arrayAlquileres[j].isEmpty==0)
                                            {
                                                if (arrayClientes[i].codigoCliente == auxIndexClientes && arrayAlquileres[j].codigoClienteAlquileres == auxIndexClientes)
                                                {
                                                    for (k=0; k< CANT_JUEGOS; k++)
                                                    {
                                                        if (arrayJuegos[k].isEmpty==0)
                                                        {
                                                            if (arrayAlquileres[j].codigoJuegoAlquileres == arrayJuegos[k].codigoJuego)
                                                            {
                                                                printf("\n DESCRIPCION DEL JUEGO:%s\n IMPORTE DEL JUEGO %0.2f \n APELLIDO:%s \n NOMBRE:%s\n"
                                                                        , arrayJuegos[k].descripcionJuego, arrayJuegos[k].importeJuego, arrayClientes[i].apellido, arrayClientes[i].nombre);

                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }


                            system ("pause");

                            break;// BREAK CASO 4 INFORMES

                            case 5: // JUEGOS MENOS ALQUILADOS

                            /*
                                for (i=0; i< CANT_JUEGOS ; i++)
                                {
                                    if (arrayJuegos[i].isEmpty==0)
                                    {
                                        for(j=0; j<CANT_ALQUILERES; j++)
                                        {
                                            if (arrayAlquileres[j].isEmpty==0)
                                            {
                                                if (arrayJuegos[i].codigoJuego == arrayAlquileres[j].codigoJuegoAlquileres)
                                                {
                                                    contadorJuegosAlquilados++;

                                                    for (k=j+1; k<CANT_ALQUILERES-1; k++)
                                                    {
                                                        if (arrayAlquileres[k].isEmpty==0)
                                                        {
                                                            if (arrayAlquileres[j].codigoJuegoAlquileres == arrayAlquileres[k].codigoJuegoAlquileres)
                                                            {
                                                                contadorJuegosAlquilados++; // ACA ENTRA SI LO ALQUILARON MAS DE UNA VEZ...
                                                                //printf ("\n ****** +++++CODIGO:%d ALQUILADO:%d", arrayAlquileres[k].codigoJuegoAlquileres, contadorJuegosAlquilados  );
                                                            }

                                                            contadorJuegosMin++;

                                                            if (contadorJuegosMin == 1)
                                                            {
                                                                maximo=0;
                                                                minimo=0;
                                                            }

                                                            if (contadorJuegosAlquilados > maximo)
                                                            {
                                                                maximo=contadorJuegosAlquilados;
                                                                auxCodMaximo= arrayAlquileres[j].codigoJuegoAlquileres;
                                                                //printf( "EL JUEGO MENOS ALQUILADO ES:%d CANTIDAD DE VECES ALQUILADO: %d \n", auxCodMinimo, minimo);
                                                            }

                                                            if (contadorJuegosAlquilados < minimo)
                                                            {
                                                                minimo=contadorJuegosAlquilados;
                                                                auxCodMinimo= arrayAlquileres[j].codigoJuegoAlquileres;
                                                            }

                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }



                                printf( "EL JUEGO MAS ALQUILADO ES:%d CANTIDAD DE VECES ALQUILADO: %d \n", auxCodMaximo, maximo);
                                printf( "EL JUEGO MENOS ALQUILADO ES:%d CANTIDAD DE VECES ALQUILADO: %d \n", auxCodMinimo, minimo);



                    */



                            break; // CASO 5 INFORMES

                            case 6:  //CLIENTES CON MAS ALQUILERES

                               /*
                                for(i=0; i<CANT_ALQUILERES; i++)
                                {
                                    if (arrayAlquileres[i].isEmpty==0)
                                    {
                                        for (k=i+1; k<CANT_ALQUILERES-1; k++)
                                        {
                                            if (arrayAlquileres[k].isEmpty==0)
                                            {
                                                if (arrayAlquileres[i].codigoClienteAlquileres == arrayAlquileres[k].codigoClienteAlquileres)
                                                {
                                                    contadorClientes++; //OJO BORRAR LO USA OTRA PARTE DEL PROGRAMA

                                                }

                                                if ()






                                */





                            break; // BREAK CASO 6

                            case 7: // JUEGOS ALQUILADOS EN DETERMINADA FECHA... // ok

                                if (utn_getNumeroAvanzada(& auxDiaFecha, "\n Ingrese el dia del alquiler: ", "El dia ingresado no es valido, debe estar compuesto solo por numeros (hasta 31 dias)....\n",1, 31,3 ) != 1)
                                break;

                                if (utn_getNumeroAvanzada(& auxMesFecha, "\n Ingrese el mes del alquiler: ", "El mes ingresado no es valido, debe estar compuesto solo por numeros (hasta 12 meses)....\n",1,12, 3 ) != 1)
                                break;

                                if (utn_getNumeroAvanzada(& auxAnioFecha, "\n Ingrese el anio del alquiler: ", "El anio ingresado no es valido, debe estar compuesto solo por numeros y dentro del rango valido....\n", 2000, 2200, 3 ) != 1)
                                break;

                                for(j=0; j<CANT_ALQUILERES; j++)
                                {
                                    if (arrayAlquileres[j].isEmpty==0)
                                    {
                                        for (i=0; i< CANT_JUEGOS ; i++)
                                        {
                                            if (arrayJuegos[i].isEmpty==0)
                                            {
                                                if ((arrayAlquileres[j].fecha.dia == auxDiaFecha) && (arrayAlquileres[j].fecha.mes == auxMesFecha) && (arrayAlquileres[j].fecha.anio == auxAnioFecha))
                                                {
                                                    if (arrayAlquileres[j].codigoJuegoAlquileres == arrayJuegos[i].codigoJuego) // aca se cambia usando el mismo indice la fecha x el codigo de juego!
                                                    {
                                                        printf("\n JUEGOS ALQUILADOS EN DETERMINADA FECHA: %s\t \%d \t \n", arrayJuegos[i].descripcionJuego, arrayJuegos[i].codigoJuego);

                                                    }
                                                }
                                            }
                                        }
                                    }
                                }


                            system ("pause");

                            break; //FIN CASO 7...

                            case 8: //  CLIENTES QUE REALIZARON AL MENOS UN ALQUILER EN DET FECHA

                                if (utn_getNumeroAvanzada(& auxDiaFecha, "\n Ingrese el dia del alquiler: ", "El dia ingresado no es valido, debe estar compuesto solo por numeros (hasta 31 dias)....\n",1, 31,3 ) != 1)
                                break;

                                if (utn_getNumeroAvanzada(& auxMesFecha, "\n Ingrese el mes del alquiler: ", "El mes ingresado no es valido, debe estar compuesto solo por numeros (hasta 12 meses)....\n",1,12, 3 ) != 1)
                                break;

                                if (utn_getNumeroAvanzada(& auxAnioFecha, "\n Ingrese el anio del alquiler: ", "El anio ingresado no es valido, debe estar compuesto solo por numeros y dentro del rango valido....\n", 2000, 2200, 3 ) != 1)
                                break;


                                for(j=0; j<CANT_ALQUILERES; j++)
                                {
                                    if (arrayAlquileres[j].isEmpty==0)
                                    {
                                        for (i=0; i< CANT_CLIENTES ; i++)
                                        {
                                            if (arrayClientes[i].isEmpty==0)
                                            {
                                                if ((arrayAlquileres[j].fecha.dia == auxDiaFecha) && (arrayAlquileres[j].fecha.mes == auxMesFecha) && (arrayAlquileres[j].fecha.anio == auxAnioFecha))
                                                {
                                                    if (arrayAlquileres[j].codigoClienteAlquileres == arrayClientes[i].codigoCliente)
                                                    {
                                                        printf("\n APELLIDO:%s\n NOMBRE:%s \n DOMICILIO:%s \n TELEFONO:%s \n CODIGO JUEGO ALQUILADO: %d \n"
                                                                        ,arrayClientes[i].apellido, arrayClientes[i].nombre, arrayClientes[i].domicilio
                                                                        ,arrayClientes[i].telefono,arrayAlquileres[j].codigoJuegoAlquileres);
                                                    }

                                                }

                                            }
                                        }
                                    }
                                }


                            break; // break case 8 INFORMES

                            case 9: //JUEGOS ORDENADOS DESCENDENTE

                                sortJuegosMasEficiente(arrayJuegos, CANT_JUEGOS);
                                printJuegos(arrayJuegos, CANT_JUEGOS);

                                system ("pause");
                            break; //fin case 9...

                            case 10:

                                sortClientesPorInsersion(arrayClientes, CANT_CLIENTES);
                                printClientes(arrayClientes, CANT_CLIENTES);

                                system ("pause");


                            system ("pause");
                            break; //break case 10



                        } // FIN SWITCH INFORMES...

                        }while (opcionesInformes !=11);

                    }
                    else
                    {
                        printf("\n ****Primero debe dar de alta un cliente y un juego..****\n \n ");
                        system( "pause");
                    }


            break; //BREAK MENU INFORMES!


        } //FIN SWITCH PRINCIPAL

    }while (opciones != 5); // OPCIONES MENU PRINCIPAL

    return 0;

}





