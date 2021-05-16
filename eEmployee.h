#ifndef EEMPLOYEE_H_INCLUDED
#define EEMPLOYEE_H_INCLUDED

#define TAMN 51
#define TRUE 1
#define FALSE 0

typedef struct{
    int id;
    char name[TAMN];
    char lastName[TAMN];
    float salary;
    int sector;
    int isEmpty;
}eEmployee;

int initEmp(eEmployee emp[], int len);
int option();
int freeIndex(eEmployee emp[], int len);
int chargeArray(char name[], char lastName[], float* salary, int* sector);
int addEmp(eEmployee emp[], int len, int* id, char name[], char lastName[], float salary, int sector, int index);
int findEmpById(eEmployee emp[], int len);
int modEmp(eEmployee emp[], int len);
int removeEmp(eEmployee emp[], int len);
int sortEmployees(eEmployee emp[], int len, int order);
int printEmployees(eEmployee emp[], int len);
int listEmployees(eEmployee emp[], int len);
int listBySalary(eEmployee emp[], int len);
#endif // EEMPLOYEE_H_INCLUDED
