/*
 * funcionMath.c
 *
 *  Created on: Apr 4, 2021
 *      Author: Elian
 */

#include "funcionMath.h"
#include <stdio.h>
#include <stdlib.h>


float funcionSum (float a, float b){
    float resultado;

    resultado = a + b;

    return resultado;
}

float funcionRes (float a, float b){
    int resultado;

    resultado = a - b;

    return resultado;
}

float funcionDiv (float a, float b, int* flag){

    float resultado = 1;

    if(b != 0){
       resultado = a / b;
    }
    else{
        *flag = 0;
    }

    return resultado;
}

float funcionMult (float a, float b){

    float resultado = 0;

    resultado = a * b;

    return resultado;
}

long long int funcionFact (float a){

    long long int resultado = 0;
    if(a == 0 || a == 1){
        resultado = 1;
    }
    else if(a > 0){
        for(int i = a - 1; i > 1; i--){
            a *= i;
        }
        resultado = a;
    }
    return resultado;
}

