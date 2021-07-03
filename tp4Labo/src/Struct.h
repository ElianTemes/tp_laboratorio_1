#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED
#include "../inc/LinkedList.h"

typedef struct{
    int id;
    char name[128];
    int workedHours;
    int salary;
}Employee;

Employee* employee_new();
Employee* employee_newParam(char* idStr, char* nameStr, char* workedHoursStr, char* salary);

void employee_delete(Employee* this);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setName(Employee* this,char* name);
int employee_getName(Employee* this,char* name);

int employee_setWorkedHours(Employee* this,int workedHours);
int employee_getWorkedHours(Employee* this,int* workedHours);

int employee_setSalary(Employee* this,int salary);
int employee_getSalary(Employee* this,int* salary);

int employee_printOne(Employee* this);

int employee_sortById(void* firstEmp, void* nextEmp);
int employee_sortByName(void* firstEmp, void* nextEmp);
int employee_sortByWh(void* firstEmp, void* nextEmp);
int employee_sortBySalary(void* firstEmp, void* nextEmp);

int employee_ListEmployee(LinkedList* pArrayListEmployee);

#endif // STRUCT_H_INCLUDED
