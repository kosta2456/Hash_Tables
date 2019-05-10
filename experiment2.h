
#include "experiment1.h"
#ifndef HHASHKK_EXPERIMENT2_H
#define HHASHKK_EXPERIMENT2_H


class experiment2 {
public:
    node** hashtable;
    int Size;
    int collisions;
    experiment2(int size);
    int midfunction(int key);
    void addkeymid(int key);
    int getBucket(int key);
};

experiment2::experiment2(int size)
{
    Size = size;
    collisions = 0;
    hashtable = new node*[Size];
    for(int i = 0; i <= Size-1; i++)
    {
        hashtable[i] = NULL;
    }
}


int experiment2::midfunction(int key)
{
    int keysquared = key * key;
    int midsquare = (keysquared / int(pow(2, 0))) % Size;
    return midsquare;
}

void experiment2::addkeymid(int key)
{
    node *temp = new node(key);
    int bucket = midfunction(key);
    cout << bucket;
    if(hashtable[bucket] != NULL && hashtable[bucket]->key != key && hashtable[bucket]->key != NULL)
    {
        collisions++;
    }

    while(hashtable[bucket] != NULL && hashtable[bucket]->key != key && hashtable[bucket]->key != NULL)
    {
        bucket++;
        bucket %= Size;
    }
    hashtable[bucket] = temp;
}

int experiment2::getBucket(int key){
    int bucket = midfunction(key);
    return bucket;
}



#endif //HHASHKK_EXPERIMENT2_H
