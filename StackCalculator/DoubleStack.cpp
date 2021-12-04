//
//  DoubleStack.cpp
//  CS201 HW4
//
//  Created by Gökberk Keskinkılıç on 12.05.2021.
//  Slides from the class were used to create stack classes using pointer based implementation
//

#include "DoubleStack.h"


// default constructor
DoubleStack::DoubleStack(){
    topPtr = NULL;
}

// copy constructor
DoubleStack::DoubleStack(const DoubleStack& aStack){

   if (aStack.topPtr == NULL)
      topPtr = NULL;  // original stack is empty

   else {
      // copy first node
      topPtr = new DoubleStackNode;
      topPtr->item = aStack.topPtr->item;

      // copy rest of stack
      DoubleStackNode *newPtr = topPtr;
       for (DoubleStackNode *origPtr = aStack.topPtr->next; origPtr != NULL; origPtr = origPtr->next){
           newPtr->next = new DoubleStackNode;
           newPtr = newPtr->next;
           newPtr->item = origPtr->item;
       }
       newPtr->next = NULL;
    }
}

//destructor
DoubleStack::~DoubleStack(){

   // pop until stack is empty
   while (!isEmpty())
      pop();

}

bool DoubleStack::isEmpty() const{
    return topPtr == NULL;
}

bool DoubleStack::push( double newItem){
    // create a new node
    DoubleStackNode *newPtr = new DoubleStackNode;

    // set data portion  of new node
    newPtr->item = newItem;

    // insert the new node
    newPtr->next = topPtr;
    topPtr = newPtr;

    return true;
}

bool DoubleStack::pop(){
    if (isEmpty())
       return false;

    // stack is not empty; delete top
    else{
       DoubleStackNode *temp = topPtr;
       topPtr = topPtr->next;

       // return deleted node to system
       temp->next = NULL;  // safeguard
       delete temp;
       return true;
    }
}

bool DoubleStack::pop( double& stackTop){
    if (isEmpty())
       return false;

    // not empty; retrieve and delete top
    else{
       stackTop = topPtr->item;
       DoubleStackNode *temp = topPtr;
       topPtr = topPtr->next;

       // return deleted node to system
       temp->next = NULL;  // safeguard
       delete temp;
       return true;
    }
}

bool DoubleStack::getTop( double& stackTop) const{
    if (isEmpty())
       return false;
    else {
       stackTop = topPtr->item;
       return true;
    }
}

char DoubleStack::getTop() const{
    if (isEmpty())
       return '@'; //random sign
    else {
       char stackTop = topPtr->item;
       return stackTop;
    }
}

