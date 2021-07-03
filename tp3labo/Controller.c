#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

int controller_freeAll(LinkedList* pArrayListEmployee){
    int auxLinkedError;
    if(pArrayListEmployee != NULL){
        auxLinkedError = ll_deleteLinkedList(pArrayListEmployee);
        if(auxLinkedError == 0 && auxLinkedError == -1){
            printf("Deleting the list has failed!\n");
            return EXIT_FAILURE;
        }
    }
    printf("Memory deallocated succesfully!\n");
    return EXIT_SUCCESS;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee){
    FILE* f = fopen(path, "r");
    int aux = 0;

    if(f == NULL){
        printf("Could not open file %s\n", path);
        return EXIT_FAILURE;
    }
    if(pArrayListEmployee != NULL){
        aux = parser_EmployeeFromText(f, pArrayListEmployee);
    }
    if(aux == EXIT_FAILURE){
        printf("Parser failed!\n");
        fclose(f);
        return EXIT_FAILURE;
    }
    fclose(f);
    printf("Load completed!\n");
    return EXIT_SUCCESS;
}

/** \brief Carga los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* pathBin , LinkedList* pArrayListEmployee){

    FILE* fb = fopen(pathBin, "rb");
    int aux;
    if(fb == NULL){
        printf("Could not open file %s\n", pathBin);
        return EXIT_FAILURE;
    }

    aux = parser_EmployeeFromBinary(fb, pArrayListEmployee);

    if(aux == EXIT_FAILURE){
        printf("Parser failed!\n");
        return EXIT_FAILURE;
    }

    fclose(fb);
    printf("Load completed!\n");
    return EXIT_SUCCESS;
}

int controller_getLastId(LinkedList* pArrayListEmployee){
    int index = 0, id, maxId = 0, len;
    Employee* auxEmp;

    if(pArrayListEmployee == NULL){
        return EXIT_FAILURE;
    }
    len = ll_len(pArrayListEmployee);
    do{
        auxEmp = (Employee*) ll_get(pArrayListEmployee, index);
        if(employee_getId(auxEmp, &id)){
            return EXIT_FAILURE;
        }
        if(maxId < id){
            maxId = id;
        }
        index++;
    }while(index < len);

    return maxId + 1;
}


/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee){
    Employee* auxEmp = NULL;
    int id, controlScanf;
    char name[128], auxId[10], workedHours[5], salary[10];

    id = controller_getLastId(pArrayListEmployee);
    itoa(id, auxId, 10);

    printf("\nEnter the name of the new employee: ");
    fflush(stdin);
    fgets(name, 128, stdin);
    name[strcspn(name, "\n")] = '\0';

    if(parseName(name) != EXIT_SUCCESS){
        printf("\nEnter a valid name: ");
        fgets(name, 128, stdin);
        name[strcspn(name, "\n")] = '\0';
    }

    printf("\nEnter the hours worked: ");
    controlScanf = scanf(" %s", workedHours);
    while(controlScanf != 1 || parseSalaryAndHours(workedHours) != EXIT_SUCCESS){
        printf("\nError, enter a valid hour: ");
        controlScanf = scanf(" %s", workedHours);
    }
    printf("\n");

    printf("\nEnter the salary: ");
    controlScanf = scanf(" %s", salary);
    while(controlScanf != 1 || parseSalaryAndHours(salary) != EXIT_SUCCESS){
        printf("\nError, enter a valid salary: ");
        controlScanf = scanf(" %s", salary);
    }
    printf("\n");

    if(auxEmp == NULL && pArrayListEmployee != NULL){
        auxEmp = employee_newParam(auxId, name, workedHours, salary);
        ll_add(pArrayListEmployee, auxEmp);
    }
    return EXIT_SUCCESS;
}

/** \brief Modificar datos de empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee){
    int id, workedHours, salary, option;
    char name[128];
    Employee* auxEmp = NULL;

    printf("\nEnter the ID of the employee that you want to modify: ");
    while(scanf("%d", &id) != 1 || id < 1){
        printf("\nError, enter a valid ID: ");
        scanf("%d", &id);
    }
    auxEmp = employee_getById(pArrayListEmployee, id);

    if(auxEmp != NULL){
        do{
            printf("\nMenu:"
            "\n1. Change name."
            "\n2. Change worked hours."
            "\n3. Change salary."
            "\n4. Exit.");
            printf("\nChoose an option: ");
            while(scanf("%d", &option) != 1 || option < 1 || option > 4){
                printf("\nError, enter a valid option: ");
                scanf("%d", &option);
            }
            switch(option){
                case 1:
                    system("cls");
                    printf("\nEnter the new name: ");
                    fflush(stdin);
                    fgets(name, 128, stdin);
                    name[strcspn(name, "\n")] = '\0';

                    if(parseName(name) != EXIT_SUCCESS){
                        printf("\nError, enter a valid name: ");
                        fgets(name, 128, stdin);
                        name[strcspn(name, "\n")] = '\0';
                    }
                    employee_setName(auxEmp, name);
                    printf("\nName succesfully edited!\n");
                    system("pause");
                break;

                case 2:
                    system("cls");
                    printf("\nEnter the new worked hours: ");
                    while(scanf("%d", &workedHours) != 1 || workedHours < 1){
                        printf("\nError, enter a valid hour: ");
                        scanf("%d", &workedHours);
                    }
                    employee_setWorkedHours(auxEmp, workedHours);
                    printf("\nWorked hours succesfully edited!\n");
                    system("pause");
                break;

                case 3:
                    system("cls");
                    printf("\nEnter the new salary: ");
                    while(scanf("%d", &salary) != 1 || salary < 1){
                        printf("\nError, enter a valid salary: ");
                        scanf("%d", &salary);
                    }
                    employee_setSalary(auxEmp, salary);
                    printf("\nSalary succesfully edited!\n");
                    system("pause");
                break;

                case 4:
                    system("cls");
                    printf("\nExiting...\n");
                    system("pause");
                break;
            }
        }while(option != 4);
    }
    return EXIT_SUCCESS;
}

/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee){
    Employee* auxEmp = NULL;
    int id;

    printf("\nEnter the ID of the employee that you want to delete: ");
    while(scanf("%d", &id) != 1 || id < 1){
        printf("\nError, enter a valid ID: ");
        scanf("%d", &id);
    }
    auxEmp = employee_getById(pArrayListEmployee, id);

    if(auxEmp != NULL){
        ll_remove(pArrayListEmployee, ll_indexOf(pArrayListEmployee, auxEmp));
        employee_delete(auxEmp);
        printf("\nEmployee succesfully deleted!\n");
        system("pause");
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}

/** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee){
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

/** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee){
    int option;
    printf("\nMenu:"
            "\n1. Sort by id."
            "\n2. Sort by name."
            "\n3. Sort by worked hours."
            "\n4. Sort by salary."
            "\n5. Exit.");
    printf("\nChoose an option: ");
    while(scanf("%d", &option) != 1 || option < 1 || option > 4){
        printf("\nError, enter a valid option: ");
        scanf("%d", &option);
    }
    if(pArrayListEmployee != NULL){
        switch(option){
            case 1:
                ll_sort(pArrayListEmployee, employee_sortById, 1);
                controller_ListEmployee(pArrayListEmployee);
            break;

            case 2:
                ll_sort(pArrayListEmployee, employee_sortByName, 1);
                controller_ListEmployee(pArrayListEmployee);
            break;

            case 3:
                ll_sort(pArrayListEmployee, employee_sortByWh, 1);
                controller_ListEmployee(pArrayListEmployee);
            break;

            case 4:
                ll_sort(pArrayListEmployee, employee_sortBySalary, 1);
                controller_ListEmployee(pArrayListEmployee);
            break;

            case 5:
                system("cls");
                printf("\nExiting...\n");
                system("pause");
            break;
        }
    }

    return EXIT_SUCCESS;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee){
    FILE* f = fopen (path, "w");
    Employee* auxEmp = NULL;
    int len = ll_len(pArrayListEmployee);
    int id, workedHours, salary, index = 0;
    char name[128];
    if(f != NULL){
        fprintf(f, "id,name,worked hours,salary\n");
        while(index < len){
            auxEmp = (Employee*) ll_get(pArrayListEmployee, index);
            employee_getId(auxEmp, &id);
            employee_getName(auxEmp, name);
            employee_getWorkedHours(auxEmp, &workedHours);
            employee_getSalary(auxEmp, &salary);
            if(auxEmp != NULL){
                if(fprintf(f, "%d ,%s ,%d ,%d\n", id, name, workedHours, salary) < 0){
                    printf("Error!");
                    system("pause");
                    return EXIT_FAILURE;
                }
                index++;
            }
        }
        fclose (f);
    }
    printf("The file was succesfully saved as text!\n");
    system("pause");

    return EXIT_SUCCESS;
}

/** \brief Guarda los datos de los empleados en el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* pathBin , LinkedList* pArrayListEmployee){
    FILE* fb = fopen (pathBin, "wb");
    Employee* auxEmp = NULL;
    int index = 0;

    if(fb != NULL){
        do{
            auxEmp = (Employee*) ll_get(pArrayListEmployee, index);
            if(auxEmp != NULL){
                if(fwrite(auxEmp, sizeof(Employee), 1, fb) != 1){
                    return EXIT_FAILURE;
                }
                index++;
            }
        }while(index < ll_len(pArrayListEmployee));
        fclose (fb);
    }
    printf("The file was succesfully saved as binary!\n");
    system("pause");

    return EXIT_SUCCESS;
}

