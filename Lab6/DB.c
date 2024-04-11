#include <stdio.h>
#include <string.h>

#include "DB.h"
#include "staff.h"
#include <stdlib.h>  


// Printing Employee Database 
void printEmployeeDB(const struct Employee* staff, int EmployeesCount) {
    printf("NAME\t\tSALARY\t\tID\n");
    printf("---------------------------------------------------------------\n");
    for (int i = 0; i < EmployeesCount; i++) {
        printf("%s %s\t%d\t\t%d\n", staff[i].first_name, staff[i].last_name, staff[i].salary, staff[i].id);
    }
    printf("---------------------------------------------------------------\n");
    printf("Number of Employees (%d)\n", EmployeesCount);
}



// Function to Add new Employee 
void addEmployee(struct Employee* staff, int* EmployeesCount) {
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
        if (staff[i].id >= nextId) {
            nextId = staff[i].id + 1;
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
        staff[*EmployeesCount] = newEmployee;
        (*EmployeesCount)++;
        printf("Employee has been added to the database.\n");
    } else {
        printf("Employee is not added to the database.\n");
    }
}
// Search employee by ID
void searchById(const struct Employee* staff, int EmployeesCount) {
    int searchId;
    printf("Please, Enter a Employee Id (6 digit): ");
    if (scanf("%d", &searchId) != 1 || searchId < minId || searchId > maxId) {
        printf("Invalid ID. Please Enter a valid 6-digit ID.\n");
        while (getchar() != '\n'); 
        return;
    }

    for (int i = 0; i < EmployeesCount; i++) {
        if (staff[i].id == searchId) {
            printEmp(&staff[i]);
            return;
        }
    }

    printf("Employee with id %d not found in the DataBase \n", searchId);
}

// Search employee by last name
void searchByLastName(const struct Employee* staff, int EmployeesCount) {
    char searchLastName[maxName];
    printf("Enter last name of the Employee (without extra spaces): ");
    if (scanf("%64s", searchLastName) != 1) {
        printf("Invalid Input. Enter a valid last name.\n");
        while (getchar() != '\n'); 
        return;
    }

    int found = 0;
    for (int i = 0; i < EmployeesCount; i++) {
        if (strcmp(staff[i].last_name, searchLastName) == 0) {
            printEmp(&staff[i]);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No, Such employees found in the DataBase with last name: %s\n", searchLastName);
    }
}

// Remove Employee
void removeEmployeeFunction(struct Employee* staff, int* EmployeesCount) {
    if (*EmployeesCount == 0) {
        printf("The DATABASE is empty! Cannot Perform remove operation\n");
        return;
    }

    int removeId;
    printf("Enter the employeeID to remove: ");
    if (scanf("%d", &removeId) != 1) {
        printf("Invalid Input!!! Please Enter a Valid employee ID.\n");
        while (getchar() != '\n'); 
        return;
    }

    // Finding Exployee index with the Entered ID
    int index = -1;
    for (int i = 0; i < *EmployeesCount; i++) {
        if (staff[i].id == removeId) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("The Employee to be removed with ID %d not found in the database.\n", removeId);
    } else {
        printf("Employee found:\n");
        printEmp(&staff[index]);

        int confirm;
        printf("Please Confirm! Do you want to remove this employee? (Select 1 for Yes, 0 for No): ");
        if (scanf("%d", &confirm) != 1 || (confirm != 0 && confirm != 1)) {
            printf("Invalid Input. Please enter 0 or 1.\n");
            while (getchar() != '\n'); 
            return;
        }

        if (confirm == 1) {
            // Removing and shifting the remaining employees
            for (int i = index; i < *EmployeesCount - 1; i++) {
                staff[i] = staff[i + 1];
            }
            (*EmployeesCount)--;
            printf("Successful! Employee with ID %d has been removed from the database.\n", removeId);
        } else {
            printf("Operation Failed! Employee with ID %d was not removed.\n", removeId);
        }
    }
}

//Update Employees

void updateEmployeeFuntion(struct Employee* staff, int EmployeesCount) {
    if (EmployeesCount == 0) {
        printf("The DATABASE is Empty! Cannot make any update.\n");
        return;
    }

    int findId;
    printf("Enter the ID of the Employee to be update: ");
    if (scanf("%d", &findId) != 1) {
        printf("Invalid ID Input! Please Enter a valid employee ID.\n");
        while (getchar() != '\n'); 
        return;
    }

    int index = -1; 

    for (int i = 0; i < EmployeesCount; i++) {
        if (staff[i].id == findId) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Employee ID %d is not found in the database.\n", findId);
    } else {
        printf("Employee with ID %d found:\n",findId);
        printEmp(&staff[index]);

        int verify;
        printf("Please Confirm! Do you want to update this employee's information? Enter (1 for Yes, 0 for No): ");
        if (scanf("%d", &verify) != 1 || (verify != 0 && verify != 1)) {
            printf("Invalid Input!. Please enter 0 or 1.\n");
            while (getchar() != '\n'); 
            return;
        }
        // confirmation before updating
        if (verify == 1) {
            
            printf("Please Confirm! Do you want to update the first name? Enter (1 for yes, 0 for no): ");
            if (scanf("%d", &verify) != 1 || (verify != 0 && verify != 1)) {
                printf("Invalid Input. Please enter 0 or 1.\n");
                while (getchar() != '\n'); 
                return;
            }
            if (verify == 1) {
                printf("Enter new first name: ");
                scanf("%64s", staff[index].first_name);
            }

            printf("Please Confirm! Do you want to update the last name? Enter (1 for yes, 0 for no): ");
            if (scanf("%d", &verify) != 1 || (verify != 0 && verify != 1)) {
                printf("Invalid Input. Please enter 0 or 1.\n");
                while (getchar() != '\n'); 
                return;
            }
            if (verify == 1) {
                printf("Enter new last name: ");
                scanf("%64s", staff[index].last_name);
            }

            printf("Please Confirm! Do you want to update the salary? Enter (1 for yes, 0 for no): ");
            if (scanf("%d", &verify) != 1 || (verify != 0 && verify != 1)) {
                printf("Invalid Input. Please enter 0 or 1.\n");
                while (getchar() != '\n'); 
                return;
            }
            if (verify == 1) {
                int newSalary;
                while (1) {
                    printf("Enter new salary (between %d and %d): ", miniSalary, maxSalary);
                    if (scanf("%d", &newSalary) != 1) {
                        printf("Invalid Input. Please enter a valid salary (between %d and %d):\n",miniSalary, maxSalary );
                        while (getchar() != '\n'); 
                    } else if (newSalary < miniSalary || newSalary > maxSalary) {
                        printf("Invalid Input. Salary outlying range. Please enter a valid salary between %d and %d.\n", miniSalary, maxSalary);
                    } else {
                        staff[index].salary = newSalary;
                        break; 
                    }
                }
            }

            

            printf("Information of Employee with ID %d has been updated successfully.\n",findId);
        } else {
            printf("Information of Employee with ID %d failed to get update.\n",findId);
        }
    }
}
// M Employees with highest salary
void highestSalariesCount(struct Employee* staff, int EmployeesCount){
    if (EmployeesCount == 0) {
        printf("The DATABASE is empty, cannot print the employees.\n");
        return;
    }

    int M;
    printf("How many employees to print with the highest salaries : ");
    if (scanf("%d", &M) != 1 || M <= 0) {
        printf("Invalid Number! Please enter a positive integer.\n");
        while (getchar() != '\n'); 
        return;
    }

    // Sort employees by salary (in descending order) using counting sort
    int maxiSalary = -1;
    for (int i = 0; i < EmployeesCount; i++) {
        if (staff[i].salary > maxiSalary) {
            maxiSalary = staff[i].salary;
        }
    }

    int* numsSalary = (int*)calloc(maxSalary + 1, sizeof(int));
    if (numsSalary == NULL) {
        printf("FAILED...Memory allocation.\n");
        return;
    }

    for (int i = 0; i < EmployeesCount; i++) {
        numsSalary[staff[i].salary]++;
    }

    int printMax = 0;
    printf("%d Number of employees with the Highest Salaries:\n\n", M);
    printf("NAME\t\t\tSALARY\t\tID\n");
    printf("---------------------------------------------------------------\n");
    for (int salary = maxSalary; salary >= 0; salary--) {
        for (int i = 0; i < EmployeesCount; i++) {
            if (staff[i].salary == salary) {
                printf("%s %s\t\t%d\t\t%d\n", staff[i].first_name, staff[i].last_name, staff[i].salary, staff[i].id);
                printMax++;
            }

            if (printMax == M) {
                break;
            }
        }

        if (printMax == M) {
            break;
        }
    }
    printf("---------------------------------------------------------------\n\n");


    free(numsSalary);
}

//All employees with same first name 

void findAllEmployeesByLastName(struct Employee* staff, int EmployeesCount) {
    char findLName[maxName];
    printf("Please, Enter the last name to be search (case-insensitive): ");
    if (scanf("%64s", findLName) != 1) {
        printf("Invalid last name. Please enter a valid last name.\n");
        while (getchar() != '\n'); 
        return;
    }

    int found = 0;
    printf("\nNAME\t\t\tSALARY\t\tID\n");
    printf("---------------------------------------------------------------\n");
    for (int i = 0; i < EmployeesCount; i++) {
        // Perform a case-insensitive comparison
        if (strcasecmp(staff[i].last_name, findLName) == 0) {
            printf("%s %s\t\t%d\t\t%d\n", staff[i].first_name, staff[i].last_name, staff[i].salary, staff[i].id);
            found = 1;
        }
    }
    printf("---------------------------------------------------------------\n\n");


    if (!found) {
        printf("Sorry! No such employees exist in the database with the given last name: %s\n", findLName);
    }
}