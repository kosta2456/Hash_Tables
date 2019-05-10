
#include "node.h"
#ifndef HHASHKK_EXPERIMENT1_H
#define HHASHKK_EXPERIMENT1_H


class experiment1 {
public:
    node** hashtable;
    int Size;
    int collisions;
    experiment1(int size);
    int mod(int key);
    void addkeymod(int key);
    int getBucket(int index);
};

experiment1::experiment1(int size)
{
    Size = size;
    collisions = 0;
    hashtable = new node*[Size];
    for(int i = 0; i <= Size-1; i++)
    {
        hashtable[i] = NULL;
    }
}

int experiment1::mod(int key)
{
    return key % Size;
}


void experiment1::addkeymod(int key)
{
    node *temp = new node(key);
    int bucket = mod(key);
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

int experiment1::getBucket(int key){
    int bucket = mod(key);
    return bucket;
}


#endif //HHASHKK_EXPERIMENT1_H
