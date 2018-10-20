#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int edad;
    char nombre[31];
}ePersona;

int main()
{
    ePersona per,pers[5],*p;
    int i;
    /*
    printf("Ingrese la edad: ");
    scanf("\n%d",&per.edad);
    printf("Ingrese el nombre: ");
    scanf("\n%s",per.nombre);
    p = &per;
    printf("\n%d",p->edad);
    printf("\n%s",p->nombre);
    printf("\n%d",(*p).edad);
    printf("\n%s",(*p).nombre);

    p = &pers[0];
    for (i=0;i<5;i++){
        printf("Ingrese la edad: ");
        scanf("\n%d",&(p+i)->edad;
        printf("Ingrese el nombre: ");
        scanf("\n%s",(p+i)->nombre);
        fflush(stdin);
    }
    for (i=0;i<5;i++){
        printf("\n%d",(p+i)->edad);
        printf("\n%s",(p+i)->nombre);
    }
     */

    p = &pers[0];
    for (i=0;i<5;i++){
        printf("Ingrese la edad: ");
        scanf("\n%d",&(*(p+i)).edad);
        printf("Ingrese el nombre: ");
        scanf("\n%s",(*(p+i)).nombre);
        fflush(stdin);
    }
    for (i=0;i<5;i++){
        printf("\n%d",(*(p+i)).edad);
        printf("\n%s",(*(p+i)).nombre);
    }
    return 0;
}
