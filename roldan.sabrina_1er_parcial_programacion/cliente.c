#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "roldan.h"

int menu_clientes()
{
    int opcion;

    system("cls");
    printf("        ***Clientes***\n");
    printf(" 1- Alta cliente\n");
    printf(" 2- Modificacion cliente\n");
    printf(" 3- Baja cliente\n");
    printf(" 4- Listar cliente\n");
    printf(" 5- Salir\n");
    printf("Ingrese opcion: ");
    scanf("%d",&opcion);

    return opcion;

}

int altaCliente(eCliente lista[], int tam, int* pId)
{
    int retorno=0;
    int indice;
    eCliente nuevoCliente;

    if(lista!=NULL && tam>0 && pId!=NULL)
    {
        system("cls");
        printf("        Alta Cliente\n\n");

        indice=buscarLibre(lista,tam);
        if(indice==-1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
            nuevoCliente.codigo=*pId;

            printf("Codigo: %d\n",nuevoCliente.codigo);

            if(!utn_getName("Ingrese el nombre del cliente: ","Error. ",3,51,4,nuevoCliente.nombre))
            {
                printf("Error al cargar el nombre.\n");
                return 0;
            }

            if(!utn_getName("Ingrese el apellido del cliente: ","Error. ",3,51,4,nuevoCliente.apellido))
            {
                printf("Error al cargar el apellido.\n");
                return 0;
            }

            if(!getSexo("Ingrese sexo: ","Error.",&nuevoCliente.sexo,4))
            {
                printf("Error al cargar el sexo.\n");
                return 0;
            }

            if(!utn_getTelefono("Ingrese telefono: ","Error. ",1,22,4,&nuevoCliente.telefono))
            {
                printf("Error al cargar el telefono.\n");
                return 0;
            }


            printf("\n");
            printf("Alta de cliente exitosa!\n\n");

            nuevoCliente.isEmpty=0;

            lista[indice]=nuevoCliente;

            (*pId)++;

            retorno=1;
        }
    }
    return retorno;
}

int buscarLibre(eCliente lista[], int tam)
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

void inicializarClientes(eCliente lista[],int tam)
{
    for(int i=0;i<tam;i++)
    {
        lista[i].isEmpty=1;
    }
}

void mostrarCliente (eCliente unCliente)
{

        printf("       %d     %10s      %10s       %c     %21s      \n"
                    ,unCliente.codigo
                    ,unCliente.nombre
                    ,unCliente.apellido
                    ,unCliente.sexo
                    ,unCliente.telefono
                    );
}

void mostrarClientes(eCliente lista[],int tam)
{
    int flag=1;

    ordenarClientes(lista,tam);

    printf("\n --------------------------------------------------------------------------------------\n");
    printf("                                Lista de Clientes\n");
    printf("     Codigo       Nombre        Apellido      Sexo               Telefono");
    printf("\n --------------------------------------------------------------------------------------\n");

    for(int i=0;i<tam;i++)
    {
        if(!lista[i].isEmpty)
        {
        mostrarCliente(lista[i]);
        flag=0;
        }
    }
    if(flag)
    {
        printf("No hay Clientes en la lista");
    }

    printf("\n\n");

}

int buscarCliente(eCliente lista[],int tam, int codigo)
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

int bajaCliente(eCliente lista[], int tam)
{
    int retorno=0;
    int indice;
    int codigo;
    char confirma;

    system("cls");
    printf("        Baja Cliente\n");
    mostrarClientes(lista,tam);
    printf("Ingrese codigo: ");
    scanf("%d",&codigo);

    indice=buscarCliente(lista,tam,codigo);

    if(indice==-1)
    {
        printf("No existe un Cliente con el codigo: %d\n", codigo);
    }
    else
    {
        mostrarCliente(lista[indice]);
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

int modificarCliente(eCliente lista[], int tam)
{
    int retorno=0;
    int indice;
    int codigo;
    int opcion;
    char confirma;
    eCliente nuevoCliente;

    system("cls");
    printf("        Modificar Cliente\n");
    mostrarClientes(lista,tam);
    printf("Ingrese codigo: ");
    scanf("%d",&codigo);

    indice=buscarCliente(lista,tam,codigo);

    if(indice==-1)
    {
        printf("No existe un Cliente con el codigo: %d\n", codigo);
    }
    else
    {
        mostrarCliente(lista[indice]);
        printf("Confirma modificacion?: ");
        fflush(stdin);
        scanf("%c",&confirma);

        if(confirma=='s')
        {
            nuevoCliente.codigo=codigo;

            printf("        Opciones a modificar:\n");
            printf("1- Nombre\n");
            printf("2- Apellido\n");
            printf("3- Telefono\n");
            printf("Ingrese opcion: ");
            scanf("%d",&opcion);

            switch(opcion){

                case 1:
                    if(!utn_getName("Ingrese el nombre del cliente: ","Error. ",3,51,4,nuevoCliente.nombre))
                    {
                        printf("Error al cargar el nombre.\n");
                        return 0;
                    }
                    strcpy(lista[indice].nombre,nuevoCliente.nombre);
                    break;

                case 2:
                    if(!utn_getName("Ingrese el apellido del cliente: ","Error. ",3,51,4,nuevoCliente.apellido))
                    {
                        printf("Error al cargar el apellido.\n");
                        return 0;
                    }
                    strcpy(lista[indice].apellido,nuevoCliente.apellido);
                    break;

                case 3:
                    if(!utn_getTelefono("Ingrese telefono: ","Error. ",1,22,4,&nuevoCliente.telefono))
                    {
                        printf("Error al cargar el telefono.\n");
                        return 0;
                    }
                    strcpy(lista[indice].telefono,nuevoCliente.telefono);
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

int ordenarClientes (eCliente lista[],int tam)
{

    eCliente auxCliente;

    for(int i=0;i<tam-1;i++)
    {
        for(int j=i+1;j<tam;j++)
        {
            if(strcmp(lista[i].apellido,lista[j].apellido)>0 && strcmp(lista[i].nombre,lista[j].nombre)>0)
            {
                auxCliente=lista[i];
                lista[i]=lista[j];
                lista[j]=auxCliente;
            }
        }
    }

}
