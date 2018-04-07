#pragma once
#include <iostream>
#include <string>
#include "node.h"

using namespace std;

//nodeInfo method definitions
nodeInfo::nodeInfo(node *nodePtr, int count) //Constructor
{
    this->nodePtr = nodePtr;
    this->count = count;
}
int nodeInfo::getCount()
{
    return count;
}
node* nodeInfo::getPointer()
{
    return nodePtr;
}
}
;