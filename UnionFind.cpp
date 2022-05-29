#include "UnionFind.h"
#include "string.h"

UnionFind::UnionFind(int k) :_size(k),_union_size(nullptr),_point_to(nullptr),_company(nullptr)
{
    if(k<=0)
    {
        //
    }
    int *newArr = new int[_size + 1];
    for(int i=1; i<=_size; i++)
    {
        _company[i] = new Company(i);
        _union_size[i] = 1;
        _point_to[i]=i;
    }
}
UnionFind::~UnionFind()
{
    delete[] _point_to;
}

// void UnionFind::makeSet()
// {

// }

Company *UnionFind::Find(int company_id)
{
    if (company_id > _size)
    {
        return nullptr;
    }
    int sum_value=0;
    int root = company_id;
    while(root != _point_to[root])
    {
        sum_value+=_company[root]->stock_value;
        root = _point_to[root];
    }
    int index = company_id;
    while(index!=root)
    {
        sum_value-=_company[index]->stock_value;
        _company[index]->stock_value += sum_value;
        _point_to[index] = root;
        index = _point_to[index];
    }
    return _company[root];
}

bool UnionFind::UnionLeftAcquire(int company_id1, int company_id2,double factor)
{
    Company *c1 = Find(company_id1);
    Company *c2 = Find(company_id2);
    if(!c1||!c2)
    {
        return false;
    }
    if(c1->id == c2->id)
    {
        return true;
    }
    if(_union_size[c1->id]>=_union_size[c2->id])
    {
        _company[company_id1]->stock_value += (_company[company_id1]->stock_value)*factor;
        _company[company_id2]->stock_value -= _company[company_id1]->stock_value;
        c1->mergeWith(*c2);
        _point_to[c2->id] = c1->id;
    }
    else
    {
        _company[company_id1]->stock_value += (_company[company_id1]->stock_value)*(factor-1);
        c2->mergeWith(*c1);
        _point_to[c1->id] = c2->id;
    }
    return true;

}





