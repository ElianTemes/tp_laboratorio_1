#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/



int main()
{
    int option = 0;
    char* path = "data.csv";
    char* pathBin = "data.bin";
    char flagOverWriteTxt;
    char flagOverWriteBin;
    int flagLoadText = 0;
    int flagLoadBin = 0;
    int flagEmployeeInit = 0;
    int flagSaved = 0;

    LinkedList* pListEmployees = ll_newLinkedList();

    do{
        system("cls");
        printf("Menu:"
     "\n1. Load data from file data.csv (text mode)."
     "\n2. Load data from file data.bin (binary mode)."
     "\n3. New employee"
     "\n4. Edit employee"
     "\n5. Delete employee"
     "\n6. List employee"
     "\n7. Sort employee"
     "\n8. Save employees data to data.csv (text mode)."
     "\n9. Save employees data to data.bin (binary mode)."
    "\n10. Exit");
        printf("\nChoose an option: ");
        while(scanf("%d", &option) != 1 || option < 1 || option > 10){
            printf("\nError enter a valid option: ");
            scanf("%d", &option);
        }
        switch(option){
            case 1:
                if(flagLoadText == 0 && flagLoadBin == 0){
                    system("cls");
                    controller_loadFromText(path, pListEmployees);
                    flagLoadText = 1;
                    flagEmployeeInit = 1;
                    system("pause");
                }
                if(flagEmployeeInit == 1 && flagLoadText == 0 && flagLoadBin == 0){
                    ll_deleteLinkedList(pListEmployees);
                    pListEmployees = ll_newLinkedList();
                    controller_loadFromText(path, pListEmployees);
                    flagLoadText = 1;
                }
                if(flagSaved == 1 && flagLoadBin == 0){
                    ll_deleteLinkedList(pListEmployees);
                    pListEmployees = ll_newLinkedList();
                    controller_loadFromText(path, pListEmployees);
                    flagLoadText = 1;
                    flagEmployeeInit = 1;
                }
            break;

            case 2:
                if(flagLoadBin == 0 && flagLoadText == 0){
                    system("cls");
                    controller_loadFromBinary(pathBin, pListEmployees);
                    flagLoadBin = 1;
                    flagEmployeeInit = 1;
                    system("pause");
                }
                if(flagEmployeeInit == 1 && flagLoadBin == 0 && flagLoadText == 0){
                    ll_deleteLinkedList(pListEmployees);
                    pListEmployees = ll_newLinkedList();
                    controller_loadFromBinary(pathBin, pListEmployees);
                    flagLoadBin = 1;
                }
                if(flagSaved == 1 && flagLoadText == 0){
                    ll_deleteLinkedList(pListEmployees);
                    pListEmployees = ll_newLinkedList();
                    controller_loadFromBinary(pathBin, pListEmployees);
                    flagLoadBin = 1;
                    flagEmployeeInit = 1;
                }
            break;

            case 3:
                system("cls");
                controller_addEmployee(pListEmployees);
                flagEmployeeInit = 1;
                system("pause");
            break;

            case 4:
                if(flagEmployeeInit == 1){
                    system("cls");
                    controller_ListEmployee(pListEmployees);
                    controller_editEmployee(pListEmployees);
                }
                else{
                    printf("\nThere's no employees loaded!\n");
                    system("pause");
                }
            break;

            case 5:
                if(flagEmployeeInit == 1){
                    system("cls");
                    controller_ListEmployee(pListEmployees);
                    controller_removeEmployee(pListEmployees);
                }
                else{
                    printf("\nThere's no employees loaded!\n");
                    system("pause");
                }
            break;

            case 6:
                if(flagEmployeeInit == 1){
                    system("cls");
                    controller_ListEmployee(pListEmployees);
                    system("pause");
                }
                else{
                    printf("\nThere's no employees loaded!\n");
                    system("pause");
                }
            break;

            case 7:
                if(flagEmployeeInit == 1){
                    system("cls");
                    controller_ListEmployee(pListEmployees);
                    controller_sortEmployee(pListEmployees);
                    system("pause");
                }
                else{
                    printf("\nThere's no employees loaded!\n");
                    system("pause");
                }
            break;
            case 8:
                if(flagLoadText == 0 && flagLoadBin == 0){
                    printf("If you save now the original file is gonna be overwriten by the actual content, do yo want to overwrite? Y/N: ");
                    scanf("%s", &flagOverWriteTxt);
                    flagOverWriteTxt = toupper(flagOverWriteTxt);
                        if(flagOverWriteTxt == 'Y'){
                            controller_saveAsText(path, pListEmployees);
                            flagSaved = 1;
                        }
                        else{
                            printf("\nOperation cancelled\n");
                            system("pause");
                        }
                }
                else{
                    controller_saveAsText(path, pListEmployees);
                }
            break;

            case 9:
                if(flagLoadBin == 0 && flagLoadText == 0){
                    printf("If you save now the original file is gonna be overwriten by the actual content, do yo want to overwrite? Y/N: ");
                    scanf("%s", &flagOverWriteBin);
                    flagOverWriteBin = toupper(flagOverWriteBin);
                        if(flagOverWriteBin == 'Y'){
                            controller_saveAsBinary(pathBin, pListEmployees);
                            flagSaved = 1;
                        }
                        else{
                            printf("\nOperation cancelled\n");
                            system("pause");
                        }
                }
                else{
                    controller_saveAsBinary(pathBin, pListEmployees);
                }
            break;

            case 10:
                system("cls");
                controller_freeAll(pListEmployees);
                system("pause");
            break;
        }
    }while(option != 10);
    controller_freeAll(pListEmployees);
    return 0;
}

