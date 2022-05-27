#include "UnionFind.h"
#include "string.h"

UnionFind::UnionFind(int k) :_size(k),_union_size(nullptr),_point_to(nullptr),_company(nullptr)
{
    if(k<=0)
    {
        //
    }
    int *newArr = new int[_size + 1];

}
UnionFind::~UnionFind()
{
    delete[] _point_to;
}

void UnionFind::makeSet(int company_id)
{
 }
    _point_to[company_id] = company_id;
    _size++;
}

Company *UnionFind::Find(int company_id)
{
    // if (company_id > _size)
    // {
    //     return nullptr;
    // }
    // int current = company_id;
    // while(current != _root_company[current])
    // {
    //     current = _root_company[current];
    // }
    // int index = current;
}



