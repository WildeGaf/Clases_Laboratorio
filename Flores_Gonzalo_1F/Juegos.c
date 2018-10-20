#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "Juegos.h"


int MenuJuegos(){
    int opcionElegida;
    printf ("*******Menu Juegos******\n");
    printf ("\n1- Ingrese uno para dar de alta un juego");
    printf ("\n2- Ingrese dos para modificar los datos de un juego");
    printf ("\n3- Ingrese tres para dar de baja un juego");
    printf ("\n4- Ingrese cuatro para Imprimir de forma ordenada");
    printf ("\n\nIngrese el numero: ");
    getInt(&opcionElegida);
    return opcionElegida;
}

void inicializarJuego(eJuegos* lista,int len){
    int i;
    for (i=0;i<len;i++){
        lista[i].isEmpty = 0;
    }
}

int primerEspacioligre(eJuegos* lista, int len){
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

int findJuego(eJuegos* lista, int len,int codigo){
    int retorno = -1;
    int i;
    for (i=0;i<len;i++){
        if(lista[i].codigoJuego == codigo){
            retorno = i;
            break;
        }
    }
return retorno;
}

int addJuego(eJuegos* lista, int len,int* altaBanderaJuego){
    int r,retorno = -1;
    int importeJuego,validar;
    char descripcion[51];
    r = primerEspacioligre(lista,len);
    if (r != -1){
        do{
        printf("Ingrese la descripcion: ");
        getString(descripcion);
        validar = strlen(descripcion);
        }while(validar>51 || validar <0);
        do{
            printf("Ingrese el importe del juego: ");
            getInt(&importeJuego);
        }while(importeJuego<0);
        strcpy(lista[r].descripcion,descripcion);
        lista[r].importe = importeJuego;
        lista[r].isEmpty = 1;
        lista[r].codigoJuego = r;
        retorno = 0;
        *altaBanderaJuego = 1;
    }
    else{
        printf("No hay espacio disponible");
    }
    return retorno;
}

void modificarJuego(eJuegos* lista,int len){
    int auxCodigoJuego,validar,auxImporteJuego,validarJuego,opcionElegida;
    char auxDescripcion[51];
    printf("Ingrese el codigo del libro que desea modificar del registro");
    getInt(&auxCodigoJuego);
    validarJuego = findJuego(lista,len,auxCodigoJuego);
    if (validarJuego == -1){
        printf("No se ha encontrado el codigo ingresado");
    }
    else {
        printf("1-Modificar descripcion");
        printf("\n2-Modificar importe");
        printf ("\n\nIngrese el numero: ");
        getInt(&opcionElegida);
        switch (opcionElegida){
            case 1:
                do{
                printf("Ingrese la nueva descripcion");
                getString(auxDescripcion);
                validar = strlen(auxDescripcion);
                }while(validar>51 || validar <0);
            break;
            case 2:
            do{
            printf("Ingrese el nuevo importe");
            getInt(&auxImporteJuego);
            }while(auxImporteJuego<0);
            lista[validarJuego].importe = auxImporteJuego;
            break;
            default:
            printf("Error al seleccion una opcion");
            break;
        }

    }
}

void ordenarJuegos(eJuegos* lista, int len){
 eJuegos AuxLista;
 int i,j;
        for (i=0;i<len;i++){
            if (lista[i].isEmpty == 1){
                for(j=i+1;j<len;j++){
                   if (lista[j].isEmpty == 1){
                        if(lista[i].importe > lista[j].importe)
                        {
                            AuxLista = lista[i];
                            lista[i] = lista[j];
                            lista[j] = AuxLista;
                        }
                        else{
                            if(lista[i].importe == lista[j].importe){
                                if(strcmp(lista[i].descripcion,lista[j].descripcion)>1) {
                                    AuxLista = lista[i];
                                    lista[i] = lista[j];
                                    lista[j] = AuxLista;
                                }
                            }
                        }
                    }
                }
            }
        }
}

void BajaJuego(eJuegos* lista, int len){
    int juegoIdEncontrado;
    int auxCodigoJuego;
    printf("Ingrese el codigo del libro que desea eliminar del registro");
    getInt(&auxCodigoJuego);
    juegoIdEncontrado = findJuego(lista,len,auxCodigoJuego);
    if (juegoIdEncontrado == -1){
        printf("Ese codigo no se encuentra en el registro");
    }
    else{
    lista[juegoIdEncontrado].isEmpty = 0;
    }
}

void imprimirListaJuegos(eJuegos* lista,int len){
    int i;
    ordenarJuegos(lista,len);
    for (i=0;i<len;i++){
        if (lista[i].isEmpty == 1){
            printf ("\n La descripcion es: %s",lista[i].descripcion);
            printf ("\n El importe es: %d",lista[i].importe);
            printf ("\n El codigo es: %d\n\n",lista[i].codigoJuego);
        }
    }
}

void promedioJuegos(eJuegos* listaJ,eAlquiler* listaA,int len){
    int i,contador = 0;
    int acumulador = 0;
    int promedio,contadorProm=0;
    for (i=0;i<len;i++){
        if(listaA[i].isEmpty !=0){
            contador = contador + 1;
            acumulador = acumulador + listaJ[i].importe;
        }
    }
    promedio = acumulador/contador;
    printf("\nEl promedio es de: %d",promedio);
    printf("\n\nEl total es de: %d",acumulador);
    for (i=0;i<len;i++){
        if(listaJ[i].isEmpty !=0 && listaJ[i].importe < promedio){
            contadorProm = contadorProm + 1;
        }
    }
    printf("\n\nLa cantidad de juegos que no superan el promedio es de: %d\n\n",contadorProm);
}

void ordenarJuegosDos(eJuegos* lista, int len){
 eJuegos AuxLista;
 int i,j;
        for (i=0;i<len;i++){
            if (lista[i].isEmpty == 1){
                for(j=i+1;j<len;j++){
                   if (lista[j].isEmpty == 1){
                        if(lista[i].importe < lista[j].importe)
                        {
                            AuxLista = lista[i];
                            lista[i] = lista[j];
                            lista[j] = AuxLista;
                        }
                   }
                }
            }
        }
}

void imprimirListaJuegosDos(eJuegos* lista,int len){
    int i;
    ordenarJuegosDos(lista,len);
    for (i=0;i<len;i++){
        if (lista[i].isEmpty == 1){
            printf ("\n La descripcion es: %s",lista[i].descripcion);
            printf ("\n El importe es: %d",lista[i].importe);
            printf ("\n El codigo es: %d\n\n",lista[i].codigoJuego);
        }
    }
}


/***************************************************************************/


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

void addCliente(eCliente* lista, int len,int *altaBanderaCliente){
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

int findCliente(eCliente* lista, int len,int codigo){
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

void ordenarClientes(eCliente* lista, int len){
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

/* void ordenarInsercion(eCliente* lista,int len){
int i,j,test;
char aux[51];
for (i=1; i<len; i++);
    j = i - 1;
    test = strcmp(lista[j].apellido,lista[i]Apellido)>0
    while (test > 1){
    lista[j+1]=lista[j];
    j--;
    //lista[j+1] = ;
    }
}
*/

/*********************************************************************************/

void inicializarAlquiler(eAlquiler* lista,int len){
    int i;
    for (i=0;i<len;i++){
        lista[i].isEmpty = 0;
    }
}

int primerEspacioAlquiler(eAlquiler* lista,int len){
    int i,retorno = -1;
    for (i=0;i<len;i++){
        if (lista[i].isEmpty == 0){
            retorno = i;
        break;
        }
    }
return retorno;
}

void addAlquiler(eCliente* listaC,int lenC,eJuegos* listaJ,int lenJ,eAlquiler* listaA,int lenA){
    int i,j,z;
    for (i=0;i<lenC;i++){
        if (listaC[i].isEmpty == 1){
            for (j=0;j<lenJ;j++){
                if (listaJ[j].isEmpty == 1){
                    z = primerEspacioAlquiler(listaA,lenA);
                    listaA[z].codigoAlquiler = z;
                    listaA[z].codigoCliente = listaC[i].codigoCliente;
                    listaA[z].codigoJuegos = listaJ[j].codigoJuego;
                }
            }
        }
    }


}


/*********************************************************************************/


void promedioJuegosAlquilados(eJuegos* listaJ,int lenJ,eAlquiler* listaA,int lenA){
    int i,j,promedio,auxCodigo,contador=0,total=0;
    for (i=0;i<lenA;i++){
        if (listaA[i].isEmpty == 1){
            auxCodigo = listaA[i].codigoJuegos;
            for (j=0;j<lenJ;j++){
                if (listaJ[j].isEmpty==1 && listaJ[j].codigoJuego == auxCodigo){
                    total = total + listaJ[j].importe;
                    contador++;
                }
            }
        }
    }
    promedio = total/contador;
    printf("\nEl promedio de los juegos alquilados es de :$ %d",promedio);
}

void alquilerJuegoDeterminado(eCliente listaC,int lenC,eAlquiler* listaA,int lenA,int codigoJ){
    int j,i;
    for (i=0;i<lenA;i++){
        if (listaA[i].isEmpty == 1 && listaA[i].codigoJuegos == codigoJ){
            for (j=0;j<lenC;j++){
                if (listaC[j].isEmpty == 1 && listaC[j].codigoCliente == listaA[i].codigoCliente){
                    printf("\nApellido: %s",listaC[j].apellido);
                    printf("\nNombre: %s",listaC[j].nombre);
                    printf("\nCodigo: %d\n\n",listaC[j].codigoCliente);
                }
            }
        }
    }
}
