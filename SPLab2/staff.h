#ifndef STAFF_H
#define STAFF_H

#define maxName 65
#define minId 100000
#define maxId 999999
#define miniSalary 30000
#define maxSalary 150000

struct Employee {
    int id;
    char first_name[maxName];
    char last_name[maxName];
    int salary;
};

void printEmp(const struct Employee* staff);
int NextAvailableId(const struct Employee* staff, int EmployeesCount);
int validateEmp(const struct Employee* staff);
int compareEmployeeByID(const void* a, const void* b);
void sortEmployeesByID(struct Employee* staff, int EmployeesCount);

#endif 