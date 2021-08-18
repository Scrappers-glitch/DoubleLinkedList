/**
* Double Linked Lists.
* 2021-2022
* @author pavl_g.
*/
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <DoubleLinkedList.h>
using namespace std;

/**
* Run main Thread
* @return the status of the run
*/
int main () {
    //test add
    Add(3); 
    Add(4);
    Add(6);
    //test display
    Display();
    //test delete
    Delete(4);
    Display();
    //test insertAfter
    InsertAfter(3, 2);
    InsertAfter(2, 1);
    Display();
    //test getByIndex
    std::cout << GetByIndex(2)->Data << std::endl; 
    //test reverse --WIP
    Reverse();
    Display();
    //test getByIndex
    std::cout << GetByIndex(2)->Data << std::endl; 
    
    return 0;
}
