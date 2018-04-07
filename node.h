#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct node //Create member variables for a node structure
{

    string tokenName; //Name of program using node
    string category;
    node *next;      //Pointer to next node
};

class nodeInfo
{
  private:
    node *nodePtr; //Declares pointer
    int count;     //Declares count for number of unalloc spaces

  public:
    nodeInfo(node *nodePtr, int count); //Constructor
    int getCount();
    node *getPointer();
};

class List //Class for linked list
{
  private:
    node *head;
    node *tail;

  public:
    List() //Constructor
    {
        head = NULL;
        tail = NULL;
    }
    void push(string tokenName); //Create new node in list
    //TODO: make that pussi POP
    void display();                                           //Iterates through linked list and displays the programs per page
    node *getHead();
    node *getTail();
    //TODO: catagorizer
    void catagorizer(vector<string> &keywords,
    vector<string> &identifier,
    vector<string> &constant,
    vector<string> &operatros, //DEBUG: this is a meme
    vector<string> &delimiter,
    vector<string> &syntaxError);
    //NOTE: need to perform depth operation concurrently

};
