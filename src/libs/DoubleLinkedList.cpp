#include <stdio.h>
#include <stdlib.h>
#include <DoubleLinkedList.h>
#include <iostream>

Node* head = nullptr;
Node* tail = nullptr;

int length = 0;

void Add(int data) {
    Node *newNode = new Node();
    newNode->Data = data;
    newNode->Prev = newNode->Next = nullptr;
    // linked list is empty
    if(head == NULL){   //first time call...
        head = tail = newNode;
    }else{   
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

void Display() {
    Node *current = head;

    while(current != NULL)
    {
        printf("%d \t", current->Data);
        current = current->Next;
    }
    printf("\n");
}

Node* Search(int data) {
    Node *current = head;

    while(current != NULL){
        if(current->Data == data){
            return current;
        }
        current = current->Next;
    }

    return NULL;
}

void updateIndices(Node* start) {
    int index = 0;
    Node* iterator = start;
    while(iterator != NULL && index < length){
        iterator->index = index++;
        iterator = iterator->Next;
    }
}
void Delete(int data) {   
    //shallow data copy
    Node *pDelete = Search(data);

    if(pDelete == NULL)
        return ;
    
    if(pDelete == head){
        if(pDelete == tail){
            head = tail = new Node();
        }else{
            head = pDelete->Next;
            head->Prev = new Node();
        }
    }else if(pDelete == tail){
        tail = pDelete->Prev;
        tail->Next = new Node();
    }else{
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
    updateIndices(head);
    free(pDelete);
    pDelete = NULL;
   
}

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
   updateIndices(head);
}
int GetItemsCount(){
    return length;
}

Node* GetByIndex(int index){
    if(index >= length){
            perror("Specified Node with this index, doesn't exist !, ArrayIndexOutOfBoundsException");
        return new Node();
    }
    //mark the head node as the start --Shallow Copy of Data
    Node* node = head;
    //loop over the list as long as the proceeding node of this node is available
    while(node != NULL){   
        //check if indices match
        if(node->index == index){
            return node;
        }
        //shallow copy the next node to this pointer
        node = node->Next;
    }

    return NULL;
}


void Reverse(){
    //shallow copy(reference vals) tail Node to a cursor pointer pointing to the same storage
    Node* retroCursor = tail;
    //A new LinkedList to hold the reversed values of the current LinkedList
    Node* start = new Node();
    Node* end = new Node();
    //prepare & format data
    start->Data = end->Data = int();
    start->Next = start->Prev = nullptr;
    end->Next = end->Prev = nullptr;
    //an index for the new LinkedList
    int index = 0;
    //loop over the main linkedList in a retrograde fashion using the reference value retroCursor
    while(retroCursor != NULL && index < GetItemsCount()){
       //create a new Node memory address
       Node* node = new Node();
       node->Next = node->Prev = nullptr;
       //fill the data with current retrograde fashioned data
       node->Data = retroCursor->Data;
       //if the current item is the first in the new list
        if(index == 0){
            start = end = node;
        }else{
            //if the current node isn't the first, then add the new node after the oldEnd & assign the OldEnd as the Prev then assign the newNode to the newEnd overriding the old one from the endPosition.
            end->Next = node;
            node->Prev = end;
            end = node;
        }
        //advance retroCursor a little bit forward
        retroCursor = retroCursor->Prev;
        //fill the index for the current node, then increment index
        node->index = index++;
    }
    //copy values to the main LinkedList
   copyVals(start);
}
void copyVals(Node* start){
    Node* cursor = new Node();
    cursor->Next = cursor->Prev = new Node();
    cursor->Data = int();
    for(int i = 0; i < length; i++){
         cursor = GetByIndex(i);
         //copy node data to the main list
         cursor->Data = start->Data;
         cursor->Next = start->Next;
         cursor->Prev = cursor->Next;
         //advance on the reversed list
         start = start->Next;
    }
}

