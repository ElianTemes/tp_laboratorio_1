/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Struct.h"
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"


int main(void)
{
     //startTesting(1);  // ll_newLinkedList
      //  startTesting(2);  // ll_len
      //  startTesting(3);  // getNode - test_getNode
     //   startTesting(4);  // addNode - test_addNode
        /*startTesting(5);  // ll_add
        startTesting(6);  // ll_get
        startTesting(7);  // ll_set
        startTesting(8);  // ll_remove
        startTesting(9);  // ll_clear
        startTesting(10); // ll_deleteLinkedList
        startTesting(11); // ll_indexOf
        startTesting(12); // ll_isEmpty
        startTesting(13); // ll_push
        startTesting(14); // ll_pop
        startTesting(15); // ll_contains
        startTesting(16); // ll_containsAll
        startTesting(17); // ll_subList
        startTesting(18); // ll_clone*/
        //startTesting(19); // ll_sort */

    LinkedList* listEmp = ll_newLinkedList();
    int len;

    Employee* Emp1 = employee_newParam("1", "Elian", "25", "65000");
    ll_add(listEmp, Emp1);
    Employee* Emp2 = employee_newParam("2", "Nina", "30", "75000");
    ll_add(listEmp, Emp2);
    Employee* Emp3 = employee_newParam("3", "Pepe", "15", "33000");

    ll_add(listEmp, Emp3);
    len = ll_len(listEmp);
    printf("Lenght of the list: %d\n", len);

    Employee* auxEmp = ll_get(listEmp, 2);
    printf("////  ID                  NAME         WORKED HOURS             SALARY////\n");
    employee_printOne(auxEmp);

    Employee* set = employee_newParam("3", "Mario", "12", "43000");
    ll_set(listEmp, 2, set);
    set = ll_get(listEmp, 2);
    printf("////  ID                  NAME         WORKED HOURS             SALARY////\n");
    employee_printOne(set);

    printf("-------------------------------------------------------------------------------------------------\n");
    ll_remove(listEmp, 2);
    len = ll_len(listEmp);
    printf("\nNew list lenght after remove: %d", len);
    ll_clear(listEmp);
    len = ll_len(listEmp);
    printf("\nNew list lenght after clear: %d\n\n", len);

    ll_deleteLinkedList(listEmp);
    employee_delete(Emp1);
    employee_delete(Emp2);
    employee_delete(Emp3);

    printf("-------------------------------------------------------------------------------------------------\n\n");
    listEmp = ll_newLinkedList();

    Emp1 = employee_newParam("1", "Elian", "25", "65000");
    ll_add(listEmp, Emp1);
    Emp2 = employee_newParam("2", "Nina", "30", "75000");
    ll_add(listEmp, Emp2);
    Emp3 = employee_newParam("3", "Pepe", "15", "33000");
    ll_add(listEmp, Emp3);

    int index = ll_indexOf(listEmp, Emp2);
    printf("Index of the Emp2 by ll_indexOf: %d\n\n", index);

    int isEmpty = ll_isEmpty(listEmp);
    printf("Is the list empty? (0 = the list has something inside -1 = error 1 = list is empty): %d\n\n", isEmpty);

    Employee* Emp4 = employee_newParam("4", "Newbie", "12", "30000");
    ll_push(listEmp, 3, Emp4);
    len = ll_len(listEmp);
    printf("List lenght after adding employee with push: %d\n\n", len);
    employee_ListEmployee(listEmp);
    printf("\n\n-------------------------------------------------------------------------------------------------\n\n");

    ll_pop(listEmp, 2);
    len = ll_len(listEmp);
    Employee* aux = ll_get(listEmp, 2); //change id to match order
    employee_setId(aux, 3);
    printf("List lenght after removing with pop: %d\n\n", len);
    employee_ListEmployee(listEmp);
    printf("\n\n-------------------------------------------------------------------------------------------------\n\n");

    Employee* pedro = employee_newParam("5", "Pedro", "40", "95000");
    int contains = ll_contains(listEmp, pedro);
    printf("-1 if error, 0 if element is ! contained, 1 if element is contained: %d\n\n", contains);
    printf("\n\n-------------------------------------------------------------------------------------------------\n\n");

    LinkedList* listEmp2 = ll_newLinkedList();
    Employee* mario = NULL;
    ll_add(listEmp2, mario);
    int containsAll = ll_containsAll(listEmp, listEmp2);
    printf("-1 if error, 0 if elements are ! contained, 1 if elements are contained: %d\n\n", containsAll);
    printf("\n\n-------------------------------------------------------------------------------------------------\n\n");

    LinkedList* listEmp3 = ll_subList(listEmp, 1, 3);
    printf("Sublist: \n\n");
    employee_ListEmployee(listEmp3);
    printf("\n\n-------------------------------------------------------------------------------------------------\n\n");

    LinkedList* listEmp4 = ll_clone(listEmp3);
    printf("Cloned sublist: \n\n");
    employee_ListEmployee(listEmp4);
    printf("\n\n-------------------------------------------------------------------------------------------------\n\n");

    ll_sort(listEmp, employee_sortBySalary, 0);
    printf("Sorted list by salary: \n\n");
    employee_ListEmployee(listEmp);
    printf("\n\n-------------------------------------------------------------------------------------------------\n\n");

    return 0;

}

































