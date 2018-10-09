#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Clientes.h"
#include "input.h"

int menuClientes(){
    int opcionElegida;
    printf ("*******Menu Clientes******\n");
    printf ("\n1- Ingrese uno para dar de alta un cliente");
    printf ("\n2- Ingrese dos para modificar los datos de un cliente");
    printf ("\n3- Ingrese tres para dar de baja un cliente");
    printf ("\n4- Ingrese cuatro para listar los clientes");
    printf ("\n\nIngrese el numero: ");
    getInt(&opcionElegida);
    return opcionElegida;
}

void inicializarCliente(eCliente* lista,int len){
    int i;
    for (i=0;i<len;i++){
        lista[i].isEmpty = 0;
    }
}

int primerEspacioCliente(eCliente* lista, int len){
int i,retorno;
retorno = -1;
    for (i=0;i<len;i++){
        if (lista[i].isEmpty == 0){
            retorno = i;
            break;
        }
    }
return retorno;
}

void addCliente(eCliente* lista, int len,int *altaBanderaCliente)
{
    int r,cantidad;
    char auxNombre[51], auxApellido[51],auxDomicilio[51];
    char auxTelefono[51];
    r = primerEspacioCliente(lista,len);
    if (r != -1){
        do{
            printf("Ingrese el apellido del cliente");
            getSringLetras(auxApellido);
            cantidad = strlen(auxApellido);
        }while(cantidad>51 || cantidad<0);
        do{
            printf("Ingrese el nombre del cliente");
            getSringLetras(auxNombre);
            cantidad = strlen(auxNombre);
        }while(cantidad>51 || cantidad<0);
        do{
            printf("Ingrese el domicilio del cliente");
            getString(auxDomicilio);
            cantidad = strlen(auxDomicilio);
        }while(cantidad>51 || cantidad<0);
        do{
            printf("Ingrese el telefono del cliente");
            getString(auxTelefono);
            cantidad = strlen(auxTelefono);
        }while(cantidad>21 || cantidad<0);
        strcpy(lista[r].apellido,auxApellido);
        strcpy(lista[r].nombre,auxNombre);
        strcpy(lista[r].domicilio,auxDomicilio);
        strcpy(lista[r].telefono,auxTelefono);
        lista[r].codigoCliente = r;
        lista[r].isEmpty = 1;
        *altaBanderaCliente = 1;
    }else{
    printf("No hay espacio disponble");
    }
}

int findCliente(eCliente* lista, int len,int codigo)
{
    int retorno = -1;
    int i;
    for (i=0;i<len;i++){
        if(lista[i].codigoCliente == codigo){
            retorno = i;
            break;
        }
    }
return retorno;
}

void modificarCliente(eCliente* lista,int len){
    int auxCodigoCliente,respuesta,clienteEncontrado;
    int cantidad;
    char auxNombreCliente[51], auxApellidoCliente[51];
    char auxDomicilioCliente[51], auxTelefonoCliente[51];

    printf("Ingrese el codigo del cliente que desea modificar");
    getInt(&auxCodigoCliente);
    clienteEncontrado = findCliente(lista,len,auxCodigoCliente);
    if (clienteEncontrado != -1){
        printf("Submenu modificacion de registro del cliente");
        printf("\n1- ingrese 1 para modificar el apellido");
        printf("\n2- ingrese 2 para modificar el nombre");
        printf("\n3- ingrese 3 para modificar el domiciolio");
        printf("\n4- ingrese 4 para modificar el telefono");
        printf ("\n\nIngrese el numero: ");
        getInt(&respuesta);
        switch(respuesta){
        case 1:
            do{
                printf("Ingrese el apellido a modificar: ");
                getSringLetras(auxApellidoCliente);
                cantidad = strlen(auxApellidoCliente);
            }while(cantidad>51 || cantidad<0);
            strcpy(lista[clienteEncontrado].apellido,auxApellidoCliente);
        case 2:
            do{
                printf("Ingrese el nombre a modificar: ");
                getSringLetras(auxNombreCliente);
                cantidad = strlen(auxNombreCliente);
            }while(cantidad>51 || cantidad<0);
            strcpy(lista[clienteEncontrado].nombre,auxNombreCliente);
        case 3:
            do{
                printf("Ingrese el domicilio a modificar: ");
                getString(auxDomicilioCliente);
                cantidad = strlen(auxDomicilioCliente);
            }while(cantidad>51 || cantidad<0);
            strcpy(lista[clienteEncontrado].domicilio,auxDomicilioCliente);
        case 4:
            do{
                printf("Ingrese el telefono a modificar: ");
                getString(auxTelefonoCliente);
                cantidad = strlen(auxTelefonoCliente);
            }while(cantidad>51 || cantidad<0);
            strcpy(lista[clienteEncontrado].telefono,auxTelefonoCliente);
        }
    }else{
        printf("No se encuentran los datos de este cliente");
    }
}

void bajaCliente(eCliente* lista,int len){
    int auxCodigo,encontrado;
    printf("Ingrese el codigo del cliente que desea eliminar del registro");
    getInt(&auxCodigo);
    encontrado = findCliente(lista,len,auxCodigo);
    if (encontrado != -1){
        lista[encontrado].isEmpty = 0;
    }else{
    printf("No se encuentra en el registro");
    }
}


void ordenarClientes(eCliente* lista, int len)
{
 eCliente AuxLista;
 int i,j;
        for (i=0;i<len;i++){
            for(j=i+1;j<len;j++){
                    if(strcmp(lista[i].apellido,lista[j].apellido)>0){
                        AuxLista = lista[i];
                        lista[i] = lista[j];
                        lista[j] = AuxLista;
                    }
                    else{
                        if (strcmp(lista[i].apellido,lista[j].apellido)==0){
                            if(strcmp(lista[i].nombre,lista[j].nombre)>0){
                                AuxLista = lista[i];
                                lista[i] = lista[j];
                                lista[j] = AuxLista;
                            }
                        }
                    }
            }
        }
}

void imprimirListaClientes(eCliente* lista,int len){
    int i;
    ordenarClientes(lista,len);
    for (i=0;i<len;i++){
        if (lista[i].isEmpty == 1){
            printf ("\n Apellido del cliente: %s",lista[i].apellido);
            printf ("\n Nombre del cliente: %s",lista[i].nombre);
            printf ("\n Direccion del cliente: %s",lista[i].domicilio);
            printf ("\n Telefono del cliente: %s",lista[i].telefono);
            printf ("\n Codigo del cliente: %d\n\n",lista[i].codigoCliente);
        }
    }
}

ordenarInsercion(eCliente* lista,len){
int i,j;
char aux[51];
for (i=1; i<len; i++);
    j = i - 1;
    while ( strcmp(lista[j].apellido,lista[i]Apellido)>0)
    lista[j+1]=lista[j];
    j--;
    lista[j+1] = temp;
}
