#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eEmployee.h"
#include "funciones.h"

#define TAM 1000
#define TAMN 51

int main(){

    eEmployee emp[TAM];
    char name[TAMN];
    char lastName[TAMN];
    float salary;
    int sector;
    int id = 1000;
    int flag = 1;
    int order;
    if(initEmp(emp, TAM) == -1){
        printf("Error initializing array!");
    }
    else{
        initEmp(emp, TAM);
    }
    int opt;
    char keepG = 'y';
    int index;
    do{
        printf("1- Add employee \n");
        printf("2- Modify employee by ID \n");
        printf("3- Remove employee by ID \n");
        printf("4- List of employees sorted by last name and sector \n");
        printf("5- List of total and average salary of each employee and how many employees surprasses the average \n");
        printf("6- Exit \n");

        printf("\nChoose an option: ");
        scanf("%d", &opt);
        system("cls");
        switch(opt){
        case 1:
           index = freeIndex(emp, TAM);
           chargeArray(name, lastName, &salary, &sector);
           addEmp(emp, TAM, &id, name, lastName, salary, sector, index);
           flag = 0;
           system("pause");
           system("cls");
        break;

        case 2:
            if(flag == 0){
                modEmp(emp, TAM);
            }
            else{
                printf("Error! first you need to add at least one employee.");
            }
            system("pause");
            system("cls");
        break;

        case 3:
            if(flag == 0){
                removeEmp(emp, TAM);
            }
            else{
                printf("Error! first you need to add at least one employee.");
            }
            system("pause");
            system("cls");
        break;

        case 4:
            if(flag == 0){
                printf("1) from highest to lowest: \n 2) from lowest to highest: ");
                getInt(&order);
                sortEmployees(emp, TAM, order);
                listEmployees(emp, TAM);
            }
            else{
                printf("Error! first you need to add at least one employee.");
            }
            system("pause");
            system("cls");
        break;

        case 5:
            if(flag == 0){
                listBySalary(emp, TAM);
            }
            else{
                printf("Error! first you need to add at least one employee.");
            }
            system("pause");
            system("cls");
        break;

        case 6:
            keepG = continuE();
            system("cls");
        break;
        }
    }while(keepG == 'y');
    return 0;
}
