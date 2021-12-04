//
//  Stack.h
//  CS201 HW4
//
//  Created by Gökberk Keskinkılıç on 10.05.2021.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <stdio.h>
using namespace std;


class Stack{

public:
    Stack();
    Stack(const Stack& aStack);
    ~Stack();

    bool isEmpty() const;
    bool push( char newItem);
    bool pop();
    bool pop( char& stackTop);
    bool getTop( char& stackTop) const;
    char getTop() const;

private:
    struct StackNode{       // a node on the stack
        char item;              // a data item on the stack
        StackNode *next;        // pointer to next node
    };

    StackNode *topPtr;      // pointer to first node in the stack
};

#endif /* Stack_hpp */
