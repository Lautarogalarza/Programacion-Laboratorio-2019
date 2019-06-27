#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

/** \brief funcion encargada de pedir un numero y guardarlo
 *
 * \param float* variable en la que se van a tomar los operandos mediante referencias
 * \return void La funcion no devuelve nada
 *
 */
void askNumber( float*  );

/** \brief Funcion encargada de realizar la Addition de los operandos recibidos
 *
 * \param float Recibe el primer operando
 * \param float Recibe el segundo operando
 * \return float Retorna la Addition entre numA y numB
 *
 */
float Addition( float  , float  );

/** \brief Funcion encargada de realizar la Substraction de los operandos recibidos
 *
 * \param float Recibe el primer operando
 * \param float Recibe el segundo operando
 * \return float Retorna la Substraction entre numA y numB
 *
 */
float Substraction( float  , float );

/** \brief Funcion encargada de realizar la multiplication de los operandos recibidos
 *
 * \param float Recibe el primer operando
 * \param float Recibe el segundo operando
 * \return float Retorna la multiplication entre numA y numB
 *
 */
float multiplication( float  , float );

/** \brief Funcion encargada de realizar la division de los operandos recibidos
 *
 * \param float Recibe el primer operando
 * \param float Recibe el segundo operando
 * \return float Retorna la division entre numA y numB
 *
 */
float division( float  , float );

/** \brief Funcion encargada de calcular el factorial de los dos operandos
 *
 * \param float Recibe el operando con el cual el factorial sera calculado
 * \return int Retorna el factorial del operando ingresado
 *
 */
int factorial(float);


#endif // FUNCTION_H_INCLUDED
