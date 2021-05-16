#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int myGets(char* cadena, int longitud){

if(cadena != NULL && longitud >0 && fgets(cadena,longitud,stdin)==cadena){
    fflush(stdin);
    if(cadena[strlen(cadena)-1] == '\n'){
        cadena[strcspn(cadena, "\n")] = '\0';
    }
    return 0;
}
return -1;
}

int getInt(int* pResultado){
char buffer[64];
if(pResultado != NULL){
    fflush(stdin);
    if(myGets(buffer,sizeof(buffer))==0 && esNumerica(buffer)){
        *pResultado = atoi(buffer);
        return 0;
    }
}
    return -1;
}

int esNumerica(char* cadena){

int posicion=0;

if(cadena != NULL && strlen(cadena) > 0){
    while(cadena[posicion] != '\0'){
        if(cadena[posicion] < '0' || cadena[posicion] > '9' ){
            return 0;
        }
        posicion++;
    }
}
return -1;
}

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int
maximo, int reintentos){

int bufferInt;

while(reintentos>0){
    reintentos--;
    printf("%s",mensaje);
        if(getInt(&bufferInt) == 0){
            if(bufferInt >= minimo && bufferInt <= maximo){
                *pResultado = bufferInt;
                return 0;
            }
        }
    printf("%s",mensajeError);
}
return -1;
}

char continuE(){
    char keepGoing;
    printf("Do you want to continue? y/n");
    scanf(" %c", &keepGoing);
    if(keepGoing != 'y' && keepGoing != 'n' ){
        printf("Wrong input! y/n");
        scanf(" %c", &keepGoing);
    }
    return keepGoing;
}
