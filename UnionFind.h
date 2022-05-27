#ifndef UNION_FIND_H
#define UNION_FIND_H

#include "Company.h"
class UnionFind
{
private:
    int _size;
    int *_union_size;
    int *_point_to;
    Company **_company;
public:
    UnionFind(int k);
    ~UnionFind();
    UnionFind(const UnionFind &uf) = delete;
    UnionFind &operator=(const UnionFind &uf) = delete;
    void makeSet(int company_id);
    bool Union(int company_id1, int company_id2);
    Company *Find(int company_id);


};

#endif
