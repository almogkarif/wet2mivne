#ifndef HW2_EMPLOYEE_TREE
#define HW2_EMPLOYEE_TREE

#include "Rank.h"
#include "Node.h"
#include "Employee.h"

class SalaryComp
{
public:
    bool operator()(const Employee* a, const Employee* b) const
    {
        if((a->_salary > b->_salary) || (a->_salary == b->_salary && a->_id > b->_salary))
            return true;
        return false;
    }
};

class RankInd
{
public:
    int operator()(const Employee* a) const
    {
        return 1;
    }
};

class RankGrade
{
public:
    int operator()(const Employee* a) const
    {
        return a->_grade;
    }
};

class employeeTree
{
public:
    RankTree<Employee*, SalaryComp, RankInd> indTree;
    

};


#endif //HW2_EMPLOYEE_TREE