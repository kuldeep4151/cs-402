#include <stdio.h>

#include "readfile.h"
#include "operate.h" 
#include "staff.h"
#include "DB.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    if (openFile(argv[1]) != 0) {
        printf("Error while opening the file.\n");
        return 1;
    }

    struct Employee staff[maxEmployee];
    int EmployeesCount = 0;

    while (EmployeesCount < maxEmployee) {
        int read_value;
        int x;
        float f;
        char s[maxName];

        read_value = readint(&x);
        if (read_value != 1) {
            break;
        }
        staff[EmployeesCount].id = x;

        read_value = readstring(staff[EmployeesCount].first_name, maxName);
        if (read_value != 1) {
            break;
        }
        read_value = readstring(staff[EmployeesCount].last_name, maxName);
        if (read_value != 1) {
            break;
        }
        read_value = readint(&x);
        if (read_value != 1) {
            break;
        }
        staff[EmployeesCount].salary = x;

        EmployeesCount++;
    }


    closeFile();
     
    int option;

    do {
        int rightOption = 1;

        printf("\nEmployee DB Menu:\n");
        printf("----------------------------------\n");
        printf("  (1) Print the Database\n");
        printf("  (2) Lookup by ID\n");
        printf("  (3) Lookup by Last Name\n");
        printf("  (4) Add an Employee\n");
        printf("  (5) Remove an Employee\n");
        printf("  (6) Update an Employee's Information\n");
        printf("  (7) Print the M Employees with the Highest Salaries\n");
        printf("  (8) Find All Employees with Matching Last Name\n");
        printf("  (9) Quit\n");
        printf("----------------------------------\n");
        printf("Enter your choice: ");

        if (scanf("%d", &option) != 1 || option < 1 || option > 9) {
            rightOption = 0;
            printf("Invalid Input. Please enter a valid number between 1 and 9.\n");
            while (getchar() != '\n');
        }

        if (rightOption) {
            switch (option) {
                case 1:
                    printEmployeeDB(staff, EmployeesCount);
                    break;
                case 2:
                    searchById(staff, EmployeesCount);
                    break;
                case 3:
                    searchByLastName(staff, EmployeesCount);
                    break;
                case 4:
                    addEmployee(staff, & EmployeesCount);
                    break; 
                case 5:
                    removeEmployeeFunction(staff, &EmployeesCount);
                    break;
                case 6:
                    updateEmployeeFuntion(staff, EmployeesCount);
                    break;
                case 7:
                    highestSalariesCount(staff, EmployeesCount);
                    break;
                case 8:
                    findAllEmployeesByLastName(staff, EmployeesCount);
                    break;
                case 9:
                    printf("Goodbye!\n");
                    break;
            }
        }
    } while (option != 9);

    return 0;
}