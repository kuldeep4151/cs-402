#ifndef DB_H
#define DB_H

#include "staff.h"
#define maxEmployee 1024


void printEmployeeDB(const struct Employee* employees, int EmployeesCount);
void addEmployee(struct Employee* employees, int* EmployeesCount);
void searchById(const struct Employee* employees, int EmployeesCount);
void searchByLastName(const struct Employee* employees, int EmployeesCount);

#endif // DB_H