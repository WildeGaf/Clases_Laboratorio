#ifndef JUEGOS_H_INCLUDED

typedef struct
{
    int dia,mes,anio;
    int codigoAlquiler;
    int codigoJuegos;
    int codigoCliente;
    int isEmpty;
}eAlquiler;

typedef struct
{
    int codigoJuego;
    char descripcion[51];
    int importe;
    int isEmpty;
}eJuegos;

/**
* @brief Desplega un menu para que el usuario seleccione una opcion
* @return Devuelve la opcion elegida por el usuario
*/
int MenuJuegos();


/**
* @brief Inicializa los valores en 0
* @param eJuegos* lista - Una lista de la estructura de juegos
* @param len - Cantidad del vector
*/
void inicializarJuego(eJuegos* lista,int len);


/**
* @brief Busca el primer espacio disponible.
* @param eJuegos* lista - Una lista de la estructura de juegos
* @param len - cantidad del vector
* @return Devuelve la ubicacion del primer espacio disponible o -1(error)
*/
int primerEspacioligre(eJuegos* lista, int len);


/**
* @brief Agrega los datos del juego
* @param eJuegos* lista - Una lista de la estructura de juegos
* @param len - cantidad del vector
* @param altaBanderaJuego - Cambia el valor si se ingresa un dato
* @return Devuelve la ubicacion o -1 para indicar error
*/
int addJuego(eJuegos* lista, int len, int* altaBanderaJuego);


/**
* @brief Busca el juego por codigo ingresado
* @param eJuegos* lista - Una lista de la estructura de juegos
* @param len - cantidad del vector
* @param codigo - Codigo del juego a buscar
* @return Devuelve la ubicacion donde se encuentra el juego
*/
int findJuego(eJuegos* lista, int len,int codigo);


/**
* @brief Elimina datos del juego ingresado por codigo
* @param eJuegos* lista - Una lista de la estructura de juegos
* @param len - cantidad del vector
*/
void BajaJuego(eJuegos* lista, int len);


/**
* @brief Imprime la lista de juegos
* @param eJuegos* lista - Una lista de la estructura de juegos
* @param len - cantidad del vector
*/
void imprimirListaJuegos(eJuegos* lista,int len);


/**
* @brief Ordena por importe y descripcion
* @param eJuegos* lista - Una lista de la estructura de juegos
* @param len - cantidad del vector
*/
void ordenarJuegos(eJuegos* lista, int len);


/**
* @brief Modifica los datos de un juego
* @param eJuegos* lista - Una lista de la estructura de juegos
* @param len - cantidad del vector
*/
void modificarJuego(eJuegos* lista,int len);

void promedioJuegos(eJuegos* listaJ,eAlquiler* listaA,int len);

void verificarAlquiler(int codigoCliente,eJuegos* listaJ,int lenJ,eAlquiler* listaA,int lenA);
int primerEspacioAlquiler(eAlquiler* lista,int len);
void inicializarAlquiler(eAlquiler* lista,int len);
void ordenarJuegosDos(eJuegos* lista, int len);
void imprimirListaJuegosDos(eJuegos* lista,int len);

#endif//JUEGOS_H_INCLUDED
