#include <stdio.h>
#include <stdlib.h>

#ifndef DDDL 
#define DDDL 555

struct Node {
    //mark the node with an index to keep track of it
    int index;
    int Data;
    Node* Next = nullptr;
    Node* Prev = nullptr;
};

/**
* Creates a new node with a new data, given a new position in the current LinkedList. 
* @param int -- data to add.
*/
extern "C" void Add(int);
/**
* Displays the current LinkedList in a friendly way.
*/
extern "C" void Display();
/**
* Searches for a particular node with the given data.
* @param int -- given Data
* @return returns a memory ref to the founded Node.
*/
extern "C" Node* Search(int);
/**
* updates the indices of the given start node of a linkedList.
* @param node -- the start node of the targeted linkedList.
*/
extern "C" void updateIndices(Node*);
/**
* Returns a particular node with a given data.
* @param int -- the data of the node needed to be deleted.
*/
extern "C" void Delete(int);
/**
* inserts data in the node after this one.
* @param afterData the data of the node that we want to add after it.
* @param data the proposed data to fill inside the wanted node.
*/
extern "C" void InsertAfter(int, int);
/**
* Gets the length of the linkedList, ie number of nodes.
* @return int -- number of nodes in the current LinkedList.
*/
extern "C" int GetItemsCount();
/**
* gets the node by an index
* @param index.
*/
extern "C" Node* GetByIndex(int);
/**
* Deep Copy values of a LinkedList to the given LinkedList.
* @param int -- the start or the head node of the Other linkedList.
*/
extern "C" void copyVals(Node*);
/**
* Reverses the current LinkedList.
*/
extern "C" void Reverse();

#endif
