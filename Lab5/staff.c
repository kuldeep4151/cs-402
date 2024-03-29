#include <stdio.h>
#include <string.h>

#include "staff.h"


void printEmp(const struct Employee* staff) {
    printf("NAME\t\tSALARY\t\tID\n");
    printf("---------------------------------------------------------------\n");
    printf("%s %s\t%d\t\t%d\n", staff->first_name, staff->last_name, staff->salary, staff->id);
    printf("---------------------------------------------------------------\n\n");
}

int NextAvailableId(const struct Employee* staff, int EmployeesCount) {
    int nextId = minId;
    for (int i = 0; i < EmployeesCount; i++) {
        if (staff[i].id >= nextId) {
            nextId = staff[i].id + 1;
        }
    }
    return nextId;
}

int validateEmp(const struct Employee* staff) {
    return (staff->id >= minId && staff->id <= maxId) &&
           (staff->salary >= miniSalary && staff->salary <= maxSalary);
}

