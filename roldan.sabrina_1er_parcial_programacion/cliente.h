#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct{
    int codigo;
    char nombre[51];
    char apellido[51];
    char sexo;
    char telefono[21];
    int isEmpty;
}eCliente;

#endif // CLIENTE_H_INCLUDED

/** \brief                      Menú de opciones para el ABM de clientes.
 *
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int menu_clientes();

/** \brief                      Toma los datos ingresados por el usuario, al analizarlos y estos cumplir las condiciones
 *                              necesarias de una estructura Cliente lo retorna al espacio de memoria del puntero
 *                              para el alta en el sistema.
 *
 * \param lista[] eCliente     Array de Clientes.
 * \param tam int               Tamaño correspondiente al array Clientes.
 * \param pId int*              Puntero al espacio memoria donde se dejará el resultado de la función.
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int altaCliente(eCliente lista[], int tam, int* pId);

/** \brief                      Toma el id ingresado por el usuario, al analizarlo y encontrar el espacio ocupado
 *                              consulta para dar de baja al Cliente. Al confirma la baja inicializa el campo isEmpty a true.
 *
 * \param lista[] eCliente     Array de Clientes.
 * \param tam int               Tamaño correspondiente al array Clientes.
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int bajaCliente(eCliente lista[], int tam);

/** \brief                      Busca un Cliente al comparar con el id ingresado.
 *
 * \param lista[] eCliente      Array de Clientes.
 * \param tam int               Tamaño correspondiente al array Clientes.
 * \param codigo int            Entero ingresado a comparar.
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int buscarCliente(eCliente lista[],int tam, int codigo);

/** \brief                      Recorre el array y al encontrar el primer Cliente con el campo isEmpty en
 *                              true retorna el índice de este.
 *
 * \param lista[] eCliente     Array de Clientes.
 * \param tam int               Tamaño correspondiente al array Clientes.
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int buscarLibre(eCliente lista[], int tam);



/** \brief                      Recorre el array de Clientes en busca del leegajo ingresado por el usuario.
 *                              Se consulta el campo a modificar y al cumplir con las condiciones necesarias
 *                              se modifica el campo del Cliente con los datos ingresados.
 *
 * \param lista[] eCliente      Array de Clientes.
 * \param tam int               Tamaño correspondiente al array Clientes.
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int modificarCliente(eCliente lista[], int tam);


/** \brief                      Inicializa todos los Clientes con el campo isEmpty en true
 *
 * \param lista[] eCliente     Array de Clientes.
 * \param tam int               Tamaño correspondiente al array Clientes.
 * \return void                 No retorna ningún valor.
 *
 */
void inicializarClientes(eCliente lista[],int tam);

/** \brief                      Muestra la información de un Cliente.
 *
 * \param unCliente eCliente  Estructura de Cliente.
 * \return void                 No retorna ningún valor.
 *
 */
void mostrarCliente (eCliente unCliente);

/** \brief                      Recorre el array y muestra la información de todos los Clientes.
 *
 * \param lista[] eCliente     Array de Clientes.
 * \param tam int               Tamaño correspondiente al array Clientes.
 * \return void                 No retorna ningún valor.
 *
 */
void mostrarClientes(eCliente lista[],int tam);


//Prototipos de funciones general
/** \brief                      Menú de opciones para el ABM de Clientes.
 *
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int menu();


/** \brief                      Menú de opciones para ornedar Clientes por diferentes criterios.
 *
 * \param lista[] eCliente      Array de Clientes.
 * \param tam int               Tamaño correspondiente al array Clientes.
 * \return int                  Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int ordenarClientes(eCliente lista[], int tam);


