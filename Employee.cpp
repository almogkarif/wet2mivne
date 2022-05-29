#include "Company.h"
#include "Employee.h"
// #include "Ex2Exceptions.h"

Employee::Employee() : _id(-1), _salary(0) ,_grade(0), _company(nullptr) {}
Employee::Employee(int n_id) : _id(n_id), _salary(0) ,_grade(0), _company(nullptr){}

Employee::Employee(int n_id,int n_salary, int n_grade, Node<Company>* n_company) : id(n_id),
    salary(n_salary) ,grade(n_grade), company(n_company){}

int Employee::getSalary()
{
    return this->salary;
}

int Employee::getGrade()
{
    return this->grade;
}

Node<Company>* Employee::getCompany()
{
    return this->company;
}

void Employee::promote(int SalaryIncrease, int BumpGrade)
{
    if(SalaryIncrease<=0)
    {
        throw invalid_input();
    }
    salary+=SalaryIncrease;
    if (BumpGrade>0)
    {
        grade++;
    }
}

void Employee::hire(Node<Company>* n_company)
{
    if(company != nullptr)
    {
        if(n_company->data->id == company->data->id)
        {
            throw already_in_company();
        }
    }
    this->company = n_company;
}


void Employee::getInfo(int *EmployerID, int *Salary, int *Grade)
{
    *EmployerID = company->data->id;
    *Salary = salary;
    *Grade = grade;
}