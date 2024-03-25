#include <stdio.h>
#include <string.h>

#include "staff.h"


void printEmp(const struct Employee* employee) {
    printf("NAME\t\tSALARY\t\tID\n");
    printf("---------------------------------------------------------------\n");
    printf("%s %s\t%d\t\t%d\n", employee->first_name, employee->last_name, employee->salary, employee->id);
    printf("---------------------------------------------------------------\n\n");
}

int NextAvailableId(const struct Employee* employees, int EmployeesCount) {
    int nextId = minId;
    for (int i = 0; i < EmployeesCount; i++) {
        if (employees[i].id >= nextId) {
            nextId = employees[i].id + 1;
        }
    }
    return nextId;
}

int validateEmp(const struct Employee* employee) {
    return (employee->id >= minId && employee->id <= maxId) &&
           (employee->salary >= miniSalary && employee->salary <= maxSalary);
}

