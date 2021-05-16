#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eEmployee.h"
#include "funciones.h"

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param array Employee
 * \param len int Array length
 * \return (-1) if Error [Invalid length or NULL pointer] or (0) if ok
 */
int initEmp(eEmployee emp[], int len){  // retorna 0 si funciono, -1 si hubo algun problema
    int position;
    if(emp != NULL && len > 0){
        for(position = 0; position < len; position++){
            emp[position].isEmpty = TRUE;
        }
        return 0;
    }
    return -1;
}

/** \brief Gets the user option (1/2/3/4) and validates it
 * \return int opt
 */
int option(){
    int opt = 0;
    int flag = 1;
    if(opt == 1 || opt == 2 || opt == 3 || opt == 4){
            flag = 0;
    }
    printf("1) Modify employee name\n");
    printf("2) Modify employee last name\n");
    printf("3) Modify employee salary\n");
    printf("4) Modify employee sector\n");
    getInt(&opt);
    while(opt != 1 && opt != 2 && opt != 3 && opt != 4 && flag == 1){
        printf("Wrong option, try again!\n");
        opt = option();
    }
    return opt;
}

/** \brief Iterates with a for loop through the array seeking for the first free index
 *
 * \param  array emp
 * \param  int len
 * \return the first free index in the array or -1 if failed
 */
int freeIndex(eEmployee emp[], int len){ // retorna el indice de la primer posicion libre del array si funciono, -1 si hubo algun problema
    int position;
    if(emp != NULL && len > 0){
        for(position = 0; position < len; position++){
            if(emp[position].isEmpty == TRUE){
                return position;
            }
        }
    }
    return -1;
}

/** \brief
 * \param
 * \param
 * \return
 */
int chargeArray(char name[], char lastName[], float* salary, int* sector){
    if(name != NULL && lastName != NULL){
        fflush(stdin);
        printf("Enter the employee name: ");
        myGets(name, TAMN);
        printf("Enter the employee last name: ");
        myGets(lastName, TAMN);
        printf("Enter the employee salary: ");
        scanf("%f", salary);
        fflush(stdin);
        printf("Enter the employee sector: ");
        getInt(sector);
        return 0;
    }
    return -1;
}

/** \brief Add in an existing array of employees the values received as parameters
 * in the first empty position
 * \param array employee
 * \param int len
 * \param int *id
 * \param char name[]
 * \param char lastName[]
 * \param float salary
 * \param int sector
 * \return (-1) if Error [Invalid length or NULL pointer or without
 *  free space] or (0) if ok
 */
int addEmp(eEmployee emp[], int len, int* id, char name[], char lastName[], float salary, int sector, int index){
    if(emp != NULL && len > 0 && index != -1){
        strcpy(emp[index].name, name);
        strcpy(emp[index].lastName, lastName);
        emp[index].salary = salary;
        emp[index].sector = sector;
        emp[index].isEmpty = FALSE;
        emp[index].id = (*id)++;
        return 0;
    }
    return -1;
}

/** \brief Find an Employee by Id en returns the index position in array.
 *
 * \param array Employee
 * \param len int
 * \param id int
 * \return employee index position or (-1) if [Invalid length or NULL
 *  pointer received or employee not found]
 */
int findEmpById(eEmployee emp[], int len){
    if(emp != NULL && len > 0){
        int position;
        int id;
        printf("Enter the ID of the employee: ");
        getInt(&id);
        for(position = 0; position < len; position++){
            if(emp[position].id == id){
                return position;
            }
        }
    }
    return -1;
}

/** \brief Modify an employee name || last name || salary || sector by ID
 *
 * \param   array emp
 * \param   int emp
 * \param   int id
 * \return (0) if it's all ok or (-1) if fails
 */
int modEmp(eEmployee emp[], int len){
    int index = findEmpById(emp, len);
    if(emp != NULL && len > 0 && emp[index].isEmpty == FALSE){
        int opt = option();
        switch(opt){

        case 1:
            myGets(emp[index].name, TAMN);
        break;

        case 2:
            myGets(emp[index].lastName, TAMN);
        break;

        case 3:
            scanf("%f", &emp[index].salary);
        break;

        case 4:
            getInt(&emp[index].sector);
        break;

        return 0;
        }
    }
    return -1;
}

/** \brief  Removes an employee by ID setting isEmpty to TRUE
 * \param   array emp
 * \param   int len
 * \param   int id
 * \return 0 if ok or -1 if fails
 */
int removeEmp(eEmployee emp[], int len){
    int index = findEmpById(emp, len);
    if(emp != NULL && len > 0 && emp[index].isEmpty == FALSE){
        emp[index].isEmpty = TRUE;
        return 0;
    }
    return -1;
}

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int sortEmployees(eEmployee emp[], int len, int order){
    if(emp != NULL && len > 0){
        eEmployee auxEmp;
        int firstCmp;
        int nextCmp;
        if(order != 1 && order != 2){
            printf("Error, wrong input! try again...\n");
            printf("1) from highest to lowest: \n 2) from lowest to highest: ");
            getInt(&order);
        }
        if(order == 1){
            for(firstCmp = 0; firstCmp < len - 1; firstCmp++){

                for(nextCmp = firstCmp + 1; nextCmp < len; nextCmp++){
                    if((strcmp(emp[firstCmp].lastName, emp[nextCmp].lastName) < 0) && (emp[firstCmp].isEmpty == FALSE && emp[nextCmp].isEmpty == FALSE || (strcmp(emp[firstCmp].lastName, emp[nextCmp].lastName) == 0) && (emp[firstCmp].sector < emp[nextCmp].sector))){
                        auxEmp = emp[firstCmp];
                        emp[firstCmp] = emp[nextCmp];
                        emp[nextCmp] = auxEmp;
                    }
                }
            }
        }
        if(order == 2){
            for(firstCmp = 0; firstCmp < len - 1; firstCmp++){

                for(nextCmp = firstCmp + 1; nextCmp < len; nextCmp++){
                    if((strcmp(emp[firstCmp].lastName, emp[nextCmp].lastName) > 0 && emp[firstCmp].isEmpty == FALSE && emp[nextCmp].isEmpty == FALSE) || (strcmp(emp[firstCmp].lastName, emp[nextCmp].lastName) == 0 && emp[firstCmp].sector < emp[nextCmp].sector)){
                        auxEmp = emp[firstCmp];
                        emp[firstCmp] = emp[nextCmp];
                        emp[nextCmp] = auxEmp;
                    }
                }
            }
        }
    return 0;
    }
    return -1;
}

/** \brief print the content of employees array
 * \param array emp
 * \param int len
 * \return 0 if succes or -1 if error
 */
int listEmployees(eEmployee emp[], int len){
    int position;
    char fullname[101];
    if(emp != NULL && len > 0) {
        printf("////ID\t FULLNAME\t SALARY\t SECTOR\t////");
        for(position = 0; position < len; position++){
            if(emp[position].isEmpty == FALSE){
                fullname[0] = '\0';
                strcat(fullname, emp[position].name);
                strcat(fullname, " " );
                strcat(fullname, emp[position].lastName);
                printf("\n%5d    %s       %.2f   %d\n",
                emp[position].id, fullname, emp[position].salary, emp[position].sector);
            }
        }
        return 0;
    }
    return -1;
}

/** \brief print a list of employees salaries
 * \param eEmployee emp
 * \param int len
 * \return 0 if ok or -1 if error
 */
int listBySalary(eEmployee emp[], int len){
    int position;
    float salaryAcum = 0.0;
    int salaryCount = 0;
    float average = 0.0;
    int moreThanAverage = 0;

    if(emp != NULL && len > 0){
        for(position = 0; position < len; position++){
            if(emp[position].isEmpty == FALSE){
                salaryAcum += emp[position].salary;
                salaryCount++;
            }
        }
        printf("Total salary of all employees: %.2f\n", salaryAcum);
        average = salaryAcum / salaryCount;
        printf("Average salary: %.2f\n", average);
        for(position = 0; position < len; position++){
            if(emp[position].isEmpty == FALSE && emp[position].salary > average){
                moreThanAverage++;
            }
        }
        printf("Employees with salaries exceeding the average: %d\n", moreThanAverage);
        return 0;
    }
    return -1;
}
