/*
 * main.c
 *
 *  Created on: Apr 4, 2021
 *      Author: Elian
 */

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "funcionMath.h"
#include "funcionMenu.h"

int main (){

    float a = 0;
    float b = 0;
    int flagFin = 1;
    int flagNum2 = 1;
    int flagNum1 = 1;
    int flagDiv = 1;
    int flagFac[] = {1, 1};
    int flagCalculo = 1;
    int opcion = 0;
    float resultado[] = {0, 0, 0, 0};
    long long int resultadoF[] = {0, 0};

    setbuf(stdout, NULL);

    do{
        cls();
        menu(&a, &b);

        printf("\nElija su opcion: ");
        scanf(" %d", &opcion);

        switch(opcion){

            case 1:
                if(flagNum1 == 1){
                	printf("\nIngrese primer operando: ");
                	scanf("%f", &a);
                	flagNum1 = 0;
                }
                else{
                	printf("\n///Error, ya ingreso el primer operando///\n\n");
                	system("PAUSE");
                	printf("\n");
                }

            break;

            case 2:
                if(flagNum1 == 0 && flagNum2 == 1){
                    printf("\nIngrese segundo operando: ");
                    scanf("%f", &b);
                    flagNum2 = 0;
                }
                else if(flagNum2 == 0){
                    printf("\n///Error, ya ingreso el segundo operando///\n\n");
                    system("PAUSE");
                    printf("\n");
                }
                else{
                    printf("\n///Error, aun no ingreso el primer operando///\n\n");
                    system("PAUSE");
                }
            break;

            case 3:

                if(flagNum1 == 0 && flagNum2 == 0 && flagCalculo == 1){

                    printf("\nCalculando...\n\n");
                    resultado[0] = funcionSum(a, b);
                    resultado[1] = funcionRes(a, b);

                    if(flagDiv != 0){
                        resultado[2] = funcionDiv(a, b, &flagDiv);
                    }

                    resultado[3] = funcionMult(a, b);

                    if(funcionFact(a) > 0){
                        resultadoF[0] = funcionFact(a);
                    }

                    else{
                        flagFac[0] = 0;
                    }

                    if(funcionFact(b) > 0){
                        resultadoF[1] = funcionFact(b);
                    }

                    else{
                        flagFac[1] = 0;
                    }

                flagCalculo = 0;
                system("PAUSE");
                }

                else if (flagCalculo == 0){
                    printf("\n///Error, ya se calcularon los resultados///\n\n");
                    system("PAUSE");
                }

                else{
                    printf("\n///Error, aun no ingreso todos los operandos///\n\n");
                    system("PAUSE");
                }

            break;

            case 4:
            	if(flagNum1 == 0 && flagNum2 == 0 && flagCalculo == 0 ){
            		printf("\nResultado de la suma: %.2f\n", resultado[0]);
            		printf("Resultado de la resta: %.2f\n", resultado[1]);
            		if(flagDiv == 0){
            			printf("///Error no se puede dividir por 0///1\n");
            		}
            		else{
            			printf("Resultado de la division: %.2f\n", resultado[2]);
            		}
            		printf("Resultado de la multiplicacion: %.2f\n", resultado[3]);
            		if(flagFac[0] == 0){
            			printf("///Error variable desbordada/factorial de numero negativo///\n");
            		}
            		else{
            			printf("Factorial de A: %I64u\n", resultadoF[0]);
            		}
            		if(flagFac[1] == 0){
            			printf("///Error variable desbordada/factorial de numero negativo///\n");
            		}
            		else{
            			printf("Factorial de B: %I64u\n", resultadoF[1]);
            		}
            	}
            	else{
            		printf("\n///Error faltan opciones anteriores///\n\n");
            	}
            	system("PAUSE");
            break;

            case 5:
                printf("\n\nFin del programa\n\n");
                flagFin = 0;
                system("PAUSE");
            break;
        }
    }while (flagFin == 1);

    return 0;
}
