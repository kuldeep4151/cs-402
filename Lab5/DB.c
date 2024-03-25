#include <stdio.h>
#include <string.h>

#include "DB.h"
#include "staff.h"

// Printing Employee Database 
void printEmployeeDB(const struct Employee* employees, int EmployeesCount) {
    printf("NAME\t\tSALARY\t\tID\n");
    printf("---------------------------------------------------------------\n");
    for (int i = 0; i < EmployeesCount; i++) {
        printf("%s %s\t%d\t\t%d\n", employees[i].first_name, employees[i].last_name, employees[i].salary, employees[i].id);
    }
    printf("---------------------------------------------------------------\n");
    printf("Number of Employees (%d)\n", EmployeesCount);
}



// Function to Add new Employee 
void addEmployee(struct Employee* employees, int* EmployeesCount) {
    if (*EmployeesCount >= maxEmployee) {
        printf("Cannot add more employees. Maximum capacity reached.\n");
        return;
    }

    struct Employee newEmployee;

    // validation of First Name
    do {
        printf("Please! Enter the first name of the employee: ");
        if (scanf("%64s", newEmployee.first_name) != 1) {
            printf("Wrong input. Enter a valid first name.\n");
            while (getchar() != '\n'); 
        }
    } while (strlen(newEmployee.first_name) == 0);

    // Validation of last Name 
    do {
        printf("Please! Enter the last name of the employee: ");
        if (scanf("%64s", newEmployee.last_name) != 1) {
            printf("Wrong input. Enter a valid last name.\n");
            while (getchar() != '\n'); 
        }
    } while (strlen(newEmployee.last_name) == 0);

    // Validation of Salary
    do {
        printf("Enter Employee's Salary (%d to %d): ", miniSalary, maxSalary);
        if (scanf("%d", &newEmployee.salary) != 1 || newEmployee.salary < miniSalary || newEmployee.salary > maxSalary) {
            printf("Incorrect Salary. Enter a valid salary.\n");
            while (getchar() != '\n'); 
        }
    } while (newEmployee.salary < miniSalary || newEmployee.salary > maxSalary);

    // Find the next available ID
    int nextId = minId;
    for (int i = 0; i < *EmployeesCount; i++) {
        if (employees[i].id >= nextId) {
            nextId = employees[i].id + 1;
        }
    }
    newEmployee.id = nextId;

    int confirm;

    do {
        printf("Are you Sure? You want to add the employee to the DB?\n");
        printf("\t%s %s, salary: %d\n", newEmployee.first_name, newEmployee.last_name, newEmployee.salary);
        printf("Enter 1 for Yes, 0 for No to Confirm : ");

        if (scanf("%d", &confirm) != 1 || (confirm != 0 && confirm != 1)) {
            printf("Wrong! Input. Please enter 0 or 1 to confirm .\n");
            while (getchar() != '\n'); 
        }
    } while (confirm != 0 && confirm != 1);

    if (confirm == 1) {
        employees[*EmployeesCount] = newEmployee;
        (*EmployeesCount)++;
        printf("Employee has been added to the database.\n");
    } else {
        printf("Employee is not added to the database.\n");
    }
}
// Search employee by ID
void searchById(const struct Employee* employees, int EmployeesCount) {
    int searchId;
    printf("Please, Enter a Employee Id (6 digit): ");
    if (scanf("%d", &searchId) != 1 || searchId < minId || searchId > maxId) {
        printf("Invalid ID. Please Enter a valid 6-digit ID.\n");
        while (getchar() != '\n'); 
        return;
    }

    for (int i = 0; i < EmployeesCount; i++) {
        if (employees[i].id == searchId) {
            printEmp(&employees[i]);
            return;
        }
    }

    printf("Employee with id %d not found in the DataBase \n", searchId);
}

// Search employee by last name
void searchByLastName(const struct Employee* employees, int EmployeesCount) {
    char searchLastName[maxName];
    printf("Enter last name of the Employee (without extra spaces): ");
    if (scanf("%64s", searchLastName) != 1) {
        printf("Invalid Input. Enter a valid last name.\n");
        while (getchar() != '\n'); 
        return;
    }

    int found = 0;
    for (int i = 0; i < EmployeesCount; i++) {
        if (strcmp(employees[i].last_name, searchLastName) == 0) {
            printEmp(&employees[i]);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No, Such employees found in the DataBase with last name: %s\n", searchLastName);
    }
}