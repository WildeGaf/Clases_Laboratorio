#ifndef JUEGOS_H_INCLUDED
#define JUEGOS_H_INCLUDED

 typedef struct
 {
     int codigoJuego;
     char descripcionJuego[51];
     float importeJuego;
     int isEmpty;

 } Juegos;

 typedef struct
 {
     int dia;
     int mes;
     int anio;

 } eFecha;

  typedef struct
 {
     int codigoAlquileres;
     int codigoJuegoAlquileres;
     int codigoClienteAlquileres;
     eFecha fecha;
     int isEmpty;

 } Alquileres;


    int initJuegos(Juegos arrayJuegos [], int longitudArray);

    int utn_buscarLugarVacioJuegos (Juegos arrayJuegos [],int longitudArray);

    int addJuegos (Juegos arrayJuegos [], int longitudArray, int codigoJuego , char descripcion[], float importe);

    int findJuegoById(Juegos arrayJuegos [], int longitudArray, int codigoJuego);

    int removeJuegos (Juegos arrayJuegos [], int longitudArray, int codigoJuego);

    int sortJuegos (Juegos arrayJuegos [], int longitudArray);

    int printJuegos(Juegos arrayJuegos [], int longitudArray);

    int sortJuegosMasEficiente (Juegos arrayJuegos [], int longitudArray);


//SECTOR ALQUILERES

    int initAlquileres (Alquileres arrayAlquileres [] , int longitudArray);

    int utn_buscarLugarVacioAlquileres(Alquileres arrayAlquileres [], int longitudArray);

    int checkCodigoJuegos (Juegos arrayJuegos [], int longitudArray, int codigoJuego);

    int addAlquileres (Alquileres arrayAlquileres [],int longitudArray, int contadorAlquileres, int auxCodigoJuegoAlquileres,
                       int auxCodigoClienteAlquileres, int auxDiaFecha, int auxMesFecha, int auxAnioFecha);


    void printPromedioImporteTotales(Alquileres arrayAlquileres [], int longitudArrayAlquileres, Juegos arrayJuegos [], int longitudArrayJuegos);

    float promedioJuegosAlquilados(Alquileres arrayAlquileres [], int longitudArrayAlquileres, Juegos arrayJuegos [], int longitudArrayJuegos);

    void printCantidadJuegosMinPromedio(Alquileres arrayAlquileres [], int longitudArrayAlquileres, Juegos arrayJuegos [], int longitudArrayJuegos);


    int printAlquileres(Alquileres arrayAlquileres [], int longitudArray); // OJOOOO BORRAR ES SOLO PARA PROBAR...OJOOOOOOOOOOOOOOOOOOOOOOOOOOO***************

    int checkCodigoAlquileres (Alquileres arrayAlquileres [], int longitudArray, int codigoJuego);


    // FUNCIONES GENERALES

   int menuJuegos (Juegos arrayJuegos[], int CANT_JUEGOS, int contadorAltasJuegos, int IMPORTE_JUEGOS, int contadorJuego);

   int menuAlquileres (Alquileres arrayAlquileres [],int CANT_ALQUILERES, Juegos arrayJuegos[], int CANT_JUEGOS, Clientes arrayClientes [], int CANT_CLIENTES);




 #endif
