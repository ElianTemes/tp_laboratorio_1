#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Struct.h"
#include "../inc/LinkedList.h"

Employee* employee_new(){
    Employee* pNewEmployee = (Employee*) malloc(sizeof(Employee));

    if(pNewEmployee != NULL){
        employee_setId(pNewEmployee, 0);
        employee_setName(pNewEmployee, "");
        employee_setWorkedHours(pNewEmployee, 0);
        employee_setSalary(pNewEmployee, 0);
        return pNewEmployee;
    }

    employee_delete(pNewEmployee);
    return NULL;
}

Employee* employee_newParam(char* idStr, char* nameStr, char* workedHoursStr, char* salaryStr){
    Employee* pNewEmployeeParam = employee_new();

    if(!employee_setId(pNewEmployeeParam, atoi(idStr)) && !employee_setName(pNewEmployeeParam, nameStr) &&
        !employee_setWorkedHours(pNewEmployeeParam, atoi(workedHoursStr)) && !employee_setSalary(pNewEmployeeParam, atoi(salaryStr))){
        return pNewEmployeeParam;
    }

    employee_delete(pNewEmployeeParam);
    return NULL;
}

void employee_delete(Employee* this){
    if(this != NULL){
        free(this);
    }
}

int employee_setId(Employee* this,int id){
    if(this != NULL && id >= 0){
        this -> id = id;
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}

int employee_getId(Employee* this, int* id){
    if(this != NULL && id != NULL){
        *id = this -> id;
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}

int employee_setName(Employee* this, char* name){
    if(this != NULL && name != NULL){
        strcpy(this -> name, name);
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}

int employee_getName(Employee* this, char* name){
    if(this != NULL && name != NULL){
        strcpy(name, this -> name);
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}

int employee_setWorkedHours(Employee* this, int workedHours){
    if(this != NULL && workedHours >= 0){
        this -> workedHours = workedHours;
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}

int employee_getWorkedHours(Employee* this, int* workedHours){
    if(this != NULL && workedHours != NULL){
        *workedHours = this -> workedHours;
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}

int employee_setSalary(Employee* this, int salary){
    if(this != NULL && salary >= 0){
        this -> salary = salary;
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}

int employee_getSalary(Employee* this, int* salary){
    if(this != NULL && salary != NULL){
        *salary = this -> salary;
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}

int employee_printOne(Employee* this){
    int id;
    int workedHours;
    int salary;
    char name[128];
    if(this != NULL){
        if(!employee_getId(this, &id) && !employee_getName(this, name) && !employee_getWorkedHours(this, &workedHours) &&
           !employee_getSalary(this, &salary)){
            printf("    %4d    %18s            %3d              %10d \n",
            id, name, workedHours, salary);
            return EXIT_SUCCESS;
        }
    }
    return EXIT_FAILURE;
}

int employee_sortById(void* firstEmp, void* nextEmp){
    int sortRet;
    if(((Employee*)firstEmp)->id > ((Employee*)nextEmp)->id){
        sortRet = 1;
    }
    if(((Employee*)firstEmp)->id < ((Employee*)nextEmp)->id){
        sortRet = -1;
    }
    else{
        sortRet = 0;
    }

    return sortRet;
}

int employee_sortByName(void* firstEmp, void* nextEmp){
    //int sortRet;
    //sortRet = strcmp(((Employee*)firstEmp)->name, ((Employee*)nextEmp)->name);
    return strcmp(((Employee*)firstEmp)->name, ((Employee*)nextEmp)->name);
}

int employee_sortByWh(void* firstEmp, void* nextEmp){
    int sortRet;

    if(((Employee*)firstEmp)->workedHours > ((Employee*)nextEmp)->workedHours){
        sortRet = 1;
    }
    else if(((Employee*)firstEmp)->workedHours < ((Employee*)nextEmp)->workedHours){
        sortRet = -1;
    }
    else{
        sortRet = 0;
    }
    return sortRet;
}

int employee_sortBySalary(void* firstEmp, void* nextEmp){
    int sortRet;
    if(((Employee*)firstEmp)->salary > ((Employee*)nextEmp)->salary){
        sortRet = 1;
    }
    else if(((Employee*)firstEmp)->salary < ((Employee*)nextEmp)->salary){
        sortRet = -1;
    }
    else{
        sortRet = 0;
    }
    return sortRet;
}

int employee_ListEmployee(LinkedList* pArrayListEmployee){
    int position;
    int len = ll_len(pArrayListEmployee);
    Employee* auxEmp = NULL;
    if(pArrayListEmployee != NULL) {
        printf("////   ID\t         NAME\t     WORKED HOURS\t        SALARY\t////\n");
        for(position = 0; position < len; position++){
            auxEmp = (Employee*)ll_get(pArrayListEmployee, position);
            if(auxEmp != NULL){
                if(employee_printOne(auxEmp)){
                    printf("Error printing\n");
                }
            }
        }
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}
