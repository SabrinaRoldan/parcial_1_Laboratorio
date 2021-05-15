#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "roldan.h"
#include "alquileres.h"


int menu_alquileres()
{
    int opcion;

    system("cls");
    printf("        ***Alquileres***\n");
    printf(" 1- Alta alquiler\n");
    printf(" 2- Modificacion alquiler\n");
    printf(" 3- Baja alquiler\n");
    printf(" 4- Listar alquileres\n");
    printf(" 5- Salir\n");
    printf("Ingrese opcion: ");
    scanf("%d",&opcion);

    return opcion;

}

int altaAlquileres(eAlquileres lista[], int tam, int* pId)
{
    int retorno=0;
    int indice;
    eAlquileres nuevoAlquileres;

    if(lista!=NULL && tam>0 && pId!=NULL)
    {
        system("cls");
        printf("        Alta Alquileres\n\n");

        indice=buscarLibre_alquiler(lista,tam);
        if(indice==-1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
            nuevoAlquileres.codigo=*pId;

            printf("Codigo: %d\n",nuevoAlquileres.codigo);

            if(!utn_getUnsignedInt("Ingrese el codigo del juego: ","Error. ",0,4,500,504,4,&nuevoAlquileres.idJuego))
            {
                printf("Error al cargar el id de juego.\n");
                return 0;
            }

            if(!utn_getUnsignedInt("Ingrese el codigo del Cliente: ","Error. ",0,4,500,504,4,&nuevoAlquileres.idCliente))
            {
                printf("Error al cargar el id de Cliente.\n");
                return 0;
            }

            if(!getFecha("Ingrese fecha: ","Error."
                     ,&nuevoAlquileres.fecha.dia
                     ,&nuevoAlquileres.fecha.mes
                     ,&nuevoAlquileres.fecha.anio
                     ,1990,2100,4))
            {
                printf("Error al cargar la fecha.\n");
                return 0;
            }

            printf("\n");
            printf("Alta de Alquileres exitosa!\n\n");

            nuevoAlquileres.isEmpty=0;

            lista[indice]=nuevoAlquileres;

            (*pId)++;

            retorno=1;
        }
    }
    return retorno;
}

int buscarLibre_alquiler(eAlquileres lista[], int tam)
{
    int indice=-1;

    if(lista!=NULL && tam>0)
    {
        for(int i=0;i<tam;i++)
       {
           if(lista[i].isEmpty==1)
           {
               indice=i;
               break;
           }
       }
    }
    return indice;
}

void inicializarAlquileres(eAlquileres lista[],int tam)
{
    for(int i=0;i<tam;i++)
    {
        lista[i].isEmpty=1;
    }
}

void mostrarAlquiler (eAlquileres unAlquileres)
{

        printf("       %d     %d      %d       %2d/%2d/%2d\n"
                    ,unAlquileres.codigo
                    ,unAlquileres.idJuego
                    ,unAlquileres.idCliente
                    ,unAlquileres.fecha
                    );
}

void mostrarAlquileres(eAlquileres lista[],int tam)
{
    int flag=1;


    printf("\n --------------------------------------------------------------------------------------\n");
    printf("                                Lista de Alquileres\n");
    printf("       Codigo        Juego          Cliente        Fecha");
    printf("\n --------------------------------------------------------------------------------------\n");

    for(int i=0;i<tam;i++)
    {
        if(!lista[i].isEmpty)
        {
        mostrarAlquiler(lista[i]);
        flag=0;
        }
    }
    if(flag)
    {
        printf("No hay Alquileres en la lista");
    }

    printf("\n\n");

}

int buscarAlquileres(eAlquileres lista[],int tam, int codigo)
{
    int indice=-1;

    if(lista!=NULL && tam>0)
    {
        for(int i=0;i<tam;i++)
       {
           if(!lista[i].isEmpty && lista[i].codigo==codigo)
           {
               indice=i;
               break;
           }
       }
    }
    return indice;
}

int bajaAlquileres(eAlquileres lista[], int tam)
{
    int retorno=0;
    int indice;
    int codigo;
    char confirma;

    system("cls");
    printf("        Baja Alquileres\n");
    mostrarAlquileres(lista,tam);
    printf("Ingrese codigo: ");
    scanf("%d",&codigo);

    indice=buscarAlquileres(lista,tam,codigo);

    if(indice==-1)
    {
        printf("No existe un Alquileres con el codigo: %d\n", codigo);
    }
    else
    {
        mostrarAlquiler(lista[indice]);
        printf("Confirma baja?: ");
        fflush(stdin);
        scanf("%c",&confirma);

        if(confirma=='s')
        {
            lista[indice].isEmpty=1;
            retorno=1;
        }
        else
        {
            printf("Baja cancelada por el usuario\n");
        }
    }

    return retorno;
}

int modificarAlquileres(eAlquileres lista[], int tam)
{
    int retorno=0;
    int indice;
    int codigo;
    int opcion;
    char confirma;
    eAlquileres nuevoAlquileres;

    system("cls");
    printf("        Modificar Alquileres\n");
    mostrarAlquileres(lista,tam);
    printf("Ingrese codigo: ");
    scanf("%d",&codigo);

    indice=buscarAlquileres(lista,tam,codigo);

    if(indice==-1)
    {
        printf("No existe un Alquileres con el codigo: %d\n", codigo);
    }
    else
    {
        mostrarAlquiler(lista[indice]);
        printf("Confirma modificacion?: ");
        fflush(stdin);
        scanf("%c",&confirma);

        if(confirma=='s')
        {
            nuevoAlquileres.codigo=codigo;

            printf("        Opciones a modificar:\n");
            printf("1- Juego\n");
            printf("2- Cliente\n");
            printf("3- Fecha\n");
            printf("Ingrese opcion: ");
            scanf("%d",&opcion);

            switch(opcion){

                case 1:
                    if(!utn_getUnsignedInt("Ingrese el codigo del juego: ","Error. ",0,3,500,504,4,&nuevoAlquileres.idJuego))
                    {
                        printf("Error al cargar el id de juego.\n");
                        return 0;
                    }
                    lista[indice].idJuego=nuevoAlquileres.idJuego;
                    break;

                case 2:
                    if(!utn_getUnsignedInt("Ingrese el codigo del Cliente: ","Error. ",0,3,500,504,4,&nuevoAlquileres.idCliente))
                    {
                        printf("Error al cargar el id de Cliente.\n");
                        return 0;
                    }
                    lista[indice].idCliente=nuevoAlquileres.idCliente;
                    break;

                case 3:
                    if(!getFecha("Ingrese fecha: ","Error."
                     ,&nuevoAlquileres.fecha.dia
                     ,&nuevoAlquileres.fecha.mes
                     ,&nuevoAlquileres.fecha.anio
                     ,1990,2100,4))
                    {
                        printf("Error al cargar la fecha.\n");
                        return 0;
                    }
                    lista[indice].fecha.dia=nuevoAlquileres.fecha.dia;
                    lista[indice].fecha.dia=nuevoAlquileres.fecha.mes;
                    lista[indice].fecha.dia=nuevoAlquileres.fecha.anio;
                    break;

                default:
                    printf("Opcion no valida\n");
                    break;
            }

            retorno=1;
        }
        else
        {
            printf("Modificacion cancelada por el usuario\n");
        }
    }

    return retorno;
}

