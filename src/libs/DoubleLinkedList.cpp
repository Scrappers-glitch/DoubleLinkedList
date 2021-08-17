#include <stdio.h>
#include <stdlib.h>
#include <DoubleLinkedList.h>

//Define the head, tail & length of the linkedlist
int length = 0;
Node *head = NULL, *tail = NULL;

void Add(int data)
{
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->Data = data;
    newNode->Prev = newNode->Next = NULL;

    if(head == NULL) // linked list is empty
    {   //first time call...
        head = tail = newNode;
    }
    else
    {   
        //add a new item after the old tail
        tail->Next = newNode;
        //assign the tail to the Prev pointer of the newNode Pointer
        newNode->Prev = tail;
        //overwrite the old tail with the new one
        tail = newNode;
    }
    //assign the index to length-1
    //length++ is a postfix incremental operation ==> increases the length after this line
    newNode->index = length++;
}

void Display()
{
    Node *current = head;

    while(current != NULL)
    {
        printf("%d \t", current->Data);
        current = current->Next;
    }
    printf("\n");
}

Node* Search(int data)
{
    Node *current = head;

    while(current != NULL)
    {
        if(current->Data == data)
        {
            return current;
        }

        current = current->Next;
    }

    return NULL;
}
/**
* swap the Next with the current Node index 
*    starting from the start index.
* @param startIndex value reference to the start index where the iterator would apply the indices swapping operation.
*/
void updateIndices(){
    int index = 0;
    Node* iterator = head;
    while(iterator != NULL && index < length){
        iterator->index = index++;
        iterator = iterator->Next;
    }
}
void Delete(int data)
{   
    //deep data copy
    Node *pDelete = Search(data);

    if(pDelete == NULL)
        return ;
    
    
    if(pDelete == head)
    {
        if(pDelete == tail)
        {
            head = tail = NULL;
        }
        else
        {
            head = pDelete->Next;
            head->Prev = NULL;
        }
    }
    else if(pDelete == tail)
    {
        tail = pDelete->Prev;
        tail->Next = NULL;
    }
    else
    {
        //assign the next of the previousNode to the next of the pDelete Node, dissolving the pDelete Node from the head
        Node* previousNode = pDelete->Prev;
        previousNode->Next = pDelete->Next;
        
        //assign the preva of the nextNode to the preva of the pDelete node, dissolving the pDelete Node from the tail
        Node* nextNode = pDelete->Next;
        nextNode->Prev = pDelete->Prev;
    }
    //remove one item from the length
    --length;
    //update the indices in accordance to the new length
    updateIndices();
    free(pDelete);
    pDelete = NULL;
   
}

/**
* inserts data in the node after this one.
* @param afterData the data of the node that we want to add after it.
* @param data the proposed data to fill inside the wanted node.
*/
void InsertAfter(int afterData, int data){
   //get the node to add after it
   Node* pNode = Search(afterData);
   //create a new node & fill its data
   Node* newNode = new Node();
   newNode->Data = data;
   newNode->Prev = pNode;
   newNode->Next = pNode->Next;
   
   //assign the next Node of the pNode to the newNode values
   pNode->Next = newNode;
   //assign the previous Node of the next node of the newNode with the values of the newNode
   newNode->Next->Prev = newNode;
   //advance the length by 1 new Node
   ++length;
   //update the indices in accordance to the new length
   updateIndices();
}
int GetItemsCount(){
    return length;
}
/**
* gets the node by an index
* @param index.
*/
Node* GetByIndex(int index){
    if(index >= length){
            perror("Specified Node with this index, doesn't exist !, ArrayIndexOutOfBoundsException");
        return new Node();
    }
    //mark the head node as the start --Shallow Copy of Data
    Node* node = head;
    //loop over the list as long as the proceeding node of this node is available
    while(node != NULL)
    {   
        //check if indices match
        if(node->index == index)
        {
            return node;
        }
        //shallow copy the next node to this pointer
        node = node->Next;
    }

    return NULL;
}



