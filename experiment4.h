
#include "experiment3.h"
#ifndef HHASHKK_EXPERIMENT4_H
#define HHASHKK_EXPERIMENT4_H


class experiment4 {

public:
    list<int> *chains;
    int Size;
    int *tablekey;
    int collisions;
    experiment4(int size);
    int midsquareHash(int size);
    void addkeymid(int key);
    int getBucket(int key);
};

experiment4::experiment4(int size)
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

int experiment4::midsquareHash(int key)
{
    int keysquared = key * key;
    int midsquare = (keysquared / int(pow(2, 0))) % Size;
    return midsquare;
}

void experiment4::addkeymid(int key)
{
    int bucket = midsquareHash(key);
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

int experiment4::getBucket(int key) {
    int bucket = midsquareHash(key);
    return bucket;
}

#endif //HHASHKK_EXPERIMENT4_H
