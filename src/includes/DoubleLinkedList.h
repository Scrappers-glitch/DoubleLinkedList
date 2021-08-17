#include <stdio.h>
#include <stdlib.h>

#ifndef DDDL 
#define DDDL 555
typedef struct Node Node;
struct Node
{
    //mark the node with an index to keep track of it
    int index;
    int Data;
    Node* Next;
    Node* Prev;
};

extern "C" void Add(int);
extern "C" void Display();
extern "C" Node* Search(int);
extern "C" void updateIndices();
extern "C" void Delete(int);
extern "C" void InsertAfter(int, int);
extern "C" int GetItemsCount();
extern "C" Node* GetByIndex(int);
extern "C" Node* copyVals(Node*);
extern "C" void Reverse();

#endif
