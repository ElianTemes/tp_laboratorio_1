#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

int parser_EmployeeFromText(FILE* f , LinkedList* pArrayListEmployee){

    int Dread;
    char id[100], name[128], workedHours[100], salary[100];
    Employee* auxEmp;

    if(f == NULL){
        return EXIT_FAILURE;
    }

    fscanf(f,"%[^,],%[^,],%[^,],%[^\n]\n", id, name, workedHours, salary);

    do{

        Dread = fscanf(f,"%[^,],%[^,],%[^,],%[^\n]\n", id, name, workedHours, salary);

        if(Dread == 4){
            auxEmp = employee_newParam(id, name, workedHours, salary);
            if(auxEmp != NULL && pArrayListEmployee != NULL){
                ll_add(pArrayListEmployee, auxEmp);
            }
        }

        else{
            printf("Error loading data to a new node!");
            system("pause");
            return EXIT_FAILURE;
        }

    }while(!feof(f));

    return EXIT_SUCCESS;
}

int parser_EmployeeFromBinary(FILE* fb, LinkedList* pArrayListEmployee){

    int Dread;
    Employee* auxEmp;

    if(fb == NULL){
        return EXIT_FAILURE;
    }

    do{
        auxEmp = employee_new();
        Dread = fread(auxEmp, sizeof(Employee), 1, fb);
        if(Dread == 1){
            if(auxEmp != NULL){
                ll_add(pArrayListEmployee, auxEmp);
            }
            else{
                printf("Error loading data to a new node!\n");
                return EXIT_FAILURE;
            }
        }

    }while(!feof(fb));

    return EXIT_SUCCESS;
}

int parseName(char name[]) {

    const char *validChars = "abcdefghijklmnopqrstuvxyzABCDEFGHIJKLMNOPQRSTUVXYZ-' ";
    int i;

    for(i = 0; i < strlen(name); i++) {
        if(strchr(validChars, name[i]) == NULL ) {
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}

int parseSalaryAndHours(char salaryOrHours[]) {

    const char *validChars = "1234567890";
    int i;

    for(i = 0; i < strlen(salaryOrHours); i++) {
        if(strchr(validChars, salaryOrHours[i]) == NULL ) {
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}
