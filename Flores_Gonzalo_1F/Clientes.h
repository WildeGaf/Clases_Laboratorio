#ifndef CLIENTES_H_INCLUDED


typedef struct
{
    int codigoCliente;
    char apellido[51];
    char nombre[51];
    char domicilio[51];
    char telefono[51];
    int isEmpty;

}eCliente;


/**
* @brief Inicializa los valores en 0
* @param eCliente* lista - Una lista de la estructura de clientes
* @param len - Cantidad del vector
*/
void inicializarCliente(eCliente* lista,int len);


/**
* @brief Busca el primer espacio disponible.
* @param eCliente* lista - Una lista de la estructura de clientes
* @param len - cantidad del vector
* @return Devuelve la ubicacion del primer espacio disponible o -1(error)
*/
int primerEspacioCliente(eCliente* lista, int len);


/**
* @brief Agrega los datos del cliente
* @param eCliente* lista - Una lista de la estructura de clientes
* @param len - cantidad del vector
* @param altaBanderaCliente - Cambia el valor si se ingresa un dato
*/
void addCliente(eCliente* lista, int len,int *altaBanderaCliente);


/**
* @brief Busca el cliente por codigo ingresado
* @param eCliente* lista - Una lista de la estructura de clientes
* @param len - cantidad del vector
* @param codigo - Codigo del cliente a buscar
* @return Devuelve la ubicacion donde se encuentra el cliente
*/
int findCliente(eCliente* lista, int len,int codigo);


/**
* @brief Desplega un menu para que el usuario seleccione una opcion
* @return Devuelve la opcion elegida por el usuario
*/
int menuClientes();


/**
* @brief Elimina datos del cliente ingresado por codigo
* @param eCliente* lista - Una lista de la estructura de clientes
* @param len - cantidad del vector
*/
void bajaCliente(eCliente* lista,int len);


/**
* @brief Modifica los datos de un cliente
* @param eCliente* lista - Una lista de la estructura de clientes
* @param len - cantidad del vector
*/
void modificarCliente(eCliente* lista,int len);


/**
* @brief Imprime la lista de Clientes
* @param eJuegos* lista - Una lista de la estructura de clientes
* @param len - cantidad del vector
*/
void imprimirListaClientes(eCliente* lista,int len);


/**
* @brief Ordena por apellido y nombre
* @param eJuegos* Cliente - Una lista de la estructura de clientes
* @param len - cantidad del vector
*/
void ordenarClientes(eCliente* lista, int len);

#endif// CLIENTES_H_INCLUDED
