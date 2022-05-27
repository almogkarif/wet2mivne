#include "library2.h"



void *Init(int k);

StatusType AddEmployee(void *DS, int employeeID, int companyID, int grade) {}

StatusType RemoveEmployee(void *DS, int employeeID) {}

StatusType AcquireCompany(void *DS, int companyID1, int companyID2, double factor){}

StatusType EmployeeSalaryIncrease(void *DS, int employeeID, int salaryIncrease) {}

StatusType PromoteEmployee(void *DS, int employeeID, int bumpGrade) {}

StatusType SumOfBumpGradeBetweenTopWorkersByGroup(void *DS, int companyID, int m, void * sumBumpGrade){}

StatusType AverageBumpGradeBetweenSalaryByGroup(void *DS, int companyID, int lowerSalary, int higherSalary, void * averageBumpGrade) {}

StatusType CompanyValue(void *DS, int companyID, void * standing){}

void Quit(void** DS);