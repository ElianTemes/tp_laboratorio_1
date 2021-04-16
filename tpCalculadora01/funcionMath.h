/*
 * funcionMath.h
 *
 *  Created on: Apr 4, 2021
 *      Author: Elian
 */

#ifndef FUNCIONMATH_H_
#define FUNCIONMATH_H_



#endif /* FUNCIONMATH_H_ */

/**
 * @brief Funcion para calcular la suma de dos operandos
 *
 * @param a Operando n1
 * @param b Operando n2
 * @return Retora el resultado de la suma
 */
float funcionSum (float a, float b);

/**
 * @brief Funcion para calcular la suma de dos operandos
 *
 * @param a Operando n1
 * @param b Operando n2
 * @return Retorna el resultado de la resta
 */
float funcionRes(float a, float b);

/**
 * @brief Funcion para calcular la division de dos operandos teniendo en cuenta la division por cero
 *
 * @param a Operando n1
 * @param b Operando n2
 * @return Evalua si el operando n2 es distinto de cero, en ese caso retorna el resultado de la division, si no, retorna 0
 */
float funcionDiv(float a, float b, int* flag);

/**
 * @brief Funcion para calcular la multiplicacion de dos operandos
 *
 * @param a Operando n1
 * @param b Operando n2
 * @return Retorna el resultado de la multiplicacion
 */
float funcionMult (float a, float b);

/**
 * @brief Funcion para calcular el factorial de un operando
 *
 * @param a Recibe un operando
 * @return Retorna el resultado de la operacion teniendo en cuenta el caso en que el operando sea 0
 */
long long int funcionFact (float a);
