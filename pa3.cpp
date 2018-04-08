#pragma once
#include <iostream>
#include <string>
#include "node.h"
#include <vector>
#include <cstdlib>
#include <fstream>

using namespace std;

//TODO: what is this?
string category(string input)
{
    return "";
}

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
void List::push(string input) //Create new node in list
{

    node *created = new node; //Initialize new node and its variables
    created->input = input;
    created->next=NULL;
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
node* List::pop() //maybe add a "&" to the tail?
{

    node *curr = new node;
    node *prev = new node;
    curr = head;
    while (curr->next != NULL)
    {
        prev = curr;
        curr = curr->next;
    }
    this->tail = prev;
    prev->next = NULL;
    delete curr;
    return prev;
}
void List::display() //Iterates through linked list and displays the programs per page
{
    node *temp = new node;
    temp = head;
    while (temp != nullptr)
    {

        cout << temp->input << "\t";
        temp = temp->next;
    }

    return;
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
//TODO: wtf????
// void print(char token[])
// {

//     for (unsigned int k = 0; k < (sizeof(token) / sizeof(token[0])); k++)
//     {
//         printf("%3d ", token[k]);
//     }
// }
void List::catagorizer(List stackList,
                       vector<string> &keywords,
                       vector<string> &identifier,
                       vector<string> &constant,
                       vector<string> &operatros, //DEBUG: this is a meme
                       vector<string> &delimiter,
                       vector<string> &syntaxError)
{
    //Start from the tail
    //input is string to be parsed
    string input = tail->input;
    //token identified
    string token;

    //DEBUG:
    int j = 0;

    while (head->next != NULL)
    {
        cout << ++j << endl;
        for (unsigned int i = 0; i <= (input.size() - 1); i++)
        {
            //DEBUG:
            cout << "input i is " << input[i] << endl;
        }
         //DEBUG:
        cout << j << endl;
         //DEBUG:
        cout << j << endl;
        cout << "cat: prev is " << stackList.pop()->input << endl;
        //cout << "tail->input is " << tail->input << endl;

        //input = tail->input;
         //DEBUG:
        cout << j << endl;
    }
    //Parse token
    //Distribute strings to proper category vector
    //Pop and start over
}

int main()
{

    cout << "please enter the name of the .txt file: " << endl;
    List stackList;
    //TODO: figure out a way to use a vector in this and future main functions for elegance
    char filename[100];

    //Creates 2d vector for catagorization
    vector<string> keywords;
    vector<string> identifier;
    vector<string> constant;
    vector<string> operatros; //DEBUG: this is a meme
    vector<string> delimiter;
    vector<string> syntaxError;

    ifstream file;
    cin.getline(filename, 100);
    file.open(filename);

    if (!file.is_open())
    {
        exit(EXIT_FAILURE);
    }

    char token[100];
    file >> token;
    while (file.good())
    {
        //  cout << token << " ";
        stackList.push(token);
        file >> token;
    }
    stackList.push(token);

    //DEBUG:
    stackList.display();
    cout << '\n';
    //
    stackList.catagorizer(stackList, keywords, identifier, constant, operatros,
                          delimiter, syntaxError);

    system("pause");
    return 0;
}