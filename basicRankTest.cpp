#include "Rank.h"
#include "Node.h"
#include <iostream>

using std::cout;
using std::endl;

class smallEmployee
{
public:
    int _id;
    int _salary;
    int _grade;

    smallEmployee() : _id(0), _salary(0), _grade(0) {}
    smallEmployee(int id, int salary) : _id(id), _salary(salary), _grade(0) {}
    smallEmployee(int id, int salary, int grade) : _id(id), _salary(salary), _grade(grade) {}
    smallEmployee(int id) : _id(id), _salary(0), _grade(0) {}

    ~smallEmployee() = default;
};

class salaryOrder
{
public:
    bool operator()( const smallEmployee& a, const  smallEmployee& b)
    {
        if((a._salary> b._salary) || (a._salary == b._salary && a._id > b._id))
        {
            return true;
        }
        
        return false;
    } 
};

class rankGrade
{
public:
    int operator()(smallEmployee& a)
    {
        return a._grade;
    }
};

class rankInd
{
public:
    int operator()(smallEmployee& a)
    {
        return 1;
    }
};


int main()
{
    RankTree<smallEmployee, salaryOrder, rankGrade> gradeTree1;
    RankTree<smallEmployee, salaryOrder, rankGrade> gradeTree2;
    RankTree<smallEmployee, salaryOrder, rankInd> indTree1;
    RankTree<smallEmployee, salaryOrder, rankInd> indTree2;

    smallEmployee e1(1, 10, 1);
    smallEmployee e2(2, 20, 5);
    smallEmployee e3(3, 30, 3);
    smallEmployee e4(4, 40, 6);
    smallEmployee e5(5, 50, 7);
    smallEmployee e6(6, 60, 3);
    smallEmployee e7(7, 70, 1);
    smallEmployee e8(8, 80, 0);

    gradeTree1.insert(e1);
    indTree1.insert(e1);
    
    gradeTree1.insert(e3);
    indTree1.insert(e3);

    gradeTree1.insert(e5);
    indTree1.insert(e5);

    gradeTree1.insert(e7);
    indTree1.insert(e7);

    gradeTree2.insert(e2);
    indTree2.insert(e2);
    
    gradeTree2.insert(e4);
    indTree2.insert(e4);

    gradeTree2.insert(e6);
    indTree2.insert(e6);

    gradeTree2.insert(e8);
    indTree2.insert(e8);

    if(indTree1.findRank(e1) != 1)
    {
        cout << "test1 faild" << endl;
    }

    if(gradeTree1.findRank(e5) != 11)
    {
        cout <<"test2 faild" <<endl;
    }

    if(gradeTree1.findRank(*indTree1.selectElement(3)) != 11)
    {
        cout <<"test3 faild" << endl;
    }

    gradeTree1.remove(e1);
    indTree1.remove(e1);


    if(gradeTree1.findRank(e5) != 10)
    {
        cout <<"test4 faild" << endl;
    }

    gradeTree1.merge(gradeTree2);
    indTree1.merge(indTree2);
    gradeTree1.insert(e1);
    indTree1.insert(e1);
    if(gradeTree1.findRank(e8) != 26)
    {
        cout <<"test5 faild" << endl;
    }
    

    return 0;
}
