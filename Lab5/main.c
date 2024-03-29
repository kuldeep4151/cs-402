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

    struct Employee employees[maxEmployee];
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
        employees[EmployeesCount].id = x;

        read_value = readstring(employees[EmployeesCount].first_name, maxName);
        if (read_value != 1) {
            break;
        }
        read_value = readstring(employees[EmployeesCount].last_name, maxName);
        if (read_value != 1) {
            break;
        }
        read_value = readint(&x);
        if (read_value != 1) {
            break;
        }
        employees[EmployeesCount].salary = x;

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
        printf("  (5) Quit\n");
        printf("----------------------------------\n");
        printf("Enter your choice: ");

        if (scanf("%d", &option) != 1 || option < 1 || option > 5) {
            rightOption = 0;
            printf("Invalid Input. Please enter a valid number between 1 and 5.\n");
            while (getchar() != '\n');
        }

        if (rightOption) {
            switch (option) {
                case 1:
                    printEmployeeDB(employees, EmployeesCount);
                    break;
                case 2:
                    searchById(employees, EmployeesCount);
                    break;
                case 3:
                    searchByLastName(employees, EmployeesCount);
                    break;
                case 4:
                    addEmployee(employees, & EmployeesCount);
                    break;
                case 5:
                    printf("Goodbye!\n");
                    break;
            }
        }
    } while (option != 5);

    return 0;
}