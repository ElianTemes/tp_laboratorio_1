/*
 * funcionMenu.c
 *
 *  Created on: Apr 4, 2021
 *      Author: Elian
 */

#include <stdio.h>
#include <stdlib.h>
#include "funcionMenu.h"

void menu (float* a, float* b){

    if(a != NULL && b != NULL){
        printf("////Bienvendio al menu de la calculadora////\n");
        printf("//// 1- Ingresar primer operando (A = %.2f) ////\n", *a);
        printf("//// 2- Ingresar segundo operando(B = %.2f) ////\n", *b);
        printf("//// 3- Calcular todas las operaciones ////\n");
        printf("\t a) Calcular la Suma %.2f + %.2f \n", *a, *b);
        printf("\t b) Calcular la Resta %.2f - %.2f \n", *a, *b);
        printf("\t c) Calcular la Division %.2f / %.2f \n", *a, *b);
        printf("\t d) Calcular la Multiplicacion %.2f * %.2f \n", *a, *b);
        printf("\t e) Calcular el factorial %.2f | %.2f \n", *a, *b);
        printf("//// 4- Informar resultados ////\n");
        printf("//// 5- Salir ////\n");
    }
}

void cls(){
    for(int i = 0; i < 40; i ++){
        printf("\n");
    }
}

