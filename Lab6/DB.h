#ifndef DB_H
#define DB_H

#include "staff.h"
#define maxEmployee 1024


void printEmployeeDB(const struct Employee* staff, int EmployeesCount);
void addEmployee(struct Employee* staff, int* EmployeesCount);
void searchById(const struct Employee* staff, int EmployeesCount);
void searchByLastName(const struct Employee* staff, int EmployeesCount);
void removeEmployeeFunction(struct Employee* staff, int* EmployeesCount);
void updateEmployeeFuntion(struct Employee* staff, int EmployeesCount);
void highestSalariesCount(struct Employee* staff, int EmployeesCount);
void findAllEmployeesByLastName(struct Employee* staff, int EmployeesCount);


#endif // DB_H