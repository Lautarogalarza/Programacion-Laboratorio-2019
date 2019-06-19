#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief crea un nuevo empleado con parametros vacios
 *
 * \return Employee* retorna el puntero al empleado
 *
 */
Employee* employee_new();
/** \brief crea un nuevo empleado con parametros
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return Employee* retorna el puntero al empleado
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
//void employee_delete();

/** \brief guarda el id en la estructura
 *
 * \param this Employee*
 * \param id int
 * \return int 1 si esta ok y 0 si hubo error
 *
 */
int employee_setId(Employee* this,int id);
/** \brief obtiene el id de la estructura
 *
 * \param this Employee*
 * \param id int*
 * \return int 1 si esta ok y 0 si hubo error
 *
 */
int employee_getId(Employee* this,int* id);

/** \brief guarda el nombre en la estructura
 *
 * \param this Employee*
 * \param nombre char*
 * \return int 1 si esta ok y 0 si hubo error
 *
 */
int employee_setNombre(Employee* this,char* nombre);
/** \brief obtiene el nombre de la estructura
 *
 * \param this Employee*
 * \param nombre char*
 * \return int 1 si esta ok y 0 si hubo error
 *
 */
int employee_getNombre(Employee* this,char* nombre);

/** \brief guarda las horas en la estructura
 *
 * \param this Employee*
 * \param horasTrabajadas int
 * \return int 1 si esta ok y 0 si hubo error
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
/** \brief obtiene las horas de la estructura
 *
 * \param this Employee*
 * \param horasTrabajadas int*
 * \return int 1 si esta ok y 0 si hubo error
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/** \brief guarda las horas en la estructura
 *
 * \param this Employee*
 * \param sueldo int
 * \return int 1 si esta ok y 0 si hubo error
 *
 */
int employee_setSueldo(Employee* this,int sueldo);
/** \brief obtiene el sueldo de la estructura
 *
 * \param this Employee*
 * \param sueldo int*
 * \return int 1 si esta ok y 0 si hubo error
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);

/** \brief modifica los campos del empleado
 *
 * \param this Employee*
 * \return void no retorna nada
 *
 */
void employee_setEmployee(Employee* this);
/** \brief compara que elemento es mayor y  menor y retorna el resultado
 *
 * \param personaA void*
 * \param personaB void*
 * \return int retorna la comparacion
 *
 */
int employee_compararPorSueldo(void* personaA, void* personaB);
/** \brief compara que elemento es mayor y  menor y retorna el resultado
 *
 * \param personaA void*
 * \param personaB void*
 * \return int retorna la comparacion
 *
 */
int employee_compararPorHoras(void* personaA, void* personaB);
/** \brief compara que elemento es mayor y  menor y retorna el resultado
 *
 * \param personaA void*
 * \param personaB void*
 * \return int retorna la comparacion
 *
 */
int employee_compararPorNombre(void* personaA, void* personaB);


#endif // employee_H_INCLUDED
