//
// Created by Kevin Kosta on 2019-03-23.
//
#include "experiment2.h"
#ifndef HHASHKK_EXPERIMENT3_H
#define HHASHKK_EXPERIMENT3_H


class experiment3 {
public:
    list<int> *chains;
    int Size;
    int *tablekey;
    int collisions;
    experiment3(int size);
    int moduloHash(int size);
    void addkeymod(int key);
    int getBucket(int key);
};

experiment3::experiment3(int size)
{
    Size = size;
    collisions = 0;
    chains = new list<int>[Size];
    tablekey = new int[Size];
    for(int i = 0; i <= Size-1; i++)
    {
        tablekey[i] = NULL;
    }
}
int experiment3::moduloHash(int key)
{
    return key % Size;
}

void experiment3::addkeymod(int key)
{
    int bucket = moduloHash(key);
    cout << bucket;
    if(chains[bucket].empty())
    {
        chains[bucket].push_back(key);
    }
    else
    {
        if(chains[bucket].front() != key && chains[bucket].back() != key)
        {
            chains[bucket].push_back(key);
            collisions++;
        }
    }
}

int experiment3::getBucket(int key) {
    int bucket = moduloHash(key);
    return bucket;
}


#endif //HHASHKK_EXPERIMENT3_H
