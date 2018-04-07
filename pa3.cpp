#pragma once
#include <iostream>
#include <string>
#include "node.h"
#include <vector>
#include <cstdlib>
#include <fstream>

using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
node *nodeInfo::getPointer()
{
    return nodePtr;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//List  method definitions
void List::createNode(bool isFree, string progName, int index) //Create new node in list
{
    node *created = new node; //Initialize new node and its variables
    created->progName = progName;
    created->isFree = isFree;
    created->index = index;

    if (head == NULL) //Check if list has been started yet
    {
        head = created; //If not, set head and tail equal to the new node
        tail = created;
        created = NULL;
    }
    else //If the list has been started, create a node based on current tail
    {
        tail->next = created;
        tail = created;
    }
}
void List::display() //Iterates through linked list and displays the programs per page
{
    node *temp = new node;
    temp = head;
    int i = 0;
    for (int row = 1; row <= 4; row++)
    {
        for (int column = 1; column <= 8; column++)
        {
            cout << temp->progName << "\t";
            temp = temp->next;
            i++;
        }
        cout << '\n';
    }
}
node *List::getHead()
{
    return head;
}
node *List::getTail()
{
    return tail;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//TODO: use vector instead of array for elegance
void print(char token[])
{

    for (unsigned int k = 0; k < (sizeof(token) / sizeof(token[0])); k++)
    {
        printf("%3d ", token[k]);
    }
}
int main()
{
    //TODO: figure out a way to use a vector in this and future main functions for elegance
    char filename[100];
    ifstream file;
    cin.getline(filename, 100);
    file.open(filename);

    if (!file.is_open())
    {
        exit(EXIT_FAILURE);
    }

    char token[100];
    file >> token;
    for (unsigned int i = 0; i < (sizeof(token) / sizeof(token[0])); i++)
    {
        cout << token << " ";
        file >> token;
    }

    //Print function
    print(token);

    system("pause");
    return 0;
}