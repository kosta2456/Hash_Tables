
#ifndef HHASHKK_NODE_H
#define HHASHKK_NODE_H
#include<iostream>
#include<list>
#include<cmath>

using namespace std;
class node
{
public:
    int key;
    node(int key);
};
node::node(int key)
{
    this->key = key;
}

#endif //HHASHKK_NODE_H
