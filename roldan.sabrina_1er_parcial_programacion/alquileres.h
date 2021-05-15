#include "fecha.h"

#ifndef ALQUILERES_H_INCLUDED
#define ALQUILERES_H_INCLUDED

typedef struct{
    int codigo;
    int idJuego;
    int idCliente;
    eFecha fecha;
    int isEmpty;
}eAlquileres;

#endif // ALQUILERES_H_INCLUDED

/** \brief                      Menú de opciones para el ABM de Alquileres.
 *
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int menu_Alquileres();

/** \brief                      Toma los datos ingresados por el usuario, al analizarlos y estos cumplir las condiciones
 *                              necesarias de una estructura Alquileres lo retorna al espacio de memoria del puntero
 *                              para el alta en el sistema.
 *
 * \param lista[] eAlquileres     Array de Alquileres.
 * \param tam int               Tamaño correspondiente al array Alquileres.
 * \param pId int*              Puntero al espacio memoria donde se dejará el resultado de la función.
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int altaAlquileres(eAlquileres lista[], int tam, int* pId);

/** \brief                      Toma el id ingresado por el usuario, al analizarlo y encontrar el espacio ocupado
 *                              consulta para dar de baja al Alquileres. Al confirma la baja inicializa el campo isEmpty a true.
 *
 * \param lista[] eAlquileres     Array de Alquileres.
 * \param tam int               Tamaño correspondiente al array Alquileres.
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int bajaAlquileres(eAlquileres lista[], int tam);

/** \brief                      Busca un Alquileres al comparar con el id ingresado.
 *
 * \param lista[] eAlquileres      Array de Alquileres.
 * \param tam int               Tamaño correspondiente al array Alquileres.
 * \param codigo int            Entero ingresado a comparar.
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int buscarAlquileres(eAlquileres lista[],int tam, int codigo);

/** \brief                      Recorre el array y al encontrar el primer Alquileres con el campo isEmpty en
 *                              true retorna el índice de este.
 *
 * \param lista[] eAlquileres     Array de Alquileres.
 * \param tam int               Tamaño correspondiente al array Alquileres.
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int buscarLibre_alquiler(eAlquileres lista[], int tam);



/** \brief                      Recorre el array de Alquileres en busca del leegajo ingresado por el usuario.
 *                              Se consulta el campo a modificar y al cumplir con las condiciones necesarias
 *                              se modifica el campo del Alquileres con los datos ingresados.
 *
 * \param lista[] eAlquileres      Array de Alquileres.
 * \param tam int               Tamaño correspondiente al array Alquileres.
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int modificarAlquileres(eAlquileres lista[], int tam);


/** \brief                      Inicializa todos los Alquileres con el campo isEmpty en true
 *
 * \param lista[] eAlquileres     Array de Alquileres.
 * \param tam int               Tamaño correspondiente al array Alquileres.
 * \return void                 No retorna ningún valor.
 *
 */
void inicializarAlquileres(eAlquileres lista[],int tam);

/** \brief                      Muestra la información de un Alquileres.
 *
 * \param unAlquileres eAlquileres  Estructura de Alquileres.
 * \return void                 No retorna ningún valor.
 *
 */
void mostrarAlquiler (eAlquileres unAlquileres);

/** \brief                      Recorre el array y muestra la información de todos los Alquileres.
 *
 * \param lista[] eAlquileres     Array de Alquileres.
 * \param tam int               Tamaño correspondiente al array Alquileres.
 * \return void                 No retorna ningún valor.
 *
 */
void mostrarAlquileres(eAlquileres lista[],int tam);


//Prototipos de funciones general
/** \brief                      Menú de opciones para el ABM de Alquileres.
 *
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int menu();


/** \brief                      Menú de opciones para ornedar Alquileres por diferentes criterios.
 *
 * \param lista[] eAlquileres      Array de Alquileres.
 * \param tam int               Tamaño correspondiente al array Alquileres.
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int ordenarAlquileres(eAlquileres lista[], int tam);
