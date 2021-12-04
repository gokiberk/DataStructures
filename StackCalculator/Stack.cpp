//
//  Stack.cpp
//  CS201 HW4
//
//  Created by Gökberk Keskinkılıç on 10.05.2021.
//  Slides from the class were used to create stack classes using pointer based implementation
//

#include "Stack.h"

// default constructor
Stack::Stack(){
    topPtr = NULL;
}

// copy constructor
Stack::Stack(const Stack& aStack){

   if (aStack.topPtr == NULL)
      topPtr = NULL;  // original stack is empty

   else {
      // copy first node
      topPtr = new StackNode;
      topPtr->item = aStack.topPtr->item;

      // copy rest of stack
      StackNode *newPtr = topPtr;
       for (StackNode *origPtr = aStack.topPtr->next; origPtr != NULL; origPtr = origPtr->next){
           newPtr->next = new StackNode;
           newPtr = newPtr->next;
           newPtr->item = origPtr->item;
       }
       newPtr->next = NULL;
    }
}

//destructor
Stack::~Stack(){

   // pop until stack is empty
   while (!isEmpty())
      pop();

}

bool Stack::isEmpty() const{
    return topPtr == NULL;
}

bool Stack::push( char newItem){
    // create a new node
    StackNode *newPtr = new StackNode;

    // set data portion  of new node
    newPtr->item = newItem;

    // insert the new node
    newPtr->next = topPtr;
    topPtr = newPtr;

    return true;
}

bool Stack::pop(){
    if ( isEmpty())
       return false;

    // stack is not empty; delete top
    else{
       StackNode *temp = topPtr;
       topPtr = topPtr->next;

       // return deleted node to system
       temp->next = NULL;  // safeguard
       delete temp;
       return true;
    }
}

bool Stack::pop( char& stackTop){
    if ( isEmpty())
       return false;

    // not empty; retrieve and delete top
    else{
       stackTop = topPtr->item;
       StackNode *temp = topPtr;
       topPtr = topPtr->next;

       // return deleted node to system
       temp->next = NULL;  // safeguard
       delete temp;
       return true;
    }
}

bool Stack::getTop( char& stackTop) const{
    if (isEmpty())
       return false;
    else {
       stackTop = topPtr->item;
       return true;
    }
}

char Stack::getTop() const{
    if (isEmpty())
       return '@';
    else {
       char stackTop = topPtr->item;
       return stackTop;
    }
}


